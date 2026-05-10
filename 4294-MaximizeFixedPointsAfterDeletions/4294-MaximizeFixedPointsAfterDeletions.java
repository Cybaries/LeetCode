// Last updated: 11/05/2026, 01:29:44
class Solution {
    public int maxFixedPoints(int[] nums) {
        List<int[]> candidates = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int x = i - nums[i];
            if (x >= 0) {
                candidates.add(new int[]{x, nums[i]});
            }
        }

        candidates.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        List<Integer> tails = new ArrayList<>();

        for (int[] pair : candidates) {
            int val = pair[1];
            int lo = 0, hi = tails.size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (tails.get(mid) < val) lo = mid + 1;
                else hi = mid;
            }
            if (lo == tails.size()) {
                tails.add(val);
            } else {
                tails.set(lo, val);
            }
        }

        return tails.size();
    }
}