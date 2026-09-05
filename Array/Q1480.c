/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* result=(int*)malloc(numsSize*sizeof(int));
    int ele=0;
    for(int i=0;i<numsSize;i++){
        ele=0;
        for(int j=0;j<=i;j++){
            ele=ele+ *(nums+j);
        }
        *(result+i)=ele;
    }
    *returnSize=numsSize;
    return result;
}
