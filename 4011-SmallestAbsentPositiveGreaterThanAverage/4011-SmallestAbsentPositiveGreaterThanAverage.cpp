// Last updated: 11/05/2026, 01:30:04
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for (int i: nums){
            sum += i;
        }
        int avg = sum/size;
        // cout<<sum << " "<<nums.size()<<" "<<avg<<endl;
        int MAX = 200;
        for (int i = max(1,avg); i <= 200; i++){
            // cout<<i<<avg<<endl;
            if (find(nums.begin(), nums.end(), i) == nums.end()){
                // cout<<i<<endl;
                if (i > avg) return i;
            }
        }
        return 0;
    }
};