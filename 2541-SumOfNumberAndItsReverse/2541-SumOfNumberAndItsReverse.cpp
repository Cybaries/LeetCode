// Last updated: 11/05/2026, 01:30:22
class Solution
{
    public:
        bool sumOfNumberAndReverse(int num)
        {
            for (int i = num / 2; i <= num; i++)
            {
                int res = 0, n = i;
                while (n)
                {
                    res = res *10 + (n % 10);
                    n /= 10;
                }
                if (i + res == num)
                    return true;
            }
            return false;
        }
};