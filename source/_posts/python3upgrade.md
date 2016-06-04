title: 升级Python3几个小总结
date: 2016-05-22 09:30:31
categories:
- Technology
tags:
- tech
- python
---

最近，主要是想集中把这次的改造写完，早日上线。这次主要干了两件事情。第一是升级Python3，这里面顺带写一点学习总结。算是个misc文章吧。下一篇主要是想聊聊没有后台的系统到底是如何搭建以及为什么要做这个实验。

OK，先说这次Python3升级吧。想了很久了，受制于各种阻力，总是担心升级会出问题。但是Python3既然已经嚷嚷了这么多年。而且还是有越来越多的系统在往Python3上迁移，所以还是用用看。至少知道坑在哪里，以后会遇到哪些问题。

总结一下本次修改较多的几个部分：

+	Print语法：Python3最有名的一个表征就是print的括号问题。在Python2里面是没有的，在3里加上了（）这个语法。所以导致从2向3升级的过程中print，成了修改最多的语法之一。

+	Pip2（Python2）和Pip3（Python3），一般来讲，如果之前装的是2的，升级到3时候Python和Pip两个命令依然表示的是2，如果要是使用3.x的话，需要加入pip3或者python3，来作为命令开头。为了简单期间，或者用env来定义。还有一种就是在bash_profile里面增加python的alias

	```
	alias python='python3'
	alias pip='pip3'
	```
	
+	MySQL-python包的使用。这个很讨厌，因为目前这个包还不支持Python3。不过也没什么着急的，换一个呗。PyMySQL这个是Python官方对于MySQL的支持包。对于基本的增删改查操作，用法基本上是一样的。只不过要特别注意的是连接时要加入“charset="utf8"”来实现对中文的支持。这个在MySQLdb里面好像是默认，至少我当时没有设置。

	```
    db = pymysql.connect(host=host, port=int(port), user=username, passwd=password, db=database, charset="utf8")
	```

+	关于unicode，这里说道大头了哈。因为绝大多数人对于Python2中文支持都是一个噩梦。文字，被在<class 'str'>-<class 'unicode'>-<class 'byte'>之间转换。但在Python3里面，很重要的一点是对中文做了很好的支持。消除了unicode这一层环节。所以现在就可以比较明确的说“中文.encode('utf-8')”就是解码环节，无需再顾忌其他。
	{% asset_img unicode.png "Python3里的中文问题" %}

+	也正是因为这个unicode的转变，其实造成了Python2里面很多原始代码都要进行一系列的和字符集相关的变化。比如一个buildin的函数open，在以前2的时代，是不需要对字符集进行指定的（话说，其实也是因为那个时代就没有什么字符集）。现在要特别说明打开字符集类型才可以进行有效的读写操作。

	```
	open(filename, 'w', newline='', encoding='utf-8')
	```
	
+	另外很赞的一点是，Unittest对Python的支持非常好。我自己实际用了unittest2和mock两个库。基本上都没有出现什么相关的修改。非常赞！所以说测试还是要加哦，很不错滴。

这次升级，确实花了些时间，处理问题。但确实得到了不少有益的实践。总结下来是两点吧

1.	单元测试很重要。整个过程中，升级后的第一件事情就是运行单元测试，其中大量的错误，但是不可怕，一个一个的改就好了。因为我的程序设计web、邮件、数据库等多方通讯，没有单元测试，效率会大打折扣，而且还有可能遇到因为网络问题而导致的联调失败
2.	Python2到3的升级并不可怕，主要问题恰恰是来自于unicode这块儿的改变。只要记好了字符集utf-8这件事情。你会发现大量问题，都和这个有直接关系。