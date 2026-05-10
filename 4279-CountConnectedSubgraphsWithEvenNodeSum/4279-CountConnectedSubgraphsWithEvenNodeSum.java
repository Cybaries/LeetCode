// Last updated: 11/05/2026, 01:29:59
class Solution {
    private int[] adj;

    private boolean isConnected(int mask) {

        // Pick the lowest node in mask as BFS start
        int start = Integer.numberOfTrailingZeros(mask);

        // Mark start as visited
        int visited = 1 << start;

        // Add start to queue
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(start);

        while (!queue.isEmpty()) {
            int node = queue.poll();

            // Neighbors of node that are:
            //   inside mask    → & mask
            //   not visited    → & ~visited
            int frontier = adj[node] & mask & ~visited;

            // Mark all of them visited at once
            visited |= frontier;

            // Add each one to the queue
            int temp = frontier;
            while (temp != 0) {
                int nb = Integer.numberOfTrailingZeros(temp);
                queue.add(nb);
                temp &= temp - 1;
            }
        }

        // If we reached every node in mask → connected
        return visited == mask;
    }
    public int evenSumSubgraphs(int[] nums, int[][] edges) {
        int n = nums.length;

        // -------------------------------------------------------
        // STEP 1: Build bitmask adjacency
        // -------------------------------------------------------
        adj = new int[n];
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u] |= (1 << v);  // v is a neighbor of u
            adj[v] |= (1 << u);  // u is a neighbor of v
        }

        int count = 0;

        // -------------------------------------------------------
        // STEP 2: Loop over every non-empty subset
        // -------------------------------------------------------
        for (int mask = 1; mask < (1 << n); mask++) {

            // ---------------------------------------------------
            // STEP 3: Check even sum (cheap check, do it first)
            // ---------------------------------------------------
            int total = 0;
            int temp = mask;

            while (temp != 0) {
                int node = Integer.numberOfTrailingZeros(temp); // get node index
                total += nums[node];                            // add its value
                temp &= temp - 1;                              // remove this node, move on
            }

            if (total % 2 != 0) {
                continue;  // odd sum → skip, don't even check connectivity
            }

            // ---------------------------------------------------
            // STEP 4: Check connectivity (expensive, only if sum passed)
            // ---------------------------------------------------
            if (isConnected(mask)) {
                count++;
            }
        }

        return count;
    }
}