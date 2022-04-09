class Solution {
    public int[] twoSum(int[] nums, int target) {
   HashMap<Integer , Integer > mp = new HashMap<Integer, Integer >();
        int n = nums.length;
            int[] result = new int[2];
        for(int i=0 ; i < n ; i++){
            if(mp.containsKey(target - nums[i])){
                  result[1] = i;
            result[0] = mp.get(target - nums[i]);
            return result;
            }
                mp.put(nums[i], i);
        }
        
        return result;
    }
}