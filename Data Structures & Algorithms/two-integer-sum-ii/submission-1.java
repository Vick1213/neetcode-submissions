class Solution {
    public int[] twoSum(int[] numbers, int target) {


    int x=0;
    int y=numbers.length -1;

    while(x<y)
    {
        int curr = numbers[x] + numbers[y];

        if(curr> target)
        {
            y--;
        }
        else if(curr<target)
        {
            x++;
        }
        else
        {
            return new int[] {x+1, y+1};
        }
    }

    return new int[0];
    }
}
