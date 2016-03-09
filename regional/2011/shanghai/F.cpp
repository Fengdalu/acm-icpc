#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <sstream>

const int Maxn = 1000;
const int Maxm = Maxn * Maxn;
char buf[3000];
std::string word[100];
std::string line;
std::map<unsigned, int>dic;
int ind[Maxn];
int t[Maxm], nt[Maxm];
int wcnt, cnt;
unsigned target;
bool vis[Maxn];
int type[Maxn];
bool flag;
int start;
unsigned Hash(std::string& s)
{
    unsigned ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        ans = ans * 31 + (s[i] - 'a' + 1);
    }
    return ans;
}
int get(std::string &s)
{
    unsigned ans = Hash(s);
    std::map<unsigned, int>::iterator it = dic.find(ans);
    if(it == dic.end())
    {
        dic.insert(std::make_pair(ans, ++wcnt));
        return wcnt;
    }
    else return it->second;
}

void add(int a, int b)
{
    //    std::cout << a <<" " << b << std::endl;
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

bool dfs1(int x)
{
    //    std::cout << x << std::endl;
    vis[x] = true;
    if(x == target) flag = true;
    for(int k = ind[x]; k != -1; k = nt[k])
        if(!vis[x] && !dfs1(t[k])) return false;
    return true;
}

bool dfs(int x)
{
    if(x == target) return true;
    vis[x] = true;
    for(int k = ind[x]; k != -1; k = nt[k])
        if(!vis[t[k]] && dfs(t[k])) return true;
    return false;
}

int main()
{
    //    freopen("F.in", "r", stdin);
    int Case;
    scanf("%d", &Case);
    gets(buf);
    for(int T = 1; T <= Case; T++)
    {
        printf("Case #%d:\n", T);
        memset(vis, 0, sizeof vis);
        wcnt = 0;
        cnt = 0;
        dic.clear();
        memset(ind, -1, sizeof ind);
        memset(type, 0, sizeof type);
        while(true)
        {
            gets(buf);
            line = std::string(buf);
            if(line[line.size() - 1] == '.')
            {
                line = line.substr(0, line.size() - 1);
                std::istringstream in(line);
                int cnt = 0;
                while(in >> word[cnt++]);
                cnt--;
                if(cnt == 3 && (word[1] == "are"))
                {
                    word[0].append("n");
                    word[2].append("n");
                    unsigned a = get(word[0]), b = get(word[2]);
                    add(a, b);
                    type[a] = type[b] = 0;
                    
                }
                else if(cnt == 3 && (word[1] == "can"))
                {
                    word[0].append("n");
                    word[2].append("v");
                    unsigned a = get(word[0]), b = get(word[2]);
                    add(a, b);
                    type[a] = 0;
                    type[b] = 1;
                }
                else if(cnt == 6 && word[0] == "everything" && word[4] == "can")
                {
                    word[3].append("v");
                    word[5].append("v");
                    unsigned a = get(word[3]), b = get(word[5]);
                    add(a, b);
                    type[a] = 1;
                    type[b] = 1;
                }
                else if(cnt == 6 && word[0] == "everything" && word[4] == "are")
                {
                    word[3].append("v");
                    word[5].append("n");
                    unsigned a = get(word[3]), b = get(word[5]);
                    add(a, b);
                    type[a] = 1;
                    type[b] = 0;
                }
            }
            else if(line[line.size() - 1] == '?')
            {
                line = line.substr(0, line.size() - 1);
                std::istringstream in(line);
                int cnt = 0;
                while(in >> word[cnt++]);
                cnt--;
                for(int i = 1; i <= wcnt; i++) vis[i] = false;
                if(cnt == 3 && word[0] == "can")
                {
                    word[2].append("v");
                    word[1].append("n");
                    target = get(word[2]);
                    if(dfs(get(word[1])))
                    {
                        printf("Y");
                    }
                    else printf("M");
                }
                if(cnt == 3 && word[0] == "are")
                {
                    word[2].append("n");
                    word[1].append("n");
                    target = get(word[2]);
                    if(dfs(get(word[1])))
                    {
                        printf("Y");
                    }
                    else printf("M");
                }
                else if(cnt == 6 && word[0] == "can")
                {
                    word[4].append("v");
                    word[5].append("v");
                    start = get(word[4]);
                    target = get(word[5]);
                    flag = false;
                    if(dfs(get(word[4])))
                    {
                        printf("Y");
                    }
                    else printf("M");
                }
                else if(cnt == 6 && word[0] == "are")
                {
                    word[4].append("v");
                    word[5].append("n");
                    start = get(word[4]);
                    target = get(word[5]);
                    flag = false;
                    if(dfs(get(word[4])))
                    {
                        printf("Y");
                    }
                    else printf("M");
                }
            }
            else break;
        }
        puts("");
    }
    return 0;
}