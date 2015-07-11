#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=1005;
const int MOD=1000000007;
#define LL __int64
LL DPPP1[N][N];
LL DPPP2[N][N];
int pepepe[N][N];
int tab[30];
char X[N],Y[N];
void Add(LL &a,LL b){
    a+=b;
    if(a>=MOD)
        a-=MOD;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",X,Y);
        int n=strlen(X);
        int m=strlen(Y);
    
        memset(DPPP1,0,sizeof(DPPP1));
        memset(DPPP2,0,sizeof(DPPP2));
        memset(tab,0,sizeof(tab));
        memset(pepepe,0,sizeof(pepepe));
        for(int i=1;i<=m;++i){
            tab[Y[i-1]-'a']=i;
            for(int j=0;j<26;++j){
                pepepe[i][j]=tab[j];
            }
        }

        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(X[i-1]==Y[j-1]){
                    DPPP1[i][j] = max(DPPP1[i-1][j-1]+1,max(DPPP1[i-1][j],DPPP1[i][j-1]));
                }
                else{
                    DPPP1[i][j] = max(DPPP1[i-1][j],DPPP1[i][j-1]);
                }
            }
        }

        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if(DPPP1[i][j]==0){
                    DPPP2[i][j]=1;
                    continue;
                }
                if(DPPP1[i-1][j] == DPPP1[i][j]){
                    Add(DPPP2[i][j],DPPP2[i-1][j]);
                }
                if(pepepe[j][X[i-1]-'a']){
                    int id=pepepe[j][X[i-1]-'a'];
                    if(DPPP1[i-1][id-1]+1 == DPPP1[i][j])
                        Add(DPPP2[i][j],DPPP2[i-1][id-1]);
                }
            }
        }
        printf("%I64d\n",DPPP2[n][m]);
    }
    return 0;
}