class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 3 pointers 

        // first slow
        //second slow
        // third fast

        // find where fast and first slow meet get new second slow to meet first slow then return that


        int slow =0;
        int fast =0;
        int slow2 =0;
        bool releaseSlow2 = false;
        while(true)
        {
            fast = nums[nums[fast]];

            slow = nums[slow];
            if (releaseSlow2)
            {
                slow2 = nums[slow2];
                if (slow2 == slow) return slow;
            }

            if (fast == slow)
            {   
                releaseSlow2 = true;
            }
        }

        return slow;
    }
};
