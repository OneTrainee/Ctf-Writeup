题目链接：<https://crackmes.one/crackme/6182052d33c5d4329c345484>

解题时间：20240703-22:47

打开文件，一个标准的Crackme

![alt text](a6d534f2ebea780fc63a97b5b0725fbb.png)

然后用IDA打开

![alt text](d20fd18f79d2fc0b20b1e8cd11c25c2f.png)

标准的字符串拼接函数，查看checkUsername

![alt text](b31a430ccff66c14d51978069846ddcc.png)

明显两种，1-7，返回0， 大于7 ，返回1

现在回来继续看下面的代码

![alt text](a0e8004fd40582dcc2c31b1a874899e1.png)

算法很明显了，不过多介绍了

第一种解法：

![alt text](3d615f6ff654d6f431ac7bad15952b9c.png)

第二种解法：

![alt text](33319a875aac4b26d3c544c1ce7c1851.png)

这题比较水，又划了一套题！！