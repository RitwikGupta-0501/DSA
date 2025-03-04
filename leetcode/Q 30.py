# 30. Substring with Concatenation of All Words
# https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

# First Solution
from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        m = len(words[0])

        result = list()
        if n < m * len(words):
            return []

        dhm = Counter(words)
        i = 0
        for i in range(n - m * k + 1):
            hashmap = dhm.copy()
            j = i
            total = 0
            while s[j: j+m] in words and hashmap[s[j: j+m]] > 0:
                hashmap[s[j: j+m]] -= 1
                total += 1
                j += m

            if total == k:
                result.append(i)
        return result
    

# Second Solution
from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        m = len(words[0])
        result = list()

        if n < m * len(words):
            return []
        
        i, j = 0, 0
        dhm = Counter(words)
        total = 0

        while j <= n:
            while s[j: j+m] in dhm and dhm[s[j: j+m]] > 0:
                dhm[s[j: j+m]] -= 1
                total += 1
                j += m
            
            if total == k:
                result.append(i)
                dhm[s[i: i+m]] += 1
                i += m
                total -= 1
            else:
                dhm = Counter(words)
                i += 1
                j = i
                total = 0
        return result