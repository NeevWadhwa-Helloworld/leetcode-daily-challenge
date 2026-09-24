class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int l=nums.size();
        for(int i=0;i<l;i++){
            int n=nums[i];
            int digitSum=0;
            while(n>0){
                int digit=n%10;
                n=n/10;
                digitSum+=digit;
            }
            if(digitSum==i){
                return i;
            }
        }
        return -1;
    }
};
