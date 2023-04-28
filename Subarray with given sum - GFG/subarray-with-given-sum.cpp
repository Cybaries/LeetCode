//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long int s)
    {
        // Your code here
        if (s == 0)
        return {-1};
        vector<int> ans;
        int first = 1, second = 0;
        for (int i = 0; i <= n; i++){
            // cout<<s<<" "<<first<<" "<<second<<" "<<arr[i]<<endl;
            if (s == 0){
                ans.push_back(first);
                ans.push_back(second);
                break;
            }
            if (s > 0){
                s -= arr[i];
                second = i+1;
            }
            while ( s < 0){
                s += arr[first-1];
                first++;
            }
            // cout<<s<<endl;
        }
        if (ans.size() == 0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends