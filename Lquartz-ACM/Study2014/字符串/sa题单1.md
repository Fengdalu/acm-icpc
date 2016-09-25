

 
		poj 2758 (不会玩儿... 等等在做) 
		poj 2406 (后缀数组做不了.....)
		poj 3080  (老办法, 暂时不刷)
		HDU 4436
		ural 1517  
		spoj 220  
		spoj 694  
		spoj 705  
		spoj 687  
		uva 11475  
		HDU 4426

 
-----------------------------------------
		
		poj 1226  (谁说的sa!!!暴枚可以过....不过sa可以很快O(nlogn),n为所有字符串总长度...
		poj 2774 (求两个串的最长公共子串, 裸的sa, 注意调用da函数的长度要n+1 !!!!!) 
		poj 3261  (二分答案, 从2~nfor语句判断连续>=k的有几个 110ms 太挫;
		改了用st记录height的区间最小值, 二分答案, for判断47ms, 可以接受)
		poj 3450  (二分答案, 暴力验证, 无法使用rmq, 因为内存不够, 172ms, 可以接受, 算是常规题, 应该hash可做)
		ural 1297  (求最长回文子串, 反串拼接, 不多说, 注意输出最靠前的而不字典序最小的, 还有不只有大小写字母, 还有答案长度为1时输出第一个字符, 初始化答案要注意!!!)



-----------------------------------------
		 
		poj 1743 (首先读懂题意, 然后后缀数组, 最后二分答案加check)

		poj 3294  (二分答案, 最后求解, 不过注意插入的分隔符的处理和长度的处理... 一定是我写搓了, 以后重写一下..)

		poj 3581  (2500+ms过的, 太挫了, 下次用杨博士的方法试试)

		poj 3623  (kyb秒出思路...贪心用sa做, 长知识了.....)

		poj 3693  (看的09年NOI论文过的, 还是不够透... 还有就是500ms太挫了)

		poj 3415  (利用height数组统计, 统计哭了都..., 不过利用height单调递增的单调栈还是解决了问题, 同时统计每个高度的后缀的个数, 和与k相减的sum和, 要好好复习一下

------------------------------------------

		//poj 3415
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
		#define PF push_front
		#define PPB pop_back
		#define PPF pop_front
		#define MP make_pair
		#define AA first
		#define BB second
		#define SZ size()
		#define BG begin()
		#define OP begin()
		#define ED end()
		#define SORT(x) sort(x.begin(), x.end())
		#define SQ(x) ((x)*(x))
		#define cmax(x, y) x = max(x, y)
		#define cmin(x, y) x = min(x, y)
		 
		const double eps = 1e-8;
		const LL MOD = 1000000007;
		const LL INF = 0x3f3f3f3f;
		#define Maxn 1111
		#define Maxm 111111
		int num[Maxn], n, k;
		int sa[Maxn], rank[Maxn], height[Maxn];
		int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];
		int mp[Maxm];
		int st[Maxn][16];
		int cmp(int * r, int a, int b, int x) {
		    return r[a] == r[b] && r[a + x] == r[b + x];
		}
		
		void da(int * r, int n, int m){
		    int i, j, k, p, * x = wa, * y = wb, * t;
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
		char str[Maxn];
		
		int main() {
		    int i, j, u, v, w;
		    //freopen("", "r", stdin);
		    //freopen("", "w", stdout);
		    while(scanf("%d", &k) != EOF && k) {
		        n = 0;
		        scanf("%s", str);
		        for(i = 0; str[i]; i++) num[i] = str[i];
		        n = w = i;
		        num[n++] = '$';
		        scanf("%s", str);
		        for(i = 0; str[i]; i++) num[i + n] = str[i];
		        n += i;
		        num[n] = 0;
		        da(num, n + 1, 300);
		        for(i = 0; i <= n; i++) {
		            cout << i << ":";
		            for(j = sa[i]; j <= n; j++) cout << (char)num[j]; cout << endl;
		        }
		        LL ans = 0, a, b;
		        for(i = 2; i <= n; ) {
		            if(height[i] >= k && (sa[i - 1] != w && sa[i] != w) ) {
		                for(j = i + 1; j <= n && height[j] >= k; j++);
		                for(u = i - 1, a = 0, b = 0; u < j; u++) {
		                    if(sa[u] < w) a++;
		                    else b++;
		                }
		                cout << i - 1 << " " << j - 1 << " " << a << " " << b << endl;
		                ans += a * b;
		                i = j;
		            }
		            else i++;
		        }
		        cout << ans << endl;
		    }
		    return 0;
		}
		


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
		
		const double eps = 1e-8;
		const LL MOD = 1000000007;
		#define Max 210000
		int num[Max];
		int sa[Max], rank[Max], height[Max];
		int wa[Max], wb[Max], wv[Max], wd[Max];
		int cmp(int *r, int a, int b, int l) {
		    return r[a] == r[b] && r[a + l] == r[b + l];
		}
		
		void da(int * r, int n, int m) {
		    int i, j, k = 0, p , *x = wa, *y = wb, *t;
		    for(int i = 0; i < m; i++) wd[i] = 0;
		    for(int i = 0; i < n; i++) wd[x[i] = r[i]]++;
		    for(int i = 1; i < m; i++) wd[i] += wd[i-1];
		    for(int i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
		    for(int j = 1, p = 1; p < n; j *= 2, m = p) {
		        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
		        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		        for(i = 0; i < n; i++) wv[i] = x[y[i]];
		        for(i = 0; i < m; i++) wd[i] = 0;
		        for(i = 0; i < n; i++) wd[wv[i]]++;
		        for(i = 1; i < m; i++) wd[i] += wd[i-1];
		        for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
		        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
		            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		        }
		    }
		    for(i = 0; i < n; i++) rank[sa[i]] = i;
		    for(i = 0; i < n - 1; height[rank[i++]] = k) {
		        for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
		    }
		}
		
		int n, tot;
		map<int, int > dmap;
		int g[Max], f[Max];
		vector<int> ans;
		int main() {
		    int i, j;
		    //freopen("", "r", stdin);
		    //freopen("", "w", stdout);
		    while(scanf("%d", &n) != EOF) {
		        for(i = 0; i < n; i++) {
		            scanf("%d", &g[n - 1 - i]);
		            f[n - i - 1] = g[n - i - 1];
		        }
		        sort(f, f + n);
		        dmap.clear(); tot = 1;
		        for(i = 0; i < n; i++) {
		            if(dmap[f[i]] == 0) dmap[f[i]] = tot++;
		        }
		        for(i = 0; i < n; i++) num[i] = dmap[g[i]];
		        da(num, n + 1, tot);
		        int l1, l2;
		        ans.clear();
		        for(i = 1; i <= n; i++) {
		            if(sa[i] > 1) {
		                l1 = sa[i];
		                for(j = l1; j < n; j++) ans.PB(g[j]);
		            }
		        }
		        for(i = 0, n = l1; i < l1; i++, n++) {
		            num[n] = num[i];
		        }
		        num[n] = 0;
		        da(num, n + 1, tot);
		        for(i = 0; i < n; i++) cout << "~ " << num[i] << " "; cout << endl;
		        for(i = 1; i <= n; i++) {
		            if(n / 2 > sa[i] && sa[i] > 0) {
		                for(j = sa[i]; j < n / 2; j++) ans.PB(g[j]);
		                for(j = 0; j < sa[i]; j++) ans.PB(g[j]);
		                break;
		            }
		            
		        }
		//        printf("%d %d %d\n", a1, a2, a3);
		        for(i = 0; i < ans.SZ; i++) {
		            printf("%d\n", ans[i]);
		        }
		    }
		    return 0;
		}
		
		
		//poj3693
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
		#define PF push_front
		#define PPB pop_back
		#define PPF pop_front
		#define MP make_pair
		#define AA first
		#define BB second
		#define SZ size()
		#define BG begin()
		#define OP begin()
		#define ED end()
		#define SORT(x) sort(x.begin(), x.end())
		#define SQ(x) ((x)*(x))
		#define cmax(x, y) x = max(x, y)
		#define cmin(x, y) x = min(x, y)
		 
		const double eps = 1e-8;
		const LL MOD = 1000000007;
		const LL INF = 0x3f3f3f3f;
		#define Maxn 111111
		#define Maxm 111111
		//O(nlogn)
		//da(num, len + 1, m);
		int len;
		int num[Maxn];  //待处理的串
		int sa[Maxn], rank[Maxn], height[Maxn];    //sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
		int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];
		
		int cmp(int *r, int a, int b, int x) {
		    return r[a] == r[b] && r[a + x] == r[b + x];
		}
		
		void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
		    int i, j, k, p, *x = wa, *y = wb, *t;
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
		int st[Maxn][18];
		void rmq_init() {
		    int i, j;
		    for(i = 0; i <= len; i++) st[i][0] = height[i];
		    for(j = 1; (1<<j) <= len; j++) {
		        for(i = 0; i + (1<<j) - 1 <= len; i++) {
		            st[i][j] = min(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
		        }
		    }
		//    for(j = 0; (1<<j) <= len; j++) {
		//        for(i = 0; i + (1<<j) - 1 <= len; i++) {
		//            cout << st[i][j] << "\t";
		//        }
		//        cout << endl;
		//    }
		}
		
		int rmq(int l, int r) {
		//    if(l == r) return height[l];
		    int k = (int)log2(r - l + 1);
		//    cout << "\t rmq " << l << " " << k << " " << r << endl;
		//    cout << "\t rmq " << st[l][k] << " " << st[r - (1<<k) + 1][k] << endl;
		    return min(st[l][k], st[r - (1<<k) + 1][k]);
		}
		
		char str[Maxn];
		int tt, pl, pr;
		int used[Maxn];
		void check(int pos, int L) {
		    cout << "check " << pos << " " << L <<endl;
		    int i, j, k, p, q, l = pos, r = len, mid;
		    while(l + 1 < r) {
		        mid = (l + r) >> 1;
		        if(rmq(pos, mid) >= L) l = mid;
		        else r = mid - 1;
		    }
		    if(rmq(pos, r) >= L) l = r;
		    if(l - (pos - 1) + 1 < tt) return;
		    for(i = pos - 1; i <= l; i++) used[sa[i]] = pos;
		    for(i = pos - 1; i <= l; i++) {
		        p = sa[i];
		        if(used[p] == pos) {
		            for(j = p + L, k = 1; j < len; j += L, k++) {
		                if(used[j] != pos) break;
		                used[j] = -1;
		            }
		            cout << p << " " << k << " " << j << endl;
		            if(k > tt) {
		                tt = k;
		                pl = p;
		                pr = p + (L * k) - 1;
		            }
		            else if(k == tt && rank[p] < rank[pl]) {
		                pl = p; 
		                pr = p + (L * k) - 1;
		            }
		        }
		    }
		}
		int main() {
		    int i, j, u, v, w, ca = 0;
		    //freopen("", "r", stdin);
		    //freopen("", "w", stdout);
		    while(scanf("%s", str) != EOF) {
		        w = strlen(str);
		        if(w == 1 && str[0] == '#') break;
		        len = w;
		        for(i = 0; i < len; i++) num[i] = str[i] - 'a' + 1;
		        num[len] = 0;
		        da(num, len + 1, 28);
		        for(i = 0; i <= len; i++) {
		            cout << i << ": ";
		            for(j = sa[i]; j <= len; j++) cout << (char)(num[j] - 1 + 'a');
		            cout <<endl;
		        }
		        rmq_init();
		        tt = 0; pl = pr = -1;
		        for(i = 0; i <= len; i++) used[i] = -1;
		        for(i = 2; i <= len; i++) {
		            if(height[i]) {
		                check(i, height[i]);
		            }
		        }
		        ca++;
		        printf("Case %d: ", ca);
		        for(i = pl; i <= pr; i++) putchar(num[i] - 1 + 'a');
		        puts("");
		    }
		    return 0;
		}
		
		/*
		abcabcpabcabd
		
		case 1: abcabc
		
		baccdbaccdbacbdbacbd
		xbcabcab
		edbea
		abcabcabcab
		accdaccaccddcacacaacad
		babbabaabaabaabab
		abaabaabaaba
		ccabababc
		daabbccaa
		bcbcbaba
		pedabacewqpz
		ababaaa
		#
		
		Case 1: accdbaccdb
		Case 2: bcabca
		Case 3: a
		Case 4: abcabcabc
		Case 5: cacaca
		Case 6: abaabaabaaba
		Case 7: abaabaabaaba
		Case 8: ababab
		Case 9: aa
		Case 10: baba
		Case 11: a
		Case 12: aaa
		*/

