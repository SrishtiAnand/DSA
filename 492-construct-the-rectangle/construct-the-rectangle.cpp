class Solution {
public:
    vector<int> constructRectangle(int area) {
        int length = area, width = 1;
        int minDiff = INT_MAX;

        for (int w = 1; w * w <= area; w++) {
            if (area % w == 0) {
                int l = area / w;
                if (l >= w && l - w < minDiff) {
                    minDiff = l - w;
                    length = l;
                    width = w;
                }
            }
        }

        return {length, width};
    }
};
