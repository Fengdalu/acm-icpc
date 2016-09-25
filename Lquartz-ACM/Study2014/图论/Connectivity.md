



####    01.  **连通性**  

>	强联通分量(Tarjan)

	/*
	 *   SCC 使用图struct
	 */      
	struct GRAPH {
	    struct node {
	        int u, v, next;
	    }adj[Maxm];
	    int tot, last[Maxn];
	    void init(int n) {
	        for(int i = 0; i <= n; i++) last[i] = -1;
	        tot = 0;
	    }
	    void adde(int u, int v) {
	        adj[tot].u = u; adj[tot].v = v; 
	        adj[tot].next = last[u]; last[u] = tot++;
	    }
	}e;
	int dfn[Maxn], low[Maxn], belong[Maxn], instack[Maxn], ncnt, nindex;
	stack<int> sta;
	void Tarjan(int u) {
	    int j, v;
	    dfn[u] = low[u] = nindex++;
	    sta.push(u);
	    instack[u] = 1;
	    for(j = e.last[u]; ~j; j = e.adj[j].next) {
	        v = e.adj[j].v;
	        if(-1 == dfn[v]) {
	            Tarjan(v);
	            if(low[u] > low[v]) low[u] = low[v];
	        }
	        else if(instack[v] && dfn[v] < low[u]) {
	            low[u] = dfn[v];
	        }
	    }
	    if(dfn[u] == low[u]) {
	        do {
	            v = sta.top();
	            sta.pop();
	            instack[v] = 0;
	            belong[v] = ncnt;
	        }while(u != v);
	        ncnt++;
	    }
	}
	void solve(){
	    int i, flag = 0;
	    memset(dfn, -1, sizeof(dfn));
	    memset(low, -1, sizeof(low));
	    memset(instack, 0, sizeof(instack));
	    memset(belong, -1, sizeof(belong));
	    ncnt = 1;
	    nindex = 1;
	    for(i = 1; i <= n; i++){
	        if(-1 == dfn[i]) {
	            Tarjan(i);
	            flag++;
	        }
	    }
	    ///*
	//    for(i = 1; i <= n; i++)
	//        printf("%d %d\n", i, belong[i]);
	    //*/
	}

>   边双连通(Tarjan)

    /*
    *EBCC
    */
    struct GRAPH {
        struct node {
            int u, v, next;
        }adj[Maxm];
        int tot, last[Maxn];
        void init(int n) {
            for(int i = 0; i <= n; i++) last[i] = -1;
            tot = 0;
        }
        void adde(int u, int v) {
            adj[tot].u = u; adj[tot].v = v; 
            adj[tot].next = last[u]; last[u] = tot++;
        }
    }e;
    int n, m;
    int dfn[Maxn], low[Maxn], belong[Maxn], instack[Maxn], nindex, ncnt;
    stack<int> sta;      
    void Tarjan(int u, int from) {
        int j, v;
        dfn[u] = low[u] = nindex++;
        instack[u] = 1;
        sta.push(u);
        for(j = e.last[u]; ~j; j = e.adj[j].next) {
            if(j == from) continue;
            v = e.adj[j].v;
            if(-1 == dfn[v]) {
                Tarjan(u, j ^ 1);
                low[u] = min(low[u], low[v]);
            }
            else if(instack[v] && dfn[v] < low[u]) {
                low[u] = dfn[v];
            }
        }
        if(dfn[u] == low[u]) {
            do {
                v = sta.top();
                sta.pop();
                instack[v] = 0;
                belong[v] = ncnt;
            } while(v != u);
            ncnt++;
        }
    }
          
    void solve() {
        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        memset(instack, 0, sizeof(instack));
        memset(belong, -1, sizeof(belong));
        ncnt = 1;
        nindex = 1;
        int flag = 0;
        for(int i = 1; i <= n; i++)
            if(-1 == dfn[i]) {
                Tarjan(i, -1);
                flag++;
            }
          
        ///*
        for(int i = 1; i <= n; i++)
            cout << i << " " << belong[i] <<endl;
        //*/
    }


