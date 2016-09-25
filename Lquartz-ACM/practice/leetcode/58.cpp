class Solution {
public:
    int lengthOfLastWord(string s) {
	int ret = 0;
	int i, j;
	for(i = 0; i < s.length(); ) {
	    while(i < s.length() && s[i] == ' ') ++i;
	    for(j = i; j < s.length() && s[j] != ' '; ++j);
	    if(j - i > 0) ret = j - i;
	    i = j;
	}
	return ret;
    }
};
