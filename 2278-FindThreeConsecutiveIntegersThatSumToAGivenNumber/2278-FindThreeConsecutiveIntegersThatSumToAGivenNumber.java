// Last updated: 11/05/2026, 01:31:11
class Solution {
    public long[] sumOfThree(long num) {
        long[] arr = new long[3];
        if (num%3 == 0){
            arr[0]= num/3-1;
            arr[1]= num/3;
            arr[2]= num/3+1;
            return arr;
        }
        else{
            long[] arrli = new long[0];
            return arrli;
        }
        
    }
}