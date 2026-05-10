// Last updated: 11/05/2026, 01:30:40
class Solution {
public:
    bool digitCount(string num) {
        vector<int> v(10,0);
        for (auto i: num){
            v[i-48]++;
            // cout<<i-48;
        }
        // for (auto i: v){
        //     cout<<i<<" ";
        // }
        for (int i = 0; i < num.size(); i++){
            cout<<num[i]<<" "<<v[i]<<endl;
            if (num[i]-48 != v[i])
                return false;
        }
        return true;
    }
};