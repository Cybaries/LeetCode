// Last updated: 11/05/2026, 01:31:05
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q0;
        queue<int> q1;
        for (int n: nums){
            if (n > 0)
                q0.push(n);
            else
                q1.push(n);
        }
        for (int i = 0; i < nums.size()/2; i++){
                nums[i*2+1] = q1.front(); 
                q1.pop();
                nums[2*i] = q0.front();
                q0.pop();
        }
        return nums;
    }
};