class MinStack {
    stack<pair<int,int> > sta;
public:
    void push(int x) {
        int val = x;
	if(!sta.empty()) val = min(val, sta.top().second);
	sta.push(make_pair(x, val));
    }

    void pop() {
        if(!sta.empty()) sta.pop();
    }

    int top() {
        return sta.top().first;
    }

    int getMin() {
        return sta.top().second;
    }
};
