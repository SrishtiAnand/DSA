class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;

        for (string op : operations) {

            
            if (op != "C" && op != "D" && op != "+") {
                arr.push_back(stoi(op));
            }

            
            else if (op == "C") {
                arr.pop_back();
            }

           
            else if (op == "D") {
                arr.push_back(2 * arr.back());
            }

            
            else if (op == "+") {
                int n = arr.size();
                arr.push_back(arr[n - 1] + arr[n - 2]);
            }
        }

        int sum = 0;

        for (int x : arr) {
            sum += x;
        }

        return sum;
    }
};