class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;

        while(beg <= end){
            int mid = (beg + end)/2;

            if(nums[mid] == target)
                return mid;

            else if(nums[beg] <= nums[mid]){
                if(nums[beg] <= target && nums[mid] >= target)
                    end = mid - 1;
                else
                    beg = mid + 1;
            }

            else{
                    if(nums[end] >= target && nums[mid] <= target){
                        beg = mid + 1;
                    }
                    else
                        end = mid - 1;
                
            }
        }
        return -1;
    }
};
