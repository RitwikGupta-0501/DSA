# 40. Combination Sum II
# https://leetcode.com/problems/combination-sum-ii/description/?envType=problem-list-v2&envId=2zxo4a4c
from typing import List


# First Solution
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)
        result = []

        def backtrack(start, path, path_sum):
            if path_sum == target:
                result.append(path[:])
                return True
            elif path_sum > target:
                return False
            
            for i in range(start, n):
                if candidates[i] == candidates[i-1] and i > start:
                    continue
                path.append(candidates[i])
                backtrack(i+1, path, path_sum + candidates[i])
                path.pop()
        
        backtrack(0, [], 0)
        return result


# Second Solution
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        for i in range(len(candidates)):
            if candidates[i] > target:
                break
        n = i+1
        result = []

        def backtrack(start, path, path_sum):
            if path_sum == target:
                result.append(path[:])
                return True
            elif path_sum > target:
                return False
            
            for i in range(start, n):
                if candidates[i] == candidates[i-1] and i > start:
                    continue
                path.append(candidates[i])
                backtrack(i+1, path, path_sum + candidates[i])
                path.pop()
        
        backtrack(0, [], 0)
        return result

# Final Solution
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        for i in range(len(candidates)):
            if candidates[i] > target:
                break
        n = i+1
        result = []

        def backtrack(start, path, path_sum):
            if path_sum == target:
                result.append(path[:])
                return
            
            for i in range(start, n):
                if i > start and candidates[i] == candidates[i-1]:
                    continue

                new_sum = path_sum + candidates[i]
                if new_sum > target:
                    break

                path.append(candidates[i])
                backtrack(i+1, path, new_sum)
                path.pop()
        
        backtrack(0, [], 0)
        return result