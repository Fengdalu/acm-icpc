class Solution {
public:
    bool isValid(string s) {
	stack<char> sta;
	for(int i = 0; i < s.length(); ++i) {
	    if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
		sta.push(s[i]);
	    }
	    else if(sta.empty()) {
		return false;
	    }
	    else {
		if(sta.top() == '(' && s[i] == ')') {
		    sta.pop();
		}
		else if(sta.top() == '[' && s[i] == ']') {
		    sta.pop();
		}
		else if(sta.top() == '{' && s[i] == '}') {
		    sta.pop();
		}
		else return false;
	    }
	}
	return sta.empty();
    }
};
