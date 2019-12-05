title: GCP搭建serverless
date: 2019-12-02 20:35:12
categories:
- Technology
tags:
- tech
- cloud
---

之前弄了阿里云的事情，最近因为做公司数据分析到AI的部分，所以必须把GCP彻底整理一遍。首先要澄清，从本身GCP的使用方面自己确实不是专家。但是感谢Google这一年多以来的合作，确实让我对high level的GCP以及相关产品，了解了许多。特别是全套的数据产品服务，也直接导致我来决策了GCP作为数据中心的定位，这也是为什么我需要开始把我的一些分析工具转移到GCP的原因。学习成本也是必须要付出的。

这次转移的部分就是数据分析平台，从原来的RJMetrics转移到以GCP为基础的Data Studio和Tableau上面。既然公司业务已经全面转移了，技术的主要数据分析，我也想一并转进来，并且借这个机会学习一下GCP的几个主要产品，为我在这边这个平台上搭建AI的技术效率分析系统做铺垫，这应该是我最近最大的兴趣所在了。让我们一起动手，消灭我们手里那些反复消磨时间的无意义工作，也许分析业务产生算法，才是程序员，至少是下一代程序员的职责（之后的时代，虽然NLP的普及，也许连分析业务也会被取代，we will see）

##GCP合理使用

Google prefer to use Google Cloud SDK. so use gsutil in terminal is much easier to use.

###关于serverless

做这件事情的动因是因为做一个个人工作分析器，内容很简单，就是从wunderlist api里把数据拿出来，然后进行分析。这玩意儿明显就是个serverless。刚好之前在阿里云上研究的也就是serverless，索性用一下，应该蛮cool的。

gcloud的serverless分为两种，code function和code run, 前者可以绑定若干种触发器，比如时间，event等等，后者主要绑定http触发。code function这里和阿里云的函数计算差不多，这里就不多说了。本次主要使用的是code run，一套基于container的方法进行的http serverless。我只能说太为程序员着想了。

之前使用阿里云函数计算最大的问题就是，lib被阿里云绑死了，没法进行扩展。而且有些库，阿里云上就没有，导致必须为了兼容serverless该自己的程序。现在不用了，有了code run，完全是一套自己封闭的环境。requirements.txt随便写，系统帮你填上需要的lib和version。好用！好用！

###Storage的选择

在GCP上面，一共有五种storage，分别是
+ SQL，这个基本上就是MySQL
+ Datastore, 可扩展的NoSQL database
+ Bigtable，这是一个结构化大数据库，是HBase的姊妹形态。如果有TB级别的结构化数据，存在大量写操作，高频low latency的读写要求，使用Bigtable是最合适的。Bigtable使用Hbase shell quickstart.sh来进行 
+ Storage, 这个主要用于做object的存储，分为standard 99.9%，Durable Reduced Availability 99%, Nearline 99%, 可以通过gsutil上传或下载
+ BigQuery

[Youtube Video: Chose you storage and database on GCP](https://www.youtube.com/watch?v=mmjuMyRBPO4)

###其他一些内容

Compute Engine，就是VM，创建instances, 每一个instance都可以依据选择访问project下的所有资源。当使用terminal来访问资源的时候，还需要进行必要的配置工作。进入。首先是在SQL里面，给MySQL配置ip

{% asset_img sql_network.png "给SQL配置IP和访问权限"

安装gcloud terminal sdk，suprise，这是我非常少有的一次成功不带阻断的精力。认证直接通过sh脚本启动service，调用远程oauth，在网页端完成认证，这种方式很新颖，免除了以前需要.ssh交换秘钥的麻烦。一气呵成，很赞！
