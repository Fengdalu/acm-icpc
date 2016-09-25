
####	01. **并查集**

> 


####    02. **生成树**  

>	Prim  

>	Kruskal  

>	Borůvka算法

>	次小生成树  

>	最小瓶颈生成树

>	直径最短生成树

>	度数最多的点, 度数最少的生成树

>	两点之间路径, 权重总和最小的生成树

>	有两种权重, 权重比值最小的生成树(最优比例生成树)

>	边不重叠, 权重最小的k棵树

>	重叠边增加额外权重, 权重最小的k棵树

>	权重最小的生成子树, 刚好k个点

>	权重最小的生成子树, 刚好是给定的K个点

>   度限制最小生成树  

>   动态最小生成树  

>	有向图最小生成树(最小树形图)

>	任意两点间路径的瓶颈, 形成两点间最小割的无向生成树

>	dfs树

>	bfs树

>	最短路径树

>   斯坦纳树 

>	最优比例生成树

	double prim (double s) {
	    clr (vis , 0);
	    double retdis = 0;
	    int retcost = 0;
	    vis[1] = 1;
	    for (int i = 2 ; i <= n ; i++) {
	        lowcost[i] = abs (v[1].h - v[i].h) - s * dis[1][i];
	        closest[i] = 1;
	    }
	    for (int num = 0 ; num < n - 1 ; num++) {
	        double minans = inf;
	        int u;
	        for (int i = 1 ; i <= n ; i++) {
	            if (vis[i]) continue;
	            if (lowcost[i] < minans) {
	                minans = lowcost[i];
	                u = i;
	            }
	        }
	        vis[u] = 1;
	        retcost += abs (v[closest[u]].h - v[u].h);
	        retdis += dis[closest[u]][u];
	        for (int i = 1 ; i <= n ; i++) {
	            double cal = abs (v[u].h - v[i].h) - s * dis[u][i];
	            if (!vis[i] &&cal < lowcost[i]) {
	                lowcost[i] = cal;
	                closest[i] = u;
	            }
	        }
	    }
	    return 1.0 * retcost / retdis;
	}
	int main() {
	    double ans = 0;
	    while (1) {
	        double tmp = prim (ans);
	        if (fabs (tmp - ans) < eps) {
	            break;
	        }
	        ans = tmp;
	    }
	    printf ("%.3f\n" , ans);
	}


