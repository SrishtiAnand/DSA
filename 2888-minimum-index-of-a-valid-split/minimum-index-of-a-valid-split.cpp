class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int dominant;
        int totalCount = 0;
        int n = nums.size();

        
        for (auto it : freq) {
            if (it.second > n / 2) {
                dominant = it.first;
                totalCount = it.second;
                break;
            }
        }

        int leftCount = 0;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] == dominant)
                leftCount++;

            int rightCount = totalCount - leftCount;

            int leftSize = i + 1;
            int rightSize = n - leftSize;

            if (leftCount > leftSize / 2 &&
                rightCount > rightSize / 2) {
                return i;
            }
        }

        return -1;
    }
};