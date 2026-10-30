class Solution {
    public int[] transformArray(int[] nums) {
        int n0=0;
        int n1=0;
        int size=nums.length;
        for(int i=0;i<size;i++){
            if(nums[i]%2==0){
                n0++;
            }else{
                n1++;
            }
        }
        for(int i=0;i<n0;i++){
            nums[i]=0;
        }
        for(int i=n0;i<n0+n1;i++){
            nums[i]=1;
        }
        return nums;
    }
}
