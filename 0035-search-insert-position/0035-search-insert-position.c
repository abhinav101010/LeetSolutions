int searchInsert(int* nums, int numsSize, int target) {
    for(int i = 0; i < numsSize; i++){
        printf("%d %d\n", target, i);
        if(nums[i] == target){
            return i;
        }else if(nums[i] > target){
            return i;
        }else if(i == numsSize-1){
            return numsSize;
        }
    }
    return 0;
}