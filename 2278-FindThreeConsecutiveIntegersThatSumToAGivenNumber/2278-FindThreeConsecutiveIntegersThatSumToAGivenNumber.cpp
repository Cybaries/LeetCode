// Last updated: 11/05/2026, 01:31:16
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> n;
        if (num%3 == 0){
            long long p = num/3;
            n.push_back(p-1);
            n.push_back(p);
            n.push_back(p+1);
        }
        return n;
    }
};