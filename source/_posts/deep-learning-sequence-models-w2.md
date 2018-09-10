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

按照andew的介绍，现在的算法变得越来越简单。但是为了方便和便于理解，介绍还是从相对复杂的算法开始

```
I       want a glass  of   orange ______
4242    9665 1 3852  6163   6257
```

I represent as $ O_{4343} \longrightarrow E \longrightarrow e_{4343} $ 
want represent as $ O_{9665} \longrightarrow E \longrightarrow e_{9665} $
a represent as $ O_{1} \longrightarrow E \longrightarrow e_{1} $

$ e_{x} $ is a 300 dimentional embedding vector. fill all e into a neural network and then feed to a softmax into a 10000 output vector. neural network with $w^{[1]}$, $b^{[1]}$; softmax parameters are $w^{[2]}$, $b^{[2]}$. the dimensional of neural network is 6 words times 300 dimentional word, which is a 1800 dimentional network layer. also we can decide a window like "a glass of orange ______", which removed "I want"

接下来文章讲述了不同的context上下文组合方式，列举例子如：

原句是：I want a glass of orange juice to go along with my cereal

+	Last 4 words (a glass of orange _____)
+	4 words on left & right  (a glass of orange _____ to go along with)
+	Last 1 word (orange _____)

作者表达了不同的应用上下文学习的方法，如果the goal is just to learn word embedding那么，使用后集中简单方法，被认为已经可以很好地学习到了

## Word2Vec算法

一种跟简单而有效的算法，学习Word Embeddings。先来看一下Skip-grams，依然是刚刚那个句子：
```
I want a glass of orange juice to go along with my cereal.
```

这个算法里面，随机的选取一个word作为context word，例如在上面那个句子里面，我们选择orange作为context word。接下来继续在一个window的去区间里面，选择一个target，比如选择了下一个word，那就是juice，选择之前两个的那个word，那就是glass等等。接下来，对于supervise learning模型而言，以context word为准，让系统去学习预测制定的target，不断校正其对应的W和b参数。

### Model

Vocab size = 10000k

$$ ContentC("orange") \longrightarrow TargetT("juice") $$
$$ O_c \longrightarrow E \longrightarrow e_c \longrightarrow softmax \longrightarrow \hat y $$

这里的softmax是个相对特殊的公式

$$ softmax = \frac{e^{\theta^T_te_c}}{\sum_{j=1}^{10000} e^{\theta^T_je_c}} $$

关于选择context的问题：

课程中提出，to，the，a，of，for，在英语中是非常常见的词语。因此在随机选择时，会把这些常见词和非常见词分开来，以保证非常见词语，比如apple，orange甚至durian能够被（sampling）采样到。

## Negative Sampling算法

定义一种新形式的supervised learning problem，举例原句不变
```
I want a glass of orange juice to go along with my cereal.
```

接下来会有两组不同的pair

$$ \begin {matrix}
     context & word & target \\
     orange & juice & 1 \\
     orange & king & 0 \\
     orange & book & 0 \\
     orange & the & 0 \\
     orange & of & 0 \\
\end {matrix} $$

第一排，是和之前的算法一样，通过在句子中进行选取，得到的一组pair，我们把这样的pair对应target值写成1，然后把从vacabulary里面随机选择出来的word，比如king，对应的target数值叫做0。事实上，所有随机从vacabulary里面抽取的数值，都会视为0

### Model

$$ p(y=1 | c,t) = \sigma (\theta^T_t e_t) $$

$$ o_{6357} \longrightarrow E \longrightarrow e_{6357} $$

接下来的意思是，$ e_{6357} $ 和 在vacabulary里面的10000个词汇进行配对，生成10000个0和1的target(logistic classification). 在实际应用中，每一次迭代选择也不是10000个，而是k个，k一般在5-20之间。每次迭代只需要计算k+1个logistic classification就可以了

同样的问题，如何选择negtive example，作者介绍了一种方法，用来做sampling，不过好像就是一种在词汇出现频次的基础上人为调整了数值的方法而已

## GloVe算法

这是本课程介绍learning word embeddings的最后一种算法。这个算法可能并没有Word2Vec和Skip-gram那么普遍使用，但是因为他更简单，所以也值得被介绍一下。

GloVe算法的全称是全向量词语表达(Global Vector for word representation)
```
I want a glass of orange juice to go along with my cereal.
```

之前我们用的c和t来表示配对关系。在GloVe算法里有如下的公式

$$ X_{ij} = #times $$

$ X_{ij} $ 可以表示为i显示在j的上下文中出现的次数。因此类比一下，这里的i可以相当于Word2Vec里面的target(t), j是context(c)

### Model

具体算法暂时不陈述了，因为没太听懂，其实还是使用了上面算法里面的那个 $ \theta^T_te_c $. 我觉得我在这个地方的确没太明白他代表了什么。需要在复习的时候重新看一下。眼下先把考试过了再说


# Applications using Word Embeddings

最后一部分了，主要讲述对于Word Embeddings的应用方法。

## Sentiment Classification

开始没懂什么意思，看图一下子就明白了
{% asset_img sentiment.png [sentiment classification] %}

### Simple sentiment classification model

```
The    desert   is   excellent    # goto 4 stars
8928    2468   4694    3180
```

$$ \begin {matrix}
     The & o_{8928} & \longrightarrow & E & \longrightarrow & e_{8928} \\
     desert & o_{2468} & \longrightarrow & E & \longrightarrow & e_{2468} \\
     is & o_{4694} & \longrightarrow & E & \longrightarrow & e_{4694} \\
     excellent & o_{3180} & \longrightarrow & E & \longrightarrow & e_{3180} \\
\end {matrix} $$

假设每一个是300个dimentional embeddings. 把这四个词放在一起，就是一个由1200个dimention组成的neural network layer。err，这里好像不太一样，这里用的是sum或avg这300个特征向量，然后把这个扔给softmax，得到1-5的一个y

### RNN for sentiment classification

```
Completely lacking in good taste, good service and good ambience    # goto 1 star
```

对于这样一句话，刚刚的算法表示很无奈。这里面虽然出现了许多的good，但是并不是说好的，而是lacking in。所以如果完全的sum或者avg很难实现 goto 1 star的效果。

使用Many-to-one RNN Achitecture
{% asset_img rnn.png [RNN for sentiment classification] %}

这里说明使用word embeddings的方法$ e_{4966} $我们训练的是结果可以有更好的类比性，比如lacking和obsent，而不再只是拘泥于一个固定词汇的训练。这让语言有了更强的灵活性。

## Debiasing Word Embeddings

去除偏差，这里指的不是deeplearning里面的bias，与embeddings相关的预测结果的偏差问题。比如

+	Man:Woman as King:Queen 这个是对的
+	Man: Programmer as Woman:Homemaker 这个就不对了
+	Father:Doctor as Mother:Nurse 这个也不合适

源自于我们生活的显示，基于性别，信仰，年龄，性别等造成了许多偏差认知，这在人类社会也广泛存在。但是我们并不希望计算机也有这种所谓偏差，甚至“歧视”出现。所以有了本文中所描述的关于如何去除偏差的方法。

## Addressing bias in Word Embeddings

因为内容感觉和我差的有点远，知道就好，所以这里做个特别简要的描述

1.	Identifiy bias direction（比如性别，年龄）
2.	Neutralize: For every word that is not definitional, project to ge rid of bias
3.	Equalize pairs

有篇论文，[Bolukbasi et. al., 2016. Man is to computer programmmer as woman is homemaker?]



