class Solution {
    public boolean isPalindrome(String s) {

         s = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
        
        StringBuilder sb = new StringBuilder(s);
        
        String reversedString = sb.reverse().toString();
        if(s.equals(reversedString))
        {
            return true;
        }
        else return false;
    }
}
