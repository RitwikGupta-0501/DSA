# 2523. Closest Prime Numbers in Range
# https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07

# Solution
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        # Sieve of Eratosthenes
        def prime(left, right):
            primes = [True] * right
            primes[0] = primes[1] = False
            for i in range(2, int(sqrt(right))+1):
                if primes[i]:
                    for j in range(i*i, right, i):
                        primes[j] = False
            return [i for i in range(right) if primes[i] and i >= left]

        primes = prime(left, right+1)
        result = [-1, -1]
        minimum = right
        for i in range(1, len(primes)):
            if primes[i] - primes[i-1] < minimum:
                result = [primes[i-1], primes[i]]
                minimum = primes[i] - primes[i-1]
        return result
        