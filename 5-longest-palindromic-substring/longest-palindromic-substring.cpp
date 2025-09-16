class Solution {
public:  
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s.substr(0,1);
        int maxi = 0;
       
        string ans = "";
        for(int i =0; i<n;i++){
            for(int j = i+1; j<n; j++){
                int l = i, r = j;
                 bool isPal = true;
                if(s[i]==s[j]){
                    int end = j;
                    while(l<r){
                        if(s[l]!=s[r]) isPal = false;
                        l++; r--;
                    }
                    if(isPal){
                    if(end-i+1>maxi){
                        ans = s.substr(i, end-i+1);
                        maxi = end-i+1;
                    } 
                    }
                }
                
                
            }
        }
        if(maxi==0) return s.substr(0,1);
        return ans;
    }
};