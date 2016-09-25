class Solution {
public:
    int myAtoi(string str) {
	long long ret = 0;
	int st = 0;
	int en = str.length();
	int neg = 0;
	while(st < en && str[st] == ' ') st++;
	while(st < en && str[en - 1] == ' ') en--;
	if(str[st] == '-') st++, neg = 1;
	else if(str[st] == '+') st++;
	if(st >= en) return 0;
	while(st < en) {
	    if(str[st] < '0' || str[st] > '9') break;
	    ret = ret * 10 + str[st] - '0';
	    if(!neg) {
		if(ret > INT_MAX) return INT_MAX;
	    }
	    else {
		if(ret * -1 < INT_MIN) return INT_MIN;
	    }
	    st++;
	}
	if(neg) ret *= -1;
	if(ret > INT_MAX) return INT_MAX;
	if(ret < INT_MIN) return INT_MIN;
	return (int)ret;
    }
};

int main() {

    return 0;
}
