//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int nth(int mid,int n,int m){
	    long long value=1;
	   // cout<<n<<" "<<m<<" "<<mid<<endl;
	    while(n--){
	        value*=mid;
	        if (value > m)
	        return 2;
	    }
	    if(value==m){
	        return 1;
	    }
	    return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low=1;
	    int high=m;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	       // cout<< mid << " "<<low<<" "<<high<<endl;
	        int val= nth(mid,n,m);
	        if(val==1){
	            return mid;
	        }
	        else if(val==0){
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends