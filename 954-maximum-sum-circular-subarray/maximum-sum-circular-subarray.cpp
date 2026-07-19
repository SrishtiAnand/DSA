class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        // Kadane for Maximum Sum
        int currMax = 0;
        int maxSum = INT_MIN;

        // Kadane for Minimum Sum
        int currMin = 0;
        int minSum = INT_MAX;

        for (int num : nums) {

            totalSum += num;

            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }

        // If all elements are negative
        if (maxSum < 0)
            return maxSum;

        // Maximum of normal and circular subarray
        return max(maxSum, totalSum - minSum);
    }
};