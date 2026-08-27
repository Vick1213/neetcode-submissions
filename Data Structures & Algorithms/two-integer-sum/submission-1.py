class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        newmap = {}
        count = 0
        for i in nums:
            newmap[i] = count
            count = count + 1

        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in newmap and newmap[diff] != i:
                return sorted([i, newmap[diff]])