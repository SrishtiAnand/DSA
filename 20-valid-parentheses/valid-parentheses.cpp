class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char curr = s[i];
            if(curr == '(' || curr == '[' || curr == '{') st.push(curr);
            else{
               if(st.empty()) return false;
               else if(curr == ')' && st.top() == '(') st.pop();
               else if(curr == ']' && st.top() == '[') st.pop();
               else if(curr == '}' && st.top() == '{') st.pop();
               else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};