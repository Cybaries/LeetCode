//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
        long long int prod = 1;
        int nmZero = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
            nmZero++;
            continue;
            }
            prod *= nums[i];
        }
        vector<long long int> ans(n);
        for (int i = 0; i < n; i++){
            if (nmZero == 0){
                ans[i] = prod / nums[i];
            }
            else if (nmZero == 1){
                if (nums[i] == 0)
                ans[i] = prod;
                else
                ans[i] = 0;
            }
            else{
                ans[i] = 0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends