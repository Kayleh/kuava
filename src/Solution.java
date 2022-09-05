class Solution {
    public int maxDistToClosest(int[] seats) {
        int maxLen = 0, curLen = 0;
        int maxLeft = 0;
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 1) {
                maxLeft = i;
                maxLen = Math.max(maxLen, curLen);
                curLen = 0;
                break;
            } else {
                curLen++;
                maxLen = Math.max(maxLen, curLen);
            }
        }

        return maxLeft + maxLen / 2;
    }
}

//[1,0,0,0,1,0,1]
