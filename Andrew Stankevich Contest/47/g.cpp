#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[12], t[12];
double dp[11][11];
double dp1[11][11];
int main() {
    int d, b;
    for(d = 1; d <= 10; d++) for(b = 2; b <= 10; b++) if(pow(b + 1, d) <= 3000) {
        cout << d << " " << b << endl;
        int Q = pow(b, d);
        map<ll, int>c;
        for(int i = 0; i < Q; i++) {
            vector<int>q;
            int k = i;
            for(int j = 0; j < d; j++) {
                q.push_back(k % b);
                k /= b;
            }
            for(int j = 0; j < d; j++) a[j] = -1;
            for(auto &x: q) {
                int m = -1, p = -1;
                for(int j = 0; j < d; j++) if(a[j] == -1) {
                    a[j] = x;
                    for(int k = 0; k < Q; k++) {
                        int tmp = k;
                        for(int ii = 0; ii < d; ii++) {
                            t[ii] = tmp % b;
                            tmp /= b;
                        }
                    }
                    for(int k = 0; k < d; k++) if(a[k] != -1) t[k] = a[k];
                    ll tmp = 0;
                    for(int k = 0; k < d; k++) tmp = tmp * 10 + t[k];
                    if(tmp > m) {
                        p = j;
                        m = tmp;
                    }
                    a[j] = -1;
                }
                a[p] = x;
            }
            ll tmp = 0;
            for(int j = 0; j < d; j++) tmp = tmp * 10ll + a[j];
            c[tmp]++;
        }
        int ans1 = 0, ans2 = 0;
        for(auto &P: c) {
            for(int k = 0; k < Q; k++) {
                vector<int>q;
                int K = k;
                for(int i = 0; i < d; i++) q.push_back(K % b), K /= b;
                for(int i = 0; i < d; i++) a[i] = -1;
                for(auto x: q) {
                    int p = -1;
                    ll s1 = -1, s2 = 1e9;
                    for(int j = 0; j < d; j++) if(a[j] == -1) {
                        int count1 = 0, count2 = 0;
                        a[j] = x;
                        for(int k = 0; k < Q; k++) {
                            int K = k;
                            for(int i = 0; i < d; i++) t[i] = K % b, K /= b;
                            for(int i = 0; i < d; i++) if(a[i] != -1) t[i] = a[i];
                            ll tmp = 0;
                            for(int i = 0; i < d; i++) tmp = tmp * 10ll + t[i];
                            if(tmp > P.first) count1++;
                            else if(tmp < P.first) count2++;
                        }
                        if(count1 > s1 || (count1 == s1 && count2 < s2)) {
                            s1 = count1;
                            s2 = count2;
                            p = j;
                        }
                        a[j] = -1;
                    }
                    a[p] = x;
                }
                ll tmp = 0;
                for(int i = 0; i < d; i++) tmp = tmp * 10ll + a[i];
                if(P.first > tmp) ans1 += P.second;
                else if(P.first < tmp) ans2 += P.second;
            }
        }
        dp[d][b] = 1.0 * ans1 / Q / Q;
        dp1[d][b] = 1.0 * ans2 / Q / Q;
    }
    printf("const double dp[11][11] = {");
        for(int i = 0; i <= 10; i++) {
            if(i != 0) printf(",");
            printf("{");
            for(int j = 0; j <= 10; j++) {
                if(j != 0) printf(",");
                printf("%.15f", dp[i][j]);
            }
            printf("}");
        }
    printf("};");

    printf("const double dp1[11][11] = {");
        for(int i = 0; i <= 10; i++) {
            if(i != 0) printf(",");
            printf("{");
            for(int j = 0; j <= 10; j++) {
                if(j != 0) printf(",");
                printf("%.15f", dp1[i][j]);
            }
            printf("}");
        }
    printf("};");

    return 0;
}
