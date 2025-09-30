class Solution {
    public int triangularSum(int[] nums) {
        ArrayList<Integer> arr=new ArrayList<>();
        for(int num:nums){
            arr.add(num);
        }

        while(arr.size()!=1){
            ArrayList<Integer> temp=new ArrayList<>();
            for(int i=0;i<arr.size()-1;i++){
                int val = (arr.get(i)+arr.get(i+1))%10;
                temp.add(val);
            }
            arr=temp;
        }
        return arr.get(0);
    }
}