// Last updated: 11/05/2026, 01:32:51
class Solution {
    public int[] countBits(int n) {
        int [] arr = new int[n+1];
        arr[0] = 0;
        for (int i = 1; i <= n; i++){
            int cnt = 0;
            int x = i;
            while( x!= 0){
                if ((x & 1) == 1) cnt++;
                x >>= 1;
            }
            arr[i] = cnt;
        }
        return arr;
    }
}