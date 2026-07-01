class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            int idx = -1;
            int minStart = INT_MAX;

            for (int j = 0; j < n; j++) {
                if (nums[j][0] >= nums[i][1]) {
                    if (nums[j][0] < minStart) {
                        minStart = nums[j][0];
                        idx = j;
                    }
                }
            }

            arr.push_back(idx);
        }

        return arr;
    }
};