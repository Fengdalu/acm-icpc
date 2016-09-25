#include <bits/stdc++.h>

char buf[1000000];
int main() {
    while(true) {
        std::map<std::pair<std::string, std::string>, int> f;
        while(true) {
            if(gets(buf) == NULL) exit(0);
            if(!strcmp(buf, "####")) break;
            std::queue<std::string>s;
            std::string word("");
            int len = strlen(buf);
            while(buf[len - 1] == ' ') len--;
            for(int i = 0; i != len; i++) {
                if(buf[i] == ',' || i == len - 1) {
                    if(buf[i] != ',') word.push_back(buf[i]);
                    if(word.size()) s.push(word);
                    word = "";
                    while(s.size() >= 2) {
                        std::string p = s.front(); s.pop();
                        f[std::make_pair(p, s.front())]++;
                    }
                    while(s.size()) s.pop();
                }
                else if(buf[i] == ' ') {
                    if(word.size()) s.push(word);
                    word = "";
                    while(i + 1 != len - 1 && buf[i + 1] == ' ') i++;
                }
                else word.push_back(buf[i]);
            }
        }
        std::vector<std::pair<int, std::string> > ans;
        for(std::map<std::pair<std::string, std::string>, int>::iterator
                it = f.begin(); it != f.end(); it++) {
            //printf("%s %s %d\n", it->first.first.c_str(), it->first.second.c_str(), it->second);
            ans.push_back(std::make_pair(it->second, it->first.first + " " + it->first.second));
        }
        std::sort(ans.begin(), ans.end());
        int sz = ans.size() - 1;
        int p = ans[sz].first;
        for(int i = 0; i != ans.size(); i++)
            if(ans[i].first == p) {
                printf("%s:%d\n", ans[i].second.c_str(), ans[i].first);
                break;
            }

    }
    return 0;
}

