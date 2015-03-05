#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
#define PB(x) push_back(x)

vector<int>f;

int main()
{
	f.clear();
	f.PB(1); f.PB(2); f.PB(-1); f.PB(2);
	int size = unique(f.begin(), f.end()) - f.begin();
	for(int i = 0; i < size; i++)
		cout << f[i] << endl;
	return 0;
}
