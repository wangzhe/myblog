title: 深度学习第三周神经网络
date: 2018-05-04 15:45:00
categories:
- Technology
tags:
- tech
- deeplearning
---

上一周（章）主要学习的是如何构建模型，梯级下降和使用numpy进行向量计算。这一周开始进入神经网络的学习。同样的首先上大纲：

*	神经网络全景图（Neural Networks Overview）
*	神经网络表达（Neural Network Representation）
*	计算神经网络输出（Computing a Neural Network's Output）
*	向量化（Vectorizing across multiple examples）
*	向量实现（Expanation for Vectorized Implmetation）
*	激励函数（Activation functions）
*	为什么需要非线性模型（Why do you need non-linear ）

这一周的学习说简单也简单，说难也难。我们来先说简单的：

所谓简单，指的是这一周的课程主要是在上一周Logistics Regression的基础上加入了一个Hidden Layer的概念，即将所有的内容从两层输入输出结构，变成了三层，因此引入了$n^0, n^1, n^2$的三个层进行计算。这样做的好处是可以将模型变得拟合度更高，进一步提高Accuracy。而所有在Logistics Regression中用到的公式和方法基本沿用，所以数学本质上并不难，只是增加一个维度。

说他难呢，基本上就是因为增加了一个维度，所以derivative的所有计算方面，确实需要更多的东西了。当然这里也有一些小改变，那就是引入了activation function的概念，将原来那个在逻辑回归中谈到的Sigmoid Functoin，作为一种activation function；从而进一步引入其他的activation function，比如“$tanh$”

把这一周的内容集中在使用场景方面的总结：
{% asset_img hl3_4.png [Hidden Layer 3] %}
对于3到4层Hidden Layer的时候

{% asset_img hl5_20.png [Hidden Layer 5] %}
对于5到20层Hidden Layer的时候

{% asset_img hl50.png [Hidden Layer 50] %}
对于50层Hidden Layer的时候

可以明显的看出当Hidden Layer提升了以后，预测拟合度就更高了，这就是神经网络带来的巨大意义
