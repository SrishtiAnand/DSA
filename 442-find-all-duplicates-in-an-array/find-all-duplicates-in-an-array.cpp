class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        unordered_map<int, int> mp;
        vector<int> ans;

        for (int num : nums) {

            mp[num]++;

            if (mp[num] == 2)
                ans.push_back(num);
        }

        return ans;
    }
};