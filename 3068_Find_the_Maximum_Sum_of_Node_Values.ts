function maximumValueSum(nums: number[], k: number, edges: number[][]): number {
        let maxSum = nums.reduce((sum, num) => sum + Math.max(num, num ^ k), 0);
        let changedCount = nums.reduce((count, num) => count + ((num ^ k) > num ? 1 : 0), 0);

        if (changedCount % 2 === 0) {
            return maxSum;
        } else {
            let minChangeDiff = Math.min(...nums.map(num => Math.abs(num - (num ^ k))));
            return maxSum - minChangeDiff;
        }

};
