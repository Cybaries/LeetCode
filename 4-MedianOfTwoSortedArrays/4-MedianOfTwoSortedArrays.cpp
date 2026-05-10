// Last updated: 11/05/2026, 01:34:41
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        vector<double> mergedArray;
        int i = 0; int j = 0;
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] <= nums2[j]){ 
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else{
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()){
            mergedArray.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()){
            mergedArray.push_back(nums2[j]);
            j++;
        }
        if ((nums1.size() + nums2.size()) %2 == 0){
            int index = floor((nums1.size() + nums2.size())/2);
            result = (mergedArray[index] + mergedArray[index - 1])/2;
        }
        else{
            int index = floor((nums1.size() + nums2.size())/2);
            result = mergedArray[index];
        }
        return result;
    }
};