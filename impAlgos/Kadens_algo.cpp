// This was a solution to a leetcode question where we had find subarray with the maximum sum
// and then we had to return that sum as the answer;

//KADEN's ALGORITHM

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0],sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(result<sum) result=sum;
            if(sum<0) sum=0;
        }
        return result;
    }
};
