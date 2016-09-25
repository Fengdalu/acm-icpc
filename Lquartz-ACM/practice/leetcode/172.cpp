

class Solution {
public:
    int trailingZeroes(int n) {
        int two = 0, five = 0;
	int m = n;
	while(m > 1) {
	    two += m / 2;
	    m /= 2;
	}
	m = n;
	while(m > 4) {
	    five += m / 5;
	    m /= 5;
	}
        return min(two, five);
    }
};
