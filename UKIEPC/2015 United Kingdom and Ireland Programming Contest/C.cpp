#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
#define LL long long

int n;
vector<string>s;
map< string, vector<string> >dic;
map< string, vector<string> >::iterator it;

map<string, int>f1, f;
map<string, int>::iterator it2;
char buf[2000100];
string line;

int cmp(const string& a, const string& b)
{
    if(f1[a] == f1[b]) return a < b;
    return f1[a] > f1[b];
}

int main()
{
    //freopen("c.in", "r", stdin);
    int n; scanf("%d", &n);
    gets(buf);
    for(int i = 0; i < n; i++)
    {
        gets(buf);
        line = string(buf);
        istringstream in(line);
        string name; in >> name;
        string word;
        vector<string>& v = dic[name];
        while(in >> word)
        {
            v.push_back(word);
            f1[word]++;
        }
    }
    for(it = dic.begin(); it != dic.end(); it++)
    {
        vector<string> &v = it->second;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for(int i = 0; i < v.size(); i++) f[v[i]]++;
    }
    s.clear();
    for(it2 = f.begin(); it2 != f.end(); it2++)
    if(it2->second == dic.size())
    {
        s.push_back(it2->first);
    }
    sort(s.begin(), s.end(), cmp);
    if(!s.size()) puts("ALL CLEAR");
    else for(int i = 0; i < s.size(); i++) printf("%s\n", s[i].c_str());
    return 0;
}
