import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class Main {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    BigInteger n;
    int k;

    BigInteger query(BigInteger L,BigInteger R)
    {
        if(L.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
            return R.subtract(L).add(BigInteger.ONE).divide(BigInteger.valueOf(2));
        else
            return R.subtract(L).add(BigInteger.valueOf(2)).divide(BigInteger.valueOf(2));
    }
    public void run() throws IOException {
        int T;
        T = Integer.parseInt(br.readLine());
        while (T > 0) {
            T--;
            String line = br.readLine().trim();
            String args[] = line.split(" ");
            n = new BigInteger(args[0]);
            k = Integer.parseInt(args[1]);
            
            int pos=1;
            BigInteger ans=BigInteger.ZERO;
            n=n.multiply(BigInteger.valueOf(2));
            BigInteger val=BigInteger.valueOf(1<<k);
            while(!n.equals(BigInteger.ZERO))
            {
                n=n.divide(val);
                ans=ans.add(query(BigInteger.ONE,n));
            }
            bw.write(ans.toString() + "\r" + "\n");
            bw.flush();
        }
    }
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 