class Solution {
   public String minWindow(String s, String t) {
        /*
            string temp = "";
            for(s : t) {
                if(s.substr(i,i+1) == t.substr(i,i+1))
                    temp += "s.substring(i,i+1)"
            }
        */
        Map<Character, Integer> targetMap = new HashMap<>();
        for(char c : t.toCharArray()) {
            targetMap.put(c, targetMap.getOrDefault(c, 0) + 1);
        }
        int left = 0;
        int count = t.length();
        int minLength = Integer.MAX_VALUE;
        String result  = "";
        for(int right = 0; right < s.length(); right++) {
            char currChar = s.charAt(right);
            if(targetMap.containsKey(currChar)) {
                if(targetMap.get(currChar) > 0) {
                    count--;
                }
                targetMap.put(currChar, targetMap.get(currChar) - 1);
            }
            while(count == 0) {
                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    result = s.substring(left, right + 1);
                }
                char leftChar = s.charAt(left);
                if(targetMap.containsKey(leftChar)) {
                    targetMap.put(leftChar, targetMap.get(leftChar) + 1);
                    if(targetMap.get(leftChar) > 0) {
                        count++;
                    }
                }
                left++;
                //*ptr LHS TO RHS
            }
        }
        return result;
    }
};
