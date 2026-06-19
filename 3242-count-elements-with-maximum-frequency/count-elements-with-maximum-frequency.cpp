class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int num : nums) {
            mpp[num]++;
        }

        int maxFreq = 0;

        for (auto it : mpp) {
            maxFreq = max(maxFreq, it.second);
        }

        int sum = 0;

        for (auto it : mpp) {
            if (it.second == maxFreq) {
                sum += it.second;
            }
        }

        return sum;
    }
};