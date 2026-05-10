// Last updated: 11/05/2026, 01:31:53
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        int x = 12;
        int y = 12;
        int z = 11;
        while(x <= high){
            if (x >= low){
                v.push_back(x);
            }
            x+=z;
            if (x%10 == 0){
                x =y*10 + ((y%10)+1);
                y = x;
                z = z*10 + 1;
            }
        }
        return v;
    }
};