class Solution {
    public boolean isAnagram(String s, String t) {
    int[] freq = new int[26];
    char[] sc = s.toCharArray();
    char[] tc= t.toCharArray();
    for(char a: sc)
    {
        freq[(int) a - 97] ++;
    }

    for(char a: tc)
    {
        freq[(int) a - 97] --;
    }

    for(int i: freq)
    {
        if(i!=0)
        {
            return false;
        }
    }

    return true;
    }
}
