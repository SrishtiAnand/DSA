class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxCap = INT_MIN;
        int h = INT_MAX;


        while(start<end){
             h = min(height[start],height[end]);
            int width = end - start;
            int currCap = h*width;

            maxCap = std::max(currCap, maxCap);

            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        return maxCap;
    }
};