#include <bits/stdc++.h>

const int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *name[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};


int main() {
    std::map<std::string, int> days;
    for(int i = 0; i < 7; i++) {
        days[name[i]] = i;
    }
    std::string x, y;
    std::cin >> x >> y;
    int offset = days[y] + 7 - days[x];
    offset %= 7;
    int tot = 0;
    for(int i = 0; i < 11; i++) {
        if((tot + a[i + 1] - tot) % 7 == offset) {
            puts("YES");
            return 0;
        }
        tot += a[i];
    }
    puts("NO");
    return 0;
}

