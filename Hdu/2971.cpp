#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXM 16

using namespace std;

long long a2, N, m, MOD;

struct Matrix
{	
	long long a[MAXM];
	int r, c;
	Matrix(int nr, int nc)
	{
		r = nr; c = nc;
		memset(a, 0, sizeof a);
	}	
	Matrix& set(int i, int j, long long num)
	{
		a[i * r + j] = num % MOD;
		return *this;
	}
	Matrix& set(long long *init)
	{
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				a[i * r + j] = init[i * r + j] % MOD;
		return *this;
	}
	Matrix operator * (Matrix& b)
	{
		Matrix res(r, b.c);
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				if(a[i * r + j])
					for(int k = 0; k < b.c; k++)
					{
						long long p = a[i * r + j] * b.a[j * b.r + k];
						if(p > MOD) p %= MOD;
						res.a[i * r + k] += p;
						if(res.a[i * r + k] > MOD) res.a[i * r + k] %= MOD;
					}		
		return res;
	}
	/*
	void disp()
	{
		putchar('\n');
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
				cout << a[i * r + j] << " ";
			putchar('\n');
		}
		putchar('\n');
	}
	*/
};


long long mul(long long p)
{	
	p--;
	Matrix x(4, 4);
	//Matrix one(4, 4);	
	Matrix res(4, 1);
	
	long long init[MAXM] = 	
	{
		1, 1, 0, 0,
		0, 4ll * ((a2 * a2) % MOD), 1, (-4ll * a2) % MOD + MOD,
		0, 1, 0, 0,
		0, 0, 2ll * a2, -1 + MOD % MOD
	};
	x.set(init);
	res.set(0, 0, 1).set(1, 0, (a2 * a2) % MOD).set(2, 0, 1).set(3, 0, a2);
	while(p)
	{
		if(p & 1) res = x * res;
		x = x * x;
		p >>= 1;
	}
	return res.a[0];
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int ii = 0; ii < T; ii++)
	{
		cin >> a2 >> N >> m;
		MOD = m;
		cout << mul(N) << endl;
	}
	return 0;
}