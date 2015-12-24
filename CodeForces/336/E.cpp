#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

const int N = 2000000;

int Next[N];
char a[N], b[N];

// `a为主串，b为钥串`
void getNext(char b[N], int m)
{
	int j,k;
    j = 0;
    k = -1;
    Next[0] = -1;
	while(j < m)
    {
		if(k == -1 || b[j] == b[k])
        Next[++j] = ++k;
		else k = Next[k];
    }
}

// `得到b在a中的第一次出现位置`
// `因为next与STL冲突所以用Next代替`
int KMP_Index(char a[N], char b[N], int n, int m)
{
	int i = 0, j = 0;
    getNext(b, m);
    while(i < n)
    {
		if(j == -1||a[i] == b[j])
        {
            i++;
            j++;
        }
        else j = Next[j];
    }
    if(j != 0) return false;
    return true;
    if(j == m) return i - m + 1;
	else return -1;
}

int n;

int main() {
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    n--;
    for(int i = 0; i < n / 2; i++) swap(a[i], a[n - i - 1]);

    for(int i = 0; i < n; i++)
    if(b[i] == 'N') b[i] = 'S';
    else if(b[i] == 'S') b[i] = 'N';
    else if(b[i] == 'W') b[i] = 'E';
    else if(b[i] == 'E') b[i] = 'W';
    if(KMP_Index(b, a, n, n)) puts("YES");
    else puts("NO");
    return 0;
}
