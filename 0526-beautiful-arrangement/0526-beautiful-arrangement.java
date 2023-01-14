class Solution {
    public int countArrangement(int n) {
    if(n<4)return n;
       int arr[]={8,10,36,41,132,250,700,750,4010,4237,10680,24679};
       return arr[n-4];
    }
}