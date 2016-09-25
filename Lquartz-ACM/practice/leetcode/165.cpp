#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getVers(string & v, vector<int> & vers) {
	int i, j;
	vers.clear();
	for(i = 0; i < v.length(); ) {
	    for(j = i + 1; j < v.length() && v[j] != '.'; ++j);
	    vers.push_back(atoi(v.substr(i, j - i).c_str()));
	    i = j;
	    if(v[i] == '.') ++i;
	}
    }
    int compareVersion(string version1, string version2) {
	vector<int> ver1, ver2;
	getVers(version1, ver1);
	getVers(version2, ver2);
	while(ver1.size() < ver2.size()) ver1.push_back(0);
	while(ver2.size() < ver1.size()) ver2.push_back(0);
	int i, n = ver1.size();
	for(i = 0; i < n; ++i) {
	    if(ver1[i] == ver2[i]) continue;
	    if(ver1[i] < ver2[i]) return -1;
	    if(ver1[i] > ver2[i]) return 1;
	}
	return 0;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.0", "1") << endl;
    cout << s.compareVersion("1.0", "1.1") << endl;

    return 0;
}
