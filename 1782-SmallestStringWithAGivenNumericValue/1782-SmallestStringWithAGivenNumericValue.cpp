// Last updated: 11/05/2026, 01:31:37
class Solution {
public:
    string getSmallestString(int n, int k) {
        string str(n,'a');
        k -= n;
        while(k>0){
            str[n-1] += min(25,k);
            k-= min(25,k);
            n--;
        }
        return str;
    }
};