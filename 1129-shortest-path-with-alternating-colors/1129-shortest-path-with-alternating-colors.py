class Solution:
    def shortestAlternatingPaths(self, n, redEdges, blueEdges):
        from collections import deque,defaultdict
        radj=defaultdict(list); badj=defaultdict(list)
        for a,b in redEdges: radj[a].append(b)
        for a,b in blueEdges: badj[a].append(b)
        res=[-1]*n; res[0]=0
        q=deque([(0,0,0),(0,1,0)]) # node,color(0 red,1 blue),dist
        seen={(0,0),(0,1)}
        while q:
            node,col,dist=q.popleft()
            adj = radj if col==0 else badj
            for nb in adj[node]:
                if (nb,1-col) in seen: continue
                seen.add((nb,1-col))
                if res[nb]==-1: res[nb]=dist+1
                q.append((nb,1-col,dist+1))
        return res