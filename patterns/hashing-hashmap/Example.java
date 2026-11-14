import java.util.*;

public class Example {
    public static Map<String, Integer> countFrequencies(String[] words) { Map<String, Integer> freq = new HashMap<>(); for (String word : words) freq.put(word, freq.getOrDefault(word, 0) + 1); return freq; }
    public static void main(String[] args) { System.out.println(countFrequencies(new String[]{"apple", "banana", "apple", "cherry"})); }
}
