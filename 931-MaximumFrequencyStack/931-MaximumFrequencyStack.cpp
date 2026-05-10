// Last updated: 11/05/2026, 01:32:06
class FreqStack {
public:
    unordered_map<int,int> frequency;
    unordered_map<int,stack<int>> group_stack;
    int max_frequency=0;
    FreqStack() {
        
    }
    void push(int val) {
        frequency[val]++;
        max_frequency=max(max_frequency,frequency[val]);
        group_stack[frequency[val]].push(val);
    }
    
    int pop() {
        int top_max_frequency=group_stack[max_frequency].top();
        group_stack[max_frequency].pop();
        frequency[top_max_frequency]--;
        if(group_stack[max_frequency].size()==0)
            max_frequency--;
        return top_max_frequency;
    }
};
