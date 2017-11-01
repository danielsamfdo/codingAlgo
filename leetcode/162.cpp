//https://leetcode.com/problems/find-peak-element/
class Solution {
    
public:

 int search(vector<int>& nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
    int findPeakElement(vector<int>& nums) {
        return search(nums,0,nums.size()-1);
        // int l = 0;
        // int r = nums.size()-1;
        // if(r==1)return 0;
        // int res;
        // while(l<r){
        //     int mid= (l+r)/2;
        //     res = mid;
        //     if(nums[mid]>nums[mid+1]){
        //         r=mid;
        //     }
        //     else{
        //         l=mid+1;
        //     }
        // }
        // return l;
    }
};//https://leetcode.com/problems/find-peak-element/solution/