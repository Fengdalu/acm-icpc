/*
 * 算法引入 :
 * 给定一个无向图 G , 求它生成树的个数 t(G) ;
 *
 * 算法思想 :
 * 1) G 的度数矩阵 D[G] 是一个 n*n 的矩阵 ,
 * 并且满足 : 当 i != j 时 , dij=0 ; 当 i=j 时 , dij 等于 vi 的度数 ;
 * 2) G 的邻接矩阵 A[G] 是一个 n*n 的矩阵 ,
 * 并且满足 : 如果 vi , vj 之间有边直接相连 , 则 aij=1 , 否则为 0 ;
 * 定义图 G 的 Kirchhoff 矩阵 C[G] 为 C[G]=D[G]-A[G] ;
 * Matrix-Tree 定理 : G 的所有不同的生成树的个数等于
 * 其 Kirchhoff 矩阵 C[G] 任何一个 n-1 阶主子式的行列式的绝对值 ;
 * 所谓 n-1 阶主子式 , 就是对于 r(1 <= r <= n) , 将 C[G] 的第r行
 * 第 r 列同时去掉后得到的新矩阵 , 用 Cr[G] 表示 ;
 *
 * Kirchhoff 矩阵的特殊性质 :
 * 1) 对于任何一个图 G, 它的 Kirchhoff 矩阵 C 的行列式总是 0 ,
 * 这是因为 C 每行每列所有元素的和均为 0 ;
 * 2) 如果 G 是不连通的 , 则它的 Kirchhoff 矩阵 C 的任一个主子式的行列式均为 0 ;
 * 3) 如果 G 是一颗树 , 那么它的 Kirchhoff 矩阵 C 的任一个 n-1 阶主子式的行列式均为 1 ;
 *
 * 算法举例 :
 * SPOJ HIGH
 *
 * 题目地址 :
 * http://www.spoj.com/problems/HIGH/
 *
 * 题目大意 :
 * 一个有 n 座城市的组成国家 , 城市 1 至 n 编号 , 其中一些城市之间可以修建高速公路 ;
 * 需要有选择的修建一些高速公路 , 从而组成一个交通网络 ;
 * 计算有多少种方案 , 使得任意两座城市之间恰好只有一条路径 ;
 **/

#include <bits/stdc++.h>
const int N=15;
typedef long long ll;

int degree[N];
ll C[N][N];
// 生成树计数 : Matrix-Tree 定理
ll det(ll a[][N],int n) {
  ll ret = 1;
  for(int i=1; i<n; i++) {
    for(int j=i+1; j<n; j++)
      while(a[j][i]) {
        ll t = a[i][i] / a[j][i];
        for(int k = i; k < n; k++)
          a[i][k] = (a[i][k] - a[j][k] * t);
        for(int k = i; k < n; k++)
          std::swap(a[i][k], a[j][k]);
        ret = -ret;
      }
    if(a[i][i] == 0)
      return 0;
    ret = ret * a[i][i];
  }
  if(ret < 0)
    ret = -ret;
  return ret;
}

int main() {
  int tcase;
  scanf("%d",&tcase);
  while(tcase--) {
    memset(degree, 0, sizeof(degree) );
    memset(C, 0, sizeof(C));
    int n ,m;
    scanf("%d%d", &n, &m);
    int u, v;
    while(m--) {
      scanf("%d%d", &u, &v);
      u--; v--;
      C[u][v] = C[v][u] = -1;
      degree[u]++; degree[v]++;
    }
    for(int i = 0; i < n; ++i)
      C[i][i] = degree[i];
    printf("%lld\n", det(C, n));
  }
  return 0;
}

