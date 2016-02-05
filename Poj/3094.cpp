#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[300];

int main() {
	while(gets(buf)) {
		if(buf[0] == '#') break;
		long long sum = 0;
		int len = strlen(buf);
		for(int i = 0; i < len; i++)
		if(buf[i] != ' '){
			sum += (long long)(i + 1) * (buf[i] - 'A' + 1);
		}
		cout << sum << endl;
	}
	return 0;
}
