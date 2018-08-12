title: 对于tensorflow基本用法的一些记录
date: 2018-08-12 20:11:27
categories:
- Technology
tags:
- tech
- deeplearning
mathjax: true
---

最近已经学到了机器学习的第四课CNN的部分。这个部分里面还是用到了一些Tensorflow的基本内容。这里把一些简单的方法做个总结，以做备忘，也许之后用得上。

```Python
 # Use tf.image.non_max_suppression() to get the list of indices corresponding to boxes you keep
    nms_indices = tf.image.non_max_suppression(boxes, scores, max_boxes, iou_threshold)
 ```

对于TF的Run始终觉得需要系统的理解一下
```Python
# Run the session with the correct tensors and choose the correct placeholders in the feed_dict.
    # You'll need to use feed_dict={yolo_model.input: ... , K.learning_phase(): 0})
    out_scores, out_boxes, out_classes = sess.run([scores, boxes, classes],
                                                  feed_dict={yolo_model.input: image_data, K.learning_phase(): 0})
```


这里除了TensorFlow还得多提一个Keras，一个构建在TF上面更加丰富函数的第三方包

```Python
keras.backend.argmax(x, axis=-1)
keras.backend.max(x, axis=None, keepdims=False)
```

