/*
 * 支持第 k 大的 BIT
 * Kyb
 */
inline int LB(int x) {return x & (-x);}
const int MXN = 1e5;
template <typename T>
struct BIT {
  T _[MXN+5];
  int n;
  void init(int m) {
    n = m + 5;
    for (int i = 0; i <= n; i++)_[i] = 0;
  }
  T query(int w) {
    T ret = 0;
    for (w += 3; w > 0; w -= LB(w))ret += _[w];
    return ret;
  }
  void update(int w, T d) {
    for (w += 3; w < n; w += LB(w))_[w] += d;
  }
  /*
   * 待验证
   */
  int find_Kth(int k) {        // UESTC_Dagon
    int ans=0,cnt=0;
    for(int i=22;i>=0;i--){
      ans+=1<<i;
      if(ans>=n||cnt+_[ans]>=k)ans-=1<<i;
      else cnt+=_[ans];
    }
    return ans - 2;
  }
};
