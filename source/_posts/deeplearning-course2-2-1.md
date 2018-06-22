title: 深度学习第二课第二周算法优化
date: 2018-06-01 19:24:02
categories:
- Technology
tags:
- tech
- deeplearning
---

在算法优化这一周的课程里，大纲是这样的

*	Mini-batch gradient descent
*	Understanding mini-batch gradient
*	Exponentially weighted averages
*	Understanding exponentially weighted averages
*	Bias correction in exponentially weighted averages
*	Gradient descent with momentum
*	RMSprop
*	Adam optimization algorithm
*	Learning rate decay
*	The problem of local optima

这一周的课程非常连贯，10节课程一气呵成没有任何分段。我们来看一下他们的内在逻辑。先看几个图：

{% asset_img gradient_descent.png [Gradient Descent] %}

在一个标准的Gradient Descent中，下降是非常直接而且直线的，很完美。然而根据本章的描述，这种完美在大数据的情况下会出现一定的问题。那就是每一次迭代update parameter的过程，因为涉及到的样本的数量过于庞大，导致需要做完所有的样本才能实现一次下降。这导致计算效率过低。如何才能提高计算效率呢，那就是争取早一点出结果，让后面的计算早一点站在“前人”的肩膀上工作。于是有了基于mini-batch的算法。

{% asset_img mini_batch_gradient_descent.png [Mini-batch Gradient Descent] %}

这种算法的好处是，虽有下降不再是那么完美的直线，但是它能让数据计算快速产生结果，让参数的更新加快、

在之后的学习中，Andew引入了Exponentially weighted averages概念。说白了，因为mini-batch的引入导致了比较剧烈的震荡，这会让下降的偏移度增加，导致下降到类似cost function指标需要的迭代明显增加了，于是引入了加权平均的概念，帮助缩小振幅，这让mini-batch算法既保留了快速应用前人结果进行下降的优势，又让下降的震荡幅度缩小。随后的momentum和RMSprop以及合体的Adam Optimization，大体就是以上逻辑的算法实现。

最后，章节描述了梯级下降中Learning rate的调优方法以及解释了局部最优困扰为什么是不存在的。