// Last updated: 11/05/2026, 01:29:56
class Solution {
    public boolean validDigit(int n, int x) {
        int cnt = 0;
        int temp = n;
        int digitCount = 0;
        while (temp != 0){
            cnt++;
            if (temp / 10 <= 0 && temp % 10 == x)
                return false;
            if (temp % 10 == x)
                digitCount++;
            temp /= 10;
        }
        if (digitCount > 0)
            return true;
        else
            return false;
    }
}