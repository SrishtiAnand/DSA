class Solution {
public:
    bool isSorted(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        vector<int> arr = nums;
        int ans = 0;

        while (!isSorted(arr)) {
            int index = 0;
            int minSum = arr[0] + arr[1];

            for (int i = 1; i < arr.size() - 1; i++) {
                int currSum = arr[i] + arr[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    index = i;
                }
            }

            arr[index] = minSum;
            arr.erase(arr.begin() + index + 1);
            ans++;
        }

        return ans;
    }
};