// class Solution {
// public:
//     int cnt = 0;
//     void merge(vector<int>& nums, int low, int mid, int high){
//         int left = low, right = mid+1;
//         vector<int> temp;
//         while(left <= mid && right <= high){
//             if (nums[left] <= nums[right]){
//                 temp.push_back(nums[left]);
//                 left++;
//             }
//             else{
//                 if (nums[left] > 2* nums[right]) cnt += mid - left +1;
//                 temp.push_back(nums[right]);
//                 right++;
//             }
//         }

//         while(left <= mid){
//             temp.push_back(nums[left]);
//             left++;
//         }
//         while(right <= high){
//             temp.push_back(nums[right]);
//             right++;
//         }
//         for (int i = low; i <= high; i++){
//             nums[i] = temp[i-low];
//         }
//     }

//     void mergeSort(vector<int>& nums, int low, int high){
//         if (low >= high) return;
//         int mid = (low + high)/2;
//         mergeSort(nums, low, mid);
//         mergeSort(nums, mid + 1, high);
//         merge(nums, low, mid, high);
//     }

//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         mergeSort(nums, 0, n-1);
//         return cnt;
//     }
// };

class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& nums, int low, int mid, int high){
        int left = low, right = mid + 1;
        vector<int> temp;

        // Counting reverse pairs
        for (int i = left; i <= mid; ++i) {
            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }

        left = low, right = mid + 1;

        // Merging the two sorted halves
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0; // Reset counter
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
