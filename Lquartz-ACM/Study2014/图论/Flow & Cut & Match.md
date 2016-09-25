

####    01. **匹配问题**  

>	匈牙利 + 贪心优化

	// O(n*m)
	// 可以处理n=3000规模
	struct enode {
	    int v, next;
	} e[Maxm];
	int last[Maxn], tot;
	int n, m, match = 0;
	int mx[Maxn], my[Maxn], dx[Maxn], dy[Maxn], dis, visit[Maxn];
	int preHungary() {
	    int res = 0, u, v;
	    for (int i = 0; i < n; i++) {
	        u = i;
	        for (int j = last[i]; -1 != j; j = e[j].next) {
	            v = e[j].v;
	            if (-1 == my[v]) {
	                mx[u] = v;
	                my[v] = u;
	                res++;
	                break;
	            }
	        }
	    }
	    return res;
	}
	
	bool dfs (int u) {
	    int v;
	    for (int j = last[u]; -1 != j; j = e[j].next) {
	        v = e[j].v;
	        if (visit[v]) continue;
	        visit[v] = true;
	        if (-1 == my[v] || dfs (my[v]) ) {
	            my[v] = u;
	            mx[u] = v;
	            return true;
	        }
	    }
	    return false;
	}
	
	int solve() {
	    match = 0;
	    for (int i = 0; i < n; i++) mx[i] = -1;
	    for (int j = n; j < n + m; j++) my[j] = -1;
	    match += preHungary();
	    for (int i = 1; i <= n; i++) {
	        if (-1 == mx[i]) {
	            for (int j = n; j < n + m; j++) visit[j] = false;
	            if (dfs (i) ) match++;
	        }
	    }
	    return match;
	}


>	HK

	验题: HDU 2389  spoj 4206(n=50000,m=150000)

	/*
	 *  HK O(E*V^0.5) 最大匹配
	 *  左半图 0~n-1
	 *  右半图 n~n+m-1
	 */
	struct edgenode {
		int v, next;
	}e[Maxm];
	int last[Maxn], tot;
	int n, m, match = 0;
	int mx[Maxn], my[Maxn], dx[Maxn], dy[Maxn], dis, visit[Maxn];
	queue<int> Q;
	int ux[Maxn], uy[Maxn], px[Maxn], py[Maxn], pv[Maxn];
	
	void adde(int u, int v) {
	    e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
	}
	bool searchPath()
	{
	    int i, j;
		dis = MOD;
		for(i = 0; i < n; i++) dx[i] = -1;
		for(j = n; j < n + m; j++) dy[j] = -1;
		while(!Q.empty()) Q.pop();
		for(int i = 0; i < n; i++)
			if(-1 == mx[i]) Q.push(i);
		int u, v;
		while(!Q.empty())
		{
			u = Q.front(); Q.pop();
			if(dx[u] > dis) break;
			for(int j = last[u]; j != -1; j = e[j].next)
			{
				v = e[j].v;
				if(-1 != dy[v]) continue;
				dy[v] = dx[u] + 1;
				if(-1 == my[v])
					dis = dy[v];
				else
				{
					dx[my[v]] = dy[v] + 1;
					Q.push(my[v]);
				}
			}
		}
		return dis != MOD;
	}
	
	bool dfs(int u)
	{
		int v;
		for(int j = last[u]; j != -1; j = e[j].next)
		{
			v = e[j].v;
			if(visit[v] || dx[u] + 1 != dy[v]) continue;
			if(dy[v] == dis && my[v] != -1) continue;
			visit[v] = true;
			if(-1 == my[v] || dfs(my[v]))
			{
				my[v] = u;
				mx[u] = v;
				return true;
			}
		}
		return false;
	}
	
	int solve()
	{
	    int i, j;
		match = 0;
		for(i = 0; i < n; i++) mx[i] = -1;
		for(j = n; j < n + m; j++) my[j] = -1;
	//	match += preHungary();
		while(searchPath())
		{
			for(j = n; j < n + m; j++) visit[j] = false;
			for(int i = 0; i < n; i++)
				if(-1 == mx[i] && dfs(i)) match++;
		}
		return match;
	}

