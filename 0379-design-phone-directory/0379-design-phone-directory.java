import java.util.*;

class PhoneDirectory {
    private Set<Integer> available;
    private int maxNumbers;
    
    public PhoneDirectory(int maxNumbers) {
        this.maxNumbers = maxNumbers;
        available = new HashSet<>();
        for (int i = 0; i < maxNumbers; i++) {
            available.add(i);
        }
    }
    
    public int get() {
        if (available.isEmpty()) return -1;
        int num = available.iterator().next();
        available.remove(num);
        return num;
    }
    
    public boolean check(int number) {
        return available.contains(number);
    }
    
    public void release(int number) {
        if (number >= 0 && number < maxNumbers) {
            available.add(number);
        }
    }
}