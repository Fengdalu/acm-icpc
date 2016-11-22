import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    public static HashMap<String, String> dic = new HashMap<String, String>();
    public static ArrayList<String> s = new ArrayList<String>();
    public static ArrayList<String> ans = new ArrayList<String>();

    public static void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(new File(
                "i18n.in")));
        PrintStream out = new PrintStream(new File("i18n.out"));
        dic.clear();
        s.clear();
        ans.clear();
        String t;
        while ((t = in.readLine()) != null) {
            s.add(t);
        }
        for (String ss : s) {
            String word = "";
            String key = "";
            String ff = "";
            for (int i = 0; i < ss.length() + 1; i++) {
                if (i == ss.length() || ss.charAt(i) == '-'
                        || ss.charAt(i) == ',' || ss.charAt(i) == '.'
                        || ss.charAt(i) == '(' || ss.charAt(i) == ')'
                        || ss.charAt(i) == ':' || ss.charAt(i) == ';'
                        || ss.charAt(i) == '!' || ss.charAt(i) == '?'
                        || ss.charAt(i) == '"' || ss.charAt(i) == ' ') {
                    String rep = dic.get(word);
                    if (rep == null) {
                        ff += word;
                        if (word.length() < 4) {
                            word = "";
                            if (i != ss.length())
                                ff += ss.charAt(i);
                            continue;
                        }
                        boolean flg = false;
                        for (int j = 0; j < word.length(); j++) {
                            if ('0' <= word.charAt(j) && word.charAt(j) <= '9')
                                flg = true;

                        }
                        if (flg) {
                            word = "";
                            if (i != ss.length())
                                ff += ss.charAt(i);
                            continue;
                        }
                        word = word.toLowerCase();
                        Integer len = new Integer(word.length() - 2);
                        key = word.charAt(0) + len.toString()
                                + word.charAt(word.length() - 1);
                        if (dic.containsKey(key) && !dic.get(key).equals(word)) {
                            dic.remove(key);
                            dic.put(key, key);
                        } else
                            dic.put(key, word);

                        word = word.toUpperCase();
                        key = word.charAt(0) + len.toString()
                                + word.charAt(word.length() - 1);
                        if (dic.containsKey(key) && !dic.get(key).equals(word)) {
                            dic.remove(key);
                            dic.put(key, key);
                        } else
                            dic.put(key, word);
                        word = word.toLowerCase();
                        word = word.toUpperCase().charAt(0) + word.substring(1);
                        key = word.charAt(0) + len.toString()
                                + word.charAt(word.length() - 1);
                        if (dic.containsKey(key) && !dic.get(key).equals(word)) {
                            dic.remove(key);
                            dic.put(key, key);
                        } else
                            dic.put(key, word);
                        word = "";
                    } else
                        ff += rep;
                    if (i != ss.length())
                        ff += ss.charAt(i);
                    word = "";
                } else {
                    word = word + ss.charAt(i);
                }
            }
            // System.out.println(ff);
            ans.add(ff);
            ff = "";
            word = "";
            key = "";
        }
        for (String ss : ans) {
            out.println(ss);
        }
        out.flush();
    }
}