>   稳定婚姻问题

	延迟认可算法(Gale-Shapley算法)

	int mx[Maxn], my[Maxm]; //x匹配的y, y匹配的x
	//yorder表示在x眼中y的顺序, 0~m-1为喜爱度递减的y的编号
	//xorder表示在y眼中x的顺序, 0~n-1为编号0~n-1的x的重要度
	//越重要, 值越小
	int yorder[Maxn][Maxm], xorder[Maxm][Maxn];
	int cur[Maxn];
	int n, m;
	queue<int> que;
	void GaleShapley() {
	    int i, j, v;
	    for(i = 0; i <= n; i++) mx[i] = -1,cur[i] = 0;//初始化
	    for(j = 0; j <= m; j++) my[j] = -1;
	    while(!que.empty()) que.pop();
	    for(i = 0; i < n; i++) que.push(i);//将x加入队列
	    while(!que.empty()) {//x还有没找到朋友的
	        i = que.front(); que.pop();
	        if(cur[i] >= m) continue;
	        v = yorder[i][cur[i]++];
	        if(my[v] == -1) {   //y没有匹配
	            mx[i] = v; my[v] = i;
	        }
	        else if(xorder[v][i] < xorder[v][my[v]]) {//i比之前的好
	            mx[my[v]] = -1;
	            que.push(my[v]);
	            my[v] = i; mx[i] = v;
	        }
	        else {//i比以前的差, i找下一个y
	            que.push(i);
	        }
	    }
	}	

>   带花树

	模板题 验题: ZOJ 3316

	int n, head, tail, Start, Finish;
	int match[Maxn];    //表示哪个点匹配了哪个点
	int father[Maxn];   //这个是增广路径的father
	int base[Maxn];     //该点属于哪朵花
	int Q[Maxn];
	bool mark[Maxn], mp[Maxn][Maxn], InBlossom[Maxn], inqueue[Maxn]; //mp[][]邻接关系
	
	void BlossomContract(int x, int y) {
	    memset(mark, false, sizeof(mark));
	    memset(InBlossom, false, sizeof(InBlossom));
	#define pre father[match[i]]
	    int lca, i;
	    for( i = x; i; i = pre) {
	        i = base[i];
	        mark[i] = true;
	    }
	    for(i = y; i; i = pre) {
	        i = base[i];        //寻找lca之旅……一定要注意i=base[i]
	        if(mark[i]) {
	            lca = i;
	            break;
	        }
	    }
	    for(i = x; base[i] != lca; i = pre) {
	        if(base[pre] != lca) father[pre] = match[i]; //对于BFS树中的父边是匹配边的点，
	                                                     //father向后跳
	        InBlossom[base[i]] = true;
	        InBlossom[base[match[i]]] = true;
	    }
	    for(i = y; base[i] != lca; i = pre) {
	        if(base[pre] != lca) father[pre] = match[i]; // 同理
	        InBlossom[base[i]] = true;
	        InBlossom[base[match[i]]] = true;
	    }
	#undef pre
	    if(base[x] != lca) father[x] = y;       //注意不能从lca这个奇环的关键点跳回来
	    if(base[y] != lca) father[y] = x;
	    for(i = 1; i <= n; i++) {
	        if(InBlossom[base[i]]) {
	            base[i] = lca;
	            if(!inqueue[i]) {
	                Q[tail++] = i;
	                inqueue[i] = true;          //要注意如果本来连向BFS树中父结点的边是非匹配边的点，
	                                            //可能是没有入队的
	            }
	        }
	    }
	}
	
	void Change() {
	    int x, y, z;
	    z = Finish;
	    while(z) {
	        y = father[z];
	        x = match[y];
	        match[y] = z;
	        match[z] = y;
	        z = x;
	    }
	}
	
	void FindAugmentPath() {
	    int i;
	    memset(father, 0, sizeof(father));
	    memset(inqueue, false, sizeof(inqueue));
	    for(i = 1; i <= n; i++) base[i] = i;
	    head = tail = 0;
	    Q[tail++] = Start;
	    inqueue[Start] = 1;
	    while(head < tail) {
	        int x = Q[head++];
	        for(int y = 1; y <= n; y++) {
	            if(mp[x][y] && base[x] != base[y] && match[x] != y) {    //无意义的边
	                if(Start == y || match[y] && father[match[y]]) {        //精髓地用father表示该点是否
	                    BlossomContract(x, y);
	                }
	                else if(!father[y]) {
	                    father[y] = x;
	                    if(match[y]) {
	                        Q[tail++] = match[y];
	                        inqueue[match[y]] = true;
	                    }
	                    else {
	                        Finish = y;
	                        Change();
	                        return;
	                    }
	                }
	            }
	        }
	    }
	}
	
	void Edmonds() {
	    memset(match, 0, sizeof(match));
	    for(Start = 1; Start <= n; Start++) {
	        if(match[Start] == 0) {
	            FindAugmentPath();
	        }
	    }
	}
	
	void output() {
	    memset(mark, false, sizeof(mark));
	    int i, cnt = 0;
	    for(i = 1; i <= n; i++) {
	        if(match[i]) cnt++;         //计算N个点中匹配好的点数
	    }
	//    printf("%d\n", cnt);          //输出匹配关系
	//    for(int i = 1; i <= n; i++) {
	//        if(!mark[i] && match[i]) {
	//            mark[i] = true;
	//            mark[match[i]] = true;
	//            printf("%d %d\n", i, match[i]);
	//        }
	//    }
	    if(cnt < n) {
	        printf("NO\n");
	    }
	    else {
	        printf("YES\n");
	    }
	}




