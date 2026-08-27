class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> HashedNum = new HashMap<>();
        for(int num: nums)
        {
            if(HashedNum.containsKey(num))
            {
                HashedNum.put(num,HashedNum.get(num)+1);
            }
            else
            {
                HashedNum.put(num,1);
            }
        }        
        
      PriorityQueue<Map.Entry<Integer, Integer>> reqiasd =
                new PriorityQueue<>(Comparator.comparingInt(Map.Entry::getValue));

        for (Map.Entry<Integer, Integer> e : HashedNum.entrySet()) {
            if (reqiasd.size() < k) {
                reqiasd.offer(e);
            } else if (e.getValue() > reqiasd.peek().getValue()) {
                reqiasd.poll();
                reqiasd.offer(e);
            }
        }

        int[] retArr = new int[Math.min(k, reqiasd.size())];
        int i = retArr.length - 1;
        while (!reqiasd.isEmpty()) {
            retArr[i--] = reqiasd.poll().getKey();
        }
        return retArr;
    }

}
