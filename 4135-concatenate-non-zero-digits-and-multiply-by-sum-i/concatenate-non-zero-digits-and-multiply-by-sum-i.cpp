class Solution {
public:
    long long sumAndMultiply(int n) {
      long sum =0;
      long x = 0;
      int num = 0;
      vector<int> ans;
     
      while(n>0){
        long digit = n%10;
        sum+=digit;
        if(digit!=0)ans.push_back(digit);
        n/=10;
      }


        reverse(ans.begin() , ans.end());
       
        for(int i =0;i<ans.size(); i++){
            num = num*10+ans[i];
        }
      
      
    x = num*sum;
    return x;
      
       
       
    }
};