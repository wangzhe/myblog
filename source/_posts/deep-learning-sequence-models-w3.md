title: 深度学习顺序模型第三周
date: 2018-09-13 16:07:05
categories:
- Technology
tags:
- tech
- deeplearning
mathjax: true
---

来到最后一周了，本周分为10课，两个大部分

# Various sequence to sequence architectures

这个部分是本周的重点，8个课都是围绕着展开的。这种模型被广泛应用在了文字翻译和语义识别领域。让我们来看看都讲述了些什么。

##	Basic Models

```
x: Jane visite I'Afrique en septembre
y: Jane is visiting Africa in September
```

这里用了两套模型进行了组合，

+	作为encoding network：$x^{<1>}, x^{<2>}, x^{<3>}, x^{<4>} ... x^{ < T_x > }$，可以是一个RNN模型（GRU或者LSTM）
+	作为decoding network：$y^{<1>}, y^{<2>}, y^{<3>}, y^{<4>} ... y^{ < T_y > }$，同时后面继续跟随了

这样一种算法，同样对于Image Captioning这样的应用有效。应用是我们的输入是一张图片，应用的输出会把图片转化成一个语义

$$ \begin {matrix}
     y^{<1>} & y^{<2>} & y^{<3>} & y^{<4>} & y^{<5>} & y^{<6>} \\
     A & Cat & sitting & on & a & chair \\
\end {matrix} $$

在这样一个应用场景下，我们可以用CNN模型作为encoding network，把这个的输出，feed到RNN的顺序模型里面，进行训练。这个的输出，就是一个对Image的描述了。

<PlaceHolder for image>

## Picking the most likely sentence

### Machine translation as building a conditional language model

一个正常的language model，是一个从$a^{0}$ 到 $x^{<1>}$ 再到 $\hat y^{<1>} $ 再进行混合的演进的顺序模型。同时在这个模型里，会有 $ P(y^{<1>}, ..., y^{< T_x >})$ 的数值，来代表每一个过程中产生的y的可能性。这个一般是用来生成普通的句子

Machine Translation Model对应的是两个部分，encoding model和decoding model。可以看到decoding model和language model是很相似的。做为encoding model的输出，就是decoding model的输入 $ a_{<0>}$

这也是为什么我们把Machine translation model也叫做conditional language model。在形象一点的说法是，一段被翻译后的句子（比如Jane is visiting Africa）本身，是由前一个被翻译前句子的作为条件形成的。这个说法还挺有意思的，让我认清了翻译这件事情的本质。的确是这样。

### Finding the most likely translation （如何找到最好翻译）

```
x: Jane visite I'Afrique en septembre
```

于是乎，我们就有了 $ P(y^{<1>}, ..., y^{< T_x >} |x) $ 这样一个可能性的表示。这里的x就是上面说的那段法语句子。所以整个翻译模型的结果就是寻找P的最大值，找到最有可能的translation结果

### Why not Greedy Search

Greedy Search是一种算法，大概的意思就是，因为有了x(翻译前句子的输入)，我们接下来寻找每一个 $ P(y^{<1>} |x)$, 然后是$ P(y^{<2>} |x y^{<1>})$，一次类推，就是每次都寻找那个最合适的。而不是 $ P(y|x)$。我觉得其实这里不用多解释，这就是一个局部优化和整体优化的问题。如果计算量允许，肯定尽量采用整体优化，这样才能取得好结果。

既然Greedy Search不好用，那么如何从$ 10000^{10} $ (假设vocabulary有10000个，句子有10个单次) 这么多种可能性里进行选取呢？当然第一方法，就是使用x作为输入，寻找较大可能性。那么然后呢？还有什么方法？于是这里就用到了更进一步的Search Algorithm。这就又回到了这一课的主题，就是寻找最好的翻译，而不是随机寻找翻译结果（这里作者列举的例子是going和visiting，前者更加常见，但是后者更加适合Jane的语境）

## Beam Search Algorith

关于Beam Search算法，第一步是吧10000 words的vacabulary放进array里面。

$$ \begin {pmatrix}
     a\\
     \vdots\\
     in\\
     \vdots\\
     jane\\
     \vdots\\
     september\\
     \vdots\\
     zulu\\
\end {pmatrix} $$

