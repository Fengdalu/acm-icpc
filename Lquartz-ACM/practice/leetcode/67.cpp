class Solution {
public:
    string addBinary(string a, string b) {
	if(a.length() < b.length()) swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int p = 0, i;
	for(i = 0; i < b.length(); ++i) {
	    p = p + a[i] - '0' + b[i] - '0';
	    a[i] = '0' + p % 2;
	    p /= 2;
	}
	for(i = b.length(); i < a.length(); ++i) {
	    p = p + a[i] - '0';
	    a[i] = '0' + p % 2;
	    p /= 2;
	}
	if(p) {
	    a = a + '1';
	}
	reverse(a.begin(), a.end());
	return a;
    }
};
