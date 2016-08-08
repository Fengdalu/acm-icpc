#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    printf("I hate");
    for(int i = 1; i < n; i++) {
        if(i != 0) printf(" that");
        if(i & 1) printf(" I love");
        else printf(" I hate");
    }
    printf(" it");
    return 0;
}

