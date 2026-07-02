class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> next(n);
        for(int i = 2*n-1; i>=0; i--){
            while(st.empty()== false && st.top() <= nums[i%n]){
                st.pop();
            }if(i<n){
            if(st.empty() == true) next[i] = -1;
            else next[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return next;
    }
};