class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 1) return -1;
        int i = 1;
        for(; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) break;
        }
        int k = nums.size() - i;
        for(int j=0; j < nums.size(); j++) {
            // if(nums[j] == target && k!=0) return j-k;
            if(nums[j] == target) return j;
        } 
        return -1;
    }
};