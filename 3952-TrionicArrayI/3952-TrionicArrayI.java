// Last updated: 11/05/2026, 01:30:08
class Solution {
    public boolean isTrionic(int[] nums) {

        int n = nums.length;
        if (n < 3)
            return false; // need at least 3 numbers to form 3 parts

        // incPrefix[i] = true if nums[0..i] goes strictly UP
        boolean[] incPrefix = new boolean[n];
        incPrefix[0] = true;
        for (int i = 1; i < n; i++) {
            incPrefix[i] = incPrefix[i - 1] && (nums[i - 1] < nums[i]);
        }

        // incSuffix[i] = true if nums[i..n-1] goes strictly UP
        boolean[] incSuffix = new boolean[n];
        incSuffix[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            incSuffix[i] = incSuffix[i + 1] && (nums[i] < nums[i + 1]);
        }

        // decRight[i] = the farthest index j we can reach from i while going strictly DOWN
        int[] decRight = new int[n];
        for (int i = 0; i < n; i++)
            decRight[i] = i;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                decRight[i] = decRight[i + 1]; // keep rolling downhill
            } else {
                decRight[i] = i; // downhill stops here
            }
        }

        // nextIncSuffix[i] = the smallest index j >= i such that incSuffix[j] is true
        // If none exists, set it to n (a sentinel meaning "not found").
        int[] nextIncSuffix = new int[n + 1];
        final int INF = n;
        nextIncSuffix[n] = INF;
        for (int i = n - 1; i >= 0; i--) {
            nextIncSuffix[i] = incSuffix[i] ? i : nextIncSuffix[i + 1];
        }

        // Try each possible middle pivot p (the end of the first UP part)
        // We need q in (p .. n-2] such that:
        //   - nums[p..q] is DOWN  (q <= decRight[p])
        //   - nums[q..] is UP     (incSuffix[q] = true)
        for (int p = 1; p <= n - 2; p++) {
            if (!incPrefix[p])
                continue; // first part must be strictly UP

            int right = Math.min(decRight[p], n - 2); // q cannot be n-1 (last part needs >= 2 numbers)
            if (p + 1 > right)
                continue; // no room for the middle DOWN part or a valid q

            int q = nextIncSuffix[p + 1]; // first index >= p+1 where suffix is UP
            if (q <= right)
                return true; // found a q that makes UP -> DOWN -> UP
        }

        return false;

    }
}