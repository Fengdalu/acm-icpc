/*
 * Kyb 示意代码 待验证
 */
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define better true

void dp(int n, int K[][100])  {
  rep(r,1,n){
    rep(i,1,n-r){
      if(r==1)K[i][i+r]=i,dp;
      else rep(k,K[i][i+r-1],K[i+1][i+r])
        if(better)K[i][i+r]=k,dp;
    }
  }
}
