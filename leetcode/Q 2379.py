# 2379. Minimum Recolors to Get K Consecutive Black Blocks
# https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08

# Solution
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        
        count = sum(1 for i in range(k) if blocks[i] == 'W')
        answer = count

        i = 1
        j = k
        while j < n:
            if blocks[i-1] == 'W':
                count -= 1
            if blocks[j] == 'W':
                count += 1
            
            answer = min(answer, count)
            i += 1
            j += 1
        return answer