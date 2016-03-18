title: 关于HIPAA
date: 2015-12-17 14:09:48
categories:
- Technology
tags:
- security
---
最近因为工作的关系，必须系统的学习一下HIPAA，把学习结果给大家分享一下，如下：

### 第一部分：什么是HIPAA
特别词汇说明（terms）：
Portability：这里特别说明，根据wiki在社会保险（social security）方面的解释，所谓携带型是保存（preserve）、维护（maintain）和交换（transfer）三个词的合意总称，因为很没有中文对应意思，所以特此解释，后面还是翻译成可携带［1］。

HIPAA，全称Health Insurance Portability and Accountability Act. 是美国关于健康保险的携带和责任的法案。HIPAA的提出，旨在改革健康医疗产业，降低费用，简化管理过程和负担，增强隐私保护和个人信息安全保护。可以说，HIPAA是美国健康卫生领域的基础大法，也是整个相关后续政策的基石。自从1996年HIPAA被正式提出以后，法案经历了5次比较大的更新，分别对医疗卫生领域在保险和医疗管理方面的工作，进行了一系列逐渐细致化和现代化的制约。

{% asset_img evolution1996.jpg "1996年第一次正式形成法案" %}
{% asset_img evolution1997.jpg "1997年引入保险改革" %}
{% asset_img evolution2009.jpg "2009年引入ARRA／HITECH法案" %}
在美国2009年更新了HIPAA，引入了美国复苏与再投资法案ARRA（American Recovery and Reinvestment Act），第一次开始引入HITECH（全称Health Information Technology for Economic and Clinic Health Act）。该法案旨在拓展对EHR（Electronic Health Records） 的使用，并开始对ePHI进行了大量升级，详细解释了HIPAA对隐私和安全的保护，同时增加了更多强制实施的内容和相对应的不符合情况下的惩罚措施。该法案与2010年2月强制生效。

{% asset_img evolution2013.jpg "2013年由美国卫生与公共关系部下发Omnibus政策" %}
之后，在2013年1月，由美国卫生与公共服务部（Department of Health and Human）最终发布了Omnibus Rule，将过去的HITECH和GINA（Generic Information Nondiscrimination Act of 2008）进行了融合，并增加了更多详细的指导细节。虽然作为行政命令，Omnibus Rule并不是法案，但是它更加细则。政令与2013年9月正式施行。所有non-compilance将会收到非常严重的惩罚。

HIPAA会影响到两类组群
A. 健康覆盖实体－医疗健康提供者（如医生、护士）、医疗健康规划者（如保险公司、雇主、政府）、医疗健康数据清洗者
B. 医疗健康业务工作组织－所有为覆盖实体提供服务的第三方合作伙伴（如律师、会计、医疗公司、咨询师等）

### 第二部分，关于的组成

下图描述了HIPAA的主要结果组成。

{% asset_img hippa.jpg "HIPAA的结构" %}

HIPAA与所有涉及健康相关的医疗、保险和个人都有直接关系。法案主要分为五个主题，合并为两大部分组成，分别是简化管理（administrative simplification）［2］和保险改革（insurance reform），这两个部分也分别对应了HIPAA的两个关键要求，前者是责任（Accountability），后者对应可携带（Portability）。通常意义上大家所说的HIPAA，都是指的管理责任这部分。如图所示主要包括三个组成子模块儿：
1）事务、代码集和身份识别
*	关于事务，2002年启用的HIPAA关于事务（Transaction）的规定要求，完整的事物要求包含以下内容：
提交和收费处信息
是否任何参与“Health Plan”计划
准入性、覆盖范围、救济金等
需要给健康计划提供者的付费内容
健康保险计划之外的附加费用
状态请求和相应
相关证书以及认证

*	关于代码集（Code Sets）部分，正如HIPAA的初衷，规定代码集大大方便了系统的交互。标准的代码，帮助系统设计之间进行有效的沟通。该部分包含5大集合，主要是为了描述疾病（desease），创伤（injury），症状（Symptoms）和操作行为（Actions）分别是：
ICD-9-CM 国际疾病分类（International Classification of Disease）
CPT （Physician Current Procedural Terminology）
HCPCS HCFA操作代码系统（HCFA Procedural Coding System）包括设备、诊断、治疗、管理疾病等
CDT 现代牙医术语（Current Dental Terminology）
NDC 国家药品代码（National Drug Codes）

