class Solution {
    public int[] singleNumber(int[] nums) {

        // Step 1: XOR everything — all pairs cancel, leaves x^y
        int xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Find rightmost bit where x and y differ
        // xorAll & (-xorAll) isolates the lowest set bit
        int separatorBit = xorAll & (-xorAll);

        // Step 3: XOR only numbers that HAVE this bit set
        // → pairs within the group cancel, leaving just one unique number
        int x = 0;
        for (int num : nums) {
            if ((num & separatorBit) != 0) {
                x ^= num;
            }
        }

        // y is trivially derived — x^y = xorAll, so y = xorAll^x
        int y = xorAll ^ x;

        return new int[]{x, y};
    }
}