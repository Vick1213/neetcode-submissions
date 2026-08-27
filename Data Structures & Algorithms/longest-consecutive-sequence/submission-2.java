class Solution {
    public int longestConsecutive(int[] nums) {

  HashSet<Integer> hashset = new HashSet<>();


    if(nums.length ==0)
    {return 0;}
int currlength =0;
  for(int num:nums)
  {
    hashset.add(num);
  }

  for(int i =0; i<nums.length; i++)
  {
    if(hashset.contains(nums[i]- 1))
    {
        int k = 1;
        while(hashset.contains(nums[i]+k))
        {
            k = k+1;
        }

        if(currlength<= k) {currlength = k;}

    }

  }

  return currlength +1;
    }}