>	度限制最小生成树


	就是图中的某些点在生成树时有度的限制，找满足这些约束的最小生成树。如果所有点都有度限制，那么这个问题将是NP难题），具体算法如下： 1. 先求出最小 m 度限制生成树：原图中去掉和 V0 相连的所有边（可以事先存两个图， Ray 的方法是一个邻接矩阵，一个邻接表，用方便枚举边的邻接表来构造新图），得到 m 个连通分量，则这 m 个连通分量必须通过 v0 来连接，所以，在图 G 的所有生成树中 dT (v0) ≥m 。也就是说，当 k<m 时，问题无解。对每个连通分量求一次最小生成树（哪个算法都行），对于每个连通分量 V’ ，用一条与 V0 直接连接的最小的边把它与 V0 点连接起来，使其整体成为一个生成树。于是，我们就得到了一个 m 度限制生成树，不难证明，这就是最小 m 度限制生成树。 2. 由最小 m 度限制生成树得到最小 m+1 度限制生成树;
	：连接和 V0 相邻的点 v ，则可以知道一定会有一个环出现（因为原来是一个生成树），只要找到这个环上的最大权边（不能与 v0 点直接相连）并删除，就可以得到一个 m+1 度限制生成树，枚举所有和 V0 相邻点 v ，找到替换后，增加权值最小的一次替换 (当然，找不到这样的边时，就说明已经求出) ，就可以求得 m+1 度限制生成树。。如果每添加一条边，都需要对环上的边一一枚举，时间复杂度将比较高（但这个题数据比较小，所以这样也没问题，事实上，直接枚举都能过这个题），这里，用动态规划解决。设 Best (v) 为路径 v0—v 上与 v0 无关联且权值最大的边。定义 father (v) 为 v 的父结点，由此可以得到动态转移方程： Best (v) =max (Best (father (v) ),ω (father (v),v) ) ，边界条件为 Best[v0]=-∞ (因为我们每次寻找的是最大边，所以 -∞ 不会被考虑) ，Best[v’]=-∞| (v0,v’) ∈E (T) 。 3. 当 dT (v0) =k 时停止 (即当 V0 的度为 k 的时候停止) ，但不一定 k 的时候最优。 接下来说一下算法的实现： 采用并查集+ kruskal 代码量还少一点。 首先， 每个连通分量的的最小生成树可以直接用一个循环，循环着 Kruskal 求出。这里利用了联通分量间的独立性，对每个连通分量分别求最小生成树，和放在一起求，毫不影响。而且kruskral算法保证了各连通分量边的有序性。 找最小边的时候，上面讲的动态规划无疑是一种好方法，但是也可以这么做： 先走一个循环，但我们需要逆过来加边，将与v0关联的所有边从小到达排序，然后将各连通分量连接起来，利用并查集可以保证每个连通分量只有一条边与v0相连，由于边已经从小到达排序，故与每个连通分量相连的边就是每个连通分量与v0相连中的最小边。 然后求 m+1 度的最小生成树时，可以直接用 DFS ，最小生成树要一直求到 k 度，然后从中找出一个最优值。 int vis[MAXN];

	int lowcost[MAXN];
	int best[MAXN];
	int pre[MAXN];
	int n , k , ans , cnt;
	int g[MAXN][MAXN];
	int edge[MAXN][MAXN];
	int fa[MAXN];
	int mark[MAXN];
	map <string ,int> m;
	void init() {
	    clr (g , 0x3f);
	    cnt = 1;
	}
	void dfs (int s) {
	    for (int i = 1 ; i <= cnt ; i++) {
	        if (mark[i] && edge[s][i]) {
	            mark[i] = 0;
	            fa[i] = s;
	            dfs (i);
	        }
	    }
	}
	int prim (int s) {
	    clr (mark , 0);
	    int sum , pos;
	    vis[s] = mark[s] = 1;
	    sum = 0;
	    for (int i = 1 ; i <= cnt ; i++) {
	        lowcost[i] = g[s][i];
	        pre[i] = s;
	    }
	    for (int i = 1 ; i <= cnt ; i++) {
	        pos = -1;
	        for (int j = 1 ; j <= cnt ; j++) {
	            if (!vis[j] && !mark[j]) {
	                if (pos == -1 || lowcost[pos] > lowcost[j]) {
	                    pos = j;
	                }
	            }
	        }
	        if (pos == -1) break;
	        vis[pos] = mark[pos] = 1;
	        edge[pre[pos]][pos] = edge[pos][pre[pos]] = 1;
	        sum += g[pre[pos]][pos];
	        for (int j = 1 ; j <= cnt ; j++) {
	            if (!vis[j] && !mark[j]) {
	                if (lowcost[j] > g[pos][j]) {
	                    lowcost[j] = g[pos][j];
	                    pre[j] = pos;
	                }
	            }
	        }
	    }
	    int minedge = inf;
	    int root = -1;
	    for (int i = 1 ; i <= cnt ; i++) {
	        if (mark[i] && g[i][1] < minedge) {
	            minedge = g[i][1];
	            root = i;
	        }
	    }
	    mark[root] = 0;
	    dfs (root);
	    fa[root] = 1;
	    return sum + minedge;
	}
	int Best (int s) {
	    if (fa[s] == 1) return -1;
	    if (best[s] != -1) return best[s];
	    int tmp = Best (fa[s]);
	    if (tmp != -1 && g[fa[tmp]][tmp] > g[fa[s]][s]) {
	        best[s] = tmp;
	    } else best[s] = s;
	    return best[s];
	}
	
	void solve() {
	    clr (vis , 0);
	    clr (fa , -1);
	    clr (edge , 0);
	    vis[1] = 1;
	    int num = 0;
	    ans = 0;
	    for (int i = 1 ; i <= cnt ; i++) {
	        if (!vis[i]) {
	            num++;
	            ans += prim (i);
	        }
	    }
	    int minadd , change;
	    for (int i = num + 1 ; i <= k && i <= cnt; i ++) {
	        clr (best , -1);
	        for (int j = 1 ; j <= cnt ; j++) {
	            if (fa[j] != 1 && best[j] == -1) {
	                Best (j);
	            }
	        }
	        minadd = inf;
	        for (int j = 1 ; j <= cnt ; j++) {
	            if (g[1][j] != inf && fa[j] != 1) {
	                int a = best[j];
	                int b = fa[best[j]];
	                int tmp = g[1][j] - g[a][b];
	                if (minadd > tmp) {
	                    minadd = tmp;
	                    change = j;
	                }
	            }
	        }
	        if (minadd >= 0) break;
	        ans += minadd;
	        int a = best[change];
	        int b = fa[best[change]];
	        g[a][b] = g[b][a] = inf;
	        fa[a] = 1;
	        g[1][a] = g[a][1] = g[change][1];
	        g[1][change] = g[change][1] = inf;
	    }
	}
	int main() {
	    m.clear();
	    m["Park"] = 1;
	    init();
	    scanf ("%d" , &n);
	    string str1 , str2;
	    int v;
	    for (int i = 0 ; i < n ; i++) {
	        cin >> str1 >> str2;
	        scanf ("%d" , &v);
	        int a = m[str1];
	        int b = m[str2];
	        if (!a) {
	            m[str1] = a = ++cnt;
	        }
	        if (!b) {
	            m[str2] = b = ++cnt;
	        }
	        if (g[a][b] > v) g[a][b] = g[b][a] = v;
	    }
	    scanf ("%d" , &k);
	    solve();
	    printf ("Total miles driven: %d\n" , ans);
	    19
	    return 0;
	}


