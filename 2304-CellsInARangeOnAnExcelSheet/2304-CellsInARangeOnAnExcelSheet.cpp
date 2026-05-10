// Last updated: 11/05/2026, 01:30:49
class Solution {
public:
    vector<string> cellsInRange(string s) {
        string first = s.substr(0,2);
        string second = s.substr(3,4);
        vector<string> str;
        for ( char a = first[0]; a <= second[0]; a++){
            for(int i = first[1]; i <= second[1]; i++){
                // cout<<first<<" "<<second;
                string sh = "";
                sh+= a;
                sh+= (char)(i);
                // cout<<sh;
                str.push_back(sh);
            }
        }
        return str;
    }
};