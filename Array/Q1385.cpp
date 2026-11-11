class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result=0;
        for(int n:arr1){
            bool exist=false;
            for(int m:arr2){
                if(abs(n-m)<=d){
                    exist=true;
                    break;
                }
            }
            if(!exist){
                result++;
            }
        }
        return result;
    }
};