>	生成树计数

	Matrix-Tree定理(Kirchhoff矩阵-树定理)   
	Kirchhoff矩阵C[G]=D[G]-A[G] (度数矩阵-邻接矩阵)  
	求C[G]任意一个n-1阶主子式的行列式(取出第i行和第i列)
		
	//spoj 104 Highways
	//朴素求解, ans是double用printf("%0.0f\n",ans)输出成int
	//返回是否有解,若有解ans*=a[i][i]中
	#define eps 1e-10
	#define fabs(x) ((x)>eps?(x):-(x))
	#define ZERO(x) (fabs(x) > eps ? 0 : 1)
	int gauss_tpivot (int n, double a[][Maxn]) {
	    int i, j, k, p;
	    double maxp, t;
	    for (k = 0; k < n; k++) {
	        if(ZERO(a[k][k])) {
	            for(i = k + 1; i < n; i++) if(!ZERO(a[i][i])) break;
	            if(i >= n) return 0;
	            for(j = k; j < n; j++) {
	                swap(a[k][j], a[i][j]);
	            }
	        }
	        maxp = a[k][k];
	        for (j = k + 1; j < n; j++) {
	            a[k][j] /= maxp;
	            for (i = k + 1; i < n; i++)
	                a[i][j] -= a[i][k] * a[k][j];
	        }
	    }
	    return 1;
	}
	
	int main() {
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                a[i][j] = b[i][j] = 0;
            }
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            if(u == v) continue;
            u--; v--;
            a[u][u]++; a[v][v]++;
            b[u][v] = b[v][u] = 1;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                a[i][j] = a[i][j] - b[i][j];
            }
        }
        double ans = 0;
        if(gauss_tpivot(n - 1, a)) {
            ans = 1;
            for(i = 0; i < n - 1; i++) ans *= a[i][i];
        }
        else ans = 0;
        printf("%0.0f\n", ans);
	}

	//hdu 4305 MOD = 10007
	//答案取模, 每一步需要取模处理
	LL gauss_tpivot (int n, LL a[][Maxn]) {
	    LL ret = 1;
	    int i, j, k;
	    LL p , q;
	    tot = 0;
	    for (k = 0; k < n; k++) {
	        if(!a[k][k]) {
	            for(i = k + 1; i < n; i++) if(a[i][k]) break;
	            if(i >= n) return 0;
	            for(j = k; j < n; j++) {
	                swap(a[k][j], a[i][j]);
	            }
	            ret *= -1;
	        }
	        if(a[k][k] < 0) {
	            for(j = 0; j < n; j++) a[k][j] *= -1;
	        }
	        p = a[k][k];
	        ret = ret * p % MOD;
	        for(i = k + 1; i < n; i++) {
	            q = a[i][k] * inv[a[k][k]] % MOD;
	            for(j = k + 1; j < n; j++) {
	                a[i][j] = (a[i][j] - a[k][j] * q) % MOD;
	                if(a[i][j] < 0) a[i][j] += MOD;
	            }
	        }
	    }
	    return ret % MOD;
	}
	
