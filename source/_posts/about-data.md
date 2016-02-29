title: 最近一次错误讨论方法的反思
date: 2015-12-17 14:09:48
categories:
- Management
tags:
- mgnt
---
本周三XTA讨论，发生了一件事情，让我不禁感慨有些东西说起来容易，真做起来却没那么简单，或者说比较容易被忽视。事情的大体经过是这样的：

XTA每周三例行周会上，我们聊到了一个话题，是否将部分诊疗圈repo牵往github上。主要原因表述为，目前武鹏和文迪在诊疗圈推行一种更先进的部署方法，部署可以直接从repo里已用写在其他repo上的依赖modules（如果我理解没错的话）。目前青云环境到公司内网环境之间的数据并没有打通，所以导致在内网使用的gitlab，无法被青云访问到。所以得到了将部分repo牵往github上的一个方案，交由XTA共同讨论。

在会上，大家为了是否迁移这件事情讨论了许多。包括是否采取架设青云到内网的访问管道，迁移github带来的权限管理成本，整体gitlab到github迁移的可行性等等。事后，虽然大家名义上达成了一致，认为可以在青云上搭设一套gitlab环境，交由ldap进行统一权限管理。但回过头来想想这个决策的讨论过程，总觉得不太对。

*	讨论的基础
	这里就不得不回到一直以来给团队设定的基线是：
	1.	科学的做事儿
	2.	使用数据和并努力作出合理优化

	之所以定义了这两条基线是源于读那本著名的《How Google Works》，我认为这本书对我的影响是相当深刻的。其中，关于文化一章有这样一个说法
	
	>“Establish a culture of Yes
    >
	>We are both parents, so we understand through years of firsthand experience the dispiriting parental habit of the reflexive no. “Can I have a soda?” No. “Can I get two scoops of ice cream instead of one?” No. “Can I play video games even though my homework isn’t done?” No. “Can I put the cat in the dryer?” NO!
	>
	>The “Just Say No” syndrome can creep into the workplace too. Companies come up with elaborate, often passive-aggressive ways to say no: processes to follow, approvals to get, meetings to attend. No is like a tiny death to smart creatives. No is a signal that the company has lost its start-up verve, that it’s too corporate. Enough no’s, and smart creatives stop asking and start heading to the exits.”
    >
	>Excerpt From: Eric Schmidt. “How Google Works.” iBooks.
	
	对于一个公司而言，树立Say Yes的文化是很重要的。那么如何树立这种文化，书里也给了比较明确的解答，那就是书里基线，一个大家都认同，并愿意为之遵守的基础。同样是参考这本书里，关于
	
	>“Decide with data
    >
	>One of the most transformative developments of the Internet Century is the ability to quantify almost any aspect of business. Decisions once based on subjective opinion and anecdotal evidence now rely primarily on data. Companies like ours aggregate anonymous signals from mobile phones to provide accurate traffic data in real time. London’s water pipes are monitored by thousands of sensors, reducing leakage by 25 percent.119 Ranchers embed sensors into their cattle that transmit information about the animals’ health and location; each cow transmits about 200 megabytes of data per year,120 allowing ranchers to fine-tune what, when, and how much they feed their cattle. That’s a cattle list for change!”
    >
	>Excerpt From: Eric Schmidt. “How Google Works.” iBooks.
	
	基于事情和数据的决策，我认为是非常好的一种工作方式。在书里写到Google在任何一个会议室都会有两个投影仪，一个用来交流，另一个用来展示数据。这充分显示了一个公司对数据的重视。问什么呢？曾经听《罗辑思维》讲，关于数据这部分，深感认同，数据是人类进行合作的重要工具，是跨时空合作得以展开的基础。有了数据其实大家都是聪明人，也就明白很多事情的决策是什么原因了。
	{% asset_img data.png "引用自《你怎么还相信中医》" %}
	

所以，说回本次周三XTA的讨论。其实我们是没有做好讨论准备的。对于这样的一个迁移，一定是选取几套方案，并根据“运维时效”、“工作时效”共同加起来，完成一个比较好的讨论。让讨论的多方理解，为什么要做这个决定，为什么是那个决定。我觉得坚持以事为中心，坚持那数据来做决策是对的，应该在任何情况下必须坚持的。接下来应该更进一步讲数据细化，2016，我一定要让运维有一整套能拿得出来的数据，2016，要让杏树林的人都拿数据来讨论问题，我们的数据平台，也要更加为主的建立起来。把这个形成公司的行为习惯。在这点上，我一定要坚持，不动摇，并且学习更好的实践。

哦，对了，也给自己和所有人说，2016，新年快乐！

