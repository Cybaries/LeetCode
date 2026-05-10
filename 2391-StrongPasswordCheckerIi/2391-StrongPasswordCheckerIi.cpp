// Last updated: 11/05/2026, 01:30:31
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8)
            return false;
        string pattern = "!@#$%^&*()-+";
        int cA = 0, ca = 0, cs = 0, cd = 0, extra = 0;
        if (password[0] <= 57 && password[0] >= 48)
            cd++;
        else if (password[0] <= 91 && password[0] >= 65)
            cA++;
        else if (password[0] <= 122 && password[0] >= 97)
            ca++;
        else if (pattern.find(password[0]) != string::npos)
            cs++;
        for (int i = 1; i < password.size(); i++){
            if (password[i] == password[i-1])
                return false;
            if (password[i] <= 57 && password[i] >= 48)
                cd++;
            else if (password[i] <= 91 && password[i] >= 65)
                cA++;
            else if (password[i] <= 122 && password[i] >= 97)
                ca++;
            else if (pattern.find(password[i]) != string::npos)
                cs++;
            else
                extra++;
        }
        // cout<< cd<<" "<< cA << " "<< ca << " "<< cs << " "<< extra<<endl;
        if (cd != 0 && ca != 0 && cA != 0 && cs != 0 && extra == 0)
            return true;
        else
            return false;
    }
};