>   点双连通(Tarjan+重建图)

	#define STEP 20
	struct GRAPH {
	    struct node {
	        int u, v, next;
	    }adj[Maxm];
	    int tot, last[Maxn];
	    void init(int n) {
	        for(int i = 0; i <= n; i++) last[i] = -1;
	        tot = 0;
	    }
	    void adde(int u, int v) {
	//        cout << "adde " << u << " " << v << endl;
	        adj[tot].u = u; adj[tot].v = v;
	        adj[tot].next = last[u]; last[u] = tot++;
	    }
	}e, e1;
	int dfn[Maxn], low[Maxn], iscut[Maxn], belong[Maxm], color[Maxm];
	int lcnt[Maxm];
	int nindex, ncnt;
	stack<int> sta;
	int n, m, q;
	void Tarjan(int u, int from) {
	    int v, child = 0;
	    dfn[u] = low[u] = ++nindex;
	    for(int j = e.last[u]; j != -1; j = e.adj[j].next) {
	        if(j == from) continue;
	        v = e.adj[j].v;
	        if(dfn[v] < dfn[u]) {
	            sta.push(j);
	            if(!dfn[v]) {
	                child ++;
	                Tarjan(v, j ^ 1);
	                low[u] = min(low[u], low[v]);
	                if(low[v] >= dfn[u]) {
	                    ncnt++;
	                    while(sta.top() != j) {
	                        belong[sta.top() / 2] = ncnt;
	                        sta.pop();
	                    }
	                    belong[j / 2] = ncnt;
	                    sta.pop();
	                    iscut[u] = 1;
	                }
	            }
	            else low[u] = min(low[u], dfn[v]);
	        }
	    }
	    if(from < 0 && child == 1)iscut[u] = -1;//child
	//    if(child
	}
	set<PII> S;
	void newAdde(int u, int v) {
	    if(u > v) swap(u, v);
	    PII ss = MP(u, v);
	    if(S.find(ss) == S.ED) {
	        S.insert(ss);
	        e1.adde(u, v);
	        e1.adde(v, u);
	    }
	}
	int visit[Maxm];
	void gao(int u) {
	    int j, v;
	    for(j = e1.last[u]; j != -1; j = e1.adj[j].next) {
	        v = e1.adj[j].v;
	        if(visit[v] == -1) {
	            visit[v] = 1;
	            gao(v);
	        }
	    }
	}
	void buildGraph() {
	    int i, j, u, v, x, y;
	    e1.init(ncnt + 10);
	    S.clear();
	    for(j = 0; j < e.tot; j += 2) {
	        u = e.adj[j].u; v = e.adj[j].v;
	        if(iscut[u] == -1 && iscut[v] == -1) continue;
	        else {
	            if(iscut[u] != -1){
	                x = iscut[u];
	                y = belong[j / 2];
	                newAdde(x, y);
	            }
	            if(iscut[v] != -1){
	                x = iscut[v];
	                y = belong[j / 2];
	                newAdde(x, y);
	            }
	        }
	    }
	    for(i = 0; i <= ncnt; i++) visit[i] = -1;
	    for(i = 1; i <= ncnt; i++) {
	        if(visit[i] == -1) {
	            visit[i] = 1;
	            gao(i);
	            e1.adde(0, i);
	            e1.adde(i, 0);
	            
	        }
	    }
	}
	void solve() {
	    int i, j;
	    memset(dfn, 0, sizeof(dfn));
	    memset(low, 0, sizeof(low));
	    memset(iscut, -1, sizeof(iscut));
	    memset(color, 0, sizeof(color));
	    memset(belong, -1, sizeof(belong));
	    ncnt = nindex = 0;
	    for(i = 1; i <= n; i++) {
	        if(!dfn[i]) {
	            while(!sta.empty()) sta.pop();
	            Tarjan(i, -1);
	        }
	    }
	    for(i = 1; i <= n; i++) {
	        if(iscut[i] == 1) {
	            color[++ncnt] = 1;
	            iscut[i] = ncnt;
	        }
	    }
	    buildGraph();
	}



####    02.  *拓扑排序*  


