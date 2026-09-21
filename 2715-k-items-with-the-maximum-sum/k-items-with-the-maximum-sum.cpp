class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    
       if(k<=numOnes){
       return k;
       }
       else if(k < numOnes+numZeros){
       return numOnes;
       }
       else
       return ((k-(numOnes+numZeros))*-1)+numOnes;
       
    }
};