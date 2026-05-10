// Last updated: 11/05/2026, 01:33:54
class Solution {
public:
    string minWindow(string s, string t) {
         if(s.size()<t.size()) return "";
        

        map<char, int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }

        int left = 0, right = 0;
        int len = INT_MAX, start = -1, cnt = mp.size();

        while(right<s.size()){
            if(mp.find(s[right])!=mp.end()){
                mp[s[right]]--;
                if(mp[s[right]]==0) cnt--;
            }

            while(cnt==0){
                if(mp.find(s[left])!=mp.end()){
                    mp[s[left]]++;
                    if(mp[s[left]]==1){
                        cnt++;
                        if(right-left+1 < len){
                            len = right-left+1;
                            start = left;
                        }
                    }
                }
                left++;
            }
            right++;
        }
        return (start == -1) ? "" : s.substr(start, len);
    }
};