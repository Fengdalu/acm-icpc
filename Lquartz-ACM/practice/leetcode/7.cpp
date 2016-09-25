class Solution {
public:
    int reverse(int x) {
	int neg = 1;
	if(x < 0) x *= -1, neg = -1;
	long long ret = 0;
	while(x) {
	    ret = ret * 10 + x % 10;
	    if(ret * neg > INT_MAX || ret * neg < INT_MIN) return 0;
	    x /= 10;
	}
	return ret * neg;
    }
};
