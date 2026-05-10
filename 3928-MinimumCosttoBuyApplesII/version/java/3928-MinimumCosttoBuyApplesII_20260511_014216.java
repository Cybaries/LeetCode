// Last updated: 11/05/2026, 01:42:16
// Check
1class Solution {
2
3    // Internal dijkstra uses long[] to safely handle large edge weights
4    private long[] dijkstra(int src, int n, List<long[]>[] adj) {
5        long[] dist = new long[n];
6        Arrays.fill(dist, Long.MAX_VALUE);
7        dist[src] = 0;
8
9        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
10        pq.offer(new long[] { 0L, src });
11
12        while (!pq.isEmpty()) {
13            long[] curr = pq.poll();
14            long currDist = curr[0];
15            int node = (int) curr[1];
16
17            if (currDist > dist[node])
18                continue;
19
20            for (long[] edge : adj[node]) {
21                int neighbor = (int) edge[0];
22                long weight = edge[1];
23                long newDist = dist[node] + weight;
24
25                if (newDist < dist[neighbor]) {
26                    dist[neighbor] = newDist;
27                    pq.offer(new long[] { newDist, neighbor });
28                }
29            }
30        }
31        return dist;
32    }
33
34    public int[] minCost(int n, int[] prices, int[][] roads) {
35
36        // long[] adjacency list: cost * taxi can reach 10^11, overflows int
37        List<long[]>[] emptyAdj = new List[n];
38        List<long[]>[] loadedAdj = new List[n];
39        for (int i = 0; i < n; i++) {
40            emptyAdj[i] = new ArrayList<>();
41            loadedAdj[i] = new ArrayList<>();
42        }
43
44        for (int[] road : roads) {
45            int u = road[0], v = road[1];
46            long cost = road[2], taxi = road[3]; // promote to long before multiplying
47
48            emptyAdj[u].add(new long[] { v, cost });
49            emptyAdj[v].add(new long[] { u, cost });
50
51            loadedAdj[u].add(new long[] { v, cost * taxi }); // safe: both are long
52            loadedAdj[v].add(new long[] { u, cost * taxi });
53        }
54
55        int[] ans = new int[n]; // ✅ return type stays int[]
56
57        for (int start = 0; start < n; start++) {
58            long[] distEmpty = dijkstra(start, n, emptyAdj);
59            long[] distLoaded = dijkstra(start, n, loadedAdj);
60
61            long best = Long.MAX_VALUE; // use long internally to avoid overflow
62
63            for (int j = 0; j < n; j++) {
64                // Skip unreachable shops — without this guard,
65                // MAX_VALUE + MAX_VALUE wraps to a tiny number and beats real answers
66                if (distEmpty[j] == Long.MAX_VALUE || distLoaded[j] == Long.MAX_VALUE) {
67                    continue;
68                }
69                long tripCost = distEmpty[j] + prices[j] + distLoaded[j];
70                best = Math.min(best, tripCost);
71            }
72
73            ans[start] = (int) best; // cast only at the very end, once overflow is impossible
74        }
75
76        return ans;
77    }
78}