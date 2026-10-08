class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st1;
        stack<char> st2;
        string str = "";

        for(char ch : s) {

            if(st1.empty()) {
                st1.push(ch);
            }
            else if(!st1.empty() && st2.empty() && ch == ')') {
                st1.pop();
            }
            else if(!st1.empty()) {

                if(ch == '(') {
                    st2.push(ch);
                    str.push_back(ch);
                }
                else {
                    st2.pop();
                    str.push_back(ch);
                }

               
            }
        }

        return str;
    }
};