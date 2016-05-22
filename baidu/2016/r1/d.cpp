#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int>f;
char buf[1000];
int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", buf);
        int len = strlen(buf);
        sort(buf, buf + len);
        printf("%d\n", f[string(buf)]++);
    }
    return 0;
}
