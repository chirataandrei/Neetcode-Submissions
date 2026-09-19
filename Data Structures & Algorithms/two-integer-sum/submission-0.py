class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = dict()
        for i, num in enumerate(nums):
            com = target - num
            if com in seen:
                return [seen[com], i]
            seen[num] = i
    
