// Last updated: 11/05/2026, 01:32:01
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        return fib(n-2) + fib(n-1);
    }
};