#include <bits/stdc++.h>

const int inf = 1e9;
template <typename T> class Matrix{
  public:
    int n,m ;
    std::vector< std::vector<T> > a;
    Matrix() {}
    Matrix(int _n , int _m) {
      n = _n , m = _m;
      a = std::vector< std::vector<T> > (n, std::vector<T>(m, -inf));
    };
    std::vector<T>& operator[] (int i) {return a[i];}

    Matrix friend operator * (Matrix A , Matrix B){
      Matrix ans(A.n , B.m);
      for (int k = 0 ; k < A.m ; ++ k)
        for (int i = 0 ; i < A.n ; ++ i) if(A[i][k] > -inf)
          for (int j = 0 ; j < A.m ; ++ j)
            ans[i][j]= std::max(ans[i][j], A[i][k] + B[k][j]);
      return ans;
    }

    void out() {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) printf("%d ", a[i][j]);
        puts("");
      }
    }
};

Matrix<int> f[10];
int n, m;
bool check(int p) {
  Matrix<int> B(n, n);
  for(int i = 0; i < B.n; i++) B[i][i] = 0;
  for(int i = 0; i < 10; i++) if(p >> i & 1) B = B * f[i];
  for(int i = 0; i < B.n; i++)
    if(B[i][i] > 0) return true;
  return false;
}


int main() {
  scanf("%d%d", &n, &m);
  Matrix<int> A(n, n);
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    int p, q;
    scanf("%d%d", &p, &q);
    A[u][v] = p; A[v][u] = q;
  }
  for(int i = 0; i < n; i++) A[i][i] = 0;
  f[0] = A;
  for(int i = 1; i < 10; i++) f[i] = f[i - 1] * f[i - 1];
  int l = 0, r = n;
  while(l < r) {
    int mid = (l + r) / 2;
    if(check(mid)) r = mid;
    else l = mid + 1;
  }
  if(check(l))
    printf("%d\n", l);
  else printf("0\n");
  return 0;
}
/*
4 4
1 2 -10 3
1 3 1 -10
2 4 -10 1
3 4 0 -3
*/
