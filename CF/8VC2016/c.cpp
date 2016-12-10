#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int i = 1, left = 0;
    while(left < a + b) {
        if(i % 2 == 0 && i % 3 == 0) left++;
        else if(a && i % 2 == 0) a--;
        else if(b && i % 3 == 0) b--;
        i++;
    }
    printf("%d\n", i - 1);
    return 0;
}
