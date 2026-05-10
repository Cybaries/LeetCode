// Last updated: 11/05/2026, 01:30:00
class Solution {
    int id(int x, int y, int z) {
        return x * 49 + y * 7 + z;
    }

    int[][] coord = new int[343][3];

    public int minGenerations(int[][] points, int[] target) {
        for (int x = 0; x < 7; x++) {
            for (int y = 0; y < 7; y++) {
                for (int z = 0; z < 7; z++) {

                    int v = id(x, y, z);

                    coord[v][0] = x;
                    coord[v][1] = y;
                    coord[v][2] = z;
                }
            }
        }

        int tar = id(target[0], target[1], target[2]);

        boolean[] vis = new boolean[343];

        ArrayList<Integer> all = new ArrayList<>();
        ArrayList<Integer> cur = new ArrayList<>();

        for (int[] p : points) {

            int v = id(p[0], p[1], p[2]);

            if (v == tar)
                return 0;

            vis[v] = true;

            all.add(v);
            cur.add(v);
        }

        int gen = 0;

        while (!cur.isEmpty()) {

            ArrayList<Integer> nxt = new ArrayList<>();

            for (int a : cur) {

                int ax = coord[a][0];
                int ay = coord[a][1];
                int az = coord[a][2];

                for (int b : all) {

                    if (a == b)
                        continue;

                    int bx = coord[b][0];
                    int by = coord[b][1];
                    int bz = coord[b][2];

                    int mid = id(
                            (ax + bx) / 2,
                            (ay + by) / 2,
                            (az + bz) / 2);

                    if (vis[mid])
                        continue;

                    vis[mid] = true;

                    if (mid == tar) {
                        return gen + 1;
                    }

                    nxt.add(mid);
                }
            }

            all.addAll(nxt);

            cur = nxt;

            gen++;
        }

        return -1;

    }
}