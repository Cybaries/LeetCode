// Last updated: 11/05/2026, 01:29:48
class Solution {
    public long minArraySum(int[] nums) {
        // Find the range we need to sieve over
        int maxVal = 0;
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }

        // Mark which values exist in the array — O(1) lookup later
        boolean[] present = new boolean[maxVal + 1];
        for (int num : nums) {
            present[num] = true;
        }

        // minDiv[v] = smallest array element that divides v
        // Every number divides itself, so initialise minDiv[v] = v
        int[] minDiv = new int[maxVal + 1];
        for (int i = 1; i <= maxVal; i++) {
            minDiv[i] = i;
        }

        // Sieve: for each present value v (small → large),
        // propagate v as a divisor to all its multiples that are also in the array.
        // Because we go small → large, the first write is always the minimum.
        for (int v = 1; v <= maxVal; v++) {
            if (!present[v]) continue;             // only care about values in nums

            for (int multiple = v; multiple <= maxVal; multiple += v) {
                if (present[multiple]) {
                    // v divides 'multiple', and v is in the array →
                    // 'multiple' can be reduced to at most v
                    minDiv[multiple] = Math.min(minDiv[multiple], v);
                }
            }
        }

        // Each element takes its minimum reachable value
        long totalSum = 0;
        for (int num : nums) {
            totalSum += minDiv[num];
        }

        return totalSum;
    }
}