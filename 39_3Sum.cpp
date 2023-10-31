class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size() <= 2)    //If size is less than '3'
            return ans;

        sort(nums.begin(), nums.end()); //Sorting
        if(nums[0] > 0) //If the first element is +ve
            return ans;
        
        for(int i = 0; i < nums.size() - 2; i++){   //Fixing the iterator.
            if(nums[i] > 0) //If the iterator is +ve.
                break;
            
            if(i > 0 && nums[i] == nums[i - 1]) //Ensuring for the same prev ele.
                continue;
            
            int low = i + 1, high = nums.size() - 1;    //Setting the pointers
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high]; //Evaluating sum
                if(sum > 0){    //if sum is +ve
                    high--;
                }
                if(sum < 0){    //If sum is -ve
                    low++;
                }

                if(sum == 0){   //If sum = 0
                    vector<int> sub;
                    sub.push_back(nums[i]);
                    sub.push_back(nums[low]);
                    sub.push_back(nums[high]);
                    ans.push_back(sub); //Pushing the triplets in the ans.
                    int low_occ = nums[low], high_occ = nums[high];

                    while(low < high && low_occ == nums[low])//To ensure that there would not an element equal to low.
                        low++;
                    
                    while(low < high && high_occ == nums[high])//To ensure that there would not an element equal to high.
                        high--;
                }
            }

        }

        return ans;
    }
};