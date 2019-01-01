#include <bits/stdc++.h>

template<typename T> T SQR(T x) { return x * x; }
int main() {
    for(int A = 1; A <= 1000; A++)
        for(int B = 1; B <= 1000 - A; B++) {
            int C = 1000 - A - B;
            if(SQR(A) + SQR(B) == SQR(C)) {
                printf("%d", A * B * C);
                return 0;
            }
        }
    return 0;
}
