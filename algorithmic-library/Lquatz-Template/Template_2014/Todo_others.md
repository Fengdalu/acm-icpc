####头文件

>	head.cpp

	//#pragma comment(linker,"/STACK:102400000,102400000")
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cstdlib>
	#include <cmath>
	#include <iostream>
	#include <sstream>
	#include <algorithm>
	#include <string>
	#include <vector>
	#include <set>
	#include <map>
	#include <queue>
	#include <stack>
	#include <bitset>
	using namespace std;
	typedef long long LL;
	typedef pair<int, int> PII;
	 
	#define PB push_back
	#define MP make_pair
	#define AA first
	#define BB second
	#define SZ size()
	#define BG begin()
	#define OP begin()
	#define ED end()
	#define SQ(x) ((x)*(x))
	#define cmax(x, y) x = max(x, y)
	#define cmin(x, y) x = min(x, y)
	 
	int main() {
	    int i, j, u, v, w;
	    //freopen("", "r", stdin);
	    //freopen("", "w", stdout);
	    
	    return 0;
	}

####配置信息

>	codeblocks


   		terminal： gnome-terminal -t $TITLE -x    在codeblocks --> setting --> 环境变量

>	eclipse


	Eclipse中默认是输入"."后出现自动提示，用于类成员的自动提示，可是有时候我们希望它能在我们输入类的首字母后就出现自动提示，可以节省大量的输入时间（虽然按alt + /会出现提示，但还是要多按一次按键，太麻烦了）。    从Window -> preferences -> Java -> Editor -> Content assist -> Auto-Activation下，我们可以在"."号后面加入我们需要自动提示的首字幕，比如"ahiz"。    然后我们回到Eclipse的开发环境，输入"a"，提示就出现了。但是我们可以发现，这个Auto-Activation下的输入框里最多只能输入5个字母，也许是Eclipse的开发人员担心我们输入的太多会影响性能，但计算机的性能不用白不用，所以我们要打破这个限制。其实上面都是铺垫，制造一下气氛，以显得我们下面要做的事情很牛似的，其实不然，一切都很简单。嘿嘿 :)   
	在"."后面随便输入几个字符，比如"abij"，然后回到开发环境，File -> export -> general -> preferences -> 选一个地方保存你的首选项，比如C:"a.epf用任何文本编辑器打开a.epf，查找字符串“abij”，找到以后，替换成“abcdefghijklmnopqrstuvwxyz”，总之就是你想怎样就怎样！！然后回到Eclipse，File -> import -> general -> preferences -> 导入刚才的a.epf文件。此时你会发现输入任何字幕都可以得到自动提示了。爽！！！最后：自动提示弹出的时间最好改成100毫秒以下，这样会比较爽一点，不然你都完事了，自动提示才弹出来:)，不过也要看机器性能。
	FileWriter fileWriter=new FileWriter("c:\\Result.txt");
	int [] a=new int[]{11112,222,333,444,555,666};
	for (int i = 0; i < a.length; i++) {
	fileWriter.write(String.valueOf(a[i])+" ");
	}


####调试注意事项

>	内存大小

	全局数组大小
	函数内数组大小
	编译时间是否算入总时间

>	堆栈


	无参递归层次
	能否开栈

>	编译器选项


	-O1 ?
	-O2 ?

>	Java类名要求


	Main ?

>	返回值


	CE
	AC
	WA
	RE
	PE
	TLE
	MLE
	SF

>	ext包


	ext/pb_ds/assoc_container.hpp
	ext/pb_ds/priority_queue.hpp
	ext/rope
	ext/hash_map
	ext/hash_set

####ASCII

	0 NUL(null) 空字符
	1 SOH(start of headline) 标题开始
	2 STX (start of text) 正文开始
	3  ETX(end of text) 正文结束
	4   EOT (end of transmission) 传输结束
	5  ENQ (enquiry) 请求
	6  ACK (acknowledge) 收到通知
	7  BEL (bell) 响铃
	8  BS (backspace) 退格
	9 HT (horizontal tab) 水平制表符
	10 LF (NL line feed, new line) 换行键
	11 VT (vertical tab) 垂直制表符
	12 FF (NP form feed, new page) 换页键
	13 CR (carriage return) 回车键
	14 SO (shift out) 不用切换
	15 SI (shift in) 启用切换
	16 DLE (data link escape) 数据链路转义 
	17 DC1 (device control 1) 设备控制1
	18 DC2 (device control 2) 设备控制2
	19 DC3 (device control 3) 设备控制3
	20 DC4 (device control 4) 设备控制4
	21 NAK (negative acknowledge) 拒绝接收
	22 SYN (synchronous idle) 同步空闲 
	23  ETB (end of trans. block) 传输块结束
	24  CAN (cancel) 取消
	25  EM (end of medium) 介质中断
	26  SUB (substitute) 替补
	27  ESC (escape) 换码(溢出)
	28  FS (file separator) 文件分割符
	29  GS (group separator) 分组符
	30   RS (record separator) 记录分离符
	31 ¬ US (unit separator) 单元分隔符
	32 space 空格
	33 !
	34 "
	35 #
	36 $
	37 %
	38 &
	39 '
	40 (
	41 )
	42 *
	43 +
	44 ,
	45 -
	46 .
	47 /
	48 0
	49 1
	50 2
	51 3
	52 4
	53 5
	54 6
	55 7
	56 8
	57 9
	58 :
	59 ;
	60 <
	61 =
	62 >
	63 ?
	64 @
	65 A
	66 B
	67 C
	68 D
	69 E
	70 F
	71 G
	72 H
	73 I
	74 J
	75 K
	76 L
	77 M
	78 N
	79 O
	80 P
	81 Q
	82 R
	83 S
	84 T
	85 U
	86 V
	87 W
	88 X
	89 Y
	90 Z
	91 [
	92 \
	93 ]
	94 ^
	95 _
	96 `
	97 a
	98 b
	99 c
	100 d
	101 e
	102 f
	103 g
	104 h
	105 i
	106 j
	107 k
	108 l
	109 m
	110 n
	111 o
	112 p
	113 q
	114 r
	115 s
	116 t
	117 u
	118 v
	119 w
	120 x
	121 y
	122 z
	123 {
	124 |
	125 }
	126 ~
	127 DEL（delete 删除）

