#include <bits/stdc++.h>

const int N = 100*1000;
struct node {
    std::string word;
    std::map<std::string, int >to;
    bool vis;
} f[N];
char buf[10000];
int tot;
std::string words[280];

void build(int &rt, int p, int cnt) {
    if(rt == 0) {
        rt = ++tot;
        f[rt].word = "";
        f[rt].to.clear();
        f[rt].vis = false;
    }
    //printf("INSERT: %d %s\n", rt, words[p].c_str());
    f[rt].word = words[p];
    if(p == cnt - 1) f[rt].vis = true;
    if(p != cnt - 1) build(f[rt].to[words[p + 1]], p + 1, cnt);
}

void output(int rt, int d) {
    if(d == 0) {
        for(std::map<std::string, int>::iterator it = f[rt].to.begin(); it != f[rt].to.end(); it++) {
            if(f[it->second].to.size()) output(it->second, d + 1);
        }
        for(std::map<std::string, int>::iterator it = f[rt].to.begin(); it != f[rt].to.end(); it++) {
        if(f[it->second].to.size() == 0)
        {
            for(int i = 0; i <= d - 1; i++)  printf("    ");
                printf("%s\n", f[it->second].word.c_str());
        }
        else if(f[it->second].vis)
        {
             for(int i = 0; i <= d - 1; i++)  printf("    ");
                printf("%s\n", f[it->second].word.c_str());
        }
    }
        return;
    }
//    bool flag = false;
    if(f[rt].to.size()) {
        for(int i = 0; i < d - 1; i++)  printf("    ");
        printf("%s\n", f[rt].word.c_str());
    }
    for(std::map<std::string, int>::iterator it = f[rt].to.begin(); it != f[rt].to.end(); it++) {
        if(f[it->second].to.size()) output(it->second, d + 1);
    }
    for(std::map<std::string, int>::iterator it = f[rt].to.begin(); it != f[rt].to.end(); it++) {
        if(f[it->second].to.size() == 0)
        {
            for(int i = 0; i <= d - 1; i++)  printf("    ");
                printf("%s\n", f[it->second].word.c_str());
        }
        else if(f[it->second].vis)
        {
             for(int i = 0; i <= d - 1; i++)  printf("    ");
                printf("%s\n", f[it->second].word.c_str());
        }
    }
//    if(f[rt].vis) {
//        for(int i = 0; i < d - 1; i++)  printf("    ");
//        printf("%s\n", f[rt].word.c_str());
//    }
}

int rt = 1;
int main() {
    int _cas = 0;
    while(true) {
        f[rt].to.clear();
        tot = 0;
        rt = 0;
        while(true) {
            if(gets(buf) == NULL) exit(0);
            if(!strcmp(buf, "0")) break;
            std::string t("");
            int len = strlen(buf);
            // while(buf[len - 1] == ' ') len--;
            int cnt = 0;
            words[cnt++] = "";
            t = "";
            for(int i = 0; i != len; i++) {
                if(buf[i] == '/') {
                    words[cnt++] = t;
                    t = "";
                }
                else t.push_back(buf[i]);
            }
            if(t.size()) words[cnt++] = t;
            //for(int i = 0; i != cnt; i++) printf("%s ", words[i].c_str()); puts("");
            for(int i = 0; i != cnt; i++) {
                int j = 0;
                while(words[i][j] == ' ') j++;
                int k = words[i].size() - 1;
                while(words[i][k] == ' ') k--;
                // words[i] = words[i].substr(j, k - j + 1);
            }
            build(rt, 0, cnt);
        }
        printf("Case %d:\n", ++_cas);
        output(rt, 0);
    }
    return 0;
}

