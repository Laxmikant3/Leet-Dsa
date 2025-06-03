class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        
        int aliceSum = 0, bobSum = 0;

        for (int i = 0; i < aliceSizes.length; i++) {
            aliceSum += aliceSizes[i];
        }

        for (int i = 0; i < bobSizes.length; i++) {
            bobSum += bobSizes[i];
        }

        for (int i = 0; i < aliceSizes.length; i++) {
            for (int j = 0; j < bobSizes.length; j++) {
                if ((aliceSum - aliceSizes[i] + bobSizes[j]) == 
                    (bobSum - bobSizes[j] + aliceSizes[i])) {
                    return new int[] { aliceSizes[i], bobSizes[j] };
                }
            }
        }

        return new int[] {};
    }
}