>	生成树相关问题	


	// 生成树相关的一些问题 By 猛犸也钻地 @ 2012.02.24
	
	/* 度限制生成树 //
	Q: 求一个最小生成树，其中V0连接的边不能超过K个或只能刚好K个
	1. 去掉所有和V0连接的边，对每个连通分量求最小生成树
	2. 如果除去点V0外共有T个连通分量，且T>K，无解
	3. 于是现在有一个最小T度生成树，然后用dp[V]计算出该点到V0的路径上
	   权值最大的边是多少，再枚举和V0连接的没有使用过的边，找出一条边
	   使得用那条边替换已有的边，增加的权值最小，不停替换直到V0出度为K */
	
	/* 次小生成树 //
	Q: 求一个次小生成树，要求权值之和必须大于等于或严格大于其最小生成树
	1. 求最小生成树
	2. 找一个根然后dp，求出每个点往上走2^L能到达的祖先是谁，以及
	   这段路径上的最大边和次大边(如果仅要求大于等于的话就不需要次大边)
	3. 枚举没有使用过的边，利用上面得到的信息，在O(logN)时间内对每条边
	   计算出其能够替换的已有的最大和次大边，然后找出最佳替换方式 */
	
	/* 斯坦纳树 //
	Q: 求一个包含指定的K个特殊点的最小生成树，其他点不一定在树中
	1. 用dp[mask][x]记录树根在点x，mask所对应的特殊点集在树中的最小权值之和
	2. 将dp[][]初始化为正无穷，只有dp[1<<i][Ai]被初始化为0，Ai为第i个特殊点
	3. 先求出所有点对间最短路，然后枚举mask，依次做两种转移：
	3.1. 枚举x和mask的子集sub，合并两棵子树
	     dp[mask][x]=min(dp[mask][x],dp[sub][x]+dp[mask^sub][x])
	3.2. 枚举x和y，计算结点从y移动到x的花费
	     dp[mask][x]=min(dp[mask][x],dp[mask][y]+minDistance(y,x))
	     在上面的转移中，也可以把这些点同时放到队列里，用spfa更新最短路 */
	
	/* 生成树计数 //
	Q: 给定一个无权的无向图G，求生成树的个数
	1. 令矩阵D[][]为度数矩阵，其中D[i][i]为结点i的度，其他位置的值为0
	2. 令矩阵A[][]为邻接矩阵，当结点i和j之间有x条边时，D[i][j]=D[j][i]=x
	3. 令矩阵C=D-A，矩阵C'为矩阵C抽去第k行和第k列后的一个n-1阶的子矩阵
	   其中k可以任意设定，构造完C'后，生成树的个数即为C'行列式的值 */


####    03. *最小树形图(有向图的最小生成树)*   

>	基础知识

	hdu4009 hdu2121 poj3164 UVa11865

	本题为不是固定根的最小树形图，我们可以虚拟出一根来，然后在把这个根跟每个点相连，相连的点可以设为无穷大，或者设为所有边和大一点，比如为r，然后就可以利用最小树形图进行计算了，计算出的结果减去r,如果比r还大就可以认为通过这个虚拟节点我们连过原图中两个点，即原图是不连通的，我们就可以认为不存在最小树形图。关于输出最小根也挺简单，在找最小入弧时，如果这条弧的起点是虚拟根，那么这条弧的终点就是要求的根

