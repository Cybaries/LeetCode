// Last updated: 11/05/2026, 01:34:34
class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxArea = 0;
        int l = 0;
        int r = height.size()-1;
        while (l < r){
            int tmpArea = 0;
            int length = r - l;
            if (height[l] < height[r]){
                tmpArea = height[l] * length;
                l++;
            }
            else{
                tmpArea = height[r] * length;
                r--;
            }
            mxArea = max(mxArea,tmpArea);
        }
        return mxArea;
    }
};