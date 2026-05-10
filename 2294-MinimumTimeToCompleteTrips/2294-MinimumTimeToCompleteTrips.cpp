// Last updated: 11/05/2026, 01:30:50
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        typedef long long ll;
        
        ll start = 0 , end = 1e16;
        
        ll ans = 1e16;
        
        while(start <= end)
        {
            ll mid = start + ((end-start)/2);
            
            ll trip = 0;
            for(auto &val : time)
            {
                ll b = val;
                trip += (mid/b);
                if(trip > totalTrips)
                    break;
            }
            
            // cout<<mid<<" "<<trip<<"\n";
            if(trip >= totalTrips) 
            {
                ans = min(ans,mid);
                end = mid-1;
            }
            else start = mid+1;
            
        }
        
        return ans;
    }
};