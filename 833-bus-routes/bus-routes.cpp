class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes,int source,int target) {

        if(source == target)
            return 0;

        unordered_map<int, vector<int>> stopToBus;

        for(int bus = 0; bus < routes.size(); bus++) {
            for(int stop : routes[bus]) {
                stopToBus[stop].push_back(bus);
            }
        }

        queue<int> q;
        q.push(source);

        unordered_set<int> visitedStops;
        unordered_set<int> visitedBus;

        visitedStops.insert(source);

        int buses = 0;

        while(!q.empty()) {

            int sz = q.size();
            buses++;

            while(sz--) {

                int stop = q.front();
                q.pop();

                for(int bus : stopToBus[stop]) {

                    if(visitedBus.count(bus))
                        continue;

                    visitedBus.insert(bus);

                    for(int nextStop : routes[bus]) {

                        if(nextStop == target)
                            return buses;

                        if(!visitedStops.count(nextStop)) {

                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};