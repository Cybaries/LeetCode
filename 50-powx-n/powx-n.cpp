class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        double ans = 1.0;
        nn = nn<0? -1*nn:nn;
        while(nn){
            if (nn%2){
                ans *= x;
                nn--;
            }
            else{
                x = x*x;
                nn/=2;
            }
        }
        if (n<0) ans = (double)1.0/ans;
        return ans;
    }
};