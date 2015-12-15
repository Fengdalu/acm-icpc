#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

char buf[20];

int main() {
    scanf("%s", buf);
    int n = strlen(buf);
    sort(buf, buf + n);
    do{
        printf("%s\n", buf);
    }while(next_permutation(buf, buf + n));
    return 0;
}
