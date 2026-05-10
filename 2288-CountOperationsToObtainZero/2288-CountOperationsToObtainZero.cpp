// Last updated: 11/05/2026, 01:30:57
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while(num1 != 0 && num2 != 0){
            int mx = max(num1,num2);
            int mn = min(num1,num2);
            num1 = mx - mn;
            num2 = mn;
            count++;
        }
        return count;
    }
};