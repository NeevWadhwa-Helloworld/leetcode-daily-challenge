/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int* arr=(int*)malloc(2*sizeof(int));
    arr[0]=-1;
    arr[1]=-1;
    if(numsSize==0){
        return arr;
    }
    int low=0;
    int high=numsSize-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            int left = mid;
            while (left >= 0 && nums[left] == target) {
                left--;
            }
            arr[0] = left + 1;
            int right = mid;
            while (right < numsSize && nums[right] == target) {
                right++;
            }
            arr[1] = right - 1;

            return arr;
        }else if(nums[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return arr;
}