>	一般图最小权匹配   

	可将求一般图最小权完美匹配的问题转化为求最大权完美匹配的问题，在杜端甫编著的《运筹图论》和龚劬编的《图论与网络最优化算法》中均介绍了求一般图最大权完美匹配的算法，可参考。

####    02. **最大流**

>	EK 

	//EK O(n*m^2)
	//每次找最短路, 直接调整流量

>   Dinic 

    //dinic O(m*n^2)
    const int MOD = 1000000007;
    #define Maxn 10000
    #define Maxm 100000
    struct node {
	    int u, v, c, next;
	}e[Maxm];
	int tot, last[Maxn];
	int cur[Maxn], dist[Maxn], que[Maxn], sta[Maxn], top, head, tail;
    
    void adde(int u, int v, int c, int c1) {
	    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
	    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
	}
	
	bool bfs(int s, int t, int n) {
	    int i, j, u, v;
	    for(i = 0; i < n; i++) dist[i] = MOD;
	    dist[s] = 0;
	    head = tail = 0;
	    que[tail++] = s;
	    while(head < tail) {
	        u = que[head++];
	        for(j = last[u]; j != -1; j = e[j].next) {
	            if(e[j].c == 0) continue;
	            v = e[j].v;
	            if(dist[v] > dist[u] + 1) {
	                dist[v] = dist[u] + 1;
	                if(v == t) return true;
	                que[tail++] = v;
	            }
	        }
	    }
	    return false;
	}
	
	int dinic(int s, int t, int n) {
	    int i, j, u, v;
	    int maxflow = 0;
	    while(bfs(s, t, n)) {
	        for(i = 0; i < n; i++) cur[i] = last[i];
	        u = s; top = 0;
	        while(cur[s] != -1) {
	            if(u == t) {
	                int tp = MOD;
	                for(i = top - 1; i >= 0; i--) {
	                    tp = min(tp, e[sta[i]].c);
	                }
	                maxflow += tp;
	                for(i = top - 1; i >= 0; i--) {
	                    e[sta[i]].c -= tp;
	                    e[sta[i] ^ 1].c += tp;
	                    if(e[sta[i]].c == 0) top = i;
	                }
	                u = e[sta[top]].u;
	            }
	            else if(cur[u] != -1 && e[cur[u]].c > 0 && dist[u] + 1 == dist[e[cur[u]].v]) {
	                sta[top++] = cur[u];
	                u = e[cur[u]].v;
	            }
	            else {
	                while(u != s && cur[u] == -1) {
	                    u = e[sta[--top]].u;
	                }
	                cur[u] = e[cur[u]].next;
	            }
	        }
	    }
	    return maxflow;
	}

	**“有提交就会有奇迹”的dinic**  
	dinic是有技巧的，以下是我喜欢的19行版dinic (by 雁过留声) 

	//这是数组以及结构定义，不计算行数
	int level[NMax+2],queue[NMax+2];
	long long Min(long long a,long long b){
		return a>b?b:a;
	}
	struct edge{
		long long e,f;
		edge *next,*opt;
	}*E[NMax];
	
	//正文
	int mkLevel(){
		for (int i=0;i<N;i++)level[i]=-1;
		int bot,x;
		level[queue[0]=0]=0;bot=1;
		for (int top=0;top<bot;top++){x=queue[top];
			for (edge *p=E[x];p;p=p->next)if (p->f && level[p->e]==-1)
				level[queue[bot++]=p->e]=level[x]+1;
		}
		return level[N-1]!=-1;
	}
	long long extend(int x,long long alpha){
		if (x==N-1)return alpha;
		long long r,t;r=0;
		for (edge *p=E[x];p;p=p->next)if (p->f && level[p->e]==level[x]+1)
			t=extend(p->e,Min(p->f,alpha-r)),p->f-=t,p->opt->f+=t,r+=t;
		if (!r)level[x]=-1;
		return r;
	}
	void Dinic(){while (mkLevel())extend(0,(long long)1<<60);}

