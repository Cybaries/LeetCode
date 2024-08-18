//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
 long long int merge(vector<long long> &arr, long long int low, long long int mid, long long int high) {
    vector<long long int> temp; 
    long long int left = low;      
    long long int right = mid+1;

    long long int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (long long int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; 
}

long long int mergeSort(vector<long long> &arr, long long int low, long long int high) {
    long long int cnt = 0;
    if (low >= high) return cnt;
    long long int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  
    cnt += mergeSort(arr, mid + 1, high); 
    cnt += merge(arr, low, mid, high); 
    return cnt;
}

long long int inversionCount(long long arr[], long long int n) {
        // Your Code Here
        vector<long long> array;
        for (long long int i = 0; i < n; i++){
            array.push_back(arr[i]);
        }
        return mergeSort(array, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends