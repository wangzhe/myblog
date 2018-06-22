title: 深度学习第四周神经网络
date: 2018-05-18 12:46:46
categories:
- Technology
tags:
- tech
- deeplearning
---

上一周（章）主要学习的是一个Hidden Layer的情况下，如何进行模型搭建。这一周开始进入多个Layer的学习。同样的首先上大纲：

*	L层深的神经网络 (Deep L-layer neural network)
*	深度网络中的向前扩展 (Forward Propagation in Deep Network)
*	正确获取和验证行列式 (Getting your matrix dimensions right)
*	深度代表什么 (Why deep representations)
*	组建深度神经网络的模块 (Building blocks of deep neural networks)
*	向前和向后扩展啊 (Forward and Backward Propagation)
*	参数和高度参数 (Parameters vs Hyperparameters)
*	计算机神经网络与大脑神经网络 (What does this have to do with the brain)


一个基本的Linear到sigmoid的公式
$A^{[L]} = \sigma(Z^{[L]}) = \sigma(W^{[L]} A^{[L-1]} + b^{[L]})$


In general, initializing all the weights to zero results in the network failing to break symmetry. This means that every neuron in each layer will learn the same thing, and you might as well be training a neural network with  n[l]=1n[l]=1  for every layer, and the network is no more powerful than a linear classifier such as logistic regression.