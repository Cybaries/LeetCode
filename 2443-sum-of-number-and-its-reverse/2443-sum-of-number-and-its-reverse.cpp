class Solution {
    int reverse(int n){
        int res = 0;
        while(n){
            res = res*10 + (n%10);
            n /= 10;
        }
        return res;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = num/2; i <= num; i++){
            if (i + reverse(i) == num)
                return true;
        }
        return false;
    }
};