>   ISAP

	//ISAP O(m*n^2)
	struct node {
	    int u, v, c, next;
	}e[Maxm];
	int tot, last[Maxn];
	void adde(int u, int v, int c, int c1) {
	    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
	    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
	}
	
	int dist[Maxn], cur[Maxn], gap[Maxn], pre[Maxn];
	int ISAP(int s, int t, int n) {
	    int i, j, u, v, det;
	    int maxflow = 0;
	    memset(dist, 0, sizeof(dist[0]) * (n + 3));
	    memset(gap, 0, sizeof(gap[0]) * (n + 3));
	    for (i = 0; i < n; i ++ )
	        cur[i] = last[i];
	    u = s;
	    gap[0] = n;
		pre[s] = -1;
	    while (dist[s] <= n) {
	        bool flag = false;
	        for (j = cur[u]; j != -1; j = e[j].next) {
	            v = e[j].v;
	            if (e[j].c > 0 && dist[u] == dist[v] + 1) {
	                flag = true;
	                pre[v] = u;
	                cur[u] = j;
	                u = v;
	                break;
	            }
	        }
	        if (flag) {
	            if (u == t) {
	                int det = MOD;
	                for (i = u; i != s; i = pre[i])
	                    det = min(det, e[cur[pre[i]]].c);
	                for (i = u; i != s; i = pre[i]) {
	                    e[cur[pre[i]]].c -= det;
	                    e[cur[pre[i]] ^ 1].c += det;
	                }
	                maxflow += det;
	                u = s;
	            }
	        }
	        else {
	            int mind = n;
	            for (j = last[u]; j != -1; j = e[j].next ) {
	                v = e[j].v;
	                if (e[j].c > 0 && dist[v] < mind) {
	                    mind = dist[v];
	                    cur[u] = j;
	                }
	            }
	            if (( -- gap[dist[u]]) == 0) break;
	            gap[dist[u] = mind + 1] ++ ;
	            if (u != s) u = pre[u];
	        }
	    }
	    return maxflow;
	}

>	平面图最小割转最短路




####    03. **费用流**  

>	spfa

	验题: 3680  

	struct node {
	    int u, v, next;
	    LL c, w;
	}e[Maxm];
	int tot, last[Maxn];
	LL dist[Maxn];
	LL cost, flow;
	int pre[Maxn];
	bool visit[Maxn];
	queue<int> Q;
	void adde(int u, int v, LL c, LL w){
	    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
	    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
	}
	bool spfa(int s, int t, int n) {
	    int i;
	    for(i = 0; i <= n; i++) {
	        dist[i] = MOD;
	        visit[i] = 0;
	        pre[i] = -1;
	    }
	    while(!Q.empty()) Q.pop();
	    Q.push(s);
	    visit[s] = true;
	    dist[s] = 0;
	    pre[s] = -1;
	    while(!Q.empty()) {
	        int u = Q.front();
	        visit[u] = false;
	        Q.pop();
	        for(int j = last[u]; j != -1; j = e[j].next) {
	            if(e[j].c > 0 && dist[u] + e[j].w < dist[e[j].v]) {
	                dist[e[j].v] = dist[u] + e[j].w;
	                pre[e[j].v] = j;
	                if(!visit[e[j].v]) {
	                    Q.push(e[j].v);
	                    visit[e[j].v] = true;
	                }
	            }
	        }
	    }
	    if(dist[t] == MOD) return false;
	    else return true;
	}
	LL ChangeFlow(int t) {
	    LL det = MOD;
	    int u = t;
	    while(~pre[u]) {
	        u = pre[u];
	        det = min(det, e[u].c);
	        u = e[u].u;
	    }
	    u = t;
	    while(~pre[u]) {
	        u = pre[u];
	        e[u].c -= det;
	        e[u ^ 1].c += det;
	        u = e[u].u;
	    }
	    return det;
	}
	LL MinCostFlow(int s, int t, int n) {
	    LL mincost, maxflow;
	    mincost = maxflow = 0;
	    while(spfa(s, t, n)) {
	        LL det = ChangeFlow(t);
	        mincost += det * dist[t];
	        maxflow += det;
	    }
	    cost = mincost;
	    flow = maxflow;
	    return mincost;
	}

>	zkw
	
	验题: 3680  

>>	朴素zkw(存在bug)
		
	//没有优化, 但是存在找到第一条可行流而计算不到费用的情况
	//不可以用了!!!
	#define MOD 0x3f3f3f3f
	int flow, cost, value;
	int dist[Maxn], visit[Maxn], src, des;
	deque<int> Q;

	void adde(int u, int v, int c, int w) {
	    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
	    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
	}

	int Aug(int u, int m) {
	    if(u == des) {
	        cost += value * m;
	        flow += m;
	        return m;
	    }
	    visit[u] = true;
	    int l = m;
	    int j, v, c, w;
	    for(j = last[u]; j != -1; j = e[j].next) {
	        v = e[j].v; c = e[j].c; w = e[j].w;
	        if(c && !w && !visit[v]) {
	            int del = Aug(v, l < c ? l : c);
	            e[j].c -= del; e[j ^ 1].c += del; l -= del;
	            if(!l) return m;
	        }
	    }
	    return m - l;
	}
	 
	 
	bool Modlabel(int src, int des, int n) {
	    int i, j, u, v, c, w, del;
	    del = MOD;
	    for(i = 0; i < n; i++) {
	        if(visit[i]) {
	            for(j = last[i]; j != -1; j = e[j].next) {
	                if(e[j].c && !visit[e[j].v] && e[j].w < del) del = e[j].w;
	            }
	        }
	    }
	    if(del == MOD) return false;
	    for(i = 0; i < n; i++) {
	        if(visit[i]) {
	            for(j = last[i]; j != -1; j = e[j].next) {
	                e[j].w -= del; e[j ^ 1].w += del;
	            }
	        }
	    }
	    value += dist[des];
	    return true;
	}
	 
	void zkw(int src, int des, int n) {
	    value = cost = flow = 0;
	   do {
	       do {
	            memset(visit, 0, sizeof(visit[0]) * (n + 3));
	       }while(Aug(src, MOD));
	   }while(Modlabel(src, des, n));
	}
	  
