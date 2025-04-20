# 3306. Count of Substrings Containing Every Vowel and K Consonants II
# https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10


# First Solution
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        result = 0

        for i in range(len(word) - (5+k) + 1):
            vowels = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0}
            count = 0
            for j in range(i, len(word)):
                if word[j] in vowels:
                    vowels[word[j]] += 1
                else:
                    count += 1

                if count > k:
                    break

                if count == k and (0 not in vowels.values()):
                    print(word[i: j+1])
                    result += 1
                    
        return result