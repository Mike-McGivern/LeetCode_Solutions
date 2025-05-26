function largestPathValue(colors: string, edges: number[][]): number {
    const n: number = colors.length;
    const graph: number[][] = Array.from({ length: n}, () => []);
    const inDegree: number[] = new Array(n).fill(0);
    const dp: number[][] = Array.from({ length: n}, () => new Array(26).fill(0));

    for(const [u,v] of edges) {
        graph[u].push(v);
        inDegree[v]++;
    }

    const queue: number[] = [];
    for(let i = 0; i < n; i++) {
        if(inDegree[i] === 0) {
            queue.push(i);
        }
    }
    let processed: number = 0;
    let maxColorValue: number = 0;

    while(queue.length) {
        const node: number = queue.shift()!;
        processed++;
        const colorIndex: number = colors.charCodeAt(node) - 97;
        dp[node][colorIndex]++;
        maxColorValue = Math.max(maxColorValue, dp[node][colorIndex]);

        for(const neighbor of graph[node]) {
            for(let i = 0; i < 26; i++) {
                dp[neighbor][i] = Math.max(dp[neighbor][i], dp[node][i]);
            }
            if(--inDegree[neighbor] === 0) {
                queue.push(neighbor);
            }
        }
    }

    return processed === n ? maxColorValue: -1;
};
