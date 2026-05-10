// Last updated: 11/05/2026, 01:30:41
class Solution {
public:
//     float round(float var)
//     {
//         char str[40];
//         sprintf(str, "%.2f", var);
//         sscanf(str, "%f", &var);

//         return var;
//     }
    string discountPrices(string sentence, int discount) {
        vector<string> v;
        stringstream s(sentence);
        string word;
        while(s >> word){
            bool flag = true;
            string num;
            if (word[0] == '$' && word.size() > 1){
                for (int i = 1; i < word.size(); i++){
                    if (word[i] == '$' || word[i] >= 97){
                        flag = false;
                         break;
                    }
                    num += word[i];
                }
                if (flag == true){
                    double x = stod(num);
                    x -= x * (discount/100.0);
                    // cout<<x<<endl;
                    stringstream stream;
                    stream << fixed << setprecision(2) << x;
                    num = '$' + stream.str();
                    // cout<< num<<endl;
                    // num = '$'+ to_string(x);
                    v.push_back(num);
                }
                else{
                    v.push_back(word);
                }
            }
            else{
                v.push_back(word);
            }
            
        }
        word = "";
        for (int i = 0; i < v.size()-1; i++){
            word += v[i] + ' ';
        }
        word+= v[v.size()-1];
        return word;
    }
};