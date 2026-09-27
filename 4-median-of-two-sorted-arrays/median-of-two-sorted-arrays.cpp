class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> arr;

        int i = 0;
        int j = 0;

        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }
            else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n) {
            arr.push_back(nums1[i]);
            i++;
        }

        while(j < m) {
            arr.push_back(nums2[j]);
            j++;
        }

        int x = arr.size();

        if(x % 2 != 0) {
            return arr[x / 2];
        }
        else {
            return (arr[x / 2] + arr[x / 2 - 1]) / 2.0;
        }
    }
};