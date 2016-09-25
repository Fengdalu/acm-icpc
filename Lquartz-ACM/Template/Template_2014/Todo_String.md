周五解决:

* 	1 ~ 6 & 9的模板(后缀数组要O(n)?)
* 	7 ~ 8准备板子, 用途 & 常见题型
* 

---------------------------------------------------------
##  String Template

### **Contents** 

1.  *Hash*    
2.  *KMP*  
3.  *拓展KMP*   
4.  *Manacher*  
5.  *AC自动机*  
6.  **后缀数组**  
7.  **后缀树**
8.	**后缀自动机**
9.	*字符串最小表示法* 
10. **Other**

----------------------------------------------------------

####    01. **Hash**  

*	一般字符串Hash  
	
		LL strhash (char *str) {
		    int i;
		    LL c, ret = 0;
		    for(i= 0, ret = 0; str[i]; i++) {
		        c = str[i] - 'a';
		        ret = ((ret << 5) + ret) ^ c;
		    }
		    return ret;
		}
		17,37, 79, 163, 331, 
		673,1361,2729,5471,10949,       
		21911,43853, 87719, 175447, 350899,
		701819,1403641,2807303,5614657, 11229331,  
		22458671, 44917381, 89834777, 179669557, 359339171, 
		718678369, 1437356741, 2147483647

####    02. **KMP**  

*	函数版

		char S[Maxn], T[Maxn];
		int next[Maxn], is[Maxn];
		void getnext(char T[], int LT, int next[]) {
		    int i, j;
		    next[0]=-1; next[1] = 0;
		    for (i = 1, j = 0; i < LT; ) {
		        while (j != -1 && T[i] != T[j]) j = next[j];
		        i++; j++;
		        next[i] = j;
		    }
		}
		void KMP (char S[], int LS, char T[], int LT, int next[]) {
		    int i, j;
		    for(i = 0; i < LS; i++) is[i] = 0;
		    for (i = 0, j = 0; i < LS; i++) {
		        while (j != -1 && S[i] != T[j]) j = next[j];
		        j++;
		        if (j == LT) {
		            is[i - LT + 1] = 1;
		            j = next[j];
		        }
		    }
		}

*	KMP类

		struct KMP {//调用init(s(待匹配串),t(模式串));适用多次KMP
		    char S[Maxn], T[Maxn];
		    int next[Maxn], is[Maxn];
		    int LT, LS;
		    void init(char s[], char t[]) {
		        int i;
		        LT = strlen(t);
		        LS = strlen(s);
		        for(i = 0; i <= LT; i++) T[i] = t[i];
		        for(i = 0; i <= LS; i++) S[i] = s[i];
		    }
		    void getnext() {
		        int i, j;
		        next[0]=-1; next[1] = 0;
		        for (i = 1, j = 0; i < LT; ) {
		            while (j != -1 && T[i] != T[j]) j = next[j];
		            i++; j++;
		            next[i] = j;
		        }
		    }
		    void kmp() {
		        int i, j;
		        for(i = 0; i < LS; i++) is[i] = 0;
		        for (i = 0, j = 0; i < LS; i++) {
		            while (j != -1 && S[i] != T[j]) j = next[j];
		            j++;
		            if (j == LT) {
		                is[i - LT + 1] = 1;
		                j = next[j];
		            }
		        }
		    }
		}kmp;

####    03. **拓展KMP**  

*	函数版

		char S[Maxn], T[Maxn];
		int next[Maxn], B[Maxn];
		void preExKmp(char T[], int LT, int next[]) {
		    int i, ind = 0, k = 1;
		    next[0] = LT;
		    while(ind + 1 < LT && T[ind + 1] == T[ind]) ind++;
		    next[1] = ind;
		    for(i = 2; i < LT; i++) {
		        if(i <= k + next[k] - 1 && next[i - k] + i < k + next[k])
		            next[i] = next[i - k];
		        else {
		            ind = max(0, k + next[k] - i);
		            while(ind + i < LT && T[ind + i] == T[ind]) ind++;
		            next[i] = ind; k = i;
		        }
		    }
		}
		
		void exKmp(char S[], int LS, char T[], int LT, int next[], int B[]) {
		    int i, ind = 0, k = 0;
		    preExKmp(T, LT, next);
		    while(ind < LS && ind < LT && T[ind] == S[ind]) ind++;
		    B[0] = ind;
		    for(i = 1; i < LS; i++) {
		        int p = k + B[k] - 1, L = next[i - k];
		        if((i - 1) + L < p)
		            B[i] = L;
		        else {
		            ind = max(0, p - i + 1);
		            while(ind + i < LS && ind < LT && S[ind + i] == T[ind]) ind++;
		            B[i] = ind;
		            k = i;
		        }
		    }
		}

*	exKmp类

####    04. **Manacher**  

*	Manacher纯模板

		//HDU_3068
		//s为原串, str为插入$和#的串
		//读入s后, 调用init(s, str, len),
		//最后调用Manacher(str,p,len)
		//求解遍历p数组求最大值, 注意输出ans-1
		//最长回文子串对应原串T中的位置：l = (i - p[i])/2; r = (i + p[i])/2 - 2;
		int len, p[Maxn];
		char s[Maxn], str[Maxn];
		void init(char s[], char str[], int& len) {
		    int i, j, k;
		    str[0] = '$';
		    str[1] = '#';
		    for (i = 0; i < len; i++) {
		        str[i * 2 + 2] = s[i];
		        str[i * 2 + 3] = '#';
		    }
		    len = len * 2 + 2;
		    s[len] = 0;
		}
		void Manacher (char str[], int p[], int len) {
		    int i;
		    int mx = 0;
		    int id;
		    for (i = len; i < Maxn; i++)
		        str[i] = 0; //没有这一句有问题。。就过不了ural1297，比如数据：ababa aba
		    for (i = 1; i < len; i++) {
		        if ( mx > i )
		            p[i] = min ( p[2 * id - i], p[id] + id - i );
		        else
		            p[i] = 1;
		        for (; str[i + p[i]] == str[i - p[i]]; p[i]++)
		            ;
		        if ( p[i] + i > mx ) {
		            mx = p[i] + i;
		            id = i;
		        }
		    }
		}
		int main() {
		    int i, ans;
		    while (scanf ("%s", s) != EOF) {
		        len = strlen (s);
		        init(s, str, len);
		        Manacher(str, p, len);
		        ans = 0;
		        for (i = 0; i < len; i++)
		            if (p[i] > ans)
		                ans = p[i];
		        printf ("%d\n", ans - 1);
		    }
		    return 0;
		}

####    05. **AC自动机**  

*	普通匹配

		struct node {
		    struct node * fail;
		    struct node * next[10];
		    bool is;
		    int lab;
		}Tree[Maxn], * root, * que[Maxn];
		int tot, head, tail;
		
		node * newNode() {
		    node * p = &Tree[tot++];
		    p->is = false;
		    p->lab = 0;
		    p->fail = NULL;
		    for(int i = 0; i < 10; i++) p->next[i] = NULL;
		    return p;
		}
		void Insert(char str[], int n) {
		    node * p = root;
		    for(int i = 0, k; str[i]; i++) {
		        k = str[i] - '0';
		        if(p->next[k] == NULL) {
		            p->next[k] = newNode();
		        }
		        p = p->next[k];
		    }
		    p->is = true;
		    p->lab = n;
		}
		
		void buildAC() {
		    head = tail = 0;
		    int i;
		    node * p, * q;
		    root->fail = root;
		    que[tail++] = root;
		    while(head < tail) {
		        p = que[head++]; q = p->fail;
		        for(i = 0; i < 10; i++) {
		            if(p->next[i] != NULL) {
		                if(p == root) p->next[i]->fail = root;
		                else {
		                    p->next[i]->fail = q->next[i];
		                    p->next[i]->is |= q->next[i]->is;
		                }
		                que[tail++] = p->next[i];
		            }
		            else {
		                if(p == root) p->next[i] = root;
		                else p->next[i] = q->next[i];
		            }
		        }
		    }
		}
		
		void query(char str[]) {
		    node * p , * q;
		    p = root;
		    for(int i = 0, k; str[i]; i++) {
		        k = str[i]-'0';
		        p = p->next[k];
		        if(p->is) {
		            q = p;
		            while(q->is) {
		                cnt[q->lab]++;
		                q = q->fail;
		            }
		        }
		    }
		}

*	AC自动机+DP


####    06. **后缀数组**  

*	模板(O(nlogn))
	
	论文模板, 使用时注意num[]有效位为0~n-1, 但是需要将num[n]=0, 否则RE;另外, 对于模板的处理将空串也处理了, 作为rank最小的串, 因此有效串为0~n共, n-1个, 在调用da()函数时, 需要调用da(num, n + 1, m); 对于sa[], rank[]和height[]数组都将空串考虑在内, 作为rank最小的后缀!
		
		//O(nlogn)
		//调用da(num, len+1, m);//m为字符个数略大
		int len;
		int num[Maxn];  //待处理的串
		int sa[Maxn], rank[Maxn], height[Maxn];    //sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
		int wv[Maxn], wd[Maxn];
		
		int cmp(int *r, int a, int b, int x) {
			return r[a] == r[b] && r[a + x] == r[b + x];
		}
		
		void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
			int i, j, k, p, *x = rank, *y = height, *t;
			for(i = 0; i < m; i++) wd[i] = 0;
			for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
			for(i = 1; i < m; i++) wd[i] += wd[i - 1];
			for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
			for(j = 1, p = 1; p < n; j <<= 1, m = p) {
		        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
		        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		        for(i = 0; i < n; i++) wv[i] = x[y[i]];
		        for(i = 0; i < m; i++) wd[i] = 0;
		        for(i = 0; i < n; i++) wd[wv[i]]++;
		        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
		        for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
		        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
		            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
				}
			}
		
		    for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
		    for(i = 0; i < n - 1; height[rank[i++]] = k) {
		        for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
		    }
		}

*	DC3(O(n))



####    07. **字符串最小表示法**  

*	朴素最小表示法
	
	ZOJ2006 ZOJ1729
	HDU 3374

		//
		int MinRep (char S[], int L) {
		    int i = 0, j = 1, k = 0, t;
		    while (i < L && j < L && k < L) { //找不到比它还小的 或者 完全匹配
		        t = S[ (i + k) % L] - S[ (j + k) % L];
		//        t = s[(i + k) >= L ? i + k - L : i + k] 
		//            - s[(j + k) >= L ? j + k - L : j + k];
		        if (t == 0)
		            k++;//相等的话,检测长度加1
		        else {
		            //大于的话,s[i]为首的肯定不是最小表示,最大表示就改<
		            if (t > 0) i += k + 1;
		            else j += k + 1;
		            if (i == j) j++;
		            k = 0;
		        }
		    }
		    return min (i, j);
		}

*	判定两串是否循环同构

####    08. **后缀树**  




####    09. **后缀自动机**  




####    10. **Other**  




####    11. **待解决的问题**  

* 	整数Hash需要?
*	KMP下标需要平移至1为起点吗?
* 	exkmp模板有点虚....
* 	manacher找找需要改板子的题目
* 	AC自动机模板?刷dp还不够啊!!!
*	后缀数组O(n)模板带不?
* 	字符串最小表示法 ZOJ2006 ZOJ1729 HDU3374
* 	后缀树, 后缀自动机**板子**, **用途**, 常见题型

