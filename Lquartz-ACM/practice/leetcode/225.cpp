#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> Q[2];
    int p = 0, q = 1;
public:
    // Push element x onto stack.
    void push(int x) {
        Q[p].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
	if(empty()) return;
        int n = Q[p].size();
	while(n > 1) {
	    --n;
	    Q[q].push(Q[p].front());
	    Q[p].pop();
	}
	Q[p].pop();
	p ^= 1;
	q ^= 1;
    }

    // Get the top element.
    int top() {
        int n = Q[p].size();
	while(n > 1) {
	    --n;
	    Q[q].push(Q[p].front());
	    Q[p].pop();
	}
	int ret = Q[p].front();
	Q[q].push(Q[p].front());
	Q[p].pop();
	p ^= 1;
	q ^= 1;
	return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q[p].empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    cout << s.top() << endl;
    s.push(2);
    cout << s.top() << endl;
    //s.pop();
    //s.pop();

    return 0;
}
