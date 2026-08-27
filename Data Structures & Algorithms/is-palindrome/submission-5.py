class Solution:
    def isPalindrome(self, s: str) -> bool:
        a =0
        s = s.lower()
        s = re.sub(r'[^a-z0-9]', '', s)
        b = len(s)-1

        while a<b:
            if s[a] == s[b]:
                a  = a +1
                b = b -1
            elif s[a] != s[b]:
                return False

        return True
