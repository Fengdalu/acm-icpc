#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int a[20];
int tot;

int fact(int n) {
    int ans = 1;
    for(int i = 1; i <= n; i++) ans = ans * i;
    return ans;
}

int c(int a, int b) { if(a < b) return 0; return fact(a) / fact(b) / fact(a - b); }
int cal() {
    int ans = 1;
    for(int i = 1; i < m; i++)  ans *= c(a[i + 1], a[i]);
    return ans;
}

void dfs(int i) {
    if(i == m + 1) tot += cal();
    else {
        for(int j=0; j <= n; j++) {
            a[i] = j;
            dfs(i + 1);
        }
    }
}


int main() {
    for(int i = 0; i < 10; i++) {
        for(int j = 2; j <= 10; j++) {
            tot = 0;
            n = i, m = j;
            dfs(1);
            cout << tot << " ";
        }
        cout << endl;
    }
    return 0;
}

