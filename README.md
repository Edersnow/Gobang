# **Gobang**

## **更新**

+ 8/25
    + **之前的前端部分代码有个巨大的问题……异步没处理好23333（前端菜鸡石锤**
    + 思考怎么实现算杀ing……

---

## **目前已实现**：
+ Minimax Search
+ Alpha-beta pruning
+ Iterative DFS
+ Zobrist hashing

已经通过baseline（未加入随机因素，先后手确定后跑的结果都是一样的。。。）

~~一直被评估函数和Generator（启发式搜索）搞得很头疼。。。详细有空再写吧再写吧~~
~~已经被web搞死了~~

## **一些详细的情况**：

这个项目最让我头疼的是评估函数和Generator部分，特别是评估函数。虽然这个项目的大体思路来自[这篇文章](https://github.com/lihongxun945/myblog/issues/11)，但是我对里面提到的评估方法不是很满意。在评估函数方面，以我自己对五子棋的理解，在基础的判断成五、活四等等的value之外，**我认为下面几个因素也应该加以考虑**：

+ 目前棋局的先后手情况
+ 棋盘上的“空间限制”问题 （比如：○+◉◉◉+○）
+ 双三类的问题（Generator也要考虑这方面的问题）

目前我采取的办法是：先将棋盘的每行/每列/每个“对角线”上的棋进行“格式化”，具体来说，例如对于每行，先根据空间限制将棋局分成一个个section（比如前面第二点的例子就会被考虑成“+◉◉◉+”这样一个section），然后再将其处理成“空一格+连子三格+空一格”这样的格式，再加以判断。具体可见Evaluator.hpp内的函数。

这样分解成section的初衷是为了让这个AI能更好地“理解”棋盘上空间限制的问题。**但是这种思路也面临着很大的问题**：

+ 评估的情况太多，过于复杂
+ 难以支持局部更新，运算量巨大

关于第一点，目前项目中实现的6层AI能够打败跑了12层的baseline，个人认为现在函数使用的方法评估的结果还算可以。

关于第二点，本人并没有很好的想法……实际上，目前的AI跑6层基本可以将时间控制在5s内，但是对于更高的层数，AI跑的时间变得相当长（就算加入了Zobrist哈希）。这和评估函数以及Generator应该是有很大关系的。

当然，笔者对五子棋的了解相当有限，有其它想法/见解欢迎告知：）

## **关于前端部分**：
因为对相关语言和web开发极其不熟悉，前端部分的代码写得超级丑……慎读。不过界面看起来还算是可以。。。

html中用到的所有素材(static文件下)全部都是自己通过ps制作的。考虑到项目时间的问题没有做的很复杂细致，而是用一些比较粗线条的简约风格制作……

## **未来希望做的事情**：

**加入算杀模块**。虽然目前6层的AI能够打败baseline，但是笔者尝试8层的时候，发现在先手的情况下被对面干掉了。笔者大致研究了下棋局过程，发现原因应该主要是AI没有算到对面的杀棋（8层），但对面算到了（12层）。笔者目前的想法是维持搜索6层不变，在评估函数部分加入判断，如果棋局上的活二、活三、死四的数量超过一定值，就尝试进行算杀。

**改善评估函数与Generator**。

**改善web框架相关代码**）

~~不过反正已经打败baseline了应该就先鸽了鸽了~~

Reference: [acm_wiki](https://acm.sjtu.edu.cn/wiki/PPCA_2020)