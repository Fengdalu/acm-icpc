


####    01. **树的Hash与同构**  

>   树Hash判定树同构

    int h[11000];
    char str1[3100], str2[3100];
    char *p;
    int Hash (int j) {
        int sum = h[j + 5000];//这里的j是记录的节点度
        //这个巧妙的循环,把子节点的hash值都加给了父节点,作为父节点的hash值
        //由于树节点顺序不确定, 因此是子树hash值*根值的累加
        while (*p && *p++ == '0') { 
            sum = (sum + h[j] * Hash (j + 1) ) % 19001;
        }
        return (sum * sum) % 19001;
    }
    inline void init() {
        //为每一个树根节点给定一个随机权值
        for (int i = 0; i < 10000; i++)
            h[i] = (rand() %19901);
    }
    int main() {
        int T;
        scanf ("%d", &T);
        init();
        while (T--) {
            scanf ("%s%s", str1, str2);
            p = str1;
            int a = Hash (1);
            p = str2;
            int b = Hash (1);
            if (a == b) {
                puts ("same");
            } else {
                puts ("different");
            }
        }
        return 0;
    }



####     02. **图的hash**  

>  


####    03. **最大团**  

>   最大团

	bool am[100][100];
	int ans;
	int c[100];
	int U[100][100];
	int n;
	bool dfs(int rest,int num) {
	  if (!rest) {
	    if (num>=ans)
	      return 1;
	    else
	      return 0;
	  }
	  int pre=-1;
	  for (int i=0; i<rest && rest-i+num>=ans; i++) {
	    int idx=U[num][i];
	    if (num+c[idx]<ans)
	      return 0;
	    int nrest=0;
	    for (int j=i+1; j<rest; j++)
	      if (am[idx][U[num][j]])
	        U[num+1][nrest++]=U[num][j];
	    if (dfs(nrest,num+1))
	      return 1;
	  }
	  return 0;
	}
	int main() {
	  while (scanf("%d",&n),n) {
	    for (int i=0; i<n; i++)
	      for (int j=0; j<n; j++)
	        scanf("%d",&am[i][j]);
	    ans=0;
	    for (int i=n-1; i>=0; i--) {
	      int rest=0;
	      for (int j=i+1; j<n; j++)
	        if (am[i][j])
	          U[0][rest++]=j;
	      ans+=dfs(rest,0);
	      c[i]=ans;
	    }
	    printf("%d\n",ans);
	  }
	  return 0;
	}
	


>   极大团计数




####    04. ***偏序集***


####    05. **弦图完美消除序列**  

>	弦图判定

	//ZOJ 1015 fishing net
	//简单的弦图判定
	int adj[Maxn][Maxn];
	int n, m;
	int L[Maxn], cnt[Maxn], visit[Maxn], mpL[Maxn];
	priority_queue<PII> que;
	
	//利用MSC最大势算法求完美消除序列L
	int getList() {
	    int i, j, k, u, v, w;
	    for(i = 1; i <= n; i++) cnt[i] = 0, visit[i] = 0;
	    while(!que.empty()) que.pop();
	    que.push(MP(0, 1));
	    k = n;
	    while(!que.empty()) {
	        u = que.top().BB; w = que.top().AA;
	        que.pop();
	        if(w != cnt[u]) continue;
	        visit[u] = 1;
	        mpL[u] = k;
	        L[k--] = u;
	        for(v = 1; v <= n; v++) {
	            if(!visit[v] && adj[u][v]) {
	                cnt[v]++;
	                que.push(MP(cnt[v], v));
	            }
	        }
	    }
	    if(k < 1) return true;
	    else return false;
	}
	
	//利用完美消除序列判断是否弦图
	int check() {
	    int i, j, k, u, v, w;
	    for(i = n - 1; i >= 1; i--) {
	        u = L[i];
	        k = -1;
	        for(j = i + 1; j <= n; j++) {
	            v = L[j];
	            if(adj[u][v]) {
	                k = v;
	                break;
	            }
	        }
	        if(k != -1) {
	            for( j++; j <= n; j++) {
	                v = L[j];
	                if(adj[u][v] && !adj[k][v]) return false;
	            }
	        }
	    }
	    return true;
	}
	int main() {
	    int i, j, u, v, w;
	    while(scanf("%d%d", &n, &m) != EOF) {
	        if(!n && !m) break;
	        for(i = 1; i <= n; i++) {
	            for(j = 1; j <= n; j++) {
	                adj[i][j] = 0;
	            }
	        }
	        for(i = 0; i < m; i++) {
	            scanf("%d%d", &u, &v);
	            adj[u][v] = adj[v][u] = 1;
	        }
	        
	        if(getList() && check()) {
	            printf("Perfect\n");
	        }
	        else {
	            printf("Imperfect\n");
	        }
	        printf("\n");
	    }
	    return 0;
	}

