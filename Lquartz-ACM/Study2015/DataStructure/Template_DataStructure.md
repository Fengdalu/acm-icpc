
##  DataStructure Template

### **Contents** 

1.  **BIT(树状数组)**    
2.  **SEGT(线段树)**  
3.  **函数式线段树(主席树)**   
10. **Other**
11. **待解决的问题**

----------------------------------------------------------

####    01. **BIT(树状数组)**  

*	一维BIT

		/*一维BIT,注意设置Maxn和Step(1<<Step), 注意查找第k大可能存在bug*/
		inline int LB(int x){return x&(-x);}
		struct BIT {
		    LL _[Maxn];
		    int n;
		    const int STEP = 20;
		    void init(int m) {
		        n = m + 5;
		        for(int i = 0; i <= n; i++) _[i] = 0;
		    }
		    LL query(int w) {
		        LL ret = 0;
		        for(w += 3; w > 0; w -= LB(w)) ret += _[w];
		        return ret;
		    }
		    void update(int w, LL d) {
		        for(w += e; w < n; w += LB(w)) _[w] += d;
		    }
		    int find_kth(int k) {   //UESTC_Dagon
		        int idx = 0;
		        for(int i = STEP; i >= 0; i--) {
		            idx |= 1<<i;
		            if(idx <= n && _[idx] < k) k -= _[idx];
		            else idx ^= 1<<i;
		        }
		        return idx - 2;
		    }
		};


*	二维BIT  
	


####    02. **SEGT(线段树)**  

*	函数版



*	KMP类



####    03. **函数式线段树(主席树)**  

	POJ2104

	#define Maxn 101111
	#define Step 20
	
	int sum[Maxn * Step], ls[Maxn * Step], rs[Maxn * Step], root[Maxn];
	int org[Maxn], des[Maxn];
	int n, q, m;
	int newnode;
	
	void build(int & r, int lt, int rt) {
	    r = newnode++;
	    sum[r] = 0;
	    //printf("build %d [%d, %d]\n", r, lt, rt);
	    if(lt >= rt) return;
	    int mid = (lt + rt) >> 1;
	    build(ls[r], lt, mid);
	    build(rs[r], mid + 1, rt);
	}
	
	void refresh(int & r, int pre, int lt, int rt, int pos) {
	    r = newnode++;
	    ls[r] = ls[pre];
	    rs[r] = rs[pre];
	    sum[r] = sum[pre] + 1;
	    //printf("refresh %d %d [%d, %d] %d\n", r, pre, lt, rt, pos);
	    if(lt >= rt) return;
	    int mid = (lt + rt) >> 1;
	    if(pos <= mid) refresh(ls[r], ls[pre], lt, mid, pos);
	    else refresh(rs[r], rs[pre], mid + 1, rt, pos);
	}
	
	int query(int l, int r, int lt, int rt, int k) {
	    //printf("query [%d, %d], [%d, %d], %d\n", l, r, lt, rt, k);
	    if(lt >= rt) return lt;
	    int mid = (lt + rt) >> 1;
	    int cnt = sum[ls[r]] - sum[ls[l]];
	    //printf("\t cnt %d\n", cnt);
	    if(cnt >= k) return query(ls[l], ls[r], lt, mid, k);
	    else return query(rs[l], rs[r], mid + 1, rt, k - cnt);
	}
	
	void printtree(int root, int r, int lt, int rt) {
	    printf("root %d r %d [%d, %d] sum %d\n", root, r, lt, rt, sum[r]);
	    if(lt == rt) return;
	    int mid = (lt + rt) >> 1;
	    printtree(root, ls[r], lt, mid);
	    printtree(root, rs[r], mid + 1, rt);
	}
	
	void debugtree() {
	    for(int i = 0; i <= n; ++i) {
	        printf("tree %d\n", i);
	        printtree(i, root[i], 1,  m);
	    }
	}
	
	int main() {
	    int i,j,k,u,v,w;
	
	    //freopen(NAME".in", "r", stdin);
	    //freopen(NAME".out", "w", stdout);
	    while(scanf("%d%d", &n, &q) != EOF) {
	        for(i = 1; i <= n; ++i) {
	            scanf("%d", &org[i]);
	            des[i] = org[i];
	        }
	        sort(des + 1, des + n + 1);
	        m = unique(des + 1, des + n + 1) - des - 1;
	        newnode = 0;
	        build(root[0], 1, m);
	        for(i = 1; i <= n; ++i) {
	            u = lower_bound(des + 1, des + m + 1, org[i]) - des;
	            refresh(root[i], root[i - 1], 1, m, u);
	        }
	        //debugtree();
	        for(int qq = 0; qq < q; ++qq) {
	            scanf("%d%d%d", &u, &v, &k);
	            if(u > v) swap(u, v);
	            printf("%d\n", des[query(root[u - 1], root[v], 1, m, k)]);
	        }
	    }
	    return 0;
	}


