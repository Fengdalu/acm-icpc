#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int Maxn = 200;
const long long Mod = 1e9 + 7;

long long A[Maxn][Maxn], B[Maxn][Maxn];
long long C[Maxn][Maxn], ans[Maxn][Maxn];
int n, b, K, x;

void mul(long long A[Maxn][Maxn], long long B[Maxn][Maxn], long long C[Maxn][Maxn]) {
	for(int i = 0; i < K; i++)
		for(int j = 0; j < K; j++)
			C[i][j] = 0;
	for(int i = 0; i < K; i++)
		for(int j = 0; j < K; j++)
			for(int k = 0; k < K; k++)
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % Mod) % Mod;
}

long long temp[Maxn][Maxn];
void pow(long long A[Maxn][Maxn], int p, long long ans[Maxn][Maxn]) {
	for(int i = 0; i < K; i++)
		for(int j = 0; j < K; j++)
			if(i == j) ans[i][j] = 1;
			else ans[i][j] = 0;
	while(p) {
		if(p & 1) {
			mul(A, ans, temp);
			for(int i = 0; i < K; i++)
				for(int j = 0; j < K; j++)
					ans[i][j] = temp[i][j];
		}
		p >>= 1;
		mul(A, A, temp);
		for(int i = 0; i < K; i++)
			for(int j = 0; j < K; j++)
				A[i][j] = temp[i][j];
	}
}

int main() {
	scanf("%d%d%d%d", &n, &b, &x, &K);
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
	memset(C, 0, sizeof C);
	for(int i = 0; i < n; i++) {
		long long num; 
		scanf("%lld", &num);
		for(int k = 0; k < K; k++)
			B[(k * 10 + num) % K][k]++;
	}
	pow(B, b, ans);
	cout << ans[x][0] << endl;
	return 0;	
}
