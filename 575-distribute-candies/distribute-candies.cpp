class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        
        for(int candy : candyType) {
            s.insert(candy);
        }
        
        int uniqueTypes = s.size();
        int canEat = candyType.size() / 2;
        
        return min(uniqueTypes, canEat);
    }
};