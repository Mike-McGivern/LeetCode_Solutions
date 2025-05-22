import java.util.List;

public class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        TrieNode root = new TrieNode();
        for (String word : dictionary) {
            TrieNode node = root;
            for (char letter : word.toCharArray()) {
                if (node.children[letter - 'a'] == null) {
                    node.children[letter - 'a'] = new TrieNode();
                }
                node = node.children[letter - 'a'];
            }
            node.word = word;
        }

        StringBuilder result = new StringBuilder();
        for (String word : sentence.split("\\s+")) {
            TrieNode node = root;
            for (char letter : word.toCharArray()) {
                if (node.word != null || node.children[letter - 'a'] == null) break;
                node = node.children[letter - 'a'];
            }
            result.append(" ");
            result.append(node.word != null ? node.word : word);
        }

        return result.deleteCharAt(0).toString();
    }

    private class TrieNode {
        TrieNode[] children;
        String word;

        TrieNode() {
            this.children = new TrieNode[26];
            this.word = null;
        }
    }
}
