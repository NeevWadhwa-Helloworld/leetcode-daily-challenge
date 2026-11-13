class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_l=0;
        int size=nums.size()-1;
        if(size==0){
            return 1;
        }
        int inc=1;
        int dec=1;
        for(int i=0;i<size;i++){
            if(nums[i+1]>nums[i]){
                inc++;
                dec=1;
            }else if(nums[i+1]<nums[i]){
                dec++;
                inc=1;
            }else{
                inc=1;
                dec=1;
            }
            max_l=max(max_l,max(inc,dec));
        }
        return max_l;
    }
};
