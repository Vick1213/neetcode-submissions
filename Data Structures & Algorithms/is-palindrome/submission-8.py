class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned = [c for c in s.lower() if c.isalnum()]
        return cleaned == cleaned[::-1]