>	基础知识

	一、拓扑排序

	    什么是拓扑排序？简单地说，由某个集合上的一个偏序得到该集合上的一个全序，这个操作称之为拓扑排序。
	    AVO网（Activity On Vertex Network），也称作顶点表示活动的网，就是用顶点表示活动，用弧表示活动间的优先关系的有向图。
	    拓扑排序是对AOV网构造一个线性序列，使所有的优先关系在此序列中得以体现，换句话说，就是在AVO网中，若Vi是Vj的前驱，那么在拓扑序列中，Vi必须排在Vj之前。
	          
	    拓扑排序的步骤如下：
	            1、在有向图中选取一个没有前驱的顶点，并输出；
	            2、从图中删除该顶点和所有以它为尾的弧；
	            3、重复1和2，直到全部顶点均被输出为止。
	            （注：弧尾指弧的起始点，弧头是指弧的终点）
	    一个有向无环图的拓扑序列是不唯一的。
	              
	二、关键路径

        与AVO网相对应的是AOE网（Activity On Edge）即边表示活动的网。
        所谓AOE网，也称作“用表示活动的网”，就是用顶点表示事件，用弧表示活动，弧上的权值表示该活动的持续时间的有向图。
        关键路径：是指AOE网上，完成工程的最短时间是从开始点到完成点的最长路径长度，路径长度最长的路径叫做关键路径。
        分析关键路径的目的是辨别哪些是关键活动，以便争取提高关键活动的工效，缩短整个工期。
        事件Vi的最早发生时间Ve(i)中从顶点V到Vi的最长路径长度。
        活动Ai的最迟开始时间V(i)是该活动的终点所表示的事件最迟发生时间与该活动的所需时间之差。
        一个活动的最迟开始时间减去最早开始时间之差定义为完成该活动的时间余量，而最迟开始时间等于最早开始时间的活动叫做关键活动。
              
        求关键路径的算法描述：
                (1) 输入e条弧<j,k>，建立AOE网的存储结构。
                (2) 从源点v1出发，令ve(1)=0,求 ve(j) 2<=j<=n。
                (3) 从汇点vn出发，令vl(n)=ve(n),求 vl(i) 1<=i<=n-1。
                (4) 根据各顶点的ve和vl值，求每条弧s（活动）的最早开始时间e(s)和最晚开始时间l(s)，其中e(s)=l(s)的为关键活动。
              
        求关键路径的算法分析
                （1） 求关键路径必须在拓扑排序的前提下进行，有环图不能求关键路径；
                （2） 只有缩短关键活动的工期才有可能缩短工期；
                （3） 若一个关键活动不在所有的关键路径上，减少它并不能减少工期；
                （4） 只有在不改变关键路径的前提下，缩短关键活动才能缩短整个工期。

>	求任意拓扑排序或判断是否可以拓扑排序

	队列实现

	dfs实现  
	记录各点完成访问的时刻(完成时间),用DFS遍历一次整个图,得出各结点的完成时间,然后按完成时间倒序排列就得到了图的拓扑序列

	/* 拓扑排序         O(e)
	 * 确保是有向无环图！
	 * 结果逆序存放在sta中！
	 * */
	VI ve[Maxn];
	bool vis[Maxn];
	int sta[Maxn], top;
	void dfsTopo(int u) {
	    vis[u] = true;
	    for (int i = 0; i < ve[u].size(); i ++ )
	           if (!vis[ve[u][i]])
	               dfsTopo(ve[u][i]);
	    sta[top ++ ] = u;
	}
	void Toposort(int n) {
	    memset(vis, 0, sizeof(vis));
	    top = 0;
	    for (int i = 1; i <= n; i ++ )
	        if (!vis[i]) dfsTopo(i);
	}

>	字典序最小解

	一般直接将队列改为优先队列即可(要求无重复标号!!!)  
	HDU1285

	区分字典序最小和标号小的尽量靠前   特殊题目要求: POJ3687

	int n, m;
	struct node {
	    int u, v, next;
	}e[Maxm];
	int tot, last[Maxn];
	priority_queue<int > Q;
	vector<int> ans, out;
	int deg[Maxn];
	
	void adde(int u, int v) {
	    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
	}
	
	int main() {
	    int i, j, u, v, te;
	    scanf("%d", &te);
	    while(te--) {
	        scanf("%d%d", &n, &m);
	        tot = 0;
	        for(i = 1; i <= n; i++) {
	            last[i] = -1;
	            deg[i] = 0;
	        }
	        for(i = 0; i < m; i++) {
	            scanf("%d%d", &u, &v);
	            adde(v, u);
	            deg[u]++;
	        }
	        while(!Q.empty()) Q.pop();
	        for(i = 1; i <= n; i++) {
	            if(deg[i] == 0) Q.push(i);
	        }
	        ans.clear();
	        out.clear();
	        while(!Q.empty()) {
	            u = Q.top();
	            Q.pop();
	            ans.PB(u);
	            for(j = last[u]; j != -1; j = e[j].next) {
	                v = e[j].v;
	                deg[v]--;
	                if(deg[v] == 0) Q.push(v);
	            }
	        }
	        if(ans.SZ < n) {
	            printf("-1\n");
	        }
	        else {
	            reverse(ans.BG, ans.ED);
	            out = ans;
	            for(i = 0; i < n; i++) {
	                out[ans[i] - 1] = i + 1;
	            }
	            for(i = 0; i < n; i++) {
	                if(i) printf(" ");
	                printf("%d", out[i]);
	            }
	            printf("\n");
	        }
	    }
	    return 0;
	}
	
	/*
	2
	
	5 4
	5 1
	4 2
	1 3
	2 3
	
	10 5
	4 1
	8 1
	7 8
	4 1
	2 8
	ans:
	2 4 5 3 1        逆向建图
	5 1 6 2 7 8 3 4 9 10  没有判重边的话就输出 -1
	
	*/

	有重复标号字典序最小???

