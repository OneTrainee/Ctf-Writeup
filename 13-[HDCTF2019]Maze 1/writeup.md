题目链接：<https://buuoj.cn/challenges#[HDCTF2019]Maze>

解题时间：20240705 - 20:52

打开题目，常规的输入题

![alt text](02e3a6dc2a4de6ac114462eccd0fdcb1.png)

打开ida，发现是upx壳

![alt text](8ac38d966216fb42c0226b86b2f8deed.png)

直接用upx工具脱壳

![alt text](baaf6f3fd0e54161a093c1564863e2ff.png)

然后用ida打开

![alt text](c1396791167ba77a95d74404225709b1.png)

什么鬼东西，肯定存在花指令

拖入x32dbg中运行，运行到花指令附近

![alt text](bfb08fc26bb194549aa6745b0b094882.png)

对比上面 2E，这个偏移有一个花指令

调整之后的花指令如下图所示

![alt text](2f8eaa00053339f535cb857af4849607.png)

这里有一个小技巧，调整完花指令之后，没法按F5生成

先把补丁打上去，NOP，然后重新打开，再按F5就出来了

。。。。当时不会用这个技巧，直接逆出了算法 

```c
#include <iostream>

int main(){
    
    int asc_408078 = 7;
    int dword_40807C = 0;
    char Str[] = "123456";

    // 0 - 0
    // 1 - 3
    // 2 - 18
    // 3 - 22 * 不能到达
    char byte_401112[] = {0,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,4,4,4,3}; // 23
    for(int i = 0 ; i <= 1;i++){
        int x = Str[i] - 'a';
        if(x > 22){
            continue;
        }

        switch(byte_401112[x]){
            case 0: //loc_401096
            asc_408078 -= 1;    // a 
            break;
            case 1: //loc_4010A5
            asc_408078 += 1;    // d
            break;
            case 2: // loc_401085
            dword_40807C -= 1; // s 
            break;
            case 3: // loc_401074 // w
            dword_40807C =+ 1;
            break;
        }
    }

    if(asc_408078 == 5 && dword_40807C == -4){
        // congruation
    }


}

// ssaaasaassdddw
```

对比一下，其实比较的挺准的

![alt text](27466ed0a481fbf978c50ab00c19d9ce.png)

这明显是一道迷宫题，一个x，一个y值，来走迷宫

迷宫在哪里呢？？？ 没找到啊！！！

好吧，看Writeup吧，真拿这题没辙了。。

好吧，藏在字符串里

![alt text](d5a4ec4bab0a6d33d777cee7501373c2.png)

直接一个 7*10 长度的字符串

![alt text](2f672ea2aa78f7c1ca1c122b14f8ce40.png)

直接 ssaaasaassdddw，走完

flag值就是 flag{ssaaasaassdddw}

其实感觉这道题还有别的解法，这个迷宫太突兀了！！！

解题心得：
1. 了解patch的方法，打完patch，重新打开就可以F5了！