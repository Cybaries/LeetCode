// Last updated: 11/05/2026, 01:30:39
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        vector <string> names;
        unordered_map<string, int> msgs;
        for (int i= 0; i < senders.size(); i++){
            int count = 0;
            stringstream s(messages[i]);
            string word;
            while(s >> word)
                count++;
            msgs[senders[i]]+= count;
        }
        int mx = 0;
        for(auto i: msgs){
            if (i.second > mx)
                mx = i.second;
        }
        for(auto i: msgs){
            if (i.second == mx)
                names.push_back(i.first);
        }
        // cout<< names[0]<<" "<<names[1];
        if (names.size()==1)
            return names[0];
        else{
            string p = names[0];
            for (string i: names){
                if (i>p)
                    p = i;
            }
            return p;
        }
    }
};