>	有向图拓扑排序计数(状压dp)

	验题: ZOJ1346 HDU4917

	// dp[status] 当前图中结点01表示, 初始化只剩一个点dp[1<<j]=1
	// deg[] 结点度数
	// g[][] vector存边
	// group[] 将当前块结点映射到group的0~now位置
	// now当前块节点数
	// 各个连通块求dp值, 乘上组合数C[n][now], 没处理一块n-=now
	int doit(int status) {
	    if(dp[status] != -1) return dp[status];
	    LL sum = 0;
	    int i, j, u, v;
	    for(i = 0; i < now; i++) {
	        u = group[i];
	        if(deg[u] == 0) {
	            deg[u] = -1;
	            for(j = 0; j < g[u].SZ; j++) {
	                v = g[u][j];
	                deg[v]--;
	            }
	            sum += doit(status ^ (1<<i));
	            for(j = 0; j < g[u].SZ; j++) {
	                v = g[u][j];
	                deg[v]++;
	            }
	            deg[u] = 0;
	        }
	    }
	    return (dp[status] = sum % MOD);
	}

>	树拓扑排序计数

	计算公式  

	n!/node[i] (1 < i <= n) 
	n表示树的总节点数, node[i] 表示以i为根的子树的节点数

>	关键路径

	求关键路径：

	1. 关键节点：
	        正向拓扑序， 求每个点最早到达时间early[i] = max(early[i], early[j] + edge[k]);
	        利用汇点的early值，反向拓扑求每个点迟到达时间late[i] = min(late[i], late[j] - edge[k]);
	        关键节点early == late
	        PS：
	                最早开始时间可以理解为是必须等到之前的任务完成才能做
	                最迟开始时间可以理解为是必须为后面的任务留出足够的时间
	              
	2. 关键路径 ：
	        源点到汇点的最长路（可能有多条）


####    03.  **LCA**  

>	倍增算法

	//改bfs
	验题: POJ1330,     

	//LCA O(nlogn)
	//加边之前使用initLCA()初始化数组
	//调用solveLCA()初始化LCA
	//调用getLCA(x,y)返回x和y的LCA
	struct node {
	    int u, v, l, next;
	}e[Maxm];
	int tot, last[Maxn];
	void adde(int u, int v) {
	    e[tot].u = u; e[tot].v = v;
	    e[tot].next = last[u]; last[u] = tot++;
	}
	int depth[Maxn], fa[16][Maxn];
	int n, m;
	void initLCA() {
	    int i, j;
	    for(i = 0; i <= n; i++) {
	        depth[i] = -1;
	        last[i] = -1;
	        for(j = 0; j < 16; j++) fa[j][i] = -1;
	    }
	    tot = 0;
	}
	void dfsLCA(int u) {
	    int j, v;
	    for(j = last[u]; j != -1; j = e[j].next) {
	        v = e[j].v;
	        if(depth[v] == -1) {
	            fa[0][v] = u;
	            depth[v] = depth[u] + 1;
	            dfsLCA(v);
	        }
	    }
	}
	
	int getLCA (int x, int y) {
	    int i, dif = abs(depth[x] - depth[y]);
	    if (depth[x] < depth[y]) swap(x, y);
	    for (i = 20 - 1; i >= 0; i--) {
	        if ((1 << i) & dif) {
	            dif -= (1 << i);
	            x = fa[i][x];
	        }
	    }
	    for (i = 16 - 1; i >= 0; i--) {
	        if (fa[i][x] != fa[i][y]) {
	            x = fa[i][x];
	            y = fa[i][y];
	        }
	    }
	    if (x == y) return x;
	    else return fa[0][x];
	}
	
	void solveLCA() {
	    int i, j, root = 1;
		for(i = 0; i <= n; i++) depth[i] = -1;
	    fa[0][root] = root;
	    depth[root] = 0;
	    dfsLCA(root);
	    for (i = 1; i < 16; i++)
	        for(j = 0; j <= n; j++)
	            fa[i][j] = fa[i-1][fa[i-1][j]];
	}

