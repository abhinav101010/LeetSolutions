class Solution {
    public int longestWPI(int[] hours) {
        int cur=0,best=0; Map<Integer,Integer> seen=new HashMap<>(); seen.put(0,-1);
        for(int i=0;i<hours.length;i++){
            cur += hours[i]>8?1:-1;
            if(cur>0) best=i+1;
            else if(seen.containsKey(cur-1)) best=Math.max(best,i-seen.get(cur-1));
            if(!seen.containsKey(cur)) seen.put(cur,i);
        }
        return best;
    }