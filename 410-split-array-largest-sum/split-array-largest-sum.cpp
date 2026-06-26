class Solution {
public:
    bool validation(vector<int> &arr, int mid, int k) {
        int n = arr.size();
        int cnt = 1;
        int s = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) return false;  

            if (s + arr[i] <= mid) {
                s += arr[i];
            } else {
                cnt++;
                s = arr[i];
            }
        }

        return cnt <= k;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();

        int min = *max_element(arr.begin(), arr.end());   
        int max = 0;

        for (int x : arr)
            max += x;                                   
        int ans = max;       

        while (min <= max) {
            int mid = min + (max - min) / 2;

            if (validation(arr, mid, k)) {
                ans = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return ans;
    }
};