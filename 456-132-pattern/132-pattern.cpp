class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int thirdEle = INT_MIN;
        for(int i=nums.size()-1; i>=0; i--){
            if(thirdEle>nums[i]) return true;
            while(!st.empty() && st.top()<nums[i]){
                thirdEle = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};