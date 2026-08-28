class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      unordered_map<long long, long long> mp;
      long long prefix = 0;
      long long ans =LLONG_MIN;
      for(int x : nums){
        if(mp.count(x-k)){
            ans = max(ans, prefix+x-mp[x-k]);
        }
        if(mp.count(x+k)){
            ans = max(ans, prefix+x-mp[x+k]);
        }
        if(!mp.count(x))
        mp[x] = prefix;
        else
        mp[x] = min(mp[x], prefix);
        prefix+=x;
      }
      return ans==LLONG_MIN?0:ans;
    }
};