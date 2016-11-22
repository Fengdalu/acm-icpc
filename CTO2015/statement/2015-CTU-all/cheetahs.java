import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.StringTokenizer;
 
/**
 * CTU Open 2015: Racing Cheetahs
 * @author Martin Kacer
 */
public class cheetahs {
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
		cheetahs instance = new cheetahs();
		while (instance.run()) {/*empty*/}
	}
 
	static class Cheetah implements Comparable<Cheetah> {
		final int start, speed;
		Cheetah(int start, int speed) { this.start = start; this.speed = speed; }
		public int compareTo(Cheetah other) { return this.start - other.start; }
	}
 
	static class Segment {
		final double tm; final Cheetah ch;
		Segment(double tm, Cheetah ch) { this.tm = tm; this.ch = ch; }
	}
 
	static final DecimalFormat DF = new DecimalFormat("0.000");
 
	int n, fcnt, lcnt;
	Cheetah[] cheetah;
	Segment[] first, last;
 
	boolean run() throws Exception {
		n = nextInt();
		if (n == 0) return false;
		cheetah = new Cheetah[n]; first = new Segment[n+1]; last = new Segment[n+1];
		for (int i = 0; i < n; ++i) cheetah[i] = new Cheetah(nextInt(), nextInt());
		Arrays.sort(cheetah);
		fcnt = lcnt = 0;
		cheetah: for (Cheetah now : cheetah) {
			for ( ; fcnt > 0; --fcnt) {
				Cheetah fst = first[fcnt-1].ch;
				if (fst.speed >= now.speed) continue cheetah;
				double cross = ((double)now.start*now.speed - (double)fst.start*fst.speed) / (now.speed - fst.speed);
				if (cross > first[fcnt-1].tm) {
					first[fcnt++] = new Segment(cross, now);
					break;
				}
			}
			if (fcnt == 0) first[fcnt++] = new Segment(now.start, now);
		}
		cheetah: for (int i = n; --i >= 0; ) {
			Cheetah now = cheetah[i];
			for ( ; lcnt > 0; --lcnt) {
				Cheetah lst = last[lcnt-1].ch;
				if (lst.speed <= now.speed) continue cheetah;
				double cross = ((double)lst.start*lst.speed - (double)now.start*now.speed) / (lst.speed - now.speed);
				if (cross > last[lcnt-1].tm) {
					last[lcnt++] = new Segment(cross, now);
					break;
				}
			}
			if (lcnt == 0) last[lcnt++] = new Segment(now.start, now);
		}
		first[fcnt] = last[lcnt] = new Segment(Double.POSITIVE_INFINITY, null);
		int li = 0, fi = 0;
		while (first[fi+1].tm < last[0].tm) ++fi;
		while (first[fi].ch.speed < last[li].ch.speed)
			if (first[fi+1].tm < last[li+1].tm) ++fi; else ++li;
		double time = Math.max(first[fi].tm, last[li].tm);
		System.out.println(DF.format((time - first[fi].ch.start) * first[fi].ch.speed - (time - last[li].ch.start) * last[li].ch.speed));
		return true;
	}
}
