#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

const int maxn = 100010;
char buf[100];
std::pair<std::vector<int>, int >ans[maxn];
std::pair<int, int>a[maxn];
int J;
int n;
std::map<std::string, int>dic;
std::string word[2 * maxn];
int c[maxn];
int cnt;
int m;

int get(std::string s) {
    std::map<std::string, int>::iterator it = dic.find(s);
    if(it == dic.end())  {
        dic.insert(std::make_pair(s, cnt));
        word[cnt] = s;
        return cnt++;
    }
    else return it->second;
}

int vcmp(std::vector<int>&a, std::vector<int>&b) {
	if(a.size() < b.size()) return 0;
	if(a.size() > b.size()) return 1;
	for(int i = 0; i < a.size(); i++) 
	if(a[i] < b[i]) return 0;
	else if(a[i] > b[i]) return 1;
	return -1;
}

bool cmp(std::pair< std::vector<int>, int> a, std::pair< std::vector<int>, int> b) {
	int code = vcmp(a.first, b.first);
	if(code == -1) return a.second < b.second;
	else return code;
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
            for(int j = 0; j < q; j++) 
				ans[J].first.push_back(c[j]);
            ans[J].second = a[i].first;
			J++;
            q = 0;
        }
    }
    std::sort(ans, ans + J, cmp);
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
        if(i == J - 1 || -1 != vcmp(ans[i].first, ans[i + 1].first)) {
            if(i - pre > 1) {
                for(int j = pre + 1; j < i + 1; j++) printf("http://%s ", word[ans[j].second].c_str());
                puts("");
            }
            pre = i;
        }
    return 0;
}
