题目链接：<https://buuoj.cn/challenges#[ACTF%E6%96%B0%E7%94%9F%E8%B5%9B2020]easyre>

解题时间：20240703-14:23

打开程序，发现是一个upx壳

![alt text](b8fbcdb6965d11a484dae1a793468e1b.png)

来直接开始脱壳，脱壳后的F5代码如下

![](408a28b7ae6d8ec710228a627787edf8.png)

注意，F5的代码很具有迷惑性，注意看这里，很明显是一个很长的字符串，包含v7 v8 v9 v10

![alt text](42ff1601b28657443c1264db3bf1bbd6.png)

再看变量v5，其明显是一个字符串数组，看到`*((char*)v5 + i))`的形式，即`v5[i]`

![alt text](e058e743e79ef876997c7ed7f5a38f10.png)

则`_data_start__`明显是一个字典

![alt text](5c0b975b70ce1b50dffe826d01496b9f.png)

IDA字符转换有一个坑，27h这里是`'`，其IDA不能识别，怕与旁边的`'`混淆。

算法很明显了，从__data_start__中遍历中间输入的数据，然后与v4的进行比较

![alt text](4d1b864f7723154b4c1f844d0456c4e0.png)

接下来编写算法，为了不让思路混乱，我们按照其原来的算法来编写自己的算法

```c
#include <Windows.h>
#include <iostream>

int main() {

	char __data_start__[] = "~}|{zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$# !\"";
	char v4[] = "*F'\"N,\"(I?+@";

	printf("%c", 0x27);

	//std::cout << strlen(__data_start__);

	for (int i = 0; i < 12; i++) {
		char ch = v4[i];
		for (int j = 0; j < strlen(__data_start__); j++) {
			if (ch == __data_start__[j]) {
				printf("%c", j + 1);
				break;
			}
		}
	}

	return 0;
}
```

这里还有一个坑，IDA粘贴过来的字符数据要进行修正，不要硬往上搬！

最后很容易解得 `flag{'U9X_1S_W6@T?}`

解题心得：
1. IDA中粘贴的字符串一定要粘贴准确；
2. 识别F5代码，其变量特征一定要清楚，不要搞混了。