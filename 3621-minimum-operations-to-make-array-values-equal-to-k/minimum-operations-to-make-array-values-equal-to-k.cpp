class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int num : nums) {

            if (num < k)
                return -1;

            if (num > k)
                mp[num]++;
        }

        return mp.size();
    }
};