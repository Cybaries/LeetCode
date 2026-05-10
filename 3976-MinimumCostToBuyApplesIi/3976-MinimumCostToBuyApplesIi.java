// Last updated: 11/05/2026, 01:30:07
class Solution {

    // Internal dijkstra uses long[] to safely handle large edge weights
    private long[] dijkstra(int src, int n, List<long[]>[] adj) {
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[src] = 0;

        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        pq.offer(new long[] { 0L, src });

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long currDist = curr[0];
            int node = (int) curr[1];

            if (currDist > dist[node])
                continue;

            for (long[] edge : adj[node]) {
                int neighbor = (int) edge[0];
                long weight = edge[1];
                long newDist = dist[node] + weight;

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.offer(new long[] { newDist, neighbor });
                }
            }
        }
        return dist;
    }

    public int[] minCost(int n, int[] prices, int[][] roads) {

        // long[] adjacency list: cost * taxi can reach 10^11, overflows int
        List<long[]>[] emptyAdj = new List[n];
        List<long[]>[] loadedAdj = new List[n];
        for (int i = 0; i < n; i++) {
            emptyAdj[i] = new ArrayList<>();
            loadedAdj[i] = new ArrayList<>();
        }

        for (int[] road : roads) {
            int u = road[0], v = road[1];
            long cost = road[2], taxi = road[3]; // promote to long before multiplying

            emptyAdj[u].add(new long[] { v, cost });
            emptyAdj[v].add(new long[] { u, cost });

            loadedAdj[u].add(new long[] { v, cost * taxi }); // safe: both are long
            loadedAdj[v].add(new long[] { u, cost * taxi });
        }

        int[] ans = new int[n]; // ✅ return type stays int[]

        for (int start = 0; start < n; start++) {
            long[] distEmpty = dijkstra(start, n, emptyAdj);
            long[] distLoaded = dijkstra(start, n, loadedAdj);

            long best = Long.MAX_VALUE; // use long internally to avoid overflow

            for (int j = 0; j < n; j++) {
                // Skip unreachable shops — without this guard,
                // MAX_VALUE + MAX_VALUE wraps to a tiny number and beats real answers
                if (distEmpty[j] == Long.MAX_VALUE || distLoaded[j] == Long.MAX_VALUE) {
                    continue;
                }
                long tripCost = distEmpty[j] + prices[j] + distLoaded[j];
                best = Math.min(best, tripCost);
            }

            ans[start] = (int) best; // cast only at the very end, once overflow is impossible
        }

        return ans;
    }
}