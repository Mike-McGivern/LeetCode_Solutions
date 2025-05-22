class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        dfs(s, 0, new ArrayList<>(), ans);
        return ans;
    }
    private void dfs(String s, int start, List<String> path, List<List<String>> ans) {
        if(start == s.length()) {
            ans.add(new ArrayList<>(path));
            return;
        }
        for(int i = start; i < s.length(); ++i) {
            if(isPalindorme(s, start, i)) {
                path.add(s.substring(start, i + 1));
                dfs(s, i + 1, path, ans);
                path.remove(path.size() - 1);
            }
        }
    }
   private boolean isPalindorme(String s, int l, int r) {
        while(l < r) {
            if(s.charAt(l++) != s.charAt(r--)) {
                return false;
            }
        }
        return true;
    }
}
