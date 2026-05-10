// Last updated: 11/05/2026, 01:33:24
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        int n  = nums.size() ;
        if(n <= 1 || k%n == 0 )
            return;
        k%= n;
        int arr[k];
        int arr1[n-k];
        
        for(int i = n - k ; i < n ; i++){
            arr[count] = nums[i];
            count++;
        }
        
        for(int i = 0; i < n - k; i++){
            arr1[i] = nums [i];
        }
        
        count = 0;
        
        for(int i = 0; i < k ; i++){
            nums [count] = arr[i];
            
            count++;
        }
        for(int i = 0; i < n-k; i++){
            nums[count] =  arr1[i];
            count++;
        }
    }
};