题目链接：<https://crackmes.one/crackme/6666e2d9e7b35c09bb266af2>

解题时间：20240709 1:04

打开题目，是一个简单的GUI

![alt text](21014e2eeb19709be0d1df44297e19be.png)

这种直接IDA查找字符串

![alt text](19ad4dfa925f89228caca7fb38faca3c.png)

点进去，找一下判断逻辑

![alt text](98e5cfa6a4dc6bde2c334c56ff1ed1e5.png)

用xdbg追一下

![alt text](f046999bda44798bf06d6127f5c25c08.png)

可以看到代码未加密，easy

![alt text](9ea705289b182016912b314f8a491344.png)

但是每次密码都会改变！！！！

我们看看其密码是什么，追一下

![alt text](9b5321be7cee0e68cd1cef60decc8033.png)

如下，这个函数，很容易追出来

![alt text](a886703adcb194642390e40b48a74416.png)

其算法逻辑如下

![alt text](55141a2e4d53bd4a476ac7d680a89ce6.png)