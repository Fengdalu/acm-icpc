/*
 * cxlove
 * spoj NSUBSTR
 * 给一个字符串 S,
 * 令 F(x) 表示 S 的所有长度为x的子串中 ,
 * 出现次数的最大值 ,
 * 求 F(1)..F(Length(S))
 * 结点的 len 值表示那一时刻的后缀长度
 */
#include <bits/stdc++.h>
#define inf 100000005
#define M 40
#define N 510005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL unsigned long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
#define test puts("OK");
#pragma comment(linker, "/STACK:1024000000,1024000000")
struct SAM {
    SAM *pre,*son[26];
    int len,g;
}que[N],*root,*tail,*b[N];
int tot;
void add(int c,int l) {
    SAM *p=tail,*np=&que[tot++];
    np->len=l;tail=np;
    while(p&&p->son[c]==NULL) p->son[c]=np,p=p->pre;
    if(p==NULL) np->pre=root;
    else {
        SAM *q=p->son[c];
        if(p->len+1==q->len) np->pre=q;
        else {
            SAM *nq=&que[tot++];
            *nq=*q;
            nq->len=p->len+1;
            np->pre=q->pre=nq;
            while(p&&p->son[c]==q) p->son[c]=nq,p=p->pre;
        }
    }
}
char str[N/2];
int dp[N/2];
int main() {
    while(scanf("%s",str)!=EOF) {
        int n=strlen(str);
        tot=0;
        root=tail=&que[tot++];
        for(int i=0;i<n;i++) add(str[i]-'a',i+1);
        int cnt[N/2];mem(cnt,0);
        for(int i=0;i<tot;i++) cnt[que[i].len]++;
        for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
        for(int i=0;i<tot;i++)  b[--cnt[que[i].len]]=&que[i];
        for(int i=0;i<n;i++) (root=root->son[str[i]-'a'])->g++;
        mem(dp,0);
        for(int i=tot-1;i>0;i--) {
            dp[b[i]->len]=std::max(dp[b[i]->len],b[i]->g);
            if(b[i]->pre) b[i]->pre->g+=b[i]->g;
        }
        for(int i=n-1;i>0;i--) dp[i]=std::max(dp[i],dp[i+1]);
        for(int i=1;i<=n;i++) printf("%d\n",dp[i]);
    }
    return 0;
}
