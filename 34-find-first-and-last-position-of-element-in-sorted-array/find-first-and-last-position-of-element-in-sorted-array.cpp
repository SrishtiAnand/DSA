class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurence(nums, target);
        int last = lastOccurence(nums, target);
        return {first, last};
    }

    int firstOccurence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
