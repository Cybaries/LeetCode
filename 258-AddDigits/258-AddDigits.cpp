// Last updated: 11/05/2026, 01:32:57
class Solution {
public:
    int addDigits(int num) {
        if (to_string(num).size() == 1)
            return num;
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num/=10;
        }
        return addDigits(sum);
    }
};