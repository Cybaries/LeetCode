// Last updated: 11/05/2026, 01:31:39
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word, worrd;
        for (string x: word1)
            word += x;
        for (string x: word2)
            worrd += x;
        if (word == worrd)
            return true;
        else return false;
    }
};