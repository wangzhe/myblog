title: 关于如何用Hexo书写数学符号(深度学习前哨贴)
date: 2018-04-23 21:36:17
categories:
- Technology
tags:
- tech
mathjax: true
---

翻了几个帖子，总算是搞定了。最主要的帖子是以下两个

[在hexo博客中使用Mathjax写LaTex数学公式"](https://blog.csdn.net/sherlockzoom/article/details/43835613)
[如何在 hexo 中支持 Mathjax？](https://blog.csdn.net/u014630987/article/details/78670258)

另外，按照Hexo文档上写的，理论上Hexo-math应该已经支持MathJax了，但是似乎用起来有点问题，不知道是hexo文档的错，还是我自己那个地方配置有错，以后找时间在研究吧。地址如下：
https://github.com/hexojs/hexo-math

还有最后要提醒一点，本次修改以后，不能用Hexo原生提供的assert方式来写作了，需要使用纯markdown模式。目前感觉良好，不知道后续会不会有什么坑。目前看这个改变不会影响之前的东西。

[markdown的书写格式](https://help.ghost.org/article/4-markdown-guide)

这是一个公式  $E=mc^2$
Simple inline $a = b + c$.

$$\sum_{i=1}^n a_i=0$$ 

$$f(x_1,x_2,\ldots,x_n) = x_1^2 + x_2^2 + \cdots + x_n^2$$

大功告成，接下来需要学习MathJax了
[MathJax一些说明](https://blog.csdn.net/ethmery/article/details/50670297)
[原文文档](https://docs.mathjax.org/en/latest/tex.html)