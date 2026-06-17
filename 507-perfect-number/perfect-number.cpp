class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;

        int sum = 0;

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                if (i != num)
                    sum += i;

                int other = num / i;
                if (other != i && other != num)
                    sum += other;
            }
        }

        return sum==num ;
    }
};