>	// 弦图与区间图 By 猛犸也钻地 @ 2012.09.13

	/* 相关定义 //
	1. 子图：原图点集的子集+原图边集的子集
	2. 诱导子图：原图点集的子集+这些点在原图中所连出的边集
	3. 团：原图的一个子图，且是完全图
	4. 极大团：此团不是其他团的子集
	5. 最大团：点数最多的团 -> 团数
	6. 最小染色：用最少的颜色给点染色使相邻点颜色不同 -> 色数
	7. 最大独立集：原图点集的子集，任意两点在原图中没有边相连
	8. 最小团覆盖：用最少个数的团覆盖所有的点
	   推论 -> 团数<=色数，最大独立集数<=最小团覆盖数
	9. 弦：连接环中不相邻的两个点的边
	10.弦图：图中任意长度大于3的环都至少有1个弦
	   推论 -> 弦图的每一个诱导子图一定是弦图
	           弦图的任一个诱导子图不同构于Cn(n>3)
	11.单纯点：记N(v)为点v相邻点的集合，若N(v)+{v}是一个团，则v为单纯点
	   引理 -> 任何一个弦图都至少有一个单纯点
	           不是完全图的弦图至少有两个不相邻的单纯
	// 重点内容 //
	12.完美消除序列：点的序列v1,v2,..,vn，满足vi在{vi,vi+1,..,vn}中是单纯点
	   定理 -> 一个无向图是弦图，当且仅当它有一个完美消除序列
	   构造算法 -> 令cnt[i]为第i个点与多少个已标记的点相邻，初值全为零
	               每次选择一个cnt[i]最大的结点并打上标记
	               标记顺序的逆序则为完美消除序列
	   判定算法 -> 对于每个vi，其出边为vi1,vi2,..,vik
	               然后判断vi1与vi2,vi3,..,vik是否都相邻
	               若存在不相邻的情况，则说明不是完美消除序列
	13.弦图各类算法：
	   最小染色算法 -> 按照完美消除序列，从后向前，依次染上可以染的最小颜色
	   最大独立集算法 -> 按照完美消除序列，从前向后，能选则选
	   最小团覆盖算法 -> 求出最大独立集，记为{p1,p2,..,pk}
	                     则{N(p1)+{p1},N(p2)+{p2},..,N(pk)+{pk}}即为解
	16.区间图：坐标轴上的一些区间看作点，任意两个交集非空的区间之间有边
	   定理 -> 区间图一定是弦图 */

####	06. **Other**

>	中国邮递员

>	网络流相关:

	1、 连续最短路算法（Successive Shortest Path）；

	2、 消圈算法（Cycle Canceling）；
	
	3、 原始对偶算法（Primal Dual）；
	
	4、 网络单纯形（Network Simplex）。

####	07. **待解决的问题**

> 	最短路

	HDU 3873

	字典序最小的路径
	
		有重复标号(如给定边长度和边标号, 输出最短路径上每条边给定的标号的最小字典序)???

>	最小环&最大环

	最大环可做???

> 	拓扑排序

	POJ1128

	字典序最小的拓扑排序

		有重复标号字典序最小???

