title: OKR学习总结
date: 2016-03-27 09:25:04
categories:
- Management
tags:
- book
- mgnt
---

OKR已经尝试了3个季度了，感觉从一团迷雾里渐渐看出了点眉目，我很难说现在的一切是对的，但是总结出一些东西，为了今后更加努力的改进。既然OKR是目标，既然OKR是数据驱动的基础，那么就要坚持演进下去。以下想表达的，更多是基于自我OKR回顾的一种总结，并不是OKR完成的组成。只是像以此描述我在定义OKR的过程中所走过的那些坑坑洼洼。

**OKR疑问有所斩获：**

+	Align目标
	这个话题其实以前是知道的，但是体会不深。直到上一次我遇到了一个世纪的问题。当时所有“基础架构”团队的OKR基本上都是1on1来制定的，基本上纯从每个人的想法出发，我这边进行了一些修改和补充。然后，后来做到一半，技术团队OKR出来了，发现之前定义的好多和技术团队OKR关系不大。包括后来又改过几次，才发现慢慢上到。所以OKR以上上下下做做右右信息透明为第一要务，为的就是让大家目标能够algin到一起去。
	具体改进方法：OKR一定要从公司级别开始定义，以此来推导出与公司目标align的技术团队OKR，这个OKR，理论上还应该回过头来和其他业务团队的OKR（针对杏树林而言，可能更多是业务团队）进行align。不过在实际目前的操作中可能并不需要从一开始就这么做，毕竟所有团队也都是为了公司的OKR完成的。因此，出于效率考虑可以继续下去。那么接下来就是小组或者个人级别的工作了。最终，通过一系列的OKR制定工作，可以保证每个季度大家都在一个方向上工作，帮助公司完成商业目标。	
	
+	团队／个人对OKR负责
	说到OKR，就不得不说到很多技术团队的同学们反应，在公司缺乏团队感，不知道向谁汇报，谁该有权利给谁分配任务。其实OKR就是很好的一个衔接点。每一个人为自己的OKR负责，OKR的来源可能是多方面的。在初期一定会有个人帮助他订立OKR，收集需求和反馈。对于业务团队内部来说，往往这件事情比较简单，就是业务团队的技术Lead和业务本身。对于基础架构或者跨团队支持的技术同事，往往这个时候技术同事的级别本身都比较高，那就需要对技术总监团队负责。总体而言，谁帮助订立OKR，就应该谁是负责人。但是OKR一旦被制定下来，每个人应该为OKR负责。
	
+	OKR为了制度改变
	OKR不是绩效目标。因为假设人是优秀和自驱动的，不满足这个条件的人，可以不存在于OKR体系，而实用类似KPI等其他体系。这个话题缘起于对OKR Review的一次讨论，集体内容不说。反思大概是这样。如果OKR的订立前提是，组织内每一个人都是积极的，主动的，乐于思考和勇于承担的，那么OKR的作用是为了帮助大家，对没有做到或没有做好的问题，寻求解决方案。而这种解决方案在实践中，往往就是公司的一些制度和方法的演进。也就是说，任何事情一定要寻找一种新的积极的流程去解决掉。这个前提就是去寻找当时订立OKR之后，发现执行过程中没想到的东西。然后寻找方法，避免掉没想到问题的再次发生。这样可以将OKR订立的更好。
	{% asset_img OKR_review.png "OKR为了制度改进" %}


**时间计划值得坚持：**

+	定理时间的经验
	根据Q1的经验，我们在给Q2定力OKR的时候做了一些改动
	*	为了更高效的完成OKR，我们采用组级别进行OKR定义，分为基础架构，公共服务组，PTL团队。
	*	将技术总监团队先完成OKR的制定，然后是基础架构团队，然后是PTL团队。
	*	先进行上季度OKR Review，然后进行新季度OKR制定
	*	继续讲人员限定在基础架构组＋PTL范围内，力图通过Q2完成人员培训工作
	{% asset_img okr_timeline.png "OKR的时间轴" %}

+	双周回顾的经验
	技术团队目前还无法形成单周回顾，效率过于频繁可能导致精力分散，而且实践执行中发现难以完成。主要还是大家没有养成这类工作的习惯。所以目前还是我一个人在推广，测算下来，基础架构组＋公共＋PTL的总人数目前有12个人，接下来Q2可能会有15个人，数量庞大，而且没有一个标准，所以尚无法完成扩展。但是下面的表格值得推广，确实效果很好。
	{% asset_img fortynight_review.png "双周回顾" %}
	

**回顾方法有待改善：**

+	Q1本季度感觉回顾方法有待改善。学习了一下文亮的OKR Checklist，打算应用到接下来的制定和回顾工作中。接下来会专门做一个表来进行工作。

_OKR检查表_

1.	Key Result 是否能够实现Objective，套用句型：通过实现XXX（某一条具体的KR），就能促进XXX（某一条具体的O）的实现。
2.	Objective 和 Key Result 描述的是达到什么，而非做了什么
3.	检查是否满足基本明确定义和可度量的要求
4.	检查是否完整反映了个人的主要工作
5.	提醒合作方、同事来给出反馈
6.	检查是否和团队的目标一致
7.	检查是否和个人能力一致 (过易和过难都不好)
8.	检查是否足够专注、优先级是否清楚

**还没有完成的话题：**

*	OKR如何打分，如何数据结果导向