####	04. **树链剖分(轻重链划分)**

*	bfs+手写栈

		//siz, dep, son, top, parent, mp, emp(边是谁的父边), ncnt线段树映射计数器
		int siz[Maxn], dep[Maxn], son[Maxn], top[Maxn], parent[Maxn], lv[Maxn], mp[Maxn], emp[Maxn], ncnt;
		//que用于bfsinit, sta, cur用于手写栈, head代替top
		int que[Maxn], head, tail;
		PII sta[Maxn];
		int cur[Maxn];
		int llv[Maxn];	//将v点或其指向父结点的边的权值映射记录用于求lv[]
		
		void bfsinit(int root = 1) {//siz[], dep[], son[], parent[], llv[], emp[]
		    int i, j, k, u, v, w;
		    int dmax;
		    head = tail = 0;
		    dep[root] = 0;
		    parent[root] = -1;
		    que[tail++] = root;
		    while(head < tail) {
		        u = que[head++];
		        siz[u] = 1;
		        for(j = last[u]; j != -1; j = e[j].next) {
		            v = e[j].v;
		            if(v == parent[u]) continue;
		            parent[v] = u;
		            dep[v] = dep[u] + 1;
		            //记录结点v初始值OR其父边的值
		            llv[v] = e[j].c;
		            emp[j / 2] = v;
		            que[tail++] = v;
		        }
		    }    
		    for(i = tail - 1; i >= 0; --i) {
		        u = que[i];
		        dmax = -1;
		        for(j = last[u]; j != -1; j = e[j].next) {
		            v = e[j].v;
		            if(v == parent[u]) continue;
		            siz[u] += siz[v];
		            if(dmax == -1 || siz[dmax] < siz[v]) dmax = v;
		        }
		        son[u] = dmax;
		    }
		}
		
		void split(int root = 1) { // 手写栈 top[], lv[], mp[]
		    int i, j, k, u, v, w;
		    int fa;
		    for(i = 0; i <= n; ++i) cur[i] = last[i];
		    head = 0;
		    sta[head++] = MP(root, root);
		    ncnt = 0;
		    while(head) {
		        head--;
		        u = sta[head].AA; fa = sta[head].BB;        
		        top[u] = fa;
		        mp[u] = ++ncnt;
		        lv[ncnt] = llv[u];
		        for(j = last[u]; j != -1; j = e[j].next) {
		            v = e[j].v;
		            if(v == parent[u]) continue;
		            if(v != son[u]) {
		                sta[head++] = MP(v, v);
		            }
		        }
		        if(son[u] != -1) {
		            sta[head++] = MP(son[u], fa);
		        }
		    }
		}

	    void split(int u, int t) {//dfs mp[], top[], lv[]
	        int j, v;
	        top[u] = t;
	        mp[u] = ++ncnt;
	        lv[ncnt] = llv[u];
	
	        if(son[u] != -1) split(son[u], t);
	        for(j = last[u]; j != -1; j = e[j].next) {
	            v = e[j].v;
	            if(v == fa[u]) continue;
	            if(v != son[u]) {
	                split(v, v);
	            }
	        }
	    }

		
		void debug() {
		    for(int i = 1; i <= n; ++i) {
		        int u = i;
		        printf("node[%d]: siz %d dep %d parent %d son %d top %d mp %d lv %d\n", 
				u, siz[u], dep[u], parent[u], son[u], top[u], mp[u], lv[u]);
		        
		    }
		}


*	平衡二叉树(Treap)



*	平衡二叉树(Splay)



*	树分治(点分治)



*	树分治(边分治)



*	


*	STL优先队列（堆）的运算符重载（推荐）


		struct cmp {
		     bool operator() (const int &a, const int &b){
		        return a>b;
		     }
		};
		priority_queue<int, vector<int>, cmp> Q;

*	RMQ(update ***initkk()*** function)

		int kk[Maxn];
		void initkk() {
		    int i;
		    for(i = 0; i < Maxn; ++i) kk[i] = log2(i);
		}
		struct RMQ {
		    int n;
		    int st[20][Maxn];
		    void init(int v[], int L) {
		        int i, j, k; n = L;
		        for(i = 0; i <= n; i++) st[0][i] = v[i];
		        for(j = 1, k = 0; (1<<j) <= n; j++, k++) {
		            for(i = 0; i + (1<<j) - 1<= n; i++) {
		                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1<<k)]);
		            }
		        }
		    }
		    int query(int l, int r) {
		//        int k = 31 - __builtin_clz(r - l + 1);
		        int k = kk[r - l + 1];
		        return min(st[k][l], st[k][r - (1<<k) + 1]);
		    }
		}rmq1, rmq2;


*	

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