>>	zkw+deque

	#define MOD 0x3f3f3f3f
	int flow, cost, value;
	int dist[Maxn], visit[Maxn], src, des;
	deque<int> Q;

	void adde(int u, int v, int c, int w) {
	    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
	    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
	}

	int Aug(int u, int m) {
	    if(u == des) {
	        cost += value * m;
	        flow += m;
	        return m;
	    }
	    visit[u] = true;
	    int l = m;
	    int j, v, c, w;
	    for(j = last[u]; j != -1; j = e[j].next) {
	        v = e[j].v; c = e[j].c; w = e[j].w;
	        if(c && !w && !visit[v]) {
	            int del = Aug(v, l < c ? l : c);
	            e[j].c -= del; e[j ^ 1].c += del; l -= del;
	            if(!l) return m;
	        }
	    }
	    return m - l;
	}
	 
	bool Modlabel(int src, int des, int n) {
	    int i, j, u, v, c, w, del;
	    memset(dist, 0x3f, sizeof(dist[0])*(n + 3));
	    dist[src] = 0;
	    while(!Q.empty()) Q.pop_back();
	    Q.push_back(src);
	    while(!Q.empty()) {
	        u = Q.front(); Q.pop_front();
	        for(j = last[u]; j != -1; j = e[j].next) {
	            v = e[j].v; c = e[j].c; w = e[j].w;
	            if(c && (del = dist[u] + w) < dist[v]) {
	                dist[v] = del;
	                if(Q.empty() || del <= dist[Q.front()]) {
	                    Q.push_front(v);
	                }
	                else {
	                    Q.push_back(v);
	                }
	            }
	        }
	    }
	    for(i = 0; i < n; i++) {
	        for(j = last[i]; j != -1; j = e[j].next) {
	            e[j].w -= dist[e[j].v] - dist[i];
	        }
	    }
	    value += dist[des];
	    return dist[des] < MOD;
	}
	 
	void zkw(int src, int des, int n) {
	    value = cost = flow = 0;
	   while(Modlabel(src, des, n)){
	       do {
	            memset(visit, 0, sizeof(visit[0]) * (n + 3));
	       }while(Aug(src, MOD));
	   }
	}
		
>>	zkw+priority_queue

	#define MOD 0x3f3f3f3f
	int flow, cost, value;
	int dist[Maxn], visit[Maxn], src, des;
	priority_queue<pair<int, int> > Q;

	void adde(int u, int v, int c, int w) {
	    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
	    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
	}

	int Aug(int u, int m) {
	    if(u == des) {
	        cost += value * m;
	        flow += m;
	        return m;
	    }
	    visit[u] = true;
	    int l = m;
	    int j, v, c, w;
	    for(j = last[u]; j != -1; j = e[j].next) {
	        v = e[j].v; c = e[j].c; w = e[j].w;
	        if(c && !w && !visit[v]) {
	            int del = Aug(v, l < c ? l : c);
	            e[j].c -= del; e[j ^ 1].c += del; l -= del;
	            if(!l) return m;
	        }
	    }
	    return m - l;
	}
	 
	bool Modlabel(int src, int des, int n) {
	    int i, j, u, v, c, w, del, d;
	    memset(dist, 0x3f, sizeof(dist[0])*(n + 3));
	    dist[src] = 0;
	    while(!Q.empty()) Q.pop();
	    Q.push(MP(0, src));
	    while(!Q.empty()) {
	        u = Q.top().BB;
	        d = -Q.top().AA;
	        Q.pop();
	        if(d != dist[u]) continue;
	        for(j = last[u]; j != -1; j = e[j].next) {
	            v = e[j].v; c = e[j].c; w = e[j].w;
	            if(c && (del = d + w) < dist[v]) {
	                dist[v] = del;
	                Q.push(MP(-del, v));
	            }
	        }
	    }
	    for(i = 0; i < n; i++) {
	        for(j = last[i]; j != -1; j = e[j].next) {
	            e[j].w -= dist[e[j].v] - dist[i];
	        }
	    }
	    value += dist[des];
	    return dist[des] < MOD;
	}
	 
	void zkw(int src, int des, int n) {
	    value = cost = flow = 0;
	   while(Modlabel(src, des, n)){
	       do {
	            memset(visit, 0, sizeof(visit[0]) * (n + 3));
	       }while(Aug(src, MOD));
	   }
	}

