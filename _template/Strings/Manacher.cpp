/*
 * 求以 i 为中心的最长回文串长度 ,
 * 结果保存在 $ pk[i] $ 中 , 下标 $ [0, n) $ ,
 * 开头 , 末尾 , 字符之间插入 \# , 例如 ababa 变为 \#a\#b\#a\#b\#a\#
 */
#include <bits/stdc++.h>
const int N = 1e5;
int pk[N];
template <typename T>
// [0, n)
void manacher(T *a, int n) {
  int mx = 0;
  int p;
  for(int i = 0; i < n; i++) {
    if(i < mx) pk[i] = std::min(pk[2 * p - i], mx - i);
    else pk[i] = 1;
    while(i + pk[i] < n && i - pk[i] > -1 && a[i + pk[i]] == a[i - pk[i]]) pk[i]++;
    if(i + pk[i] > mx) { p = i; mx = i + pk[i]; }
  }
}
