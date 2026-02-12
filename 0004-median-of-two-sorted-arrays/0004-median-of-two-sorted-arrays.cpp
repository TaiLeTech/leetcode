class Solution {
public:
    vector<int> gopVector (vector<int>& nums1, vector<int>& nums2) {
        vector<int> sum = nums1;
        sum.insert(sum.end(), nums2.begin(), nums2.end());
        sort(sum.begin(), sum.end());
        return sum;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a = gopVector(nums1, nums2);
        if(a.size()%2 != 0) {
            return (0.0 + a[a.size()/2]);
        }
        return (a[a.size()/2] + a[a.size()/2 - 1])/2.0;
    }
};