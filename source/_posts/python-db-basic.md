title: python_db_basic
date: 2015-01-16 18:58:15
categories:
- Technology
tags:
- tech
- python
---
有些东西就是放下来记录一下，关于python的。这两天病了，忽然觉得这个事情总是对着有一种箭在弦上不得不发的感觉，所以说什么也要把这几块儿技术上的东西完成。搞完这个，应该可以踏踏实实的看看公司下一步的内部管理要如何做了，现在开始有点疲态的感觉，可能是因为平台接二连三的事故。不过这个我倒是不担心，毕竟一直在运行，一点点小聪明还是可以搞定的，只是，眼看，需要一个系统行的计划了，新的一个半年计划应该要搞一下出来了。

这个title叫python db basic，其实名字不好，主要是记录一下几个主要的命令，如何继续完成我的这个小玩具。

1）Python DB，超简单的东西，Djangle框架和RoR框架一样，基本上对于简单应用就是记住几行命令

在Models里面建立好class

在命令行里面运行，并生成migration脚本

```bash
python manage.py makemigrations
```

在命令行里面运行，并生成数据库的内容

```bash
python manage.py syncdb
```

在view里面用class直接产生新的obj，然后obj.save()就可以了

2）一个微信的小东西
ngrok用来做本地调试，却是好用截个图，剩下的自己查吧



王哲，CTOin杏树林
紧张的时候，静下来写一写条目，来看看哪些在做，哪些要做，哪些没做
