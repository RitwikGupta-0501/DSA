# 34. Find First and Last Position of Element in Sorted Array
# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/


# First Attempt
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = 0
        last = len(nums) - 1

        while first <= last:

            if nums[first] == target and nums[last] == target:
                return [first, last]
            
            if nums[first] == target:
                last -= 1
            elif nums[last] == target:
                first += 1
            else:
                first += 1
                last -= 1

        return [-1, -1]


# Second Attempt
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def search(nums, target):
            high = len(nums)-1
            low = 0
            while low <= high:
                mid = low + (high-low)//2
                if nums[mid] == target:
                    return mid
                
                if nums[mid] > target:
                    high = mid-1
                else:
                    low = mid+1
            return -1
        
        i = j = search(nums, target)
        if i == -1:
            return [-1, -1]

        while i >= 0:
            if nums[i] < target:
                break
            i -= 1

        while j < len(nums):
            if nums[j] > target:
                break
            j += 1

        return [i+1, j-1]