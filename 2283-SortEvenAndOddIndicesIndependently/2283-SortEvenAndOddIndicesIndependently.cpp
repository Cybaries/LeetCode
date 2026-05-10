// Last updated: 11/05/2026, 01:31:01
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if (nums.size() <=2)
            return nums;
        vector<int> odd;
        vector<int> even;
        for(int i = 0; i< nums.size(); i++){
            // cout<<i<<" " <<nums[i]<<endl;
            if (i % 2)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        reverse(odd.begin(),odd.end());
        int pos = 0;
        for (int i = 0; i < even.size(); i++){
            // cout<<pos<<" "<<i<<endl;
            nums[pos] = even[i];
            pos+=2;
        }
        pos = 1;
        for (int i = 0; i < odd.size(); i++){
            // cout<<pos<<" "<<i<<endl;
            nums[pos] = odd[i];
            pos+=2;
        }
        return nums;
    }
};