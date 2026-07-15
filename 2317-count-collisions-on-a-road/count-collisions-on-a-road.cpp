class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int count = 0;

        for (char ch : directions) {

            if (ch == 'R') {
                st.push('R');
            }

            else if (ch == 'S') {

                while (!st.empty() && st.top() == 'R') {
                    st.pop();
                    count++;
                }

                st.push('S');
            }

            else { // ch == 'L'

                if (st.empty()) {
                    st.push('L');
                }
                else if (st.top() == 'R') {

                    st.pop();
                    count += 2;

                    while (!st.empty() && st.top() == 'R') {
                        st.pop();
                        count++;
                    }

                    st.push('S');
                }
                else if (st.top() == 'S') {

                    count++;
                    st.push('S');
                }
                else { // top == 'L'
                    st.push('L');
                }
            }
        }

        return count;
    }
};