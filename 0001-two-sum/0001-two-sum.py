class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        size = len(nums)
        i = 0
        for i in range(size):
            for j in range(i+1,size):
                sum = nums[i]+nums[j]
                if sum == target :
                    return [i,j]
