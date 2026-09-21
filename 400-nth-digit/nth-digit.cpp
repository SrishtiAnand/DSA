class Solution {
public:
    int findNthDigit(int n) {
        long long digitlen = 1;
        long long cnt = 9;
        long long start = 1;
        while(n> digitlen*cnt){
            n-=digitlen*cnt;
            digitlen++;
            cnt *= 10;
            start*= 10;
        }
        start += (n-1)/ digitlen;
        string num = to_string(start);
        return num[(n-1)%digitlen]-'0';
    }

};