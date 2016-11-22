#include <cstdio>
#include <iostream>
#include <cstring>
#define MOD 1000000007
#define MAXS 200000

using namespace std;

int c[4];
int n;
char s[MAXS];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	
	memset(c, 0, sizeof c);
	int LEN = strlen(s);
	for(int i = 0; i < LEN; i++)
		if(s[i] == 'A') c[0]++;
		else if(s[i] == 'G') c[1]++;
		else if(s[i] == 'C') c[2]++;
		else if(s[i] == 'T') c[3]++;	
	int M = -1;
	long long cc = 0;
	for(int i = 0; i < 4; i++) M = max(c[i], M);
	for(int i = 0; i < 4; i++) if(c[i] == M) cc++;
	
	long long ans = 1;
	for(int i = 0; i < n; i++) ans = (ans * cc) % MOD;
	printf("%I64d\n", ans);
	return 0;
} 