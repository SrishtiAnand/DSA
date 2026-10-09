class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        int rem = sum % p;

        if(rem == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int ans = n;
        long long curr = 0;

        for(int i = 0; i < n; i++){
            curr = (curr + nums[i]) % p;

            int need = (curr - rem + p) % p;

            if(mp.find(need) != mp.end()){
                ans = min(ans, i - mp[need]);
            }

            mp[curr] = i;
        }

        return ans == n ? -1 : ans;
    }
};