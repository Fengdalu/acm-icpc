#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef long long ll;
#define AA first
#define BB second
#define MP make_pair
#define SZ size
#define PB push_back

int main(){
    int m, s;
    scanf("%d%d", &m, &s);
    int left = m, sum = s;
    string a(""), b("");
    for(int i = 0; i < m; i++) {
        left--;
        int cur = -1;
        int op = (i == 0 && m != 1) ? 1: 0;
        for(int j = op; j < 10; j++) if(cur == -1) {
            if(sum - j <= 9 * left) cur = j;
        }
        sum -= cur;
        if(~cur) a.push_back('0' + cur);
        else {
            printf("-1 -1\n");
            return 0;
        }
    }
    sum = s; left = m;
    for(int i = 0; i < m; i++) {
        left--;
        int cur = -1;
        int op = (i == 0 && m != 1)? 1: 0;
        for(int j = 9; j >= op; j--) if(cur == -1){
            if(sum - j >= 0) cur = j;
        }
        sum -= cur;
        if(~cur) b.push_back('0' + cur);
        else {
            printf("-1 -1\n");
            return 0;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
