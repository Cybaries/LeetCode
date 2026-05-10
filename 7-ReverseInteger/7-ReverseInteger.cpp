// Last updated: 11/05/2026, 01:34:37
class Solution {
public:
    int reverse(int x) {
        int sign = 1;long long rev = 0;
        if (x < 0)
            sign = -1;
        x = abs(x);
        while(x > 0){
            rev = rev * 10 + (x%10);
            x /= 10;
        }
        rev = rev * sign;
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;
        return (int)rev;
    }
};