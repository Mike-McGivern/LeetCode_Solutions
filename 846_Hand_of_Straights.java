import java.util.TreeMap;

public class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        TreeMap<Integer, Integer> count = new TreeMap<>();
        for (int card : hand) {
            count.put(card, count.getOrDefault(card, 0) + 1);
        }
        for (int card : count.keySet()) {
            if (count.get(card) > 0) {
                for (int i = groupSize - 1; i >= 0; --i) {
                    if (count.getOrDefault(card + i, 0) < count.get(card)) {
                        return false;
                    }
                    count.put(card + i, count.get(card + i) - count.get(card));
                }
            }
        }
        return true;
    }
}