>	朱刘算法

	验题:POJ3164 HDU2121
	/* 
	 * 最小树形图（根固定）     O(VE)
	 * 有向图最小生成树
	 * 根不固定，添加一个根节点与所有点连无穷大的边！
	 * 如果求出比2*MOD大, 则不连通; 求根, 则求和虚拟根相连的结点
	 * 根据pre的信息能构造出这棵树！
	 * 注意结点必须从0~n-1, 因为要考虑重新标号建图的统一
	 * mytype 根据实际情况确定
	 */
	typedef int mytype;
	int visit[Maxn], pre[Maxn], belong[Maxn], ROOT;
	mytype inv[Maxn]; 
	mytype dirtree(int n, int m, int root) {
	    mytype sum = 0;
	    int i, j, k, u, v;
	    while (1) {
	        for (i = 0; i < n; i++) {
	            inv[i] = MOD;
	            pre[i] = -1;
	            belong[i] = -1;
	            visit[i] = -1;
	        }
	        inv[root] = 0;
	        for (i = 0; i < m; i++) {//除原点外，找每个点的最小入边
	            u = e[i].u; v = e[i].v;
	            if (u != v) {
	                if (e[i].w < inv[v]) {
	                    inv[v] = e[i].w;
	                    pre[v] = u;
	                    if(u == root) ROOT = i; //记录根所在的边
	                                            //输出根时利用ROOT-m计算是原图哪个结点
	                }
	            }
	        }
	        for (i = 0; i < n; i++) {
	            
	            if (inv[i] == MOD) return -1;
	        }
	        int num = 0;
	        for (i = 0; i < n; i++) { //找圈，收缩圈
	            if (visit[i] == -1) {
	                j = i;
	                for(j = i; j != -1 && visit[j] == -1 && j != root; j = pre[j]) {
	                    visit[j] = i;
	                }
	                if (j != -1 && visit[j] == i) {
	                    for (k = pre[j]; k != j; k = pre[k]) {
	                        belong[k] = num;
	                    }
	                    belong[j] = num ++ ;
	                }
	            }
	            sum += inv[i];
	        }
	        if (num == 0) return sum;
	        for (i = 0; i < n; i++){
	            if (belong[i] == -1) {
	                belong[i] = num ++ ;
	            }
	        }
	        for (i = 0; i < m; i++) { //重新构图
	            e[i].w = e[i].w - inv[e[i].v];
	            e[i].v = belong[e[i].v];
	            e[i].u = belong[e[i].u];
	        }
	        n = num;
	        root = belong[root];
	    }
	}

####	04. **斯坦纳树**

>  

####    05.	*最短路*  

>	floyd  

>	dijkstra
  
>	spfa  

	普通入队列方式可以被cha  

	deque判当前节点和队首节点可以被三角形数据cha  

	priority_queue优化(本质dijkstra靠谱!)
	
>	最短路次短路计数

	void dij() {
	    clr (cnt , 0);
	    clr (vis , 0);
	    for (int i = 0 ; i <= n ; i++) {
	        dis[i][0] = inf;
	        dis[i][1] = inf;
	    }
	    dis[st][0] = 0;
	    cnt[st][0] = 1;
	    for (int i = 1 ; i <= 2 * n ; i++) {
	        int tmp = inf , tx = -1 , flag;
	        for (int j = 1 ; j <= n ; j++) {
	            if (!vis[j][0] && dis[j][0] < tmp) {
	                tmp = dis[j][0];
	                tx = j;
	                flag = 0;
	            } else
	                if (!vis[j][1] && dis[j][1] < tmp) {
	                    tmp = dis[j][1];
	                    tx = j;
	                    flag = 1;
	                }
	        }
	        if (tx == -1) break;
	        13
	        vis[tx][flag] = 1;
	        for (int j = head[tx] ; ~j ; j = e[j].next) {
	            int v = e[j].v , c = e[j].c;
	            if (dis[tx][flag] + c < dis[v][0]) {
	                dis[v][1] = dis[v][0];
	                cnt[v][1] = cnt[v][0];
	                dis[v][0] = dis[tx][flag] + c;
	                cnt[v][0] = cnt[tx][flag];
	            } else
	                if (dis[tx][flag] + c == dis[v][0]) {
	                    cnt[v][0] += cnt[tx][flag];
	                } else
	                    if (dis[tx][flag] + c == dis[v][1]) {
	                        cnt[v][1] += cnt[tx][flag];
	                    } else
	                        if (dis[tx][flag] + c < dis[v][1]) {
	                            dis[v][1] = dis[tx][flag] + c;
	                            cnt[v][1] = cnt[tx][flag];
	                        }
	        }
	    }
	}


>	K短路  

	练手: POJ2449 UVA10740   
	提高: SGU145 SGU314

	最短路+A*

		f[x] = g[x] + h[x]
		其中h[x]以从t到x的最短路
		g[x]为从s到x的当前路径长度

	YEN算法

	MPS算法

	最短路树+回溯

	带环K短路

	无环K短路
	
	不重复k短路
		
		费用流~.~

>	求字典序最小的路径

	无重复标号(如给定边长度, 输出最短路径上经过的结点的最小字典序):hdu1385

	有重复标号(如边长度都为d, 每条边给定标号, 输出最短路径上边标号的最小字典序)http://codeforces.com/gym/100084 (I题)

	有重复标号(如给定边长度和边标号, 输出最短路径上每条边给定的标号的最小字典序)???


####	06. **差分约束**

>  


####    07. **欧拉回路**

>	判断无向图欧拉路和欧拉回路的条件


