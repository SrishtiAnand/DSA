class Solution {
public:
    int findRadius(vector<int>& H, vector<int>& h) {
          sort(h.begin(), h.end());

        int inf = 1000000007;

        vector<int> mn(H.size());

        for(int i = 0; i < H.size(); ++i) 
            mn[i] = inf;

        for(int i = 0; i < H.size(); ++i) {
            // Closest heater in the right

            int n = h.size();

            if(H[i] <= h[n - 1]) {
                int lo = 0 , hi = h.size() - 1;
                int inx = h.size();

                while(lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if(h[mid] == H[i]) {
                        inx = mid;
                        break;
                    } 

                    if(h[mid] > H[i]) { 
                        inx = mid;
                        hi = mid - 1;
                    } else 
                        lo = mid + 1;  
                }

                mn[i] = h[inx] - H[i];
            }

            if(H[i] >= h[0]) {
                int lo = 0 , hi = h.size() - 1;
                int inx = h.size();

                while(lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if(h[mid] == H[i]) {
                        inx = mid;
                        break;
                    } 

                    if(h[mid] < H[i]) { 
                        inx = mid;
                        lo = mid + 1;
                    } else 
                        hi = mid - 1;  
                }

                mn[i] = min(mn[i] , H[i] - h[inx]);
            }
        }

        int ans = 0;

        for(int i = 0; i < H.size(); ++i) 
            ans = max(ans , mn[i]);

        return ans;    
    }
};