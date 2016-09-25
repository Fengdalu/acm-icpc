class Solution {
    int cnt[300], cns[300];
public:
    bool isAnagram(string s, string t) {
	int i;
	memset(cnt, 0, sizeof(cnt));
	for(i = 0; i < s.length(); ++i) cns[s[i]]++;
	for(i = 0; i < t.length(); ++i) cnt[t[i]]++;
	for(i = 0; i < 300; ++i) if(cns[i] != cnt[i]) return false;
	return true;
    }
};
