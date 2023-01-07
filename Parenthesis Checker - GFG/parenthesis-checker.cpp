//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        st.push('a');
        for (char c: x){
            // cout<<c<<endl;
            if (c=='(' || c=='{' || c=='[')
            st.push(c);
            else{
                if ((c==')' && st.top()=='(') || (c=='}' && st.top()=='{') || (c==']' && st.top()=='[')){
                    st.pop();
                }
                else
                return false;
            }
        }
        if (st.size() == 1)
        return true;
        else
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends