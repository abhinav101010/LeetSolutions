import java.util.*;

class FileSystem {
    private Map<String, Integer> store;

    public FileSystem() {
        store = new HashMap<>();
        store.put("/", null); // root
    }

    public boolean createPath(String path, int value) {
        if (store.containsKey(path)) {
            return false;
        }
        int lastSlash = path.lastIndexOf('/');
        String parent;
        if (lastSlash == -1) {
            parent = "/";
        } else {
            parent = path.substring(0, lastSlash);
            if (parent.isEmpty()) {
                parent = "/";
            }
        }
        if (!store.containsKey(parent)) {
            return false;
        }
        store.put(path, value);
        return true;
    }

    public int get(String path) {
        Integer val = store.get(path);
        return val == null ? -1 : val;
    }
}
