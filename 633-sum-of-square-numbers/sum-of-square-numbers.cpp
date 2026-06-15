class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long a = 0; a * a <= c; a++) {

            long long target = c - a * a;

            long long low = 0, high = target;

            while(low <= high) {
                long long mid = low + (high - low) / 2;

                if(mid * mid == target)
                    return true;
                else if(mid * mid < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};