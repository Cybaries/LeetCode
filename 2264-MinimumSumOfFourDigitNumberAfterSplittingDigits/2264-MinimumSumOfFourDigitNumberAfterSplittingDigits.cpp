// Last updated: 11/05/2026, 01:31:17
class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        v.push_back(num%10);
        v.push_back((num/10)%10);
        v.push_back((num/100)%10);
        v.push_back(num/1000);
        sort(v.begin(),v.end());
        int x,y;
        x = v[0]*10+v[3];
        y = v[1]*10+v[2];
        return x+y;
    }
};