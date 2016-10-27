#include <bits/stdc++.h>

const int M = 26;
const int N = 2000;
struct trie {
    int to[N][M]; // 节点指针
    int w[256]; // 字母下标
    int fail[N]; // 失配指针
    int cnt;

    trie() {
        // 标注下标
    }

    int newNode() {
        memset(to[cnt], 0, sizeof to[cnt]);
        return cnt++;

    }
    void init() {
        cnt = 0;
        memset(to[0], 0, sizeof to[0]);
    }

    void insert(char *a, int mask) {
        int p = 0;
        while(*a) {
            int v = w[*a];
            if(!to[p][v]) {
                to[p][v] = newNode();
            }
            p = to[p][v];
            a++;
        }
    }

    void ac() {
        std::queue<int>q;
        memset(fail, 0, sizeof fail);
        for(int i = 0; i < 4; i++) if(to[0][i]) {
            q.push(to[0][i]);
        }
        while(q.size()) {
            int p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int v = to[p][i];
                if(v) {
                    fail[v] = to[fail[p]][i];
                    q.push(v);
                }
                else
                    to[p][i] =  to[fail[p]][i];
            }
        }
    }
};
