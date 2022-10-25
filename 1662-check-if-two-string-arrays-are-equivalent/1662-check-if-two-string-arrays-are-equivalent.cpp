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