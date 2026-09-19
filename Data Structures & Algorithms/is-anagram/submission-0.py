class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        freq = list()
        freq = [0] * 26
        for c1, c2 in zip(s, t):
            idx1 = ord(c1) - ord('a')
            idx2 = ord(c2) - ord('a')
            freq[idx1] += 1
            freq[idx2] -= 1
        
        return all(x == 0 for x in freq)