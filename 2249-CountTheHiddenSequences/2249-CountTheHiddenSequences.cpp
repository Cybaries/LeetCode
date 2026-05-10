// Last updated: 11/05/2026, 01:31:22
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int low = lower, up = upper;
        for (int x:differences){
            low = max(lower,low+x);
            up = min(upper,up+x);
            if (low > upper || up < lower)
            return 0;
        }
        return up-low+1;
//         lo, up = lower, upper
//         for diff in differences:
//             lo, up = max(lower, lo + diff), min(upper, up + diff)
//             if lo > upper or up < lower: return 0

//         return up - lo + 1
    }
};