>>	zkw+queue

	//zkw queue实现
	#define MOD 0x3f3f3f3f
	int flow, cost, value;
	int dist[Maxn], visit[Maxn], src, des;
	queue<int> Q;

	void adde(int u, int v, int c, int w) {
	    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
	    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
	}

	int Aug(int u, int m) {
	    if(u == des) {
	        cost += value * m;
	        flow += m;
	        return m;
	    }
	    visit[u] = true;
	    int l = m;
	    int j, v, c, w;
	    for(j = last[u]; j != -1; j = e[j].next) {
	        v = e[j].v; c = e[j].c; w = e[j].w;
	        if(c && !w && !visit[v]) {
	            int del = Aug(v, l < c ? l : c);
	            e[j].c -= del; e[j ^ 1].c += del; l -= del;
	            if(!l) return m;
	        }
	    }
	    return m - l;
	}
	 
	bool Modlabel(int src, int des, int n) {
	    int i, j, u, v, c, w, del;
	    memset(dist, 0x3f, sizeof(dist[0])*(n + 3));
	    dist[src] = 0;
	    while(!Q.empty()) Q.pop();
	    Q.push(src);
	    while(!Q.empty()) {
	        u = Q.front(); Q.pop();
	        for(j = last[u]; j != -1; j = e[j].next) {
	            v = e[j].v; c = e[j].c; w = e[j].w;
	            if(c && (del = dist[u] + w) < dist[v]) {
	                dist[v] = del;
	                Q.push(v);
	            }
	        }
	    }
	    for(i = 0; i < n; i++) {
	        for(j = last[i]; j != -1; j = e[j].next) {
	            e[j].w -= dist[e[j].v] - dist[i];
	        }
	    }
	    value += dist[des];
	    return dist[des] < MOD;
	}
	 
	void zkw(int src, int des, int n) {
	    value = cost = flow = 0;
	    while(Modlabel(src, des, n)) {
	        do {
	            memset(visit, 0, sizeof(visit[0]) * (n + 3));
	        } while(Aug(src, MOD));
	    }
	}

>>	对于poj3680效率比较:
		
	nocow上zkw板块的作者代码可以达到360ms
	
	最快是 zkw + deque 860ms
	
	其次是 zkw + priority_queue 1250ms
	
	然后是 zkw + queue 2094ms
	
	对于普通spfa 2407ms
	
	另外, 手写que需要注意, 一个点可能入队不止一次.

####    04. *全局最小割*  

>   StoerWagner(求全局最小割)

    验题:POJ2914
    //朴素最小割
    //注意节点下标0~n-1
    int comb[Maxn];
    int edge[Maxn][Maxn], g[Maxn][Maxn], node[Maxn];
    int S, T, minCut;
    int top, sta[Maxn];
    int maxi;
    vector<int> parta, partb;
    vector<int> belong[Maxn];
    
    int Search (int n) {
        int i, j, u;
        int vis[Maxn], wet[Maxn];
        memset(vis, 0, sizeof(vis)); 
        memset(wet, 0, sizeof(wet));
        int minCut = 0, temp = -1, top = 0;
        int maxi;
        S = -1, T = -1;
        for (i=0; i< n; i++) {
            maxi = -MOD;
            for (j = 0; j < n; j++) {
                u = node[j];
                if (!comb[u] && !vis[u] && wet[u] > maxi) {
                    temp = u;
                    maxi = wet[u];
                }
            }
            sta[top++] = temp;
            vis[temp] = true;
            if (i == n - 1)
                minCut = maxi;
            for (j = 0; j < n; j++) {
                u = node[j];
                if (!comb[u] && !vis[u]) {
                    wet[u] += edge[temp][u];
                }
            }
        }
        S = sta[top - 2];
        T = sta[top - 1];
        for (i = 0; i < top; i++)  node[i] = sta[i];
        return minCut;
    }
    
    int StoerWagner (int n) {
        int ans = MOD, i, j, cur;
        memset(comb, 0, sizeof(comb));
        for (i = 0; i < n; i++)
            node[i] = i;
        for (i = 1; i < n; i++) {
            k = n - i + 1;
            cur = Search (k);
            if (cur < ans) {
                ans = cur;
            }
            if (ans == 0) return ans;
            comb[T] = true;
            for (j = 0; j < n; j++) {
                if (j == S) continue;
                if (!comb[j]) {
                    edge[S][j] += edge[T][j];
                    edge[j][S] += edge[j][T];
                }
            }
        }
        return ans;
    }
    int n, m;
    int main() {
        int i, j, u, v, w;
        while (scanf ("%d%d", &n, &m) != EOF) {
            memset(edge, 0, sizeof(edge));
            for (int i = 0; i < m; i++) {
                int u, v, z;
                scanf ("%d%d%d", &u, &v, &z);
                edge[u][v] += z;
                edge[v][u] += z;
            }
            printf ("%d\n", StoerWagner (n) );
        }
        return 0;
    }

