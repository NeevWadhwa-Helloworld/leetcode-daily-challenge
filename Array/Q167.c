int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result=(int*)malloc(2*sizeof(int));
    int left=0;
    int right=numbersSize-1;
    int sum;
    while(left<right){
        sum=numbers[left]+numbers[right];
        if(sum==target){
            result[0]=left+1;
            result[1]=right+1;
            *returnSize=2;
            return result;
        }else if(sum>target){
            right--;
        }else{
            left++;
        }
    }
    *returnSize=0;
    return NULL;
}
