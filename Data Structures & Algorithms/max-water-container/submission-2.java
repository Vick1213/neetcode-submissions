class Solution {
    public int maxArea(int[] heights) {
    

    int l =0;
    int r = heights.length-1;
    int currMaxArea =0;

    while(l<r)
    {   
        int length = r-l;
        int height = Math.min(heights[l],heights[r]);
        int Area = length*height;
        if(currMaxArea<Area)
        {
            currMaxArea = Area;
        }
        if(heights[r]<heights[l])
        {
            r--;
            
        }
        else
        {
            l++;
        }
    }

    return currMaxArea;
    }
}