>	Tarjan

	验题: HDU2586

	//Tarjan离线LCA
	//e存放树边
	//q存放query
	struct GRAPH {
	    struct node {
	        int u, v, n, next;
	    }adj[Maxm];
	    int tot, last[Maxn];
	    void init(int n) {
	        for(int i = 0; i <= n; i++) last[i] = -1;
	        tot = 0;
	    }
	    void adde(int u, int v, int n) {
	        adj[tot].u = u; adj[tot].v = v; adj[tot].n = n;
	        adj[tot].next = last[u]; last[u] = tot++;
	    }
	}e, q;
	int fa[Maxn], lca[Maxn], ans[Maxn];
	int visit[Maxn];
	int getfa(int x) {
	    if(x == fa[x]) return x;
	    else return (fa[x] = getfa(fa[x]));
	}
	
	void tarjanLCA(int u) {
	    int i, j, v, f;
	    fa[u] = u;
	    visit[u] = 1;
	    for(j = e.last[u]; j != -1; j = e.adj[j].next) {
	        v = e.adj[j].v;
	        if(!visit[v]) {
	            tarjanLCA(v);
	            fa[v] = u;
	        }
	    }
	    for(j = q.last[u]; j != -1; j = q.adj[j].next) {
	        v = q.adj[j].v;
	        if(visit[v]) {
	            lca[q.adj[j].n] = f = getfa(v);
	            ans[q.adj[j].n] = dist[v] + dist[u] - 2 * dist[f];
	        }
	    }
	}

>	LCA 转 RMQ

	0:			(1)
		    	/ \
	1:		 (2)   (7)
		     / \     \
	2:	   (3) (4)   (8)
		      /   \
	3:	    (5)   (6)

	step 1: dfs遍历树, 依次记录每次到达的点, 以及每个点的深度得到序列:

		结点访问顺序是: 1 2 3 2 4 5 4 6 4 2 1 7 8 7 1 //共2n-1个值
		结点对应深度是: 0 1 2 1 2 3 2 3 2 1 0 1 2 1 0

	step 2: 利用ST计算任意区间最小深度的点的ID

	step 3: 对于每次查询, 查询u第一次出现位置到v第一次出现位置区间的最小值

>	



####    04. **2 SAT**  

>	综述

    	综述：每个条件的形式都是x[i]为真/假或者x[j]为真/假， 每个x[i]拆成2*i和2*i+1两个点，分别表示x[i]为真，x[i] 为假；加的每一条边之间的关系是and 模型一：两者（A，B）不能同时取（但可以两个都不选） 说明：A 为假或 B 为假 那么选择了 A 就只能选择 B’，选择了 B 就只能选择 A’ 连边 A→B’，B→A’ 模型二：两者（A，B）不能同时不取（但可以两个都选） 说明：A 为真或 B 为真 那么选择了 A’就只能选择 B，选择了 B’就只能选择 A 连边 A’→B，B’→A 模型三：两者（A，B）要么都取，要么都不取 说明：...... 那么选择了 A，就只能选择 B，选择了 B 就只能选择 A，选择了 A’就只能选择 B’， 选择了 B’就只能选择 A’ 连边 A→B，B→A，A’→B’，B’→A’ 模型四：两者（A，A’）必取A 那么，那么，该怎么说呢？先说连边吧。 连边 A’→A 模型五（补充） ：两者（A，B）两个必须不相同，即要么选A，要么选B 逻辑表达：A||B 非 A||非 B 连边：A 为真或 B 为真： A’--->B B’--->A;
    	29
    	A 为假或 B 为假: A-->B’ B-->A 说明：A 或 B，非 A 或非 B，前者表示两者至少有一个 true，后者表示至少有一个 false

>    判断可行性

    建图，求强连通，判断任意对象的两部是否属于同一强连通：
    
