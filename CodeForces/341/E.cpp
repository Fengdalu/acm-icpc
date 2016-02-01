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

struct Matrix {
	int row, col;
	long long a[Maxn][Maxn];
};

Matrix& mul(const Matrix &a, const Matrix &b, Matrix &c) {
	memset(c.a, 0, sizeof c.a);
	for(int i = 0; i < a.row; i++)
		for(int j = 0; j < b.col; j++) {
			for(int k = 0; k < a.col; k++)
				c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % Mod) % Mod;
		}
	return c;
}

int main() {
}
