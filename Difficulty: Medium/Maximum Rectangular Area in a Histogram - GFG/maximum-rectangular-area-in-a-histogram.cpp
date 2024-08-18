//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<pair<long long,long long>> s1;
        stack<pair<long long,long long>> s2;
        vector<long long> l(n);
        vector<long long> r(n);
        for (int i = 0; i < n; i++){
            long long ans = 1, ans1 = 1;
            while(!s1.empty() && arr[i] <= s1.top().first){
                ans += s1.top().second;
                s1.pop();
            }
            while(!s2.empty() && arr[n-i-1] <= s2.top().first){
                ans1 += s2.top().second;
                s2.pop();
            }
            s1.push({arr[i], ans});
            s2.push({arr[n-i-1], ans1});
            l[i] = ans;
            r[n-i-1] = ans1;
        }
        long long maxArea = 0;
        for (int i = 0; i < n; i++){
            // cout<<l[i]<<" "<<r[i]<<" "<<arr[i]<<endl;
            long long area = (r[i]+l[i]-1)*arr[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends