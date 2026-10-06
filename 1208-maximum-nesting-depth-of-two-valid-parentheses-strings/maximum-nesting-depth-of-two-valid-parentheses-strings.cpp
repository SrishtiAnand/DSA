class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        stack<int> st ;
        int cnt =0;
        vector<int> ans ;

        for(char ch : seq){

            if(ch=='('){
                cnt++;
                st.push(ch);

                ans.push_back(cnt%2);
                
            }else{
                st.pop();
                ans.push_back(cnt%2);
                cnt--;

            }

        }

        return ans ;
        
    }
};