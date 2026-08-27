class Solution {
    public int evalRPN(String[] tokens) {
    
    // use stack till reaching a operator, pop till stack gets over, then continure till end, perform calculations
    
    Stack<Integer> intStack = new Stack();
    
    // evaluate first notation
    if(tokens.length == 1)
    {
        return Integer.parseInt(tokens[0]);
    }
    if(tokens.length == 2)
    {
        return 0;
    }
     if(tokens[2].equals("+"))
        {
            intStack.push(Integer.parseInt(tokens[0]) +Integer.parseInt(tokens[1]));
        }
        else if(tokens[2].equals("-"))
        {
            intStack.push(Integer.parseInt(tokens[0]) - Integer.parseInt(tokens[1]) );

        }else if(tokens[2].equals("*"))
        {
            intStack.push(Integer.parseInt(tokens[0]) * Integer.parseInt(tokens[1]) );

        }
        else if(tokens[2].equals("/"))
        {
            intStack.push(Integer.parseInt(tokens[0]) / Integer.parseInt(tokens[1]));
        }


    for(String token:tokens)
    {
        if(token.equals("+"))
        {
            int num = intStack.pop();
            int res = intStack.pop();
            intStack.push(num +res);
        }
        else if(token.equals("-"))
        {
            int num = intStack.pop();
            int res = intStack.pop();
            intStack.push(res - num);

        }else if(token.equals("*"))
        {
            int num = intStack.pop();
            int res = intStack.pop();
            intStack.push(res * num);

        }
        else if(token.equals("/"))
        {
            int num = intStack.pop();
            int res = intStack.pop();
            intStack.push(res / num);
        }
        else
        {
            intStack.push(Integer.parseInt(token));
        }
    
    }

    return(intStack.pop());
}
}
