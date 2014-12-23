title: python_misc
date: 2014-12-22 18:29:22
categories:
- Diary
tags:
- tech
- python
---
研究python，发现最大的问题就是中英文的转换，实在是太郁闷了，研究了好久。最主要的还是出在python的encode和decode上面
http://www.jb51.net/article/17560.htm
这篇文章不错，基本上把需要的内容都解释的很清楚了。

在别人代码的基础上做了些修改，现在已经基本可以用了。

这个是该出来的加入的内容
python ./jira -s http://bug.xingshulin.com -u ＊＊＊＊ -p ＊＊＊＊ cat JCTP-9
python ./jira -s http://bug.xingshulin.com -u ＊＊＊＊ -p ＊＊＊＊ comment JCTP-9 "let do something fantastic"
python ./jira -s http://bug.xingshulin.com -u ＊＊＊＊ -p ＊＊＊＊ create -s "this is summary2" -d "nothing special" -p JCTP -t "运维事故" -a "wangzhe" -f "customfield_10200:20/12/14"

有个挺tricky的地方是要把jira里面的时间传输格式进行调整，默认的是d/MMM/yy，但是因为python对中文的支持问题，所以需要被调整成dd/mm/yy


{'priority': 3, 'description': None, 'customFieldValues': [[{'values': [['2014-12-23']], 'customfieldId': 'customfield_10200'}]], 'summary': 'Test issue using all available defaults', 'project': 'JCTP', 'assignee': 'wangzhe', 'type': 7}
{'priority': 3, 'description': None, 'customFieldValues': [[{'values': [['2014-12-22']], 'customfieldId': 'customfield_10200'}]], 'summary': 'this is summary', 'project': 'JCTP', 'assignee': 'wangzhe', 'type': 6}