>    求任意解

    方法是，对原图求一次强连通分量，然后看每组中的两个点是否属于同一个强连通分量，如果存在这种情况，那么无解
    然后对于缩点后的图G'，我们将G'中所有边转置。进行拓扑排序。
       对于缩点后的所有点，我们先预处理求出所有冲突顶点。例如缩点后Ai所在强连通分支的ID为id[ Ai] ，同理~Ai在 id[~Ai], 所以冲突顶点
        conflict[ id[Ai] ]=conflict[ id[~Ai] ];
    同理conflict[ id[~Ai] ]=conflict[ id[Ai] ];
        设缩点后有Nscc个点。
        然后对拓扑序进行染色，初始化所有点color均为未着色
        顺序遍历得到的拓扑序列，对于未着色的点x，将x染成红色，同时将所有与x矛盾的点conflic[x]染成蓝色。
    2-sat的一组解就等价于所有缩点后点颜色为红色的点，也就是color[ id[i] ]=RED的所有点
    缩点
    　　Tarjan算法缩点，将所有的边反过来（ 为什么？后面有嗯 ）
    判可行
    　　枚举集合的两个元素，看其是否处于不同的块内，若否的话则给出不可行信息
    记录矛盾
    　　这里所说的矛盾不是题中给出的两个人之间有仇恨，那样的边是实际存在，我们这里说的矛盾是指若两个块分别含有两个对立节点，也就是说一个集合的两个元素分布在了两个不同的块中，那么这两个块就是矛盾的，即不可能同时被选择，这样一种矛盾关系是不存在于边中的，是不依赖于输入的数据的，我们要找到与一个块对立的块，并把它们保存下来。
    拓扑排序
    　　将缩点后的图进行拓扑排序（排的是块而不是节点）
    构造方案
    　　按照拓扑序列的顺序，依次访问所有块，若一个块未被标记，将其标记为“选择”，不传递“选择”标记，将被选块的对立块标记为“不选择”，将其“不选择”标记沿着边正向传递。（ 不是逆着边么？哼，图已经被反过来了，你到底有没有认真看呐！囧 ）
    /*2-sat*/
    #define Maxn 5010
    vector<VI> e, ne;
    
    
    int dfn[Maxn], low[Maxn], block[Maxn], sta[Maxn], top, tsp, N;
    int sta1[Maxn], rid[Maxn], top1; //rid 新旧图映射，sta1, top1 拓扑排序，输出路径
    /*初始化 top = tsp = N = 0 和 block为 -1, dfn 为 0*/
    void tarjan(int u, int root) {
        dfn[u] = low[u] = ++ tsp;
        sta[top ++ ] = u;
        for (int i = 0; i < e[u].size(); i ++ ) {
            int v = e[u][i];
            if (!dfn[v]) tarjan(v, root);
            if (dfn[v] < dfn[root]) continue;
            low[u] = min(low[u], low[v]);
        }
        if (low[u] == dfn[u]) {
            int v;
            do {
                v = sta[ -- top];
                block[v] = N;
            } while (v != u);
            rid[N] = u;
            sta1[top1 ++ ] = N;
            N ++ ;
        }
    }
    int color[Maxn];
    void colorBlue(int u) {
        color[u] = 2;
        for (int i = 0; i < ne[u].size(); i ++ ) {
            int v = ne[u][i];
            if (!color[v])
                colorBlue(v);
        }
    }
    bool twoSat(int n) {
        memset(dfn, 0, sizeof(dfn));
        memset(block, -1, sizeof(block));
        top1 = top = N = tsp = 0;
        for (int i = 0; i < n * 2; i ++ )
            if (!dfn[i])
                tarjan(i, i);
    
    
        for (int i = 0; i < n * 2; i += 2 )
            if (block[i] == block[i ^ 1])
                return 0;
        //return 1;
        /*建立新图*/
        ne.clear();
        for (int i = 0; i < N; i ++ ) {
            VI p;
            ne.PB(p);
        }
        for (int i = 0; i < n * 2; i ++ )
            for (int j = 0; j < e[i].size(); j ++ )
                if (block[i] != block[e[i][j]])
                    ne[block[e[i][j]]].PB(block[i]); //反向建图
        
        memset(color, 0, sizeof(color));
        for (int i = 0; i < top1; i ++ ) {
            int x = sta1[i];
            if (!color[x]) {
                color[x] = 1;
                x = block[rid[x] ^ 1];
                colorBlue(x);
            }
        }
        return 1;
    }


