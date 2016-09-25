#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int cnt[22],w[22];
int dp[22][100005];
int main() {
	int i,j,k;
	int m,n;
	while ( ~scanf( "%d%d",&m,&n ) ) {
		for(i=0;i<=n;i++)for(j=0;j<=m;j++)dp[i][j]=0;
		dp[0][0]=1;
		for ( i=1; i<=n; i++ )scanf( "%d%d",&cnt[i],&w[i] );
		for ( i=0; i<n; i++ )for ( j=0; j<=m; j++ )if ( dp[i][j] )
					for ( k=0; k<=cnt[i+1]&&j+w[i+1]*k<=m; k++ )dp[i+1][j+w[i+1]*k]=1,dp[i+1][j]=1;
		while ( !dp[n][m] )m--;
		printf( "%d\n",m );
	}
	return 0;
}
