#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXM 20 

using namespace std;

long long a2, N, MOD;

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
		a[i * c + j] = num;
		return *this;
	}
	long long get(int x, int y)
	{
		return a[x * c + y];
	}

	Matrix operator * (Matrix& b)
	{
		Matrix res(r, b.c);
		for(int i = 0; i < r; i++)
			for(int j = 0; j < b.c; j++)
			{
				for(int k = 0; k < c; k++)
					res.set(i, j, res.get(i, j) + get(i, k) * b.get(k, j));
					res.set(i, j, res.get(i, j) % MOD);
			}
		return res;
	}
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
	p -= 2;
	Matrix x(4, 4);
	//Matrix one(4, 4);	
	Matrix res(4, 1);
	
	long long a22 = a2 * a2 % MOD;
	x.set(0, 0, 1).set(0, 1, 1);

	long long e = -8;
	while(e < 0) e += MOD;
	x.set(1, 1, 4LL * a22 % MOD).set(1, 2, 4LL * a2 % MOD)
	.set(1, 3, ((e * a22) % MOD + 1) % MOD);
	x.set(2, 2, MOD - 1LL).set(2, 3, 2 * a2 % MOD);
	x.set(3, 1, 1);

	long long a3 = (2LL * a2 * a2 % MOD + (MOD - 1)) % MOD;
	res.set(0, 0, (1 + a22) % MOD).set(1, 0, a3 * a3 % MOD).set(2, 0, a2).set(3, 0, a22); 
		
	while(p)
	{
		if(p & 1) res = x * res;
		x = x * x;
		p >>= 1;
	}
	return (res.a[0]) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int ii = 0; ii < T; ii++)
	{
		cin >> a2 >> N >> MOD;
		cout << mul(N) << endl;
	}
	return 0;
}
