#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T, ii;
	unsigned int x;
	cin >> T;
	for(int ii = 0; ii < T; ii++)
	{
		cin >> x;
		cout << "Case #" << ii + 1 << ": ";
		cout << ((x & 65535) << 16) + ((x & (65535 << 16)) >> 16) << endl;
	}
	return 0;
}
