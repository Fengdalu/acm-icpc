
####	01. **Maxn速查表**

>	2^i

	11   2048
	12   4096
	13   8192
	14   16384
	15   32768
	16   65536
	17   131072
	18   262144
	19   524288
	20   1048576
	21   2097152
	22   4194304
	23   8388608
	24   16777216
	25   33554432
	26   67108864
	27   134217728
	28   268435456
	29   536870912

####	02. **基础图**

>	图struct

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

>   n条边的带一个环树森林

    struct CirGraph {
        struct node {
            //onCir==0 不在环上, ==1在环上
            int u, v, l, onCir, next;
        } adj[Maxm];
        int tot, last[Maxn];
        //vis==0未遍历, ==1遍历不是环上, ==2在环上
        int top, vis[Maxn], sta[Maxn];
        void adde(int u, int v, int l) {
            adj[tot].u = u; adj[tot].v = v; adj[tot].l = l; adj[tot].onCir = 0;
            adj[tot].next = last[u]; last[u] = tot++;
        }
        void init(int n) {
            tot = 0;
            for(int i = 0; i <= n; i++) last[i] = -1;
        }
        void dfs(int u, int from) {
            int j, v;
            vis[u] = 1;
            for(j = last[u]; j != -1; j = adj[j].next) {
                if(j == from) continue;
                v = adj[j].v;
                if(!vis[v]) {
                    sta[++top] = j;
                    dfs(v, j ^ 1);
                    top--;
                }
                else if(vis[v] == 1 && vis[u] == 1){
                    int tp = top, jj;
                    sta[++tp] = j;
                    while(tp) {
                        jj = sta[tp--];
                        adj[jj].onCir = adj[jj ^ 1].onCir = 1;
                        vis[adj[jj].u] = 2;
                        if(adj[jj].u == v) break;
                    }
                }
            }
        }
        void ready(int n) {
            int i, j;
            for(i = 0; i <= n; i++) vis[i] = 0;
            for(i = 1; i <= n; i++) {
                if(!vis[i]) {
                    top = 0;
                    dfs(i, -1);
                }
            }
        }
    }gg;

