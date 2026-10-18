import java.util.*;

class Tree {
    public int id;
    public Integer p_id;
    public Tree(int id, Integer p_id) { this.id = id; this.p_id = p_id; }
}

class Solution {
    public List<List<String>> treeNode(List<Tree> tree) {
        Set<Integer> isParent = new HashSet<>();
        for (Tree t : tree) if (t.p_id != null) isParent.add(t.p_id);
        List<Tree> nodes = new ArrayList<>(tree);
        nodes.sort((a, b) -> Integer.compare(a.id, b.id));
        List<List<String>> result = new ArrayList<>();
        for (Tree t : nodes) {
            String type;
            if (t.p_id == null) type = "Root";
            else if (isParent.contains(t.id)) type = "Inner";
            else type = "Leaf";
            result.add(Arrays.asList(String.valueOf(t.id), type));
        }
        return result;
    }
}
