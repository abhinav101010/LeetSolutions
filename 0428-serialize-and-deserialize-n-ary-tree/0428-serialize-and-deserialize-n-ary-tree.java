// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
    // Encodes a tree to a single string.
    public String serialize(Node root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }
    
    private void serialize(Node node, StringBuilder sb) {
        if (node == null) {
            return;
        }
        sb.append(node.val).append(',');
        int size = node.children == null ? 0 : node.children.size();
        sb.append(size).append(',');
        for (Node child : node.children) {
            serialize(child, sb);
        }
    }
    
    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if (data == null || data.isEmpty()) {
            return null;
        }
        String[] tokens = data.split(",");
        Iterator<String> it = Arrays.asList(tokens).iterator();
        return deserialize(it);
    }
    
    private Node deserialize(Iterator<String> it) {
        int val = Integer.parseInt(it.next());
        int size = Integer.parseInt(it.next());
        Node node = new Node(val, new ArrayList<>());
        for (int i = 0; i < size; i++) {
            node.children.add(deserialize(it));
        }
        return node;
    }
}
