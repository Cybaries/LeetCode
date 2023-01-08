//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle = INT_MAX;
    stack<int> v;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           return minEle == INT_MAX? -1: minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if (s.empty())
           return -1;
           int x = s.top();
           if (s.top() == minEle){
               v.pop();
               minEle = v.empty()?INT_MAX:v.top();
           }
           s.pop();
           return x;
           
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           s.push(x);
           if (minEle >= x){
               minEle = x;
               v.push(x);
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends