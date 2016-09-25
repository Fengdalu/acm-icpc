class Solution {
    set<int> S;
public:
    int change(int n) {
	int ret = 0, p;
	while(n) {
	    p = n % 10;
	    n /= 10;
	    ret += p * p;
	}
	return ret;
    }
    bool isHappy(int n) {
        S.clear();
	while(1) {
	    if(n == 1) break;
	    n = change(n);
	    if(S.find(n) != S.end()) return false;
	    S.insert(n);
	}
	return true;
    }
};
