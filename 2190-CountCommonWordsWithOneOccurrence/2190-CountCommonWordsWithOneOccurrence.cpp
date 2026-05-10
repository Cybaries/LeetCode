// Last updated: 11/05/2026, 01:31:26
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map <string, int> map1;
        unordered_map <string, int> map2;
        for (auto i: words1){
            if (map1.find(i) == map1.end()){
                map1[i] = 1;
            }
            else{
                map1[i]++;
            }
        }
        int count = 0;
        for (auto i: words2){
            if (map2.find(i) == map2.end()){
                map2[i] = 1;
            }
            else{
                map2[i]++;
            }
        }
        for (auto x: map1){
            if (x.second == 1){
                for (auto y: map2){
                    if (y.first == x.first && y.second == 1)
                        count++;
                }
            }
        }
        return count;
    }
};