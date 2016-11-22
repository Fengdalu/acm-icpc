import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
 
/**
 * CTU Open 2015: Lunch Budget
 * Version with 4 dishes and unbounded prices (limited only by integer capacity)
 * @author Martin Kacer
 */
public class lunch {
    StringTokenizer st = new StringTokenizer("");
    BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    boolean hasNextToken() throws Exception {
        while (!st.hasMoreTokens()) {
            String line = input.readLine();
            if (line == null) return false;
            st = new StringTokenizer(line);
        }
        return true;
    }
    String nextToken() throws Exception {
        return (!hasNextToken()) ? null : st.nextToken();
    }
    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }
    public static void main(String[] args) throws Exception {
        lunch instance = new lunch();
        while (instance.run()) {/*empty*/}
    }
 
    int[] cnt = new int[4];
    int[][] price = new int[4][];
    int[] comb2;
 
    /** Binary search. We cannot use the built-in method reliably, because we need the FIRST value in the array. */
    int bsearch(int[] values, int search) {
        int left = 0, right = values.length;
        while (left+1 < right) {
            int mid = (left+right)>>1;
            if (search > values[mid]) left = mid; else right = mid;
        }
        if (search > values[left]) ++left;
        return left;
    }
 
    boolean run() throws Exception {
        int budget = nextInt();
        for (int i = 0; i < 4; ++i)
            if ((cnt[i] = nextInt()) == 0) return false;
            else price[i] = new int[cnt[i]];
        for (int i = 0; i < 4; ++i) for (int j = 0; j < cnt[i]; ++j)
            price[i][j] = nextInt();
        comb2 = new int[cnt[0] * cnt[1]];
        for (int i = 0, k = 0; i < cnt[0]; ++i) for (int j = 0; j < cnt[1]; ++j)
            comb2[k++] = price[0][i] + price[1][j];
        Arrays.sort(comb2);
        long sum = 0;
        for (int i = 0; i < cnt[2]; ++i) for (int j = 0; j < cnt[3]; ++j)
            sum += bsearch(comb2, budget - price[2][i] - price[3][j] + 1);
        System.out.println(sum);
        return true;
    }
}
