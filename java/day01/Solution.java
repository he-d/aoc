import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        String inputFile = "src/input.txt";
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(inputFile))) {
            String line = "";
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                list1.add(Integer.parseInt(parts[0]));
                list2.add(Integer.parseInt(parts[1]));
            }
        } catch (IOException e) {
            System.err.println("Error reading file" + e.getMessage());
        }
        Collections.sort(list1);
        Collections.sort(list2);

        int totalDistance = 0;
        for (int i = 0; i < list1.size(); ++i) {
            totalDistance += Math.abs(list1.get(i) - list2.get(i));
        }

        System.out.println("Total distance: " + totalDistance);
    }
}

