class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        unordered_map<char, int> mp3;
        vector<string> arr;

        mp1['q']=1;
        mp1['w']=1;
        mp1['e']=1;
        mp1['r']=1;
        mp1['t']=1;
        mp1['y']=1;
        mp1['u']=1;
        mp1['i']=1;
        mp1['o']=1;
        mp1['p']=1;

        mp2['a']=1;
        mp2['s']=1;
        mp2['d']=1;
        mp2['f']=1;
        mp2['g']=1;
        mp2['h']=1;
        mp2['j']=1;
        mp2['k']=1;
        mp2['l']=1;

        mp3['z']=1;
        mp3['x']=1;
        mp3['c']=1;
        mp3['v']=1;
        mp3['b']=1;
        mp3['n']=1;
        mp3['m']=1;

        for(string word : words) {
            int c1 = 0, c2 = 0, c3 = 0;

            for(char ch : word) {
                ch = tolower(ch);

                if(mp1.count(ch)) c1++;
                if(mp2.count(ch)) c2++;
                if(mp3.count(ch)) c3++;
            }

            if(c1 == word.size() || c2 == word.size() || c3 == word.size()) {
                arr.push_back(word);
            }
        }

        return arr;
    }
};