class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        List<Integer>[] radj=new ArrayList[n], badj=new ArrayList[n];
        for(int i=0;i<n;i++){radj[i]=new ArrayList<>();badj[i]=new ArrayList<>();}
        for(int[]e:redEdges) radj[e[0]].add(e[1]);
        for(int[]e:blueEdges) badj[e[0]].add(e[1]);
        int[] res=new int[n]; Arrays.fill(res,-1); res[0]=0;
        boolean[][] seen=new boolean[n][2]; seen[0][0]=seen[0][1]=true;
        Deque<int[]> q=new ArrayDeque<>(); q.offer(new int[]{0,0,0}); q.offer(new int[]{0,1,0});
        while(!q.isEmpty()){
            int[] cur=q.poll(); int node=cur[0],col=cur[1],dist=cur[2];
            List<Integer> adj = col==0?radj[node]:badj[node];
            for(int nb:adj){
                if(seen[nb][1-col]) continue;
                seen[nb][1-col]=true;
                if(res[nb]==-1) res[nb]=dist+1;
                q.offer(new int[]{nb,1-col,dist+1});
            }
        }
        return res;
    }
}