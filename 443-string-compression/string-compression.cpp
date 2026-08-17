class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int idx = 0;  // write pointer

        for (int i = 0; i < n; ) {

            char ch = chars[i];
            int count = 0;

            // count consecutive same chars
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // write character
            chars[idx++] = ch;

            // write count if > 1
            if (count > 1) {
                string cnt = to_string(count);

                for (char digit : cnt) {
                    chars[idx++] = digit;
                }
            }
        }

        return idx;
    }
};