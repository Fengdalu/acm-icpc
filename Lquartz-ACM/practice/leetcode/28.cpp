class Solution {
public:
    int strStr(string haystack, string needle) {
	int i, j;
	for(i = 0; i + needle.length() <= haystack.length(); ++i) {
	    for(j = needle.length() - 1; j >= 0; --j) {
		if(needle[j] != haystack[i + j]) break;
	    }
	    if(j < 0) return i;
	}
	return -1;
    }
};
