#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define cmax(x, y) x = max(x, y)

map<string, int >Ind;
vector<int>to[50010];
pair<int, int>cnt[50010];
int n;
char buf[200];
vector<int>ans;

int main() {
    freopen("join.in", "r", stdin);
    freopen("join.out", "w", stdout);
    scanf("%d", &n);
    gets(buf);
    for(int i = 0; i < n; i++) {
        gets(buf);
        string w("");
        int len = strlen(buf);

        int j = 0;
        string name("");
        for(j = 0; ;j++) {
            if(buf[j] == ':') {
                name = w;
                w = "";
                j+=2;
                break;
            }
            else w +=buf[j];
        }
        //cout << "Name : "<< name < endl;
        bool flg = true;
        w = "";
        for(; j < len; j++) if(buf[j] == ' ' ) {
            if(w[0] == '@' && w != name) {
                if(Ind.find(w) != Ind.end()) {
                    to[i].push_back(Ind[w]);
                }
            }
            w = "";
        }else w += buf[j];
        if(w[0] == '@' && w != name) {
            if(Ind.find(w) != Ind.end()) {
                to[i].push_back(Ind[w]);
            }
        }
        cnt[i].first = 1;
        cnt[i].second = -1;
        for(int j = 0; j < to[i].size(); j++) {
            cmax(cnt[i].first, 1 + cnt[to[i][j]].first);
        }
        for(int j = 0; j < to[i].size(); j++) if(1 + cnt[to[i][j]].first == cnt[i].first) cnt[i].second = to[i][j];
        if(Ind.find(name) == Ind.end()) Ind[name] = i;
        else if(cnt[i].first > cnt[Ind[name]].first) Ind[name] = i;
    }

    int pos = 0;
    for(int i=0; i < n; i++) {
        if(cnt[i].first > cnt[pos].first) pos = i;
    }
    ans.clear();
    while(pos != -1) {
        ans.push_back(pos);
        pos = cnt[pos].second;
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i = 0; i != ans.size(); i++) {
        printf("%d ", ans[i] + 1);
    }
    fclose(stdout);
    return 0;
}