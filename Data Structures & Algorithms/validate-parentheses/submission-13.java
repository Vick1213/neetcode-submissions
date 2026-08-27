class Solution {
    public boolean isValid(String s) {

        char[] c = s.toCharArray();
        Stack<Character> st = new Stack<>();


        for(char i:c)
        {
            
            if(i == '{')
            {
                st.push('}');
            }
            else if(i == '(')
            {
                st.push(')');
            }
            else if(i == '[')
            {
                st.push(']');
            }
            else if(i == ')' || i == '}' || i == ']')
            {
                if(st.isEmpty() || st.pop() != i) return false;
            }
        }

        if(!st.isEmpty()) return false;

        return true;

    }
}
