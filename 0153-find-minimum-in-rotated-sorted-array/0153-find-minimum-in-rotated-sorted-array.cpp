class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int result = nums[0];
        while(left <= right) {
            int mid = left + (right - left)/2; 
            if(result > nums[mid]) {
                result = nums[mid];
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return result;
    }
};