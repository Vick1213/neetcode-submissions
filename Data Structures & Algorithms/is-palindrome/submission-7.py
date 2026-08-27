class Solution:
    def isPalindrome(self, s: str) -> bool:
        a =0
        s = s.lower()
        b = len(s)-1

        while a<b:
            if not s[a].isalnum() :
                a = a+1
                continue
            if not s[b].isalnum():
                b = b-1
                continue
            if s[a] == s[b]:
                a  = a +1
                b = b -1
            elif s[a] != s[b]:
                return False

        return True
