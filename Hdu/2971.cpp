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
		a[i * c + j] = num % MOD;
		return *this;
	}
	Matrix& set(long long *init)
	{
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				a[i * c + j] = init[i * r + j] % MOD;
		return *this;
	} 
	long long get(int x, int y)
	{
		return a[x * c + y];
	}

	Matrix operator * (Matrix b)
	{
		Matrix res(r, b.c);
		for(int i = 0; i < r; i++)
			for(int j = 0; j < b.c; j++)
			{
				for(int k = 0; k < c; k++)
					res.set(i, j, (res.get(i, j) + get(i, k) * b.get(k, j) % MOD) % MOD);
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

ostream& operator << (ostream& out, Matrix& a)
{
	for(int i = 0; i < a.r; i++)
	{
		for(int j = 0; j < a.c; j++)
			out << a.a[i * a.c + j] << " ";
		if(i != a.r - 1) out << endl;
	}
	return out;
}

long long mul(long long p)
{	
	if(p == 1) return 1;
	if(p == 2) return (1 + (a2 * a2) % MOD) % MOD;
	p--;p--;
	Matrix x(4, 4);
	//Matrix one(4, 4);	
	Matrix res(4, 1);
	
	long long init[MAXM] = 	
	{
		1, 4 * a2 % MOD * a2 % MOD, (-4 * a2 + MOD) % MOD, 1,
		0, (4 * a2) % MOD, (-4 * a2 % MOD) % MOD, 1,
		0, 0, -1 + MOD, 2 * a2 % MOD,
		0, 1, 0, 0 
	};
	x.set(init);
	res.set(0, 0, (1 + (a2 * a2) % MOD) % MOD).set(1, 0, a2 * a2 % MOD).set(2, 0, 0).set(3, 0, 0);
	while(p)
	{
		if(p & 1) res = x * res;
		x = x * x;
		p >>= 1;
	}
	return res.a[1];
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
