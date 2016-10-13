// Author Marko
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class fox {
 
static int N;
 
// strategy: 
// -- scan the number from right to left
// -- find the first place j where the change starts
// -- update the string from j back to the right
 
// confusing fact: 
// indices of strings are in reverse order relative to the order of digits
 
 
static String solves (String s) {
	// process negative input, which reduces to  
	// closest bigger num with bigger sum for positive numbers
	char [] sol = new char [s.length()+3];
 
	int sollen = 0;
 
	// if exactly  "-9999...9
	if (s.charAt(0) == '-') {
		int j = s.length()-1;
		while(j > 0 && s.charAt(j) == '9') j--;
 
		sol[sollen++] = '-';
 
		// if exactly  "-9999...9
		if (j == 0) {	
			sol[sollen++] = '1';
			for(int i = 1; i < s.length(); i++) 
				sol[sollen++] = '9'; 
 
			return String.valueOf(sol, 0, sollen);
		}
 
		// if not exactly "-9999...9
		for(int i = 1; i < j; i++) sol[sollen++] = s.charAt(i); 
		// increase first non-'9'
		sol[sollen++] =  (char)((int)s.charAt(j)+1);
		j++;
		// fill rest with 9
		while(j < s.length()) // fill rest with 9
			{ sol[sollen++] = '9'; j++; }
		return String.valueOf(sol, 0, sollen);
	}
 
	// process positive input or 0 
 
	int j,              // scans the string
	    backlen,        // just for convenience, j+backlen = string.length-1
	    backsum;        // sum of all digits *behind* j
 
	j = s.length()-2; // j points to the rightmost candidate for change
	backlen = 1;
	backsum = (int)s.charAt(j+1)-48; 
 
	// find the leftmost candidate for change
	while(j >= 0  &&   backsum+2 > backlen*9 ){
	backlen++; backsum += (int)s.charAt(j)-48; j--;		
	} 
 
	while(j >= 0  &&   s.charAt(j) == '0' )  j--; 
 
	// the leftmost candidate for change exists  
	if (j >= 0) {  
		for(int i = 0; i < j; i++) sol[sollen++] = s.charAt(i); 
 
		// if number of digits is NOT to be reduced
		if (!(j == 0 && s.charAt(0) == '1'))   
   		sol[sollen++] = (char)((int)s.charAt(j)-1);
 
	// update the string from j back to the right
		j++; 
		backsum += 2;
		int printdigit;		
		while (backsum > 0) {
			printdigit = Math.min(backsum, 9);
			sol[sollen++] = (char)(printdigit+48);
			backsum -= printdigit;
			j++;		
		}	
		while (j < s.length()){ sol[sollen++] = '0'; j++; } 
		return String.valueOf(sol, 0, sollen);
	}
 
	// the leftmost candidate for change does not exist, switch to negative values
	sol[sollen++] = '-';
	backsum++;
		// if output is not "-9...9"  
	if (backsum%9 != 0) {
		sol[sollen++] = (char)((backsum%9) + 48);
		backsum -= backsum%9;
	}
	for(int i = 0; i < backsum / 9; i++)	
		sol[sollen++] = '9';
	return String.valueOf(sol, 0, sollen);	
}	
 
// ***************************************************************************
//                              M A I N
// ***************************************************************************
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String Nstring = br.readLine();
 
		while (!Nstring.equals("END")) {
			System.out.printf("%s\n",solves(Nstring));
			Nstring = br.readLine();
		}
	}
 
}
