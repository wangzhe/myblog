title: 物体检测
date: 2018-08-12 20:58:16
categories:
- Technology
tags:
- tech
- deeplearning
mathjax: true
---

终于有点时间，可以写继续写notes，这样可以让整个学习过程的印象更加深入。

本节课为CNN的第三周，总的来说就是讲述如何通过pre-train的物体模型，识别整张照片上的物体。和以往前两周的课程一样，围绕着若干篇论文算法展开 Detecting Algorithm

+	Object Localization
+	Landmark Detection, which describe less in the class about how to detect the interal features of an object by key landmarks
+	Object Detection, talking about how to detect an object with bounding box
+	Sliding Window


这里主要重点回顾YOLO（you only look once）。这是本课重点阐述的内容，video有两个，作业也是直接就是讲述YOLO，顺带一点其他算法。

{% asset_img startyolo.png [Encoding architecture for YOLO] %}

-	起点，将原图划分成19x19的区块 （方便简化计算）
-	Input image (608, 608, 3)
-	The input image goes through a CNN, resulting in a (19,19,5,85) dimensional output.
-	After flattening the last two dimensions, the output is a volume of shape (19, 19, 425):
	+	Each cell in a 19x19 grid over the input image gives 425 numbers.
	+	425 = 5 x 85 because each cell contains predictions for 5 boxes, corresponding to 5 anchor boxes, as seen in lecture.
	+	85 = 5 + 80 where 5 is because  (pc,bx,by,bh,bw)(pc,bx,by,bh,bw)  has 5 numbers, and and 80 is the number of classes we'd like to detect
-	You then select only few boxes based on:
	+	Score-thresholding: throw away boxes that have detected a class with a score less than the threshold
	+	Non-max suppression: Compute the Intersection over Union and avoid selecting overlapping boxes
-	This gives you YOLO's final output.


What you should remember:

-	YOLO is a state-of-the-art object detection model that is fast and accurate
-	It runs an input image through a CNN which outputs a 19x19x5x85 dimensional volume.
-	The encoding can be seen as a grid where each of the 19x19 cells contains information about 5 boxes.
-	You filter through all the boxes using non-max suppression. Specifically:
	+	Score thresholding on the probability of detecting a class to keep only accurate (high probability) boxes
	+	Intersection over Union (IoU) thresholding to eliminate overlapping boxes
-	Because training a YOLO model from randomly initialized weights is non-trivial and requires a large dataset as well as lot of computation, we used previously trained model parameters in this exercise. If you wish, you can also try fine-tuning the YOLO model with your own dataset, though this would be a fairly non-trivial exercise.
