import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static HashSet<String> f;
    public static String s;
    public static Scanner in = new Scanner(System.in);
    
    public static void main(String args[]) {
        int n, nc;
        while (in.hasNext()) {
            f = new HashSet<String>();
            n = in.nextInt();
            nc = in.nextInt();
            s = in.next();
            String tmp = "";
            for (int i = 0; i < n; i++)
                tmp += s.charAt(i);
            for (int i = n; i < s.length(); i++) {
                f.add(tmp);
                tmp = tmp.substring(1);
                tmp += s.charAt(i);
            }
            f.add(tmp);
            System.out.println(f.size());
        }
        System.out.flush();
    }
}