>   判断有向图欧拉路和欧拉回路的条件

>   注意图的连通性的影响


>   fleury算法(和一般dfs的差别???)


>   磁鼓欧拉回路(HDU 2894)
    
            n个触头, 建图以(1<<(n-1))个结点, 建1<<n条有向边, 从最大结点出发跑欧拉回路
            

>   混合欧拉路欧拉回路的判断-->网络流模型

    (相关题目：pku1637，zju1992，hdu3472, hdu1956)

    给出一张混合图（有有向边，也有无向边），判断是否存在欧拉回路。  
    首先是对图中的无向边随意定一个方向，然后统计每个点的入度（indeg）和出度（outdeg），如果（indeg - outdeg）是奇数的话，一定不存在欧拉回路；  
    如果所有点的入度和出度之差都是偶数，那么就开始网络流构图：  
    1，对于有向边，舍弃；对于无向边，就按照最开始指定的方向建权值为 1 的边；  
    2，对于入度小于出度的点，从源点连一条到它的边，权值为（outdeg - indeg）/2；出度小于入度的点，连一条它到汇点的权值为（indeg - outdeg）/2 的边；  
    构图完成，如果满流（求出的最大流值 == 和汇点所有连边的权值之和），那么存在欧拉回路，否则不存在。  

	建图基础:
		
	//outdeg出度, indeg入度, !w双向边
	for(i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        outdeg[u]++;
        indeg[v]++;
        if(!w) {
            adde(u, v, 1);
        }
    }
    int flag = true;
    for(i = 1; i <= n; i++) {
        if(abs(indeg[i] - outdeg[i]) & 1) {
            flag = false;
            break;
        }
    }
    if(flag) {
        S = 0; T = n + 1; sums = sumt = 0;
        for(i = 1; i <= n; i++) {
            if(outdeg[i] > indeg[i]) {
                adde(S, i, (outdeg[i] - indeg[i]) / 2);
                sums += (outdeg[i] - indeg[i]) / 2;
            }
            if(indeg[i] > outdeg[i]) {
                adde(i, T, (indeg[i] - outdeg[i]) / 2);
                sumt += (indeg[i] - outdeg[i]) / 2;
            }
        }
        int flow = dinic(S, T, T + 1);
        if(flow != sums) flag = false;
    }

####    08.	**哈密尔顿回路**

>	
	

####    09.  *最小环&最大环* 

>	最小环  

	验题: POJ1734 
			    
	//floyd算法
	//g[][] 边
	//f[][] 最短路
	//pre[][] 记录路径
	int MinCircle() {
	    int i, j, k, p;
	    int mc = MOD;
	    for(i = 1; i <= n; ++i) {
	        for(j = 1; j <= n; ++j) {
	            f[i][j] = g[i][j];
	            if(g[i][j] < MOD && i != j) {
	                pre[i][j] = j; //记录初始长度为1的路径
	            }
	            else {
	                pre[i][j] = -1;
	            }
	        }
	    }
	    for(k = 1; k <= n; ++k) {
	        for(i = 1; i < k ; ++i) {
	            for(j = i + 1; j < k; ++j) {
	                int tp = g[k][i] + f[i][j] + g[j][k];
	                if(tp < mc) { //更新最小环和路径
	                    mc = tp;
	                    for(p = i, len = 0; p != -1; p = pre[p][j], len++) {
	                        path[len] = p;
	                    }
	                    path[len++] = k;
	                }
	            } 
	        }
	        for(i = 1; i <= n; ++i) { //普通floyd过程
	            for(j = 1; j <= n; ++j) {
	                if(f[i][j] > f[i][k] + f[k][j]) {
	                    f[i][j] = f[i][k] + f[k][j];
	                    pre[i][j] = pre[i][k];
	                }
	            }
	        }
	    }
	    return mc;
	}

	未验题:

	//http://www.cnblogs.com/Yz81128/archive/2012/08/15/2640940.html
	//dijkstra
	//求一条边的两段的结点之间最短路(不包含这条边)和这条边之和
	//O(m*m*logn)


>	 最大环(??? 可做)

	poj2240
	//这一题, 货币兑换, 看看是否存在能使自己增值的方案, 感官上并不能算最大环问题, 而更贴切的看法是转换为最长路, 由BellmanFord思想判断存在>1的环的问题, 不过可以通过floyd的**松弛操作**同样解决掉 






