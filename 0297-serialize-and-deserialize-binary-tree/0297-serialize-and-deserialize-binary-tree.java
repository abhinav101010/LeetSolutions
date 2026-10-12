/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;

public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializeHelper(root, sb);
        return sb.toString();
    }
    
    private void serializeHelper(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append("N,");
            return;
        }
        sb.append(node.val).append(",");
        serializeHelper(node.left, sb);
        serializeHelper(node.right, sb);
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] vals = data.split(",");
        index = 0;
        return deserializeHelper(vals);
    }
    
    private int index;
    
    private TreeNode deserializeHelper(String[] vals) {
        if (vals[index].equals("N")) {
            index++;
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(vals[index]));
        index++;
        node.left = deserializeHelper(vals);
        node.right = deserializeHelper(vals);
        return node;
    }
}