>   K连通块计数

    HDU 4654
    
    int n, m, k;
    //K连通块计数
    //注意节点下标0~n-1
    int comb[Maxn];
    int edge[Maxn][Maxn], g[Maxn][Maxn], node[Maxn];
    int S, T, minCut;
    int top, sta[Maxn];
    int maxi;
    vector<int> parta, partb;
    vector<int> belong[Maxn];
    
    int Search (int n) {
        int i, j, u;
        int vis[Maxn], wet[Maxn];
        memset(vis, 0, sizeof(vis)); 
        memset(wet, 0, sizeof(wet));
        int minCut = 0, temp = -1, top = 0;
        int maxi;
        S = -1, T = -1;
        for (i=0; i< n; i++) {
            maxi = -MOD;
            for (j = 0; j < n; j++) {
                u = node[j];
                if (!comb[u] && !vis[u] && wet[u] > maxi) {
                    temp = u;
                    maxi = wet[u];
                }
            }
            sta[top++] = temp;
            vis[temp] = true;
            if (i == n - 1)
                minCut = maxi;
            for (j = 0; j < n; j++) {
                u = node[j];
                if (!comb[u] && !vis[u]) {
                    wet[u] += edge[temp][u];
                }
            }
        }
        S = sta[top - 2];
        T = sta[top - 1];
        for (i = 0; i < top; i++)  node[i] = sta[i];
        return minCut;
    }
    
    int StoerWagner (vector<int> & li) {
        int ans = MOD, i, j, k,cur, n = li.SZ, u, v;
        int used[Maxn];
        memset(comb, 0, sizeof(comb));
        for (i = 0; i < n; i++) {
            node[i] = i;
            belong[i].clear();
            belong[i].PB(i);
        }
        for (i = 1; i < n; i++) {
            k = n - i + 1;
            cur = Search(k);
            if (cur < ans) {
                ans = cur;
                for(j = 0; j < n; j++) used[j] = 0;
                for(j = 0; j < belong[T].SZ; j++) {
                    used[belong[T][j]] = 1;
                }
            }
            for(j = 0; j < belong[T].SZ; j++) belong[S].PB(belong[T][j]);
            if (ans == 0) break;
            comb[T] = true;
            for (j = 0; j < n; j++) {
                if (j == S) continue;
                if (!comb[j]) {
                    edge[S][j] += edge[T][j];
                    edge[j][S] += edge[j][T];
                }
            }
        }
        parta.clear(); partb.clear();
        for(j = 0; j < n; j++) {
            if(used[j]) parta.PB(li[j]);
            else partb.PB(li[j]);
        }
        return ans;
    }
    int dfs(vector<int> &li) {
        int n = li.SZ, i, j;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                edge[i][j] = g[li[i]][li[j]];
            }
        }
        int cur = StoerWagner(li);
        if(cur >= k) return 1;
        vector<int> a(parta), b(partb);
        return dfs(a) + dfs(b);
    }
    int main() {
        int i, j, u, v, w;
        while (scanf ("%d%d%d", &n, &m, &k) != EOF) {
            memset(g, 0, sizeof(g));
            for (int i = 0; i < m; i++) {
                scanf ("%d%d", &u, &v);
                u--; v--;
                g[u][v] += 1;
                g[v][u] += 1;
            }
            vector<int> li;
            for(i = 0; i < n; i++) li.PB(i);
            printf ("%d\n", dfs(li));
        }
        return 0;
    }


####    05. **网络流拓展**  

