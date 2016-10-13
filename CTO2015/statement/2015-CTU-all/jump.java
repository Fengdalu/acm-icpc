// Author Marko
 
// A solution with BIG time overhead
// 10^6 edges processes in about 3 - 4 sec.
// Very liberal, indeed. :-) 
 
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
 
public class jump {
 
// Solution is based on observation that edge (i, j) between stones i and j
// exists iff  (j-spots[j]) == (i+spots[i]),	 
// a multiset of values (j-spots[j]) and a multiset of values (i+spots[i]) 
// are considered, their intersection specifies the edges,
// the intersection can be found in time proprotional to its size. 
// Edge detection thus runs in Theta(|E|).
// Followed by standard BFS	which runs in Theta(|E|) as well
 
static int N, E;
static int [] dg; 
static int [][] g;	
static int [] spots;
 
 
static void addedge(int n1, int n2) {
	if (n1 == n2) return;
	if (dg[n1] >= g[n1].length) g[n1] = Arrays.copyOf(g[n1], 2*dg[n1]);
	if (dg[n2] >= g[n2].length) g[n2] = Arrays.copyOf(g[n2], 2*dg[n2]);
	g[n1][dg[n1]++] = n2;
	g[n2][dg[n2]++] = n1;		
	E++;
}
 
static void buildgraph() {
	g = new int [N][1];
	dg = new int [N];	
	int [] backref = new int [1]; // equal values of a multiset are in a list
	int [] noderef = new int [1];  
	int lastinref = -1;
	HashMap<Integer, Integer> j_multiSet = new HashMap(); 
	int i_vali, ref; 
 
	// build map with empty j-spots[j] value references
	for(int j = 0; j < N; j++) 
		j_multiSet.put(j-spots[j], -1);
 
	// add all (j-spots[j]) value references 
	for(int j = 0; j < N; j++) {
		ref = j_multiSet.get(j-spots[j]);
		if (lastinref + 1 == noderef.length) {
			noderef = Arrays.copyOf(noderef, noderef.length*2);
			backref = Arrays.copyOf(backref, backref.length*2);
		}
		noderef[++lastinref] = j;
		backref[lastinref] = ref;
		j_multiSet.put(j-spots[j], lastinref);
	}
 
	// add all edges, i.e. all pairs of nodes (i, j), where j-spots[j] == i+spots[i].  
	for(int i = 0; i < N; i++) {
	  i_vali = i + spots[i];  
		if (j_multiSet.containsKey(i_vali)) {
			ref = j_multiSet.get(i_vali);
			while(ref != -1) {
				addedge(i, noderef[ref]);
				ref = backref[ref];				
			}
		}
	} // for all edges
}
 
static int BFS (int currn) {
	int [] q = new int [N];
	int [] d = new int [N]; // 
	boolean [] marked = new boolean [N]; 
	int head = 0, tail = -1,  neigh, rightmost = 0, maxd = 0;
 
	q[++tail] = currn; 
	d[currn] = 0;
	marked[currn] = true;  
 
	while (head <= tail) { 
		currn = q[head++];
       if (rightmost <= currn) maxd = Math.max(maxd, d[currn]); 
		rightmost = Math.max(currn,rightmost);  
		for(int j = 0; j < dg[currn]; j++) {
			neigh = g[currn][j];
			if (!marked[neigh]) 
			  { marked[neigh] = true; q[++tail] = neigh; d[neigh] = d[currn] +1;}
		}
	}
	return rightmost;
}
 
// ***************************************************************************
//                            M A I N
// ***************************************************************************
 
public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	while (true) {
		if (!readInput(br)) break;	
		buildgraph();
		System.out.printf("%d\n", BFS(0));
	}
}
 
static boolean readInput(BufferedReader br) throws IOException  {
	StringTokenizer st = new StringTokenizer(br.readLine());
	N = Integer.valueOf(st.nextToken());
	if (N == 0) return false;
	spots = new int [N];	
 
	st = new StringTokenizer(br.readLine()); 
	for(int i = 0; i < N; i++) 
		spots[i] = Integer.valueOf(st.nextToken());
 
	return true;			
}
 
}
