class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb = 0;
        int hb = nums.size() - 1;
        
        while (lb <= hb) {
            int mid = lb + (hb - lb) / 2; 
            
            if (nums[mid] == target)
                return mid;
            
            if (nums[lb] <= nums[mid]) {
                if (nums[lb] <= target && target < nums[mid]) {
                    hb = mid - 1;
                } else {
                    lb = mid + 1; 
                }
            } 
            else {
                if (nums[mid] < target && target <= nums[hb]) {
                    lb = mid + 1;
                } else {
                    hb = mid - 1;
                }
            }
        }
        return -1;
    }
};