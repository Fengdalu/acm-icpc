class Queue {
    stack<int> s1, s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
	s2.push(x);
	        
    }

    // Removes the element from in front of queue.
    void pop(void) {
	if(s1.empty()) {
	    while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	    }
	}
	if(!s1.empty()) {
	    s1.pop();
	}
        
    }

    // Get the front element.
    int peek(void) {
	if(s1.empty()) {
	    while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	    }
	}
	return s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
	if(s1.empty() && s2.empty()) return true;
	else return false;
    }
};
