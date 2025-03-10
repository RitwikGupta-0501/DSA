# 3208. Alternating Groups II
# https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        N = len(colors)
        left = 0
        right = 1
        result = 0

        while right < N+k-1:
            if colors[right % N] == colors[(right-1)%N]:
                left = right
            
            if right - left + 1 == k:
                result += 1
                left += 1
            
            right += 1

        return result