>	输出任一解

	//POJ3648
	#define Maxn 411
	#define Maxm 411111
	/*
	 *   SCC 使用图struct
	 */      
	struct GRAPH {
	    struct node {
	        int u, v, next;
	    }adj[Maxm];
	    int tot, last[Maxn];
	    void init(int n) {
	        for(int i = 0; i <= n; i++) last[i] = -1;
	        tot = 0;
	    }
	    void adde(int u, int v) {
	//        cout << "adde " << u << "-->" << v << endl;
	        adj[tot].u = u; adj[tot].v = v; 
	        adj[tot].next = last[u]; last[u] = tot++;
	    }
	}e, e1;
	int dfn[Maxn], low[Maxn], belong[Maxn], instack[Maxn], ncnt, nindex;
	stack<int> sta;
	int rid[Maxn], sta1[Maxn], top1; //rid 新旧图映射，sta1拓扑排序，输出路径
	void Tarjan(int u) {
	    int j, v;
	    dfn[u] = low[u] = nindex++;
	    sta.push(u);
	    instack[u] = 1;
	    for(j = e.last[u]; ~j; j = e.adj[j].next) {
	        v = e.adj[j].v;
	        if(-1 == dfn[v]) {
	            Tarjan(v);
	            if(low[u] > low[v]) low[u] = low[v];
	        }
	        else if(instack[v] && dfn[v] < low[u]) {
	            low[u] = dfn[v];
	        }
	    }
	    if(dfn[u] == low[u]) {
	        do {
	            v = sta.top();
	            sta.pop();
	            instack[v] = 0;
	            belong[v] = ncnt;
	        }while(u != v);
	        rid[ncnt] = u;
	        sta1[top1++] = ncnt;
	        ncnt++;
	    }
	}
	
	int color[Maxn];
	void colorBlue(int u) {
	    int j, v;
	    color[u] = 2;
	    for(j = e1.last[u]; j != -1; j = e1.adj[j].next) {
	        v = e1.adj[j].v;
	        if(!color[v]) colorBlue(v);
	    }
	}
	void buildGraph() {
	    int i, j, u, v, x, y;
	    e1.init(ncnt);
	    for(j = 0; j < e.tot; j++) {
	        x = belong[u = e.adj[j].u];
	        y = belong[v = e.adj[j].v];
	        if(x != y) {
	            e1.adde(y, x);//反向建图
	        }
	    }
	}
	int twoSat(int n) {
	    int i, u, v, flag = 0;
	    memset(dfn, -1, sizeof(dfn));
	    memset(low, -1, sizeof(low));
	    memset(instack, 0, sizeof(instack));
	    memset(belong, -1, sizeof(belong));
	    ncnt = 0; //缩点, 新点[0,ncnt)
	    nindex = 1;
	    top1 = 0;
	    for(i = 0; i < 2*n; i++) {
	        if(-1 == dfn[i]) {
	            while(!sta.empty()) sta.pop();
	            Tarjan(i);
	        }
	    }
	//    for(i = 0; i < 2 * n; i++) cout << i << " ~ " << belong[i] << endl;
	    for(i = 0; i < 2 * n; i += 2) {
	        if(belong[i] == belong[i ^ 1]) return false;
	    }
	    //建新图
	    buildGraph();
	    memset(color, 0, sizeof(color));
	    for(i = 0; i < top1; i++) {
	        u = sta1[i];
	        if(!color[u]) {
	            color[u] = 1;
	            v = belong[rid[u] ^ 1];
	            colorBlue(v);
	        }
	    }
	    return 1;
	}
	int n, m;
	char cu, cv;
	int main() {
	    int i, j, u, v, w, x, y;
	    //freopen("", "r", stdin);
	    //freopen("", "w", stdout);
	    while(scanf("%d%d", &n, &m) != EOF) {
	        if(n == 0 && m == 0) break;
	        e.init(4 * n);
	        for(i = 0; i < m; i++) {
	            scanf("%d%c%d%c", &u, &cu, &v, &cv);
	            if(cu == 'w') u <<= 1;
	            else u=(u<<1)|1;
	            if(cv == 'w') v <<= 1;
	            else v=(v<<1)|1;
	            if(u != (v ^ 1)) {
	                e.adde(u, v ^ 1);
	                e.adde(v, u ^ 1);
	            }
	        }
	        e.adde(0, 1);
	        if(!twoSat(n)) {
	            printf("bad luck\n");
	        }
	        else {
	            for(i = 1; i < n; i++) {
	                if(i > 1)printf(" ");
	                if(color[belong[i<<1]] == 1) {
	                    printf("%dh", i);
	                }
	                else printf("%dw", i);
	            }
	            printf("\n");
	        }
	    }
	    return 0;
	}
	
	/*
	2 3
	0w 1h
	1w 0h
	0h 1h
	
	10 6
	3h 7h
	5w 3w
	7h 6w
	8w 3w
	7h 3w
	2w 5h
	0 0
	*/


