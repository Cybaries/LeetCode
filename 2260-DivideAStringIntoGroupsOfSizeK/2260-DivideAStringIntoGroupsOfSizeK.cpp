// Last updated: 11/05/2026, 01:31:20
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector <string> v;
        int n = s.size();
        for (int i = 0; i < n;){
            int j = 0;
            string str = "";
            for (;j<k && i<n;j++,i++){
                str += s[i];
            }
            if (j < k){
                while(j<k){
                    str+= fill;
                    j++;
                }
            }
            v.push_back(str);
        }
        return v;
    }
};