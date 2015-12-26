#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
using namespace std;
#define LL long long
#define cmin(x, y) x = min(x, y)
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

string s;
string line;
map<string, int>f;
map<string, int>::iterator it;
set<string>S;
string word;
char buf[1000010];
typedef pair<int, string> obj;
obj ans[20000];
int cnt;

void get(string &s) {
    gets(buf);
    s = string(buf);
}

bool valid(char x) {
    if('a' <= x && x <= 'z') return true;
    if('A' <= x && x <= 'Z') return true;
    return false;
}

int main() {
    //freopen("input.in", "r", stdin);
    int T; scanf("%d", &T);
    gets(buf);
    while(T) {
        get(line);
        T--;
        S.clear();
        f.clear();
        while(true) {
            get(line);
            if(line == "</oldwords>") break;
            istringstream is(line);
            while(is >> word) {
                for(int i = 0; i < word.length(); i++) word[i] = tolower(word[i]);
                S.insert(word);
            }
        }
        get(line);
        bool flg = false;
        while(true) {
            //if(!flg)
            word = "";
            get(line);

            if(line == "</article>") break;
            for(int i = 0; i < line.length(); i++) {
                if(valid(line[i])) {
                    word.push_back(tolower(line[i]));
                }
                else {
                    /*
                    if(i == line.length() - 1 && line[i] == '-' && word.length() > 0) {
                        flg = true;
                        break;
                    }
                    */
                    if(word != "" && (word.length() > 0) && (S.find(word) == S.end()) ) f[word]++;
                    word = "";
                }
            }
            //if(!flg)
            if((word.length() > 0) && (S.find(word) == S.end())) f[word]++;
            word = "";
        }
        cnt = 0;
        for(it = f.begin(); it != f.end(); it++) if(it->AA.length() > 0){
            ans[cnt].AA = -it->BB;
            ans[cnt].BB = it->AA;
            cnt++;
        }
        if(cnt < 10) {
            sort(ans, ans + cnt);
        }
        else {
            nth_element(ans, ans + 9, ans + cnt);
            sort(ans, ans + 9);
        }
        for(int i = 0; i < min(cnt, 10); i++) {
            printf("%s\n", ans[i].BB.c_str(), ans[i].AA);
        }
        printf("\n");
    }
    return 0;
}
