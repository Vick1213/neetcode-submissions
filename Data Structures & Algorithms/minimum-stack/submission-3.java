class MinStack {
    boolean init = false;
    Stack<int[]> intStack;

    public MinStack() {
        init = true;
        intStack = new Stack<>();
    }
    
    public void push(int val) {
        if(init){
        int[] s = new int[2];
        s[0] = val;
        if(!intStack.isEmpty())
        s[1] = Math.min(intStack.peek()[1], val);
        else 
        s[1] = val;
        intStack.push(s);
        }
    }
    
    public void pop() {
        if(init)
      intStack.pop();
    }
    
    public int top() {
        if(init)
        return intStack.peek()[0];
        return -1;
    }
    
    public int getMin() {
        if(init)
        return intStack.peek()[1];
        return -1;
    }
}