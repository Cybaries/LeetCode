// Last updated: 11/05/2026, 01:30:59
class Solution {
public:
    long long smallestNumber(long long num) {
        int sign = num >= 0? 1:-1;
        vector<long long> v;
        int count = 0;
        while(num!=0){
            int n = num%10;
            if (n == 0)
                count++;
            v.push_back(n);
            num /= 10;
        }
        if (sign >= 1){
            sort(v.begin(),v.end());
            if (count >= 1){
            swap(v[0],v[count]);
            }
        }
        else{
            sort(v.begin(),v.end());
            // reverse(v.begin(),v.end());
        }
        for (long long i: v){
            num = num*10 + i;
        }
        // cout<<num<<endl;
        return (num);
    }
};