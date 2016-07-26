import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * Created by dalufeng on 16/7/26.
 */
public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


    public void run() throws Exception{
        String s;
        while((s = br.readLine()) != null) {
            if(s.length() > 10) {
                bw.write("TAT\r\n");
                bw.flush();
                continue;
            }
            long t = Long.parseLong(s);
            boolean flag = false;
            int i;
            for(i = 0; i < 5; i++) {
                t = (long)Math.sqrt(t);
                if(t == 1) { flag = true; break; }
            }
            if(flag) {
                bw.write(String.format("%d\r\n", i + 1));
            }
            else bw.write("TAT\r\n");
            bw.flush();
        }
    }

    public static void main(String args[]) throws Exception{
        new Main().run();
    }
}
