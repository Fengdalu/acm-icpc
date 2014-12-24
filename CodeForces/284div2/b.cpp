#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#define N 50010

using namespace std;

map<string, string>dic;
string a, b;
map<string ,string >::iterator it;;


int main()
{
	ios::sync_with_stdio(false);
	dic.clear();
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if(a.length() > b.length()) dic.insert(make_pair(a, b));
		else dic.insert(make_pair(b, a));
	}
	
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		it = dic.find(a);
		if(it == dic.end()) cout << a << " ";
		else cout << it->second << " ";
	}
	cout << endl;
	return 0;
} 