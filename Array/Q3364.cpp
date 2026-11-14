class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int min_sum=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(j-i+1>=l && j-i+1<=r && sum>0){
                    min_sum=min(min_sum,sum);
                }
            }
        }
        if(min_sum==INT_MAX){
            return -1;
        }else{
            return min_sum;
        }
    }
};
