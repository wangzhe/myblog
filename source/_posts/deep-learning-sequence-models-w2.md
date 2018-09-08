title: 深度学习顺序模型第二周
date: 2018-09-08 13:15:35
categories:
- Technology
tags:
- tech
- deeplearning
mathjax: true
---

第二周啦，这一周开始进入更深入的顺序模型的训练，这一周分为了三个部分，一共10课。

# Introduct to word embedding

第一部分是NLP and Word Embeddings，词语的嵌入

## Word Representation 语言表示

根据先前所学，每一个word被表现在一个Vocabulary的词典里面
```Python
V=[a, aaron, ..., zulu, <UNK>]  #假设 |V|=10,000
```
之前的表示，使用1-hot表达法。比如需要表示“Man”，假设这个词在词汇表的5391位置

$$ Man： O_{5291} =
\begin {pmatrix}
     0 \\
     0 \\
     \vdots \\
     1 \\
     \vdots \\
     0 \\
     0 \\
\end {pmatrix} 
$$

在实际应用场景中，当我们有一个训练模型来预测下一个单次的时候，例如
```
I want a glass of orange ____ (juice)
I want a glass of apple ____
```
按照常识，我们可以猜到下一个可能是juice，因为orange juice是比较流行常见的词汇。在训练中，我们当然也是这样做的。这样机器可以知道orange的下一个词可能是juice。然而，如果换成Apple呢？按理说，apple juice应该也是个很组合词汇。按照我们人类的推理，我们大约知道orange和apple是很相近的东西，所以既然有orange juice，大约也就有apple juice。但是根据以目前从训练模型的角度，因为在1-hot的词语表示下，每两个词之间相乘（product）得到的结果都是0。因此在这种情况下，我们说单词与单词之间是没有距离的。也就没有关联性可言，我们无法让机器从orange juice推演出apple后面是juice的预测结果。


### Featurized representation: word embedding

这里我们新学了一种方法叫做 word embedding
{% asset_img featurized.png [featurized representation] %}

每一个单词都会对应有一系列features，比如Man，对应Gender（性别），Royal（皇室），Age（年龄），Food（食物）。把这些feature和Man这个单词的关联关系进行数据化描述，得到一个数组用字母e来表示，比如Man，表示为$e_{5291}$。如图所示，我们可以通过对比$e_{456}$和$e_{4257}$，得到Apple和Orange两者存在较大关联，因此可以得到后面为juice的预测结果。这就是我们说的Word Embeddings

下一个问题相对简单，就是如何可视化word embeddings。因为按照之前的理论，每一个词，有300个维度（假设这里有300个feature）。为了可视化，我们把它降为展开到2D上。这个被叫做t-SNE

## Using word embeddings 使用word embeddings

这一节，主要是学习如何应用word embeddings到NLP，从而完成自然语言模型的训练。还是从例子开始

+	Sally Johnson is an orange farmer

根据前面的学习，我们大概知道了Sally和Johnson是两个名字。根据之前我们的学习，

+	Sally是$x^{<1>}$, Johnsan是$x^{<2>}$, is是$x^{<3>}$, an是$x^{<4>}$, orange是$x^{<5>}$, farmer是$x^{<6>}$

接下来就是通过这个的训练，来生成下面的处理结果

+	Robert Lin is an apple farmer (a durian cultivator)

通过网上上百万千万的词汇和特性关联，我们尝试寻找到durian和apple与orange之间的关联，以及farmer和cultivator之间的关联性。transfer learning

### Transfer learning and word embeddings

1.	从大量词汇文集中（1-100B words）学习word embeddings；当然也可以从线上下载一些被pre-trained embedding
2.	把这些embedding，通过使用一个相对小的训练集，迁移到新的任务中（比如100k的词汇），在这里我们就可以使用一个小得多的特征向量（比如300个，而不是10000个）
3.	可选项：通过新的数据，持续调整（finetune）word embeddings，来改进模型

个人觉得，这个其实很容易理解，我们每个人都在学很多的基础知识，然后因为各种不同的场景，我们需要学习一些上下文。比如同样一个词，在军事领域和民用领域就不一样。这个在Wikipedia里查词的时候非常常见。尤其是缩写

Andrew在这之后介绍了，face encoding（DeepFace）和word embedding的雷同之处。两者都是把一个“object”转化成了一系列特征向量，然后进行对比的方法

## Properties and word embeddings

一个关键词：analogies（类比），这个确实是一种人类很神奇的东西，但这也是NLP应用最重要的东西

接下来主要描述的是如何让机器理解类比。课程中描述了，一个类比，如果Man到Woman，如何类别出King到Queen。文章使用的方法是

$ e_{man}-e_{woman} \approx \begin {pmatrix}
     -2 \\
     0 \\
     0 \\
     0 \\
\end {pmatrix} 
$ 和 $ e_{king}-e_{quene} \approx \begin {pmatrix}
     -2 \\
     0 \\
     0 \\
     0 \\
\end {pmatrix} 
$ 最终我们得到 $ (e_{man}-e_{woman}) \approx (e_{king}-e_{quene})$ 以此来表明类比关系

这个的总结公式是 

$$ Find word(w): arg max_w sim(e_w, e_{king}-e_{man}+e_{woman}) $$

进一步数学化这个公式，来解释$ sim(e_w, e_{king}-e_{man}+e_{woman}) $. 常用的解释方法是Cosine similarity.

$$ sim(u,v) = \frac{u^Tv}{||u||_2 ||v||_2} $$

用余弦函数来描述sim的数值。根据余弦函数，$cos \phi$ 是一个在$(1，-1)$区间的值。现实中，也有人使用方差来表示$ ||u-v||^2 $

Some more examples like:

+	Man:Woman as Boy:Girl
+ 	Ottawa:Canada as Noirobi:Kenya
+	Big:Bigger as Tall:Taller
+	Yen:Japan as Ruble:Russia

## Embedding matrix

$ E \cdot O_{6257} = \begin {pmatrix}
     0 \\
     0 \\
     \vdots \\
     1 \\
     \vdots \\
     0 \\
     0 \\
\end {pmatrix} = e_{6257} = e_{orange}
$  这是一个 $(300, 1)$ 的矩阵，来表示Orange这个词对应的embeddings

in common，总结一下

$ E \cdot O_j = e_j $ 等于 embedding for word (j)

因此我们就得到了，对于模型而言，我们的训练目标就是获得这个Embedding Matrix $E$。在Keas里面，事实上使用embedding layer来解决问题，这样更加有效

# Learning Word Embeddings: Word2vec & GloVw

好了，进入第二部分，在上一部分，学习了关于embedding，和模型训练目标Embedding Matrix $E$。这个部分就是来讲述如何训练模型$E$

## Learning Word Embeddings


