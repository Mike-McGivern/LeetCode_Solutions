/**
 * @param {string} colors
 * @param {number[][]} edges
 * @return {number}
 */
var largestPathValue = function(colors, edges) {
    const n = colors.length;
    const graph = Array.from({ length: n}, () => []);
    const inDegree = new Array(n).fill(0);
    const dp = Array.from({ length: n}, () => new Array(26).fill(0));

    for(const [u, v] of edges) {
        graph[u].push(v);
        inDegree[v]++;
    }
    let queue = []
    for(let i = 0; i < n; i++) {
        if(inDegree[i] === 0) {
            queue.push(i);
        }
    }

    let processed = 0, maxColorValue = 0;

    while(queue.length) {
        let node = queue.shift();
        processed++;
        let colorIndex = colors.charCodeAt(node) - 97;
        dp[node][colorIndex]++;
        maxColorValue = Math.max(maxColorValue, dp[node][colorIndex]);

        for(let neighbor of graph[node]) {
            for(let i = 0; i < 26; i++) {
                dp[neighbor][i] = Math.max(dp[neighbor][i], dp[node][i]);
            }
            if(--inDegree[neighbor] == 0) {
                queue.push(neighbor);
            }
        }
    }

    return processed === n ? maxColorValue : -1;
};
