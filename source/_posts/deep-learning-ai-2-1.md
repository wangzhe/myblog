title: 深度学习第二周课程（下）
date: 2018-04-25 21:22:38
categories:
- Technology
tags:
- tech
- deeplearning
---

上一章节提到的梯度下降（Gradient Decent）过程需要多层嵌套For-Loop循环。这种循环非常耗费计算资源。为了降低计算资源消耗，提升计算效率，本章节引入向量计算（Vectorization）的概念。本章的主要内容也是围绕着向量计算和使用Python中的numpy库来实现限量计算的过程。

本章课程内容目录（与本文无关）：
*	向量计算（Vectorization）
*	使用向量计算逻辑回归（Vectorizing Logistic Regression）
*	使用向量计算逻辑回归中的梯度下降（Vectorizing Logistic Regression's Gradient）
*	Python的广播（Broadcasting in Python）
*	Python/numpy向量的介绍
*	逻辑回归里的Cost Function解释

### 安装一下jupyter

本章开始需要进行练习，Python是必须要装的，强烈建议Python3，课程使用Jupyter，这里也提示了一下安装，不过后来发现好像用处也不大。这个工具主要是可以把Python的程序脚本和文字进行混排，方便与演示。如果从来没有接触过Python的话，可以考虑用一下，毕竟这个是课程也在用的环境。如果有一点基础的话，Python有自己的IDE工具，PyCharm，很好用直接下载就行。

安装Python&Jupyter。因为一直写Python所以这个一直有没什么大问题，但是Jupyt这个倒是头一次见，好像是一种基于Browser的IDE，挺有意思的。具体可以访问以下几个地址：

*	安装Python，我一直用Brew install就好了
*	安装Pip，不过因为买了这个新电脑以后就没怎么写代码，所以竟然没有Pip。这个倒也不难，随便上网搜索“install pip”，两步简单操作就搞定了
*	安装Jupyter，没有按照web上说的用pkg包的方式，只是担心会安装额外的Python3.所以选择了通过pip命令行形式进行安装。

OK，三个安装结束，键入下面命令，直接启动Browser的界面

```
jupyter notebook
```

下面是标准编辑页面（竟然Hexo的asset_img可以用，好激动，但是asset_link确实不行，估计是因为marked里面escape的问题）

{% asset_img jupyter.png [jupyter starter] %}

首界面很简单，就是系统文件夹。右上角有新建功能，可以新建一个可运行的python文件。在课程中，Andrew主要介绍了 np.dot(i,j) 在程序中对比for-loop，超过300倍的优势。笔者后来自己查了一下原因，看来主要还是回到了Python作为解释性语言本身的问题。为了对初学者友好，Python作为解释性语言牺牲了许多性能上的东西。而np.dot之所以much faster，主要原因是一句Python语言，对应的是用C写成numpy库，这个库会将输入进来的数据进行编译，形成编译后的语言进行调用。这种方法，远好于Python一个字符一个字符的进行读取，并根据语法分析器进行描述，占据了大量的时间。当然其他原因也有许多，比如借助编译可以使用CPU或者GPU的SIMD指令集（Simple instuction multiple data）进行并行计算，大大提升效率。根据文章将，numpy的效率可以是原生python的2万倍。而据说选用cpython会达到20万倍之多。具体原理可以参看知乎上的这篇文章：

[python的numpy向量化语句为什么会比for快？](https://www.zhihu.com/question/67652386)

### 建立神经网络的主要过程

####	先来回顾一下基础算法：
For one example $x^{(i)}$:
$$z^{(i)} = w^T x^{(i)} + b \tag{1}$$
$$\hat{y}^{(i)} = a^{(i)} = sigmoid(z^{(i)})\tag{2}$$ 
$$ \mathcal{L}(a^{(i)}, y^{(i)}) =  - y^{(i)}  \log(a^{(i)}) - (1-y^{(i)} )  \log(1-a^{(i)})\tag{3}$$

The cost is then computed by summing over all training examples:
$$ J = \frac{1}{m} \sum_{i=1}^m \mathcal{L}(a^{(i)}, y^{(i)})\tag{4}$$

####	建模过程
*	定义模型结构（例如输入feature的数量）
*	初始化模型参数
*	升级参数（Gradient Descent）

讲上述三个部分逐个建立并整合进一个叫做model()的 $function$ 里。几个简单的 $function$ 会包含的 $sigmoid$ , initialize_with_zeros() , propagate() 

特别说明，关于 propagate() 的算法回顾如下：
Forward Propagation:
- You get X
- You compute $A = \sigma(w^T X + b) = (a^{(1)}, a^{(2)}, ..., a^{(m-1)}, a^{(m)})$
- You calculate the cost function: $J = -\frac{1}{m}\sum_{i=1}^{m}y^{(i)}\log(a^{(i)})+(1-y^{(i)})\log(1-a^{(i)})$

Here are the two formulas you will be using: 

$$ \frac{\partial J}{\partial w} = \frac{1}{m}X(A-Y)^T\tag{7}$$
$$ \frac{\partial J}{\partial b} = \frac{1}{m} \sum_{i=1}^m (a^{(i)}-y^{(i)})\tag{8}$$

下面的Code里面用到了一些“内积”、“外积”、“General Dot”的概念。在课程中有相关的联系材料。具体参见这个解释可能会更加实在

[使用numpy进行行列式乘积的计算](https://hk.saowen.com/a/c2cbbdb3dc43d41a717517faca384dc6228a9d2cbab31b59eca3f468c59e33b4)


```Python	
    m = X.shape[1]
    
    # FORWARD PROPAGATION (FROM X TO COST)
    ### START CODE HERE ### (≈ 2 lines of code)
    A = sigmoid(np.dot(X.T, w) + b).reshape(1, -1) # compute activation
    cost = - (1/m) * np.sum(Y*np.log(A) + (1-Y) * np.log(1-A))  # compute cost
    ### END CODE HERE ###
    
    # BACKWARD PROPAGATION (TO FIND GRAD)
    ### START CODE HERE ### (≈ 2 lines of code)
    dw = 1/m * np.dot(X, (A-Y).T)
    db = 1/m * np.sum(A-Y)
    ### END CODE HERE ###

    assert(dw.shape == w.shape)
    assert(db.dtype == float)
    cost = np.squeeze(cost)
    assert(cost.shape == ())
    
    grads = {"dw": dw,
             "db": db}
    
    return grads, cost
```

总结一下，这里建立的初始模型包括
$sigmoid$, $initialize$, $propagate$

####	优化模型参数（Optimization）
*	初始化参数
*	计算cost function 
*	通过梯级下降的方式进行参数更新并计算w和b的结果()

最近基本的梯级下降依据如下：
$$ \theta = \theta - \alpha \text{ } d\theta \tag{9}$$ 
where $\alpha$ is the learning rate

{% asset_img closing.jpg [gradient descent] %}

总结一下，这里建立的初始模型包括
$initialize$, $optimize$, $predict$

####	整合模型

合并模型建立$model$，使用plot建立拟合线

