class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nums;
        for(int i=0; i<n; i++){
            if(arr[i]>0 ) st.push(arr[i]);
            else{
                int ele = abs(arr[i]);
                while(st.empty() == false && st.top()>0){
                    if(ele == st.top()){
                        st.pop();
                        ele = 0;
                        break;
                    }
                    else if(ele > st.top()){
                        st.pop();
                    }else {
                        ele = 0;
                        break;
                    }
                }
                if(ele!=0) st.push(arr[i]);
            }
        }
        while(!st.empty()) {
            nums.push_back(st.top());
            st.pop();
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};