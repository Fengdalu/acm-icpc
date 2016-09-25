class Solution {

public:
    bool isIsomorphic(string s, string t) {
	int marks[300], markt[300];
	int curs, curt;
	memset(marks, -1, sizeof(marks));
	memset(markt, -1, sizeof(markt));
	curs = curt = 0;
	for(int i = 0; i < s.length(); ++i) {
	    if(marks[s[i]] == -1) marks[s[i]] = curs++;
	    if(markt[t[i]] == -1) markt[t[i]] = curt++;
	    if(marks[s[i]] != markt[t[i]]) return false;
	}
	return true;
    }
};
