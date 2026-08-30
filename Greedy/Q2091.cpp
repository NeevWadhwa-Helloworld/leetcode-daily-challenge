class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_i=0;
        int max_i=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<nums[min_i]){
                min_i=i;
            }else if(nums[i]>nums[max_i]){
                max_i=i;
            }
        }
        int left=min(min_i,max_i);
        int right=max(min_i,max_i);
        int remove_front = right + 1;
        int remove_back = n - left;
        int remove_both = (left + 1) + (n - right);

        return std::min({remove_front, remove_back, remove_both});
    }
};
