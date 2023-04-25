//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution{
  public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q) {
        vector<bool>vc;

        for(int i=0; i<q; i++)

        {

            int low=queries[i].first;

            int high=queries[i].second;

            int j=low;

            while(j<high && a[j]<=a[j+1])

            {

               j++;}

            while(j<high && a[j]>=a[j+1])

               { j++;

            }

                if(j<high)

                   {vc.push_back(false);}

                   else{

                   vc.push_back(true);}

                  

           }

           return vc;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
// } Driver Code Ends