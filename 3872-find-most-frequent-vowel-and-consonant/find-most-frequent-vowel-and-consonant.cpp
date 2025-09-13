class Solution {
public:
    int maxFreqSum(string s) {
        if (s.size() == 0) return 0;
        int mxEven = 0, mxOdd = 0;
        unordered_map<char,int> mp;
        for (char c:s){
            mp[c]++;
        }
        for (auto i: mp){
            if (i.first == 'a' || i.first == 'e' || i.first == 'i' || i.first == 'o' || i.first == 'u'){
                mxEven = max(mxEven, i.second);
            }
            else{
                mxOdd = max(mxOdd, i.second);
            }
        }
        return mxEven + mxOdd;
    }
};