>   常见建图方式
    
    B[u,v]表示(u,v)流量的下限，C[u,v]表示(u,v)流量的上限, F[u,v]表示(u,v)的流量,
    g[u,v]表示F[u,v]-B[u,v] 显然 0<=g[u,v]<=C[u,v]-B[u,v] 
      
    1.无源汇的可行流 :
    我们要想办法转换为有源汇的最大流问题.
    考虑流量都为g[,]且容量为C[,]-B[,]的网络，貌似有点接近最后的转换方式了，
    为了不忽略B[,]这一条件，我们把g[,]最后强制加上B[,].
    但会发现一个致命漏洞，加上后就未必满足流量平衡了！
    对于这个有两种办法解决..
    一种方法是 添加附加源汇S,T  对于某点 u, 设 M(u)=sigma(B[i,u])-sigma(B[u,j]) ，
                       则根据流量平衡条件有 M(u)同时等于 sigma(g[u,j])-sigma(g[i,u])
                       若M(u)<0，即sigma(g[u,j]) < sigma(g[i,u]) 进入u的流量比从u 出去的多，
                                         所以 u -> T 连容量为  -(sigma(B[i,u])-sigma(B[u,j]) ) 的边
                      同理. M(u)>0时，即 S->u 连容量为 sigma(B[i,u])-sigma(B[u,j])  的边.
                      然后再 对于任意边(i,u)/(u,j) 连一条 C[u,v]-B[u,v]的边.
                      这样 只需对新的网络求一遍最大流即可. 若出附加源点的边都满流即是存在可行流，反之不然.
                      满流的必要条件是显然的. 不满流不能保证加上B[,]后流量平衡. 前面都白费了.
    另一种方法相对简单.其实类似，本质相同.
                    仍添加附加源汇S,T 对于某边 (u,v) 在新网络中连边
                    S->v 容量 B[u,v]   ,  u->T 容量 B[u,v]  ， u->v 容量 C[u,v]-B[u,v]
                    可以这样理解，边S->v : 求的时候直接从S流过来的流量值B[u,v], 与最终解中边(u,v)强制加上的从 u流过来的流量B[u,v]，对v点的流量平衡条件的影响 实质等价.
                   边u->T同理.
                   最后，一样也是求一下新网络的最大流，判断从附加源点的边，是否都满流即可.
      
    具体的解？根据最前面提出的强制转换方式，边(u,v)的最终解中的实际流量即为g[u,v]+B[u,v]
    为什么这种方法只适用于无源汇上下界可行流？
    本质上是因为S,T并不满足流量平衡，而上述的方法都是考虑到每点的流量平衡而建的. 但有些时候貌似还是可以出正确解. 至于有没有什么解决方法，下次再想想吧~【标记下】
    例题 ZOJ 2314 / SGU 194 Reactor Cooling http://acm.sgu.ru/problem.php?contest=0&problem=194
    2.有源汇的上下界可行流
    从汇点到源点连一条上限为INF，下限为0的边. 按照 1.无源汇的上下界可行流 一样做即可.
    改成无源汇后，求的可行流是类似环的，流量即T->S边上的流量.  这样做显然使S,T也变得流量平衡了.
    3.有源汇的上下界最大流
    方法一 ： 2.有源汇上下界可行流中，从汇点到源点的边改为连一条上限为INF，下限为x的边.
    因为显然x>ans即MIN(T->S )> MAX(S->T) ,会使求新网络的无源汇可行流无解的（S,T流量怎样都不能平衡）
    而x<=ans会有解.
    所以满足二分性质，二分x，最大的x使得新网络有解的即是所求答案原图最大流.
    方法二：从汇点T到源点S连一条上限为INF，下限为0的边，变成无源汇的网络.  照求无源汇可行流的方法(如1)，建附加源点S'与汇点T'，求一遍S'->T‘的最大流. 再把从汇点T到源点S的这条边拆掉 . 求一次从S 到T 的最大流即可. （关于S',T'的边好像可以不拆？）（这样一定满足流量平衡？）表示这方法我也没有怎么理解.
    4.有源汇的上下界最小流
    方法一： 2.有源汇上下界可行流中，从汇点到源点的边改为连一条上限为x，下限为0的边.
    与3同理，二分上限，最小的x使新网络无源汇可行流有解，即是所求答案原图最小流.
    方法二:  照求无源汇可行流的方法(如1)，建附加源点S'与汇点T'，求一遍S'->T‘的最大流. 但是注意这一遍不加汇点到源点的这条边，即不使之改为无源汇的网络去求解. 求完后，再加上那条汇点到源点上限INF的边. 因为这条边下限为0，所以S',T'无影响. 再直接求一遍S'->T'的最大流. 若S’出去的边全满流，T->S边上的流量即为答案原图最小流，否则若不全满流即无解.
     和求3.有源汇的上下界最大流过程相反，感性理解是: 
    首先明确，我们的方法是通过加边转化成对任一点都有流量平衡的无源汇的网络，进行求解.
    即最终解只能是加上边后，求的无源汇可行流，即T->S这边上的流量.  不改成无源汇的直接求的解是未必正确的，在（1）中已经提到.
    然后，因为第一遍做的时候并无这条边，所以S->T的流量在第一遍做的时候都已经尽力往其他边流了. 于是加上T->S这条边后，都是些剩余的流不到其他边的流量. 从而达到尽可能减少T->S这边上的流量的效果，即减小了最终答案.
    感觉上第一遍做的既然是不改成无源汇直接求的，应该是错误的？
    这里不是错误的. 首先我们的解都是按照第二遍所求的而定，其次这里这样做本质是延迟对T->S这条边的增流.



####    06. **分数规划**  

> todo

	POJ2728, 2976, 3155, 3621 ZOJ2676


