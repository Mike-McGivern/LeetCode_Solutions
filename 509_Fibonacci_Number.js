/**
 * @param {number} n
 * @return {number}
 */
let fib = function(N) {
    if (N <= 0) {
        return 0;
    } else if (N === 1) {
        return 1;
    } else {
        return fib(N-1) + fib(N-2)
    }
};
