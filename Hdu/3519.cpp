#include <bits/stdc++.h>

const int MXN = 4;
const int mod = 1e4+7;
template <typename T> class Matrix{
  public:
    int n,m ;
    T a[MXN][MXN];
    Matrix() {memset(a , 0 , sizeof(a));}
    Matrix(int _n , int _m) {
      n = _n , m = _m , memset(a , 0 , sizeof(a));
    };
    T* operator[] (int i) {return a[i];}
    Matrix friend operator * (Matrix A , Matrix B){
      Matrix ans(A.n , B.m);
      for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)if(A[i][j]!=0)
          for (int k = 0 ; k < B.m ; ++ k)
            ans[i][k]=(ans[i][k]+A[i][j]*B[j][k]) % mod;
      return ans;
    }
};

int qpow(int x, int p) {
  int r = 1;
  while(p) {
    if(p & 1) r = (r * x) % mod;
    p >>= 1;
    x = (x * x) % mod;
  }
  return r;
}

int main() {
  int n;
  while(~scanf("%d", &n)) {
    Matrix<int> a(3, 3), g(3, 1);
    a[0][1] = 1;
    a[1][2] = 1;
    a[2][1] = a[2][2] = 1;

    g[0][0] = 1; g[1][0] = 2; g[2][0] = 4;
    
    int tot = qpow(2, n);
    while(n) {
      if(n & 1) g = a * g;
      n >>= 1;
      a = a * a;
    }
    printf("%d\n", (tot + mod - g[0][0]) % mod);
  }
  return 0;
}
