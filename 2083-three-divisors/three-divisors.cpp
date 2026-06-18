class Solution {
public:
    bool isThree(int n) {
        int count = 0;
        int root = sqrt(n);

        for (int i = 1; i <= root; i++) {
            if (n % i == 0) {
                count++;          

                if (i != n / i)
                    count++;      
            }
        }

        return count == 3;
    }
};