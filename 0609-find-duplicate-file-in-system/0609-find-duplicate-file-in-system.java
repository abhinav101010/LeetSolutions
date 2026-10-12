import java.util.*;

class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> contentToFiles = new HashMap<>();
        
        for (String path : paths) {
            String[] parts = path.split(" ");
            String directory = parts[0];
            for (int i = 1; i < parts.length; i++) {
                String fileInfo = parts[i];
                int idx = fileInfo.indexOf('(');
                String filename = fileInfo.substring(0, idx);
                String content = fileInfo.substring(idx + 1, fileInfo.length() - 1);
                contentToFiles.computeIfAbsent(content, k -> new ArrayList<>()).add(directory + "/" + filename);
            }
        }
        
        List<List<String>> result = new ArrayList<>();
        for (List<String> files : contentToFiles.values()) {
            if (files.size() > 1) result.add(files);
        }
        return result;
    }
}