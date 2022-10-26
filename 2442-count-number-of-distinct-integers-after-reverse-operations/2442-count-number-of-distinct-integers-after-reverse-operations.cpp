class Solution {
    int reverse(int n){
        int res = 0;
        while(n > 0){
            res = res *10 + (n%10);
            n /= 10;
        }
        return res;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); i++){
            st.insert(reverse(nums[i]));
        }
        return st.size();
    }
};