class Solution {
    public int trap(int[] height) {
        
        if(height.length == 0 || height == null)
        {return 0;}
        int l = 0;
        int r = height.length -1;
        int lMax = height[l];
        int rMax = height[r];
        int res =0;
        int i=0;
        while(l<r)
        {
            if(lMax<rMax)
            {
                 l++;
                lMax = Math.max(lMax,height[l]);
                res += lMax- height[l];
               
            }
            else
            {
                r--;
                rMax = Math.max(rMax,height[r]);
                res += rMax- height[r];
                
            }
        }

        return res;


    }
}
