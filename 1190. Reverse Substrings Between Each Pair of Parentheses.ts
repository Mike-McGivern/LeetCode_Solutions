function reverseParentheses(s: string): string {
    const stack: string[] = [''];

    for (const ch of s) {
        if (ch === '(') {
            // Start a new substring level
            stack.push('');
        } else if (ch === ')') {
            // Pop, reverse, and append to previous level
            const reversed = stack.pop()!.split('').reverse().join('');
            stack[stack.length - 1] += reversed;
        } else {
            // Normal character, append to current level
            stack[stack.length - 1] += ch;
        }
    }

    return stack[0];
}
