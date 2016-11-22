#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int MXN = 2;
const int mod = 1e9+7;
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

int main() {
  int x, y, n;
  scanf("%d%d%d", &x, &y, &n);
  Matrix<long long>f(2, 1);
  f[0][0] = x;
  f[1][0] = y;
  Matrix<long long> A(2, 2);
  A[0][1] = 1;
  A[1][0] = -1;
  A[1][1] = 1;
  n--;
  while(n) {
    if(n & 1) f = A * f;
    A = A * A;
    n >>= 1;
  }
  printf("%I64d\n", (f[0][0] + mod) % mod);
  return 0;
}
