题目链接：<https://crackmes.one/crackme/6648f35e6b8bd8ddfe33cc00>

解题时间：20240706 - 23:52

这题一开始没看出来，最后好兄弟动态追一下，知道答案了

打开程序，是个输入程序

![alt text](3d193e086f08ad2b6df872462edefc6e.png)

打开IDA，代码比较长，但通过cin这里，判断第一个为输入sudo

![alt text](ad56a4a6690a06f87e6db7ab38496773.png)

确认一下，果然是输入sudo

![alt text](2d8548b368366275bdb038dbd931e860.png)

下面就是输入密码了

代码太长了，我们直接从字符串入手，找到成功的字符串

![alt text](5a1aade14bebd17681656ed6011927c4.png)

直接看其跳转逻辑

![alt text](d0fdb573aaf30c0d36b5e3440fbaef60.png)

跳转判断如下

![alt text](cbe4081b6b6b138929f81f642574b3cb.png)

直接用x32dbg追下去查看

![alt text](e5f62ef032065cf5d8c582fa90ff2acf.png)

密码就是 5755574853

验证一下，验证成功

![alt text](723a43c4263855aa5e2b8c9375cd83c1.png)

这题很简单，密码都是明文，但当时做的时候太粗心，没有足够的耐心！
