title: 关于Collection和Set
date: 2015-08-29 07:39:44
categories:
- Diary
tags:
- math
---
早上看MongoDB的文档，忽然看到Collection，疑惑了一下为什么起这个名字，于是上网搜寻了一下Collection和Set的区别，主要是看了[Stackexchange的一篇文章](http://math.stackexchange.com/questions/172966/difference-between-class-set-family-and-collection)。

也就是认为Collection代表一个集合，可以放任何东西，是一种总集合。数学上，在提及一个概念的时候，通常正式表带为notion。然后用公立（axioms）来描述这个概念（notion）。如果这个公立被认为不是自相矛盾的，那么就开始根据公立来定义一系列定理（definition）。所谓一个Collection，就是那些适用公立存在的东西（a collection is a notion of something that we can talk about, like a mystery bag）。

那么说Set有什么不同呢？Native Belief，我们本能可以相信Collection就是Set，尤其是对于非数学人士。这里的例外是Collection包含有哪些悖论的存在，而Set是不可以有的。如果是一个Set，那么通过反证也可以推导出是Set的结论。但是悖论不行，如Russell's Paradox。

这里补充知识，Russell's Paradox（罗素悖论）也叫理发师悖论
在某个城市中有一位理发师，他的广告词是这样写的：“本人的理发技艺十分高超，誉满全城。我将为本城所有不给自己刮脸的人刮脸，我也只给这些人刮脸。我对各位表示热诚欢迎！”来找他刮脸的人络绎不绝，自然都是那些不给自己刮脸的人。可是，有一天，这位理发师从镜子里看见自己的胡子长了，他本能地抓起了剃刀，你们看他能不能给他自己刮脸呢？如果他不给自己刮脸，他就属于“不给自己刮脸的人”，他就要给自己刮脸，而如果他给自己刮脸呢？他又属于“给自己刮脸的人”，他就不该给自己刮脸。于是产生矛盾。

Collection公式如下
{% asset_img russell_paradox.png "russell_paradox" %}

<!-- ![russell_paradox](russell_paradox.png) -->

这个就不应该叫做Set了，但是依然可以称之为Collection。本来悖论这个事情，造成了第三次数学危机。不过内涵公里，进行了证明。
