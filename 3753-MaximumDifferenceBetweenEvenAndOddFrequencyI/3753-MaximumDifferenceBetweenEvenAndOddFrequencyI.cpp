// Last updated: 11/05/2026, 01:30:11
class Solution {
public:
    int maxDifference(string s) {
        int mxOdd = 0, minEven = INT_MAX;
        vector<int> freq (26, 0);
        for (char i: s) freq[i-97]++;
        for (int i: freq){
            if (i != 0){
                if (i % 2 == 0) {
                    minEven = min(minEven, i);
                }
                else{
                    mxOdd = max(mxOdd, i);
                }
            }
        }
        // cout <<mxOdd <<" "<<minOdd<<" "<<mxEven<<" "<<minEven<<endl;
        return (mxOdd - minEven);
    }
};