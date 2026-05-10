// Last updated: 11/05/2026, 01:30:01
class Solution {
    public int minFlips(String s) {
        int n = s.length();
        int one = 0;

        for (int i = 0; i < n; i++){
            if (s.charAt(i) == '1') one++;
        }
        int zero = n - one;
        int only1 = Math.abs(one - 1);
        int maxFlips = Integer.MAX_VALUE;
        if (n >= 2){
            int midOne = 0;
            for (int i = 1; i < n - 1; i++){
                if (s.charAt(i) == '1') midOne++;
            }
            int left, right;
            left = s.charAt(0) == '1'? 0 : 1;
            right = s.charAt(n - 1) == '1'? 0 : 1;
            maxFlips = midOne + left + right;
        }
        return Math.min(Math.min(one, zero), Math.min(only1, maxFlips));
    }
}