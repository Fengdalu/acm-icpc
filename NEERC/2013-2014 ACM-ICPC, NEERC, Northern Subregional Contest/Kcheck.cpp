#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>
#define OP begin()
#define ED end()

int a, b, c, d;
int v1, v2;
int t1[100], t2[100];
int f1[100], f2[100];


void for4() {
    FILE *file = fopen("kids.in", "w");
    for(int i = 1; i <= 50; i++)
    for(int j = 1; j <= 50; j++)
    for(int k = 1; k <= 50; k++)
    for(int p = 1; p <= 50; p++)
        fprintf(file, "%d %d %d %d\n", i, j, k, p);
    fclose(file);
}

int main() {
    FILE *file1 = fopen("kids.in", "r");
    FILE *file = fopen("kids.out", "r");
    freopen("kids.in", "r", stdin);
    while(~fscanf(file1, "%d%d%d%d", &a, &b, &c, &d)) {
        int x, y;
        memset(t1, 0, sizeof t1);
        memset(t2, 0, sizeof t2);
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        fscanf(file, "%d%d", &v1, &v2);
        for(int i = 0; i < v1 * a + v1 * b + v2 * c + v2 * d; i += 2) {
            fscanf(file, "%d%d", &x, &y);
            if(x > y) swap(x, y);
            if(x <= v1 && y > v1) {
                t2[x]++;
                f2[y]++;
            }
            else if(x <= v1) {
                t1[x]++;
                t1[y]++;
            }
            else {
                f1[x]++;
                f1[y]++;
            }
        }
        for(int i = 1; i <= v1; i++) {
            if(t1[i] != a || t2[i] != b) { cout <<"WA" << endl; return -1;}
        }
        for(int i = v1 + 1; i <= v1 + v2; i++) {
            if(f1[i] != d || f2[i] != c) { cout <<"WA" << endl; return -1;}
        }
    }
    return 0;
}
