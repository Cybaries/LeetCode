// Last updated: 11/05/2026, 01:29:50
class Solution {

    public boolean isPrime(int n){
        if (n == 0 || n == 1) return false;
        for (int i = 2; i < n; i++){
            if (n % i == 0) return false;
        }
        return true;
    }
    public int sumOfPrimesInRange(int n) {
        int cnt = 0;
        int ans = 0;

        int temp = n;
        int r = 0;
        while (temp != 0){
            int digit = temp%10;
            r = r*10 + digit;
            temp /= 10;
            cnt++;
        }
        if (n < r){
            for (int i = n; i <= r; i++){
                if (isPrime(i) == true)
                    ans += i;
            }
        }
        else{
            for (int i = r; i <= n; i++){
                if (isPrime(i) == true)
                    ans += i;
            }
        }
        return ans;
    }
}