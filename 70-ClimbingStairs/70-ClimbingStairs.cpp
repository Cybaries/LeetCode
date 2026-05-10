// Last updated: 11/05/2026, 01:34:01
class Solution {
   
public:
    int climbStairs(int n) {
        int a = 1, b = 1,c;
        while (n-- > 1){
            c = a + b;
            swap(a,b);
            b = c;
        }
        return c;
    }
};