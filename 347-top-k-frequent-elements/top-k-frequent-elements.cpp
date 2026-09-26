class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        vector<pair<int, int>> v(freq.begin(), freq.end());

        

        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { 
                return a.second > b.second;
                
                 });

        vector<int> arr;

           for (auto it : v) {
            arr.push_back(it.first);
            if(arr.size()==k){
                break;
            }
        }
        return arr;
    }
};