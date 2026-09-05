void moveZeroes(int* nums, int numsSize) {
    int j=0;
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[j++]=nums[i];
        }
    }
    while(j<i){
        nums[j++]=0;
    }
}
