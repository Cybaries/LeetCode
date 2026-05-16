class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        // ans[0] = 0 automatically (0 has no set bits)

        for (int i = 1; i <= n; i++) {

            ans[i] = ans[i >> 1] // popcount of i with last bit removed
                    + (i & 1); // add 1 if last bit is set, 0 if not
        }

        return ans;
    }
}