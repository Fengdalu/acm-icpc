import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Main {

  boolean checkLeft(char root, char b) {
    if(root == '/') {
      if(b == '+' || b == '-') return true;
    }
    if(root == '*') {
      if(b == '+' || b == '-') return true;
    }
    return false;
  }

  boolean checkRight(char root, char b) {
    if(root == '-') {
      if(b == '+' || b == '-') return true;
    }
    if (root == '*') {
      if (b == '+' || b == '-') return true;
    }
    if (root == '/') {
      return true;
    }
    return false;
  }



  class Tree {
    public String op;
    public Tree left, right;

    public Tree() {
      left = null;
      right = null;
    }

    boolean isleaf() {
      return (left == null && right == null);
    }
  }

  class KV implements Comparable{
    public String key, value;

    public KV(String key, String value) {
      this.key = key;
      this.value = value;
    }
    @Override
    public int compareTo(Object o) {
      return -1 * (new Integer(this.key.length())).compareTo(((KV)(o)).key.length());
    }
  }

  void build(String s, Tree tree)  {
    if(s.charAt(0) == '(' && s.charAt(s.length() - 1) == ')') {
      int cover = 0;
      boolean all = true;
      for(int i = s.length() - 1; i > 0; i--) {
        if(s.charAt(i) == '(') cover++;
        else if(s.charAt(i) == ')') cover--;
        else if(cover == 0) {
          all = false;
          break;
        }
      }
      if(all) {
        build(s.substring(1, s.length() - 1), tree);
        return;
      }
    }
    int cover = 0;
    for(int i = s.length() - 1; i >= 0; i--) {
      if(s.charAt(i) == '(') cover++;
      else if(s.charAt(i) == ')') cover--;
      else if(cover == 0 && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
        tree.left = new Tree();
        tree.right = new Tree();
        tree.op = s.substring(i, i + 1);
        build(s.substring(0, i), tree.left);
        build(s.substring(i + 1), tree.right);
        return ;
      }
    }
    for(int i = s.length() - 1; i > -1; i--) {
      if(s.charAt(i) == '(') cover++;
      else if(s.charAt(i) == ')') cover--;
      else if(cover == 0 && (s.charAt(i) == '*' || s.charAt(i) == '/')) {
        tree.left = new Tree();
        tree.right = new Tree();
        tree.op = s.substring(i, i + 1);
        build(s.substring(0, i), tree.left);
        build(s.substring(i + 1), tree.right);
        return ;
      }
    }
    tree.op = s;
  }

  String getExp(Tree tree) {
    if(tree.isleaf()) {
      return tree.op;
    }
    String left = getExp(tree.left), right = getExp(tree.right);
    if(tree.left.isleaf() && tree.right.isleaf()) {
      return left + tree.op + right;
    }
    if(!tree.left.isleaf() && checkLeft(tree.op.charAt(0), tree.left.op.charAt(0)))
      left = "(" + left + ")";
    if(!tree.right.isleaf() && checkRight(tree.op.charAt(0), tree.right.op.charAt(0)))
      right = "(" + right + ")";
    return left + tree.op + right;
  }

  String process(String a, KV[] dict, boolean mode) {
    int pre = 0;
    ArrayList<String> ele = new ArrayList<String>();
    for(int i = 0; i < a.length(); i++) {
      int ch = a.charAt(i);
      if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
        if(i > pre) ele.add(a.substring(pre, i));
        ele.add(a.substring(i, i + 1));
        pre = i + 1;
      }
    }
    if(pre < a.length()) {
      ele.add(a.substring(pre));
    }
    String ans = "";
    for(String e : ele) {
        for(KV kv : dict) {
         if(e.compareTo(kv.key) == 0)  {
           if(mode) e = "(" + process(kv.value, dict, mode) + ")";
           else e = process(kv.value, dict, mode);
           break;
         }
      }
      ans = ans + e;
    }
    return ans;
  }

  public static void main(String[] args){
    new Main().run();
  }

  public void run() {
    InputReader reader = new InputReader(System.in);
    PrintWriter writer = new PrintWriter(System.out);
    try {
      int n; n = Integer.parseInt(reader.nextLine());
      KV[] dict = new KV[n];
      for(int i = 0; i < n; i++) {
        String line = reader.nextLine();
        line = line.substring(line.indexOf("define") + 6).trim();
        int token = line.indexOf(' ');
        dict[i] = new KV(line.substring(0, token).replace(" ", ""), line.substring(token + 1).replace(" ", ""));
      }
      Arrays.sort(dict);
      String expr = reader.nextLine().replace(" ", "");
      String expr2 = expr;

      expr = process(expr, dict, false);
      expr2 = process(expr2, dict, true);

      expr = expr.replace(" ", "");
      expr2 = expr2.replace(" ", "");
      Tree tree1 = new Tree(), tree2 = new Tree();
      build(expr, tree1);
      build(expr2, tree2);
      if(getExp(tree1).compareTo(getExp(tree2)) == 0) {
        writer.write("OK\n");
      }
      else writer.write("Suspicious\n");
    } catch (Exception e) {
    } finally {
      writer.close();
    }
  }

  class InputReader {
    InputReader(InputStream in) {
      this.reader    = new BufferedReader(new InputStreamReader(in));
      this.tokenizer = new StringTokenizer("");
    }

    public String nextLine() throws IOException {
      return reader.readLine();
    }

    public String nextToken() throws IOException {
      while (!tokenizer.hasMoreTokens()) {
        tokenizer = new StringTokenizer(reader.readLine());
      }
      return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
      return Integer.parseInt(nextToken());
    }

    private BufferedReader  reader;
    private StringTokenizer tokenizer;
  }

  private void debug(Object...o) {
    System.err.println(Arrays.deepToString(o));
  }
}
