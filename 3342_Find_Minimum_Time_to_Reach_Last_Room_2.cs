using System;
using System.Collections.Generic;

public class Solution
{
    public int MinTimeToReach(int[][] moveTime)
    {
        int n = moveTime.Length, m = moveTime[0].Length;
        int[,] dist = new int[n, m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dist[i, j] = int.MaxValue;
        
        dist[0, 0] = 0;
        var pq = new SortedSet<(int d, int i, int j)>(Comparer<(int, int, int)>.Create((a, b) => a.Item1 == b.Item1 ? (a.Item2 == b.Item2 ? a.Item3 - b.Item3 : a.Item2 - b.Item2) : a.Item1 - b.Item1));
        pq.Add((0, 0, 0));

        int[] dirs = { -1, 0, 1, 0, -1 };

        while (pq.Count > 0)
        {
            var current = pq.Min;
            pq.Remove(current);
            int d = current.d, i = current.i, j = current.j;

            if (i == n - 1 && j == m - 1)
                return d;

            if (d > dist[i, j]) continue;

            for (int k = 0; k < 4; k++)
            {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < m)
                {
                    int t = Math.Max(moveTime[x][y], dist[i, j]) + (i + j) % 2 + 1;
                    if (dist[x, y] > t)
                    {
                        dist[x, y] = t;
                        pq.Add((t, x, y));
                    }
                }
            }
        }
        return -1; // Shouldn't reach here, but provides fallback.
    }
}
