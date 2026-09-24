class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> nums_map;
        int l=nums.size();
        for(int num:nums){
            nums_map[num]++;
        }
        for(int i=0;i<l;i++){
            int target1=nums[i]-k;
            int target2=nums[i]+k;
            if(nums_map.find(target1) != nums_map.end()){
                ans+=nums_map[target1];
            }
            if(nums_map.find(target2) != nums_map.end()){
                ans+=nums_map[target2];
            }
            
        }
        return ans/2;
    }
};
