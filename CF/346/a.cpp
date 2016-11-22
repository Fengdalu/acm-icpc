#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    cout << ((a + b) % n + n) % n + 1 << endl;
}