所以这里的Step1，第一步就是 $P(y^{<1>}|x)$ 对应的单词。这里插入一个概念B，叫做Beam width, 例如B=3.这里给出的Beam的数值，就是为了系统记录下B个最有可能的单词。看起来，其实意思就是说，Greedy Search不是每次只找一个最好的么，这个Beam Search是根据Beam的数值，找B个最好的。

接下来进行Step2第二步。就很简单了，其实就是因为前一个假设是in了，那想标准的language model一样，会有一个$P(y^{<2>}|x”in“)$这样的表达式，来表示下一个最大可能的单词。因此下面这个公式还挺重要的，就是：

$$ P(y^{<1>}, y^{<2>} |x) = P(y^{<1>}|x) \times P(y^{<2>}|x”in“) $$

Again, 这里因为Beam Width为3，所以我们还是，选择最大可能的三个，不过这回就是三个pair了 $P(y^{<1>}, y^{<2>} |x) $. 如此循环进行下一步的运算。你看，这里B=1的话，那就真的是Greedy Search了

## Refinements to Beam Search

### Length normalization

这个就是Beam Search里面的一个部分。他的用法是这样的。

如同前文讲的，Beam Search的核心是寻找到最大的B个可能性，并进行模型推演。所以

$$ P(y|x) = avg max \prod_{t=1}^{T_y} P(y^{<t>} | x, y^{<1>}, y^{<2>}, ... , y^{<t-1>} ) $$

但是这里有一个问题，就是若干个百分之几十的数字相乘，会让这个结果趋近于非常小，不方便计算。于是这里引入了log，作为计算函数。这里P的数值越大，

$$ \log^{P(y|x)} = avg max \sum_{t=1}^{T_y} P(y^{<t>} | x, y^{<1>}, y^{<2>}, ... , y^{<t-1>} ) $$

$$ \frac{1}{Ty^\alpha} avg max \sum_{t=1}^{T_y} P(y^{<t>} | x, y^{<1>}, y^{<2>}, ... , y^{<t-1>} ) $$

$ \alpha $ 一般是从0到1的一个中间值，比如0.7。这个数用来对于模型进行校正和调整是比较管用的

## Error Analysis on Beam Search

关于整个翻译过程实际上是用到了Beam Search算法和两个RNN模型，对于结果而言，如何评价到底是哪里不好导致的问题。Error Analysis提供了一些方法

{% asset_img error_analysis.png [Error Analysis] %}

Case1: $ P(y_{*}|x) > P( \hat y|x) $
在这种情况下，因为Beam Search的作用是用来进行选取$\hat y$，那么既然命名$P(y_{*}|x)$会更好，但是Beam Search却选的不对。说明Beam Search有问题

Case2：$ P(y_{*}|x) < P( \hat y|x) $
RNN负责预测 $\hat y$ 而他错误的将$ P( \hat y|x) $ 生成了一个更大的P数值，这说明生成有问题。是RNN需要被调整

## Attention Module intuition

对比于简单使用输入RNN和输出RNN，Attention Module更好的处理翻译过程中的长句子问题。我们注意到在日常翻译中，MT在处理10个左右单词的句子时候，表现效果会比较好。但是如果再长，效果就会下降的非常明显。因此我们需要更好的模型来改进这一点。

首先分析一下原因，主要是单词的记忆导致的。事实上，人类在翻译长句子的时候，采用的是一部分一部分的翻译方式，并不会把他们都记录下来，因为记忆的原因。这个事情同样出现在机器上面，因为计算资源有限，所以我们也无法给计算机留出那么大量的选项进行综合运算。

+	Attention Weight，标注了对于一个生成的词来讲，哪些input word是应该被关注的，以及关注Weight是多少

+	$ \alpha^{ <1,2> } $ 这个表示第一个翻译后词汇，需要对翻译前句子中的第二个词的关注度有多高

## Atention Module

$$ \sum_{t} \alpha^{ <1, t> } = 1 $$ 
$$ C^{ <1> } （context）=  \sum_{t} \alpha^{ <1, t> } a^{ <t> }$$

$$ bug_{a} =  \alpha * sprint_{a} + \beta * sprint_{a-1} + bias $$


# 领域应用

## 语音识别 （Speech Recorgnition）

Audio Clip x，translate to ，Transcript y 