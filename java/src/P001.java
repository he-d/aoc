import java.io.BufferedReader;
import java.io.FileReader;
import java.util.LinkedList;
import java.util.List;

public class P001 {

    public static void main(String[] args) {
        int result = 0;
        String inputFilePath = "./001.txt";
        List<String> inputs = GetInputStrings(inputFilePath);

        for (String str : inputs) {
            result += GetCalibrationValue(str);
        }

        System.out.println(result);
    }


    private static int GetCalibrationValue(String str) {
        int result = 0;
        if (str.isEmpty()) {
            return result;
        }
        result = GetFirstCalibrationValue(str) * 10;
        result += GetSecondCalibrationValue(str);

        return result;
    }

    private static int GetFirstCalibrationValue(String str) {
        int result = 0;
        char[] chars = str.toCharArray();
        for (char aChar : chars) {
            if (Character.isDigit(aChar)) {
                result = Character.getNumericValue(aChar);
                break;
            }
        }

        return result;
    }

    private static int GetSecondCalibrationValue(String str) {
        int result = 0;
        char[] chars = str.toCharArray();
        for (int i = str.length() - 1; i >= 0; --i) {
            if (Character.isDigit(chars[i])) {
                result = Character.getNumericValue(chars[i]);
                break;
            }
        }
        return result;
    }

    private static List<String> GetInputStrings(String filePath) {
        List<String> results = new LinkedList<>();
        try {
            BufferedReader br = new BufferedReader(new FileReader(filePath));
            String str;

            while ((str = br.readLine()) != null) {
                results.add(str);
            }
        } catch (Exception ex) {
            return results;
        }
        return results;
    }
}
