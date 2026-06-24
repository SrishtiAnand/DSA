class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> prefix(n);
        vector<int> suffix(n);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                 if(!st.empty()) prefix[i] =st.top()+1;
                 else prefix[i] = 0;
                 st.push(i);
                   }
        while(!st.empty()) st.pop();
        for(int i= n-1; i>=0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(!st.empty()) suffix[i] = st.top() - 1;
        else suffix[i] = n-1;
        st.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
        maxArea = max(maxArea, heights[i]*(suffix[i]-prefix[i]+1));
        }
        return maxArea;
    }
        
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m);
        int ans =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1') arr[j]++;
                else arr[j] = 0;
            }
            ans = max(ans, largestRectangleArea(arr));
        }
   return ans;
    }
};