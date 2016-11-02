/*
 * MatrixMul: 稀疏矩阵乘法
 * n: 方阵大小
 */
typedef long long ll;
const int N = 1000;
void matrixMul(ll a[][N], ll b[][N], ll c[][N], int n) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      c[i][j] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0;j < n; j++) {
      if(0 == a[i][j])continue;
      for(int k = 0; k < n; k++)
        c[i][k] += a[i][j] * b[j][k];
    }
  }
}
