class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
	if(digits.size() == 0) digits.push_back(0);
	reverse(digits.begin(), digits.end());
	int p = 1 + digits[0], i;
	digits[0] = p % 10;
	p /= 10;
	for(i = 1; p && i < digits.size(); ++i) {
	    p = p + digits[i];
	    digits[i] = p % 10;
	    p /= 10;
	}
	if(p) digits.push_back(p);
	reverse(digits.begin(), digits.end());
	return digits;
    }
};
