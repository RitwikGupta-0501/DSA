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


# Final Solution
from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        m = len(words[0])
        dhm = Counter(words)
        result = list()

        if n < m * len(words):
            return []

        for start_index in range(m):
            i = start_index
            j = i
            hm = dhm.copy()
            matched = 0
            while j + m <= n:
                new_word = s[j : j + m]

                if new_word in words:
                    if hm[new_word] > 0:
                        hm[new_word] -= 1
                        matched += 1
                    else:
                        while s[i : i + m] != new_word:
                            hm[s[i : i + m]] += 1
                            matched -= 1
                            i += m
                        i += m
                else:
                    hm = dhm.copy()
                    matched = 0
                    i = j + m

                if matched == k:
                    result.append(i)

                j += m
        return result