>	输出任意解from XMZhou


	struct Edge {
	    int v,next;
	} e[MAXE];
	int head[MAXN],num;
	void init() {
	    num = 0;
	    memset (head,-1,sizeof (head) );
	}
	void addedge (int u,int v) {
	    e[num].v = v;
	    e[num].next = head[u];
	    head[u] = num++;
	}
	int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值1~scc
	int Index,top;
	int scc;
	bool Instack[MAXN];
	void Tarjan (int u) {
	    int v;
	    Low[u] = DFN[u] = ++Index;
	    Stack[top++] = u;
	    Instack[u] = true;
	    for (int i = head[u]; i != -1; i = e[i].next) {
	        v = e[i].v;
	        if ( !DFN[v] ) {
	            Tarjan (v);
	            if (Low[u] > Low[v]) Low[u] = Low[v];
	        } else
	            if (Instack[v] && Low[u] > DFN[v]) Low[u] = DFN[v];
	    }
	    if (Low[u] == DFN[u]) {
	        scc++;
	        do {
	            v = Stack[--top];
	            Instack[v] = false;
	            Belong[v] = scc;
	        } while (v != u);
	    }
	}
	bool solvable (int n) { //n是总个数,需要选择一半
	    memset (DFN,0,sizeof (DFN) );
	    memset (Instack,false,sizeof (Instack) );
	    Index = scc = top = 0;
	    for (int i = 0; i < n; i++) if (!DFN[i]) Tarjan (i);
	    for (int i = 0; i < n; i += 2) {
	        if (Belong[i] == Belong[i^1]) return false;    //************************************************* //拓扑排序求任意一组解部分
	    }
	    return true;
	}
	queue<int>q1,q2;
	vector<vector<int> > dag;//缩点后的逆向DAG图
	char color[MAXN];//染色，为'R'是选择的
	int indeg[MAXN];//入度
	int cf[MAXN];
	void solve (int n) {
	    dag.assign (scc+1,vector<int>() );
	    memset (indeg,0,sizeof (indeg) );
	    memset (color,0,sizeof (color) );
	    for (int u = 0; u < n; u++) for (int i = head[u]; i != -1; i = e[i].next) {
	            int v = e[i].v;
	            if (Belong[u] != Belong[v]) {
	                dag[Belong[v]].push_back (Belong[u]);
	                indeg[Belong[u]]++;
	            }
	        }
	    for (int i = 0; i < n; i += 2) {
	        cf[Belong[i]] = Belong[i^1];
	        cf[Belong[i^1]] = Belong[i];
	    }
	    while (!q1.empty() ) q1.pop();
	    while (!q2.empty() ) q2.pop();
	    for (int i = 1; i <= scc; i++) if (indeg[i] == 0) q1.push (i);
	    while (!q1.empty() ) {
	        int u = q1.front();
	        q1.pop();
	        if (color[u] == 0) {
	            color[u] = 'R';
	            color[cf[u]] = 'B';
	        }
	        int siz = dag[u].size();
	        for (int i = 0; i < siz; i++) {
	            indeg[dag[u][i]]--;
	            if (indeg[dag[u][i]] == 0) q1.push (dag[u][i]);
	        }
	    }
	}
	int change (char s[]) {
	    int ret = 0;
	    int i = 0;
	    while (s[i]>='0' && s[i]<='9') {
	        ret *= 10;
	        ret += s[i]-'0';
	        i++;
	    }
	    if (s[i] == 'w') return 2*ret;
	    else return 2*ret+1;
	}
	int main() {
	    int n,m;
	    char s1[10],s2[10];
	    while (scanf ("%d%d",&n,&m) == 2) {
	        if (n == 0 && m == 0) break;
	        init();
	        while (m--) {
	            scanf ("%s%s",s1,s2);
	            int u = change (s1);
	            int v = change (s2);
	            addedge (u^1,v);
	            addedge (v^1,u);
	        }
	        addedge (1,0);
	        if (solvable (2*n) ) {
	            solve (2*n);
	            for (int i = 1; i < n; i++) { //注意这一定是判断
	                color[Belong[ if (color[Belong[2*i]] == 'R') printf ("%dw",i);
	                              else printf ("%dh",i);
	                              if (i < n-1) printf (" ");
	                              else printf ("\n");
	            }
	        } else printf ("bad luck\n");
	    }
	    return 0;
	}



>    求字典序最小的解

    也就是说，沿着一条路径，如果一个点被选择了，那么这条路径以后的点都将被选择，那么，出现不可行的情况就是，存在一个党派两个党员都被选择了，那么，我们只需要枚举一下就可以了，数据不大，答案总是可以出来的。
    这么一个简单的算法，放在第一个说，看来你已经知道它不是重点了，但是，若题目要求的是字典序最小的方案的话，那就只能选择这个算法了。

    //求字典序最小解
    struct Edge {
        int v,next;
    } e[MAXE];
    int head[MAXN],tot;
    void init() {
        tot = 0;
        memset (head,-1,sizeof (head) );
    }
    void addedge (int u,int v) {
        e[tot].v = v;
        e[tot].next = head[u];
        head[u] = tot++;
    }
    bool vis[MAXN];//染色标记，为true表示选择
    int S[MAXN],top;//栈
    bool dfs (int u) {
        if (vis[u^1]) return false;
        if (vis[u]) return true;
        vis[u] = true;
        S[top++] = u;
        for (int i = head[u]; i != -1; i = e[i].next) if (!dfs (e[i].v) ) return false;
        return true;
    }
    bool Twosat (int n) {
        memset (vis,false,sizeof (vis) );
        for (int i = 0; i < n; i += 2) {
            if (vis[i] || vis[i^1]) continue;
            top = 0;
            if (!dfs (i) ) {
                while (top) vis[S[--top]] = false;
                if (!dfs (i^1) ) return false;
            }
        }
        return true;
    }
    int main() {
        int n,m;
        int u,v;
        while (scanf ("%d%d",&n,&m) == 2) {
            init();
            30
            while (m--) {
                scanf ("%d%d",&u,&v);
                u--;
                v--;
                addedge (u,v^1);
                addedge (v,u^1);
            }
            if (Twosat (2*n) ) {
                for (int i = 0; i < 2*n; i++) if (vis[i]) printf ("%d\n",i+1);
            } else printf ("NIE\n");
        }
        return 0;
    }

