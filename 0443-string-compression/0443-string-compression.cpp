class Solution {
public:
    int compress(vector<char>& chars) {
        int indexAns = 0, index = 0;
        while(index < chars.size()){
            char currentChar = chars[index];
            int count = 0;
            while(index < chars.size() && chars[index] == currentChar){
                index++;
                count++;
            }
            chars[indexAns++] = currentChar;
            if(count != 1)
                for(char c : to_string(count)) 
                    chars[indexAns++] = c;
        }
        return indexAns;
    }
};