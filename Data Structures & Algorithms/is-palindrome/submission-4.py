class Solution:
    def isPalindrome(self, s: str) -> bool:
        a =0
        s = s.lower()
        string = re.sub(r'[^a-z0-9]', '', s)
        b = len(string)-1

        while a<b:
            if string[a] == string[b]:
                a  = a +1
                b = b -1
            elif string[a] != string[b]:
                return False

        return True
