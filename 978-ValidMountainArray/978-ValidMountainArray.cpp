// Last updated: 11/05/2026, 01:32:10
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        int i = 0, count1 = 0, count2 = 0, n = arr.size();
        for (i; i < n-1; i++){
            if (arr[i] >= arr[i+1])
                break;
            else
                count1++;
        }
        for (i; i < n-1; i++){
            if (arr[i] <= arr[i+1])
                break;
            else
                count2++;
        }
        if (count1 == 0 || count2 == 0)
            return false;
        if (count1 + count2 == n-1)
            return true;
        else
            return false;
    }
};