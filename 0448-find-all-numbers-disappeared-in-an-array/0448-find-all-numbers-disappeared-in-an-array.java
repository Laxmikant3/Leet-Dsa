class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        HashMap<Integer , Boolean> map = new HashMap<>();
        for(int num : nums){
            map.put(num, true);
        }
        List<Integer> ans= new ArrayList<>();

        for(int i=1;i<=nums.length;i++){
            if(!map.containsKey(i)){
                ans.add(i);

            }
        }
        return ans;
    }
}