class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // fixed - hours and piles

        // sort piles 

        // minimym Eating speed = greedy try 
        // 1 2 3 4 5 6 7 - [1,2,3,4] highest would  max [list]

        int low = 1;
        int high = std::ranges::max(piles);
        int mid;

        while(low<high)
        {
             mid = low + (high- low)/2;

            if(checkIfUnderTarget(mid, piles, h))
            {
                high = mid;
            }
            else
            {
                low = mid +1;
            }
        }
        return low;

    }

    bool checkIfUnderTarget(int mid,vector<int>&piles, int h)
    {
        for(int &b:piles)
        {
            h = h - (b + mid - 1) / mid ;
        }

        return h>=0;

    }
};
