#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

char buf[100010];
int main() {
    scanf("%s", buf);
    printf("%s", buf);
    reverse(buf, buf + strlen(buf));
    printf("%s", buf);
    return 0;
}
