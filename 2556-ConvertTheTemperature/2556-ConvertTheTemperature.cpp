// Last updated: 11/05/2026, 01:30:20
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> chng(2);
        chng[0] = celsius + 273.15;
        chng[1] = celsius * 1.80 + 32.00;
        return chng;
    }
};