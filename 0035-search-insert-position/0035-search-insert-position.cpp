class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int lb = 0;
       int n = nums.size();
       int hb = n - 1;
       while(lb<=hb){
        int mid = (lb + hb)/2;
        if(nums[mid] == target){
            return mid ;
        }
        else if(target>nums[mid]){
            lb = mid + 1;        }
        else {
            hb = mid - 1;
        }

       }
       return lb;
    }
};