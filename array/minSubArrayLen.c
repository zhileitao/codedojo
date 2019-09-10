/* 
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

int minSubArrayLen(int s, int* nums, int numsSize){
        int i = 0, j, sum, minlen = INT_MAX;
        if (!nums) 
                return 0;
        for (j = 0; j < numsSize, j++) {
                sum += nums[j];
                while(sum >= s) {
                        minlen = minlen > (j-i+1) ? (j-i+1) : minlen;
                        sum -= nums[i];
                        i++;
                }
        }
        return (minlen != INT_MAX) ? minlen : 0;
}
