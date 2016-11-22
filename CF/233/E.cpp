#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n == 5) {
		cout << "1 2 3" << endl;
		cout << "1 3 3" << endl;
		cout << "2 4 2" << endl;
		cout << "4 5 1" << endl;	
		cout << "3 4" << endl;
		cout << "3 5" << endl;
	}
	else {
		for(int i = 1; i <= n / 2; i++) cout << i << " " << i + n / 2 << " " << 1 << endl;
		for(int i = n / 2 + 1; i <= n - 1; i++) 
			cout << i << " " << i + 1 << " " << 2 * (i - n / 2) - 1 << endl; 
		for(int i = 1; i < n / 2; i++) cout << i << " " << i + 1 << endl;
		cout << "1 3" << endl;
	}
	return 0;
}
