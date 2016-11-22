#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void run() {
	int n, k, p;
	cin >> n >> p >> k;
	if(1 < p - k)
	cout << "<< ";
	for(int i = max(1, p - k); i < p; i++) cout << i << " ";
	cout << "(" << p << ") ";
	for(int i = p + 1; i <= min(n, p + k); i++) cout << i << " ";
	if(p + k < n)
	cout << ">>";
}

int main() {
	run();
}

