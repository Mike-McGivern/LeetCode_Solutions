public class Solution {
    public string ReverseParentheses(string s) {
        var stack = new Stack<StringBuilder>();
        stack.Push(new StringBuilder());

        foreach (char ch in s) {
            if (ch == '(') {
                // Start a new level
                stack.Push(new StringBuilder());
            }
            else if (ch == ')') {
                // Pop, reverse, and append to previous level
                var sb = stack.Pop();
                ReverseStringBuilder(sb);
                stack.Peek().Append(sb);
            }
            else {
                // Normal character
                stack.Peek().Append(ch);
            }
        }

        return stack.Pop().ToString();
    }

    private void ReverseStringBuilder(StringBuilder sb) {
        int left = 0, right = sb.Length - 1;
        while (left < right) {
            char temp = sb[left];
            sb[left] = sb[right];
            sb[right] = temp;
            left++;
            right--;
        }
    }
}