>   完整版

    set<LL> Hset;
    int S[Maxn<<1|1], T[Maxn];
    int next[Maxn<<1|1], is[Maxn];
    void getnext(int T[], int LT, int next[]) {
        int i, j;
        next[0]=-1; next[1] = 0;
        for (i = 1, j = 0; i < LT; ) {
            while (j != -1 && T[i] != T[j]) j = next[j];
            i++; j++;
            next[i] = j;
        }
    }
    void KMP (int S[], int LS, int T[], int LT, int next[]) {
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
    //init初始化
    //adde加边(注意单向边和双向边)
    //ready()连通块, 环, 求树hash, 求环可旋转位置
    struct CirGraph {
        struct node {
            //onCir==0 不在环上, ==1在环上
            int u, v, l, onCir, next;
        } adj[Maxm];
        int tot, last[Maxn];
        //vis==0未遍历, ==1遍历不是环上, ==2在环上
        int top, vis[Maxn], sta[Maxn];
        int dep[Maxn];
        LL H[Maxn];
        LL h[Maxn];
        vector<int> ok[Maxn];//(每个环可旋转长度)
        vector<int> belong[Maxn];//(每个环结点集合)
        int circnt;//环/树个数(1~circnt)
        void adde(int u, int v, int l) {
            adj[tot].u = u; adj[tot].v = v; adj[tot].l = l; adj[tot].onCir = 0;
            adj[tot].next = last[u]; last[u] = tot++;
        }
        void init(int n) {
            tot = 0;
            for(int i = 0; i <= n; i++) last[i] = -1;
        }
        void dfs(int u, int from) {
            int j, v;
            vis[u] = 1;
            for(j = last[u]; j != -1; j = adj[j].next) {
                if(j == from) continue;
                v = adj[j].v;
                if(!vis[v]) {
                    sta[++top] = j;
                    dfs(v, j ^ 1);
                    top--;
                }
                else if(vis[v] == 1 && vis[u] == 1){
                    int tp = top, jj;
                    sta[++tp] = j;
                    while(tp) {
                        jj = sta[tp--];
                        adj[jj].onCir = adj[jj ^ 1].onCir = 1;
                        vis[adj[jj].u] = 2;
                        belong[circnt].PB(adj[jj].u);
                        if(adj[jj].u == v) break;
                    }
                }
            }
        }
        void getDep(int u, int from) {
            int j, v;
            dep[u] = 1;
            for(j = last[u]; j != -1; j = adj[j].next) {
                if(j == from || adj[j].onCir) continue;
                v = adj[j].v;
                getDep(v, j ^ 1);
                cmax(dep[u], dep[v] + 1);
            }
        }
        void Hash(int u, int from) {
            int j, v;
            LL s = h[dep[u]];
            for(j = last[u]; j != -1; j = adj[j].next) {
                if(j == from || adj[j].onCir) continue;
                v = adj[j].v;
                Hash(v, j ^ 1);
                s = (s + h[dep[u]] * H[v]) % MOD;
            }
            H[u] = s;
        }
        void ready(int n) {
            int i, j;
            circnt = 0;
            for(i = 0; i <= n; i++) vis[i] = 0;
            for(i = 1; i <= n; i++) {
                if(!vis[i]) {
                    top = 0;
                    circnt++;
                    belong[circnt].resize(0);
                    dfs(i, -1);
                }
            }
    //        for(i = 0; i < tot; i++) printf("%d %d --> %d %d\n", i, adj[i].u, adj[i].v, adj[i].onCir);
            Hset.clear();
            srand(time(NULL));
            for(i = 0; i <= n; i++) {
                LL x = ((rand() << 15) + rand()) % MOD;
                while(Hset.find(x) != Hset.ED) x = ((rand() << 15) + rand()) % MOD;
                Hset.insert(x);
                h[i] = x;
            }
            for(i = 1; i <= n; i++) if(vis[i] == 2) {
                getDep(i, -1);
                Hash(i, -1);
            }
    //        for(i = 1; i <= n; i++) cout << "hash " << i <<" " << H[i] << endl;
            for(i = 1; i <= circnt; i++) {
                ok[i].resize(0);
                int L = belong[i].SZ;
                for(j = 0; j < L; j++) {
                    S[j + L] = S[j] = T[j] = H[belong[i][j]];
                }
                getnext(T, L, next);
                KMP(S, L << 1, T, L, next);
                for(j = 0; j < L; j++) {
                    if(is[j]) ok[i].PB(j);
                }
    //            cout << "OK ";for(j = 0; j < ok[i].SZ; j++) cout << ok[i][j] << " "; cout << endl;
            }
        }
        
    }gg;



####    03.  **RMQ**  

>	RMQ实现模板

	验题 POJ3264

	struct RMQ {
	    int n;
	    int st[20][Maxn];
	    void init(int v[], int L) {
	        int i, j, k;
	        n = L;
	        for(i = 0; i <= n; i++) st[0][i] = v[i];
	        for(j = 1, k = 0; (1<<j) <= n; j++, k++) {
	            for(i = 0; i + (1<<j) - 1<= n; i++) {
	                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1<<k)]);
	            }
	        }
	    }
	    int query(int l, int r) {	//求[l, r]
	//        int k = log2(r - l + 1);
	//        int k = 31 - __builtin_clz(r - l + 1);
	          int k = kk[r - l + 1];
	        return min(st[k][l], st[k][r - (1<<k) + 1]);
	    }
		int query(int l, int r) {	//对于sa, 求原串l, r为起点的之间的height
		    if(l == r) return len - r;
		    int u = rank[l], v = rank[r];
		    if(u > v) swap(u, v);
		    int k = kk[v - (u + 1)+ 1];
		    return min(st[u + 1][k], st[v - (1<<k) + 1][k]);
		}
	}rmq1, rmq2;

	//kk初始化0, C++/G++通用
    memset(kk, -1, sizeof(kk));
    for(i = 0; (1<<i) < Maxn; i++) kk[1<<i] = i;
    for(i = 0; i < Maxn; i++) if(kk[i] == -1) kk[i] = kk[i - 1];

	//kk初始化1, G++
    for(i = 0; i < Maxn; i++) kk[i] = 31 - __builtin_clz(i);

	//kk初始化2, G++
    for(i = 0; i < Maxn; i++) kk[i] = log2(i);


