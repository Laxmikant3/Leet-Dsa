class Solution {
  int minimumPairRemoval(List<int> nums) {
    int operations = 0;

    while (!_isNonDecreasing(nums)) {
      int minSum = nums[0] + nums[1];
      int index = 0;

      // Find leftmost adjacent pair with minimum sum
      for (int i = 1; i < nums.length - 1; i++) {
        int sum = nums[i] + nums[i + 1];
        if (sum < minSum) {
          minSum = sum;
          index = i;
        }
      }

      // Merge the chosen pair
      nums[index] = minSum;
      nums.removeAt(index + 1);
      operations++;
    }

    return operations;
  }

  bool _isNonDecreasing(List<int> nums) {
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] < nums[i - 1]) return false;
    }
    return true;
  }
}