int singleNumber(int* nums, int numsSize) {
    int single = 0;
    for(int i = 0; i<numsSize; i++){
        for(int j = 0; j<numsSize; j++){
            if(nums[i] == nums[j] && i != j){
                break;
            }else if(j == numsSize-1){
                single = 1;
            }
        }

        if(single){
            return nums[i];
        }
    }
    return 0;
}