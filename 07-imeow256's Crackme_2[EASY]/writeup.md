题目链接：<https://crackmes.one/crackme/663fa0746b8bd8ddfe33c780>

解题时间：20240703-2:07

打开窗口，很明显一个标准的输入窗口！

![alt text](3b3288946d4da0ba629fa26b10f098b1.png)

没啥好说的，拖到IDA里看看！

![alt text](bedd25a62176abec8cc4bbdcd5cf0653.png)

关键函数，比较V8和V7，V8明显是输入进来的，而V7应该就是密码了！

其经过一系列运算，我们直接采用动态调试的办法

![alt text](a813a413f449d71470cd967981cd152a.png)

直接查看其rbp中的数据结构

![alt text](7d2c1ca09bc8b4c517561265683ba457.png)

其明显是两个内存地址，点进去看一下

![alt text](f73b5b185124a21fde5e6478c99191fe.png)

答案呼之欲出了！ abnskvf

![alt text](74598f0346986bed2647b26c7222ecec.png)

解题心得：
1. 栈中的数据有时并不会解析，此时追进内存看一下。
