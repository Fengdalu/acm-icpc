#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

const int maxn = 100010;
char buf[100];
std::pair<unsigned long long, int>ans[maxn];
std::pair<int, int>a[maxn];
int J;
int n;
std::map<unsigned long long, int>dic;
std::string word[2 * maxn];
int c[maxn];
int cnt;
int m;

int get(std::string s) {
    unsigned long long mask = 0;
    for(int i = 0; i < s.size(); i++) {
        unsigned long long cur;
        if(s[i] == '#') cur = 63;
        if(s[i] == '.') cur = 27;
        else if(s[i] >= 'a') cur = 28 + s[i] - 'a';
        else cur = s[i] - 'A' + 1;
        mask = mask * 67 + cur;
    }
    std::map<unsigned long long, int>::iterator it = dic.find(mask);
    if(it == dic.end())  {
        dic.insert(std::make_pair(mask, cnt));
        word[cnt] = s;
        return cnt++;
    }
    else return it->second;
}

int main() {
    scanf("%d", &n);
    m = 0;
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        std::string s = std::string(buf);
        s = s.substr(7, s.size() - 7);
        int b = s.find("/");
        if(b != -1)
            a[m++] = std::make_pair(get(s.substr(0, b)), get(s.substr(b + 1, s.size() - b - 1)));
        else
            a[m++] = std::make_pair(get(s), get("#"));
        
    }
    std::sort(a, a + m);
    m = std::unique(a, a + m) - a;
    J = 0;
    int q = 0;
    for(int i = 0; i < m; i++) {
        c[q++] = a[i].second;
        if(i == m - 1 || a[i].first != a[i + 1].first) {
            unsigned long long mask = 0;
            for(int j = 0; j < q; j++)
                mask = mask * (cnt + 17) + (c[j]);
            ans[J++] = std::make_pair(mask, a[i].first);
            q = 0;
        }
    }
    std::sort(ans, ans + J);
    int tot = 0;
    int pre = -1;
    for(int i = 0; i < J; i++)
        if(i == J - 1 || ans[i].first != ans[i + 1].first) {
            if(i - pre > 1) tot++;
            pre = i;
        }
    printf("%d\n", tot);
    pre = -1;
    for(int i = 0; i < J; i++)
        if(i == J - 1 || ans[i].first != ans[i + 1].first) {
            if(i - pre > 1) {
                for(int j = pre + 1; j < i + 1; j++) printf("http://%s ", word[ans[j].second].c_str());
                puts("");
            }
            pre = i;
        }
    return 0;
}
