class MyQueue {
    vector<int> s;
    int cnts = 0;
public:
    MyQueue() {
        s.resize(9);
    }
    
    void push(int x) {
        s[cnts++] = x;
    }
    
    int pop() {
        int x = s[0];
        s.erase(s.begin());
        cnts--;
        return x;
    }
    
    int peek() {
        return s[0];
    }
    
    bool empty() {
        return !cnts;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */