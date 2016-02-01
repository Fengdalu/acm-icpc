#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[2000];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int num = 0;
	long long tot = 0;
	for(int i = 0; i < n; i++) if(a[i] > tot) {
		num++;
		tot += a[i];
	}
	printf("%lld\n", num);
	return 0;
}