*	关于独立标示（Unique Identifiers）用来表明患者、供应商、赔款人和雇主
ProviderID：给所有健康服务供应商的10位数字ID号码
EmployerID：所有为健康医疗提供资金的雇主，由9位数字表示（EIN）
PayerID：所有为健康医疗服务付钱的组织，由9位数字表示（EIN）
PatientID：所有接受服务的患者，目前尚在国会（congress）讨论中，主要是Social Security Number已经存在，是不是还需要一个独立的ID存在争议。

2）隐私－任何形式下的健康信息保护（PHI）
美国卫生及公共服务部（Department of Health and Human Services）［4］在2000年颁布，2002年修改了个人医疗信息隐私政策，明确了医疗实体禁止使用和披露个人受保护健康信息（Protected Health Information）。要求受保护的内容包括电子病历，纸质病历和口头沟通。同时HIPAA作为联邦政府法案，是各州遵循但不限于的基础。各州有权利要求医疗供应商等遵循更加严格的州法案。

PHI包含所有个人可辨识健康信息，包含任何形式过去、现在和可能未来的健康情况。（纸质电子病历、医疗交费记录，包括抄写副本）, 其中有一个非常重要的部分叫做个人可辨识信息（Individually Identifiable Information）
－姓名（Name）
－住址（Address）
－电子邮件（E-mail）
－日期（Dates）
－账户号（Account Number）
－证书号（Certification Number）
－驾照（License Number）
－车证（Vehicle Number）
－社会保险号（Social Security Number）
－病历号（Medical Record Number）
－健康医疗保险号（Health Plan Beneficiary Number）
－面部信息（Facial Photograph）
－电话号码（Telephone Number）
－网络地址（URLs）
－网络IP地址（IP Address）
－生物身份识别（Biometric Identification）
－其他独立识别码

了解了这个部分，我们就可以明白为什么HIPAA的一个非常有意思的规定，PHI的使用和暴露可以在两种情况下被使用。
*	被授权情况 
*	祛标示信息情况

也就是说在祛标示信息（De-identity）后，其实所有的数据就可以被Freely的使用不收到太多限制。

3）安全－电子信息形式下的健康信息保护（ePHI）
{% asset_img security.jpg "安全" %}
虽然安全被分成了三个级别，但是作为一个技术同学，我还是重点看了看技术安全的五个方面：
+	访问控制 （ACCESS Control）
+	审计控制（Audit Controls（R））
+	数据完整性（Integrity）
+	认证（Person and Entity Authentication）
+	传输安全（Transmission Security）

隐私和安全的区别：
隐私关注个人受保护健康信息（PHI）的控制和使用权力。任何形式的该信息不得在未经授权的情况下进行暴露。
安全特指电子受保护健康信息（ePHI）的防护标准。防止该信息在未经授权情况下被暴露、破坏或丢失
隐私信息部分依赖于安全来确保被保护。

参考文献：
［1］Portability (social security) https://en.wikipedia.org/wiki/Portability_(social_security)
［2］HIPPA http://baike.baidu.com/link?url=FeWuYF_ezrLt1Cg1v94jfq6zb2GfplUzM4FtURhfhMRYmKn3Hmu8erdzR9m7SG0iD9jDZcTM0ARPDOQxY-1QPK
［3］Pre Existing Conditions - Understanding Exclusions and Creditable Coverage  http://healthinsurance.about.com/od/healthinsurancebasics/a/preexisting_conditions_overview.html
［4］美国卫生及公共服务部 https://zh.wikipedia.org/wiki/%E7%BE%8E%E5%9B%BD%E5%8D%AB%E7%94%9F%E5%8F%8A%E5%85%AC%E5%85%B1%E6%9C%8D%E5%8A%A1%E9%83%A8
