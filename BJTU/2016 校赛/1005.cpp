#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++) {
		long long a, b;
		cin >> a >> b;
		set<long long>s;
		queue<long long>q;
		bool flag = false;
		while(true) {
			if(10 * a % b == 0) {
				flag = true;
				break;
			}
			long long x = 10 * a % b;
			if(s.find(x) != s.end()) break;
			q.push(10 * a / b);
			s.insert(x);
			a = 10 * a % b;
		}
		if(flag) {
			printf("Case %d: heiheihei\n", ii + 1);
		}
		else {
			printf("Case %d: 0.", ii + 1);
			while(q.size()) {
				printf("%lld", q.front());
				q.pop();
			}
			printf("\n");
		}
	}
	return 0;
}
