class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startIdx = findIndex(nums, target, true);
        if(startIdx == -1) return {-1,-1};
        int endIdx = findIndex(nums, target, false);
        return {startIdx, endIdx};
    }

private:
    int findIndex(vector<int>& nums, int target, bool isFirst) {
        int result = -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) {
                result = mid;
                if(isFirst) right = mid-1;
                else left = mid+1;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid - 1;
        }
        return result;
    }
};
