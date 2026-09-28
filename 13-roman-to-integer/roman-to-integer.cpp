class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        unordered_map<string, int> mp1;

        mp1["IV"] = 4;
        mp1["IX"] = 9;
        mp1["XL"] = 40;
        mp1["XC"] = 90;
        mp1["CD"] = 400;
        mp1["CM"] = 900;

        int T = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (i + 1 < n) {
                string two = s.substr(i, 2);

                if (mp1.count(two)) {
                    T += mp1[two];
                    i++;
                    continue;
                }
            }

            T += mp[s[i]];
        }

        return T;
    }
};