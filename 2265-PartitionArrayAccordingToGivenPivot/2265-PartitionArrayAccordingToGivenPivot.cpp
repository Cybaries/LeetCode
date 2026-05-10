// Last updated: 11/05/2026, 01:31:15
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q;
        queue<int>s;
        int count = 0;
        for (int x: nums){
            if (x < pivot)
                q.push(x);
            else if (x > pivot)
                s.push(x);
            else count++;
        }
        
        int i = 0;
        for (; i < nums.size() && q.size() > 0; i++){
            nums[i] = q.front();
            q.pop();
        }
        while(count-- && i< nums.size()){
            nums[i]=pivot;
            i++;
        }
        for (; i < nums.size() && s.size() > 0; i++){
            nums[i] = s.front();
            s.pop();
        }
        return nums;
    }
};