import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Main {

  boolean checkLeft(char root, char b) {
    if(root == '*' || root == '/') {
      if(b == '+' || b == '-') return false;
    }
    return true;
  }

  boolean checkRight(char root, char b) {
    if(root == '*' || root == '/') if(b == '+' || b == '-') return false;
    if(root == '-' && (b == '+' || b == '-')) return false;
    if(root == '/') return false;
    return true;
  }

  class Tree {
    public String op;
    public Tree left, right;
    boolean expand;

    public Tree() {
      left = null;
      right = null;
      expand = false;
    }

    boolean isleaf() {
      return (left == null && right == null);
    }
  }

  boolean dfs(String s, Tree tree, HashMap<String, String>dict)  {
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
        if(!dfs(s.substring(1, s.length() - 1), tree, dict)) return false;
        tree.expand = false;
        return true;
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
        if(!dfs(s.substring(0, i), tree.left, dict)) return false;
        if(!dfs(s.substring(i + 1), tree.right, dict)) return false;
        break;
      }
    }
    if(tree.isleaf()) {
      for (int i = s.length() - 1; i > -1; i--) {
        if (s.charAt(i) == '(') cover++;
        else if (s.charAt(i) == ')') cover--;
        else if (cover == 0 && (s.charAt(i) == '*' || s.charAt(i) == '/')) {
          tree.left = new Tree();
          tree.right = new Tree();
          tree.op = s.substring(i, i + 1);
          if(!dfs(s.substring(0, i), tree.left, dict)) return false;
          if(!dfs(s.substring(i + 1), tree.right, dict)) return false;
          break;
        }
      }
    }
    if(tree.isleaf()) {
      String key = s, value = dict.get(key);
      if(value != null) {
        tree.expand = true;
        dict.remove(key);
        boolean result;
        if(preAns.get(key) != null) {
          result = preAns.get(key);
          Tree tmp = preTree.get(key);
          tree.op = tmp.op;
          tree.expand = tmp.expand;
          tree.left = tmp.left;
          tree.right = tmp.right;
        }
        else {
          result = dfs(value, tree, dict);
          preAns.put(key, result);
          preTree.put(key, tree);
        }
        if(!result) {
          dict.put(key, value);
          return false;
        }
        dict.put(key, value);
        return true;
      }
      else {
        tree.expand = false;
        tree.op = key;
        return true;
      }
    }
    boolean flag = true;
    if(tree.left.expand) flag &= checkLeft(tree.op.charAt(0), tree.left.op.charAt(0));
    if(tree.right.expand) flag &= checkRight(tree.op.charAt(0), tree.right.op.charAt(0));
    return flag;
  }

  public static void main(String[] args){
    new Main().run();
  }

  HashMap<String, Boolean> preAns = new HashMap<String, Boolean>();
  HashMap<String, Tree> preTree = new HashMap<String, Tree>();

  public void run() {
    InputReader reader = new InputReader(System.in);
    PrintWriter writer = new PrintWriter(System.out);
    try {
      int n; n = Integer.parseInt(reader.nextLine());
      HashMap<String, String>dict = new HashMap<String, String>();
      String[] keys = new String[n], values = new String[n];
      for(int i = 0; i < n; i++) {
        String line = reader.nextLine();
        line = line.substring(line.indexOf("define") + 6).trim();
        int token = line.indexOf(' ');
        dict.put(line.substring(0, token).replace(" ", "").trim(), line.substring(token + 1).replace(" ", "").trim());
        keys[i] = line.substring(0, token).replace(" ", "").trim();
        values[i] = line.substring(token + 1).replace(" ", "").trim();
      }

      for(int i = 0; i < n; i++) {
        dict.remove(keys[i]);
        Tree tree = new Tree();
        tree.expand = true;
        preAns.put(keys[i], dfs(values[i], tree, dict));
        preTree.put(keys[i], tree);
        dict.put(keys[i], values[i]);
      }

      String expr = reader.nextLine().replace(" ", "");

      expr = expr.replace(" ", "").trim();
      Tree tree = new Tree();
      if(dfs(expr, tree, dict)) writer.write("OK\n");
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
  }
}
