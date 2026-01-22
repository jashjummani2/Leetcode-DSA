class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        
        n = len(nums)
        def isSorted(arr):
            for i in range(len(arr)-1):
                if arr[i]>arr[i+1]:
                    return False
            return True
        
        ops =0
        while not isSorted(nums):
            idx = 0
            min_sum = float('inf')
            for i in range(len(nums)-1):
                sm = nums[i]+nums[i+1]
                if sm < min_sum:
                    min_sum = sm
                    idx =i
            nums = nums[:idx]+[min_sum]+nums[idx+2:]
            ops+=1
        return ops