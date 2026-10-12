import java.util.*;

public class Codec {
    private Map<String, String> urlToCode = new HashMap<>();
    private Map<String, String> codeToUrl = new HashMap<>();
    private String chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    private String base = "http://tinyurl.com/";
    private Random rand = new Random();

    public String encode(String longUrl) {
        if (urlToCode.containsKey(longUrl)) return base + urlToCode.get(longUrl);
        StringBuilder code = new StringBuilder();
        for (int i = 0; i < 6; i++) {
            code.append(chars.charAt(rand.nextInt(chars.length())));
        }
        String codeStr = code.toString();
        while (codeToUrl.containsKey(codeStr)) {
            code = new StringBuilder();
            for (int i = 0; i < 6; i++) {
                code.append(chars.charAt(rand.nextInt(chars.length())));
            }
            codeStr = code.toString();
        }
        urlToCode.put(longUrl, codeStr);
        codeToUrl.put(codeStr, longUrl);
        return base + codeStr;
    }

    public String decode(String shortUrl) {
        String code = shortUrl.replace(base, "");
        return codeToUrl.getOrDefault(code, "");
    }
}