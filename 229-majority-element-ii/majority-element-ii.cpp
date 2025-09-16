class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = -1e9-1, el2 = -1e9-2;
        for (int i: nums){
            if (cnt1 == 0 && el2 != i){
                cnt1 = 1;
                el1 = i;
            }
            else if (cnt2 == 0 && el1 != i){
                cnt2 = 1;
                el2 = i;
            }
            else if (i == el1) cnt1++;
            else if (i == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i : nums){
            if (el1 == i) cnt1++;
            if (el2 == i ) cnt2++;
        }
        vector<int> ans;
        int check = int(nums.size()/3);
        if (cnt1 > check) ans.push_back(el1);
        if (cnt2 > check) ans.push_back(el2);
        return ans;
    }
};