class Solution:
    def findMin(self, nums: List[int]) -> int:
        # compare first and last
        flagR = False
        if nums[0]>nums[-1]:
            flagR = True

        if flagR:
            for i in range(len(nums)-1,0,-1):
                if nums[i]<nums[i-1]:
                    return nums[i]
        else:
            return nums[0]