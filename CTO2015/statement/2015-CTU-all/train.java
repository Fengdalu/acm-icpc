// Author Marko

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// ------------ BASIC GEOMETRY TYPES ------------------------------------------

// all vectors consistently point from their pt1 to pt2
// all vectors are supposed to be of nonzero length
// all cones are strictly convex, non degenerate,
// with  vertex p0, angle(p1, p0, p2) < 180,

class Point { long x, y; }
class DPoint { double x, y; }
class Segment { Point pt1, pt2; }
class Rect {Point [] p; } // 4 points

// shade may be a cone with the tip cut away => two vertices p01 and p02
// or a simple cone, then values p01 == p02.
class Shade { long vertices; Point p01, p02, p1, p2; }

// Shade boudaries intersections with the trail, also to be sorted
class Isc implements Comparable<Isc> { double dist; boolean shadestart;
		public Isc(double x, boolean y) {dist = x; shadestart = y; }
		@Override
		public int compareTo(Isc o2) {
			if (this.dist < o2.dist) return -1; else if (this.dist > o2.dist) return 1;
			return 0;
		}
}
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

public class train {

	static int N;
	static Rect rects []; // all rectangles
  static Segment trail;

	static long INSIDE = 1, BOUNDARY = 0, OUTSIDE = -1, BACKWARD = 2;
	static long LEFT = 1, RIGHT = -1, AHEAD = 0, PARALLEL = 0;
	// types of segment shade intersection
	static long segShaINSIDE = -1,
					    segShaP1_IN = 1, segShaP2_IN = 2, segShaP12_OUT = 3, segShaEMPTY = 4;


// ------------------ CREATE THE SHADE OF A BUILDING ---------------------

static void cpyPt(Point p1, Point p2) { p2.x=p1.x; p2.y=p1.y; }
static Point sp01 = new Point(), sp02 = new Point(); // prospective shade vertices
static Point sp1 = new Point(), sp2 = new Point();   // prospective shade ray points
static Point Ap0 = new Point(), Ap = new Point();    // current ray; Ap0 is rectangle vertex,
						                                         // Ap is mirror of source vertex wrt Ap0, so we have
		                                                 // a ray pointing in correct direction

	static void buildShade (Rect source, Rect rec, Shade sha) {
		long vectvectpos;
		// start with one ray (= 0-thin seed cone and thicken) it eventually
		// by  considering all other 15  rays, it will produce ray1 and ray2
		// delimiting the shade

		cpyPt(rec.p[0], sp01); cpyPt(sp01, sp02);
		sp1.x = 2*sp01.x-source.p[0].x;  sp1.y = 2*sp01.y-source.p[0].y;
		cpyPt(sp1, sp2);

		// i goes through source corners, j through rectangle corners
		for(int i = 0; i < 4; i++)	for(int j = 0; j < 4; j++) { // nested loops!
			// create current ray:
			cpyPt(rec.p[j], Ap0);
			Ap.x = 2*Ap0.x-source.p[i].x; Ap.y = 2*Ap0.y-source.p[i].y;

			// compare and update ray1 and ray2
			vectvectpos =  vectVectPosition(sp01, sp1, Ap0, Ap);
			if (vectvectpos == RIGHT) {cpyPt(Ap0, sp01); cpyPt(Ap, sp1);}
			vectvectpos =  vectVectPosition(sp02, sp2, Ap0, Ap);
			if (vectvectpos == LEFT) {cpyPt(Ap0, sp02); cpyPt(Ap, sp2);}

		} // ray1 and ray2 fertig

		sha.vertices = 2;
		if (sp01.x == sp02.x && sp01.y == sp02.y) sha.vertices = 1;
		cpyPt(sp01, sha.p01); cpyPt(sp02, sha.p02);
		cpyPt(sp1, sha.p1); cpyPt(sp2, sha.p2);
	}

// ----------  INTERSECT ALL SHADES BOUNDARIES WITH THE TRACK --------------
// --------------------AND SORT THE INTERSECTIONS --------------------------

static double collectIntersections() {
	Isc [] iscs = new Isc[2*N+2]; // intersections
	int noiscs = 0;
	// at most two intersection points of a shade with the trail
	DPoint ipt1 = new DPoint(), ipt2 = new DPoint();
	Shade shade = new Shade(); shade.p01 = new Point(); shade.p02 = new Point();
	                  shade.p1 = new Point(); shade.p2 = new Point();
	long isctype;
	double traillen = dist(trail.pt1, trail.pt2);
	double distipt1, distipt2;

	// check all shades and register intersections with the segment;
	for(int i_rect = 1; i_rect < N; i_rect++) {
		buildShade(rects[0], rects[i_rect], shade);

		isctype = ShadeSegmentIntersection(shade, trail, ipt1, ipt2);

		if (isctype == segShaEMPTY) continue; // trail completely outside shade

		if (isctype == segShaINSIDE) { // trail completely inside shade
			iscs[noiscs++] = new Isc(0, true);
			iscs[noiscs++] = new Isc(traillen+1.0, false);
		}

		if (isctype == segShaP1_IN) { // start in the shade, end out of shade
			iscs[noiscs++] = new Isc(0, true);
			iscs[noiscs++] = new Isc(dist(ipt1, trail.pt1), false);
		}

		if (isctype == segShaP2_IN) { // end in the shade, start out of shade
			iscs[noiscs++] = new Isc(dist(ipt1, trail.pt1), true);
			iscs[noiscs++] = new Isc(traillen, false);
		}

		if (isctype == segShaP12_OUT) { // start out of shade, end out of shade
			distipt1 = dist(ipt1, trail.pt1);
			distipt2 = dist(ipt2, trail.pt1);
      if (distipt1 < distipt2)	{
				iscs[noiscs++] = new Isc(distipt1, true);
				iscs[noiscs++] = new Isc(distipt2, false);
			}
			else {
				iscs[noiscs++] = new Isc(distipt2, true);
				iscs[noiscs++] = new Isc(distipt1, false);
			}
		}
	}// for all shades

	// dummy iscs at the beg and end
	iscs[noiscs++] = new Isc(0.0, true);
	iscs[noiscs++] = new Isc(0.0, false);
	iscs[noiscs++] = new Isc(traillen, true);
	iscs[noiscs++] = new Isc(traillen, false);

	Arrays.sort(iscs, 0, noiscs);

	// sort the intersections and  total the un-shaded subsegments
	double totlen = 0, lastlen = 0;
	long shadecount = 0;
	for(int i = 0; i < noiscs; i++) {
		if (iscs[i].shadestart) {
			if (shadecount == 0) totlen += iscs[i].dist-lastlen;
			shadecount++;
		}
		else { // shade end
			if (shadecount == 1) lastlen = iscs[i].dist;
			shadecount--;
		}
	} // all non-shades added

	return totlen;

}

// ************************************************************************
//     O                                                              O
//   O O O                        M A I N                           O O O
//     O                                                              O
// ************************************************************************

public static void main(String[] args) throws IOException {
	runall();
}

static void allocate(int n) {
	rects = new Rect[n];
	for(int i = 0; i < n; i++) {
		rects[i] = new Rect(); rects[i].p = new Point[4];
		for(int j = 0; j < 4; j++) rects[i].p[j] = new Point();
	}
	trail = new Segment(); trail.pt1 = new Point(); trail.pt2 = new Point();
}

static void runall() throws IOException  {
  double totlen;
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	while(true) {
		// read input
		N = Integer.valueOf(br.readLine().trim());
	  if (N == 0) break;
		allocate(N);
		sgtosegm(br.readLine(), trail);
		for(int i = 0; i < N; i++)
			sgtorec(br.readLine(), rects[i]);
		// compute
		//br.readLine(); // if empty line exists
		totlen = collectIntersections();
		System.out.printf("%.6f\n", totlen);
	}
}

static void sgtorec(String s, Rect rec) {
	StringTokenizer st = new StringTokenizer(s);
		for(int j = 0; j < 4; j++) {
			rec.p[j].x = Integer.valueOf(st.nextToken());
			rec.p[j].y = Integer.valueOf(st.nextToken());
	}
}

static void sgtosegm(String s, Segment seg) {
	StringTokenizer st = new StringTokenizer(s);
	seg.pt1.x = Integer.valueOf(st.nextToken());
	seg.pt1.y = Integer.valueOf(st.nextToken());
	seg.pt2.x = Integer.valueOf(st.nextToken());
	seg.pt2.y = Integer.valueOf(st.nextToken());
}

// --------------------------------------------------------------------------
//               G E O M E T R Y     P A R A P H E R N A L I A
// --------------------------------------------------------------------------

	static long sqr(long x) {return x*x;}
	static double sqr(double x) {return x*x;}
	static double abs(double x) {return Math.abs(x); }
	static double sqrt(long x) {return Math.sqrt(x); }
	static double sqrt(double x) {return Math.sqrt(x); }
	static double dist(DPoint A, Point B) {return sqrt(sqr (A.x-B.x) + sqr(A.y-B.y)); }
	static double dist(Point A, Point B) {return sqrt(sqr (A.x-B.x) + sqr(A.y-B.y)); }
	static long sign(long x) {if (x<0) return -1; if (x>0) return 1; return 0; }

	static long dotprd (Point v1p1, Point v1p2, Point v2p1, Point v2p2) {
		return (v1p2.x-v1p1.x)*(v2p2.x-v2p1.x) + (v1p2.y-v1p1.y)*(v2p2.y-v2p1.y);}

	static long normSquared (Point p1, Point p2) {
		return sqr(p2.x-p1.x) + sqr(p2.y-p1.y); }

	static boolean parallel(Point a, Point b, Point c, Point d) {
		return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x) == 0; }

// ----------------- OBJECTS MUTUAL POSITIONS -------------------------

	// (p3->4 positon wrt p1->p2)
	static long vectVectPosition(Point p1, Point p2, Point p3, Point p4) {
		long det = (p2.x-p1.x)*(p4.y-p3.y) - (p2.y-p1.y)*(p4.x-p3.x);
		if (det == 0) return PARALLEL;
		if (det < 0) return RIGHT;
		if (det > 0) return LEFT;
	  return 0;	// foo
	}

	static long pointRayPosition(Point p1, Point p2, Point pt) {
		if (p1.x == pt.x && p1.y == pt.y) return 0;
	// determinant of the parallelogram
	  long pos = sign((p2.x-p1.x)*(pt.y-p1.y)-(p2.y-p1.y)*(pt.x-p1.x));
	  if (pos == 1) return LEFT;
		if (pos == -1) return RIGHT;
		if (sign(dotprd(p1, p2, p1, pt)) == -1) return BACKWARD;
		return AHEAD;
	}

	static long PointConePosition(Point p0, Point p1, Point p2 , Point p) {
		long  pVersusr1 = pointRayPosition(p0, p1, p);
		long  pVersusr2 = pointRayPosition(p0, p2, p);
		if (pVersusr1 == BOUNDARY || pVersusr2 == BOUNDARY) return BOUNDARY;
		if (pVersusr1 == LEFT && pVersusr2 == RIGHT) return INSIDE;
		return OUTSIDE;   // suposing no point exists between shade 2 vertices
	}

	static long PointShadePosition (Shade shade, Point pt) {

		// point may be on the boundary
		if (    pointRayPosition(shade.p01, shade.p1, pt) == AHEAD
		     || pointRayPosition(shade.p02, shade.p2, pt) == AHEAD)
			   // suposing no point exists between shade 2 vertices
			return BOUNDARY;

    // shade made of single cone
		if (shade.vertices == 1)
			return PointConePosition(shade.p01, shade.p1, shade.p2, pt);

  	// shade made of two cones => consider cones intersection
	  if (   PointConePosition(shade.p01, shade.p1, shade.p02, pt) == INSIDE
				&& PointConePosition(shade.p02, shade.p01, shade.p2, pt) == INSIDE)
			return INSIDE;

		return OUTSIDE;
	}

	static boolean isSegmentInsideRay (Point p1, Point p2, Segment s) {
		return    pointRayPosition(p1, p2, s.pt1) == AHEAD
					&& 	pointRayPosition(p1, p2, s.pt2) == AHEAD;
	}

// ---------------- INTERSECTIONS --------------------------------------------

	// returns the type of intersections and the intersection themselves
	static long ShadeSegmentIntersection
					(Shade shade, Segment seg, DPoint ipt1, DPoint ipt2) {

		// the whole segment might be part of shade boundary
		// fortunately, not just partial.
		if (    isSegmentInsideRay(shade.p01, shade.p1, seg)
				 || isSegmentInsideRay(shade.p02, shade.p2, seg)	)
			return segShaEMPTY; // the assignment demands this

		// find relative positons of the segment ends
		long isec_segpt1_sha = PointShadePosition(shade, seg.pt1) ;
		long isec_segpt2_sha = PointShadePosition(shade, seg.pt2) ;

		// is the segment completely inside?
		if ((isec_segpt1_sha == BOUNDARY || isec_segpt1_sha == INSIDE) &&
				(isec_segpt2_sha == BOUNDARY || isec_segpt2_sha == INSIDE))
			return segShaINSIDE; // segment completely shaded => trivial 0 solution

	 // now the segment is not completely inside the shade, nor on the boundary
   boolean i_Sha1SegExists = raySegIntersection(shade.p01, shade.p1, seg, ipt1);
   boolean i_Sha2SegExists = raySegIntersection(shade.p02, shade.p2, seg, ipt2);

	 // completely outside?
	 if (!i_Sha1SegExists && !i_Sha2SegExists) return segShaEMPTY;

	 // two intersections
	 if (i_Sha1SegExists && i_Sha2SegExists) return segShaP12_OUT;

	 // one intersection with ray 1 of the shade
	 if (i_Sha2SegExists) { ipt1.x = ipt2.x; ipt1.y = ipt2.y; } // move result to 1
	 if (isec_segpt1_sha == BOUNDARY || isec_segpt1_sha == INSIDE)
		return segShaP1_IN;

	return segShaP2_IN;
	} // intersection(s) segment -- shade;

// ---------------------------------------------------------------------------
	// supposing segment not part of the ray
	static boolean raySegIntersection(Point p1, Point p2, Segment seg, DPoint dp) {
	  if (parallel(p1, p2, seg.pt1, seg.pt2)) return false;

		// one point of the segment on the ray ?
		long  possegpt1 = pointRayPosition(p1, p2, seg.pt1);
		long  possegpt2 = pointRayPosition(p1, p2, seg.pt2);
		if (possegpt1 == AHEAD) { dp.x = seg.pt1.x; dp.y = seg.pt1.y; return true;}
		if (possegpt2 == AHEAD) { dp.x = seg.pt2.x; dp.y = seg.pt2.y; return true;}

		//  segment whole on one side of the ray
		if ((possegpt1==LEFT && possegpt2==LEFT) || (possegpt1==RIGHT && possegpt2==RIGHT))
			return false;

		// calculate lines intersection they should exist now
		return raySegIntersCoords(p1, p2, seg.pt1, seg.pt2, dp);
	}

	// ---------------------------------------------------------------------------

	// supposes intersection exists
	static boolean raySegIntersCoords(Point A, Point B, Point C, Point D, DPoint P) {
		// A->B is the ray
		double eps = 0.00001;
		long det   = (B.x-A.x)*(C.y-D.y)- (B.y-A.y)*(C.x-D.x);
		long detAB = (C.x-A.x)*(C.y-D.y)- (C.y-A.y)*(C.x-D.x);
		long detCD = (B.x-A.x)*(C.y-A.y)- (B.y-A.y)*(C.x-A.x);

		P.x = A.x + (B.x-A.x) * (double)(detAB)/det;
		P.y = A.y + (B.y-A.y) * (double)(detAB)/det;
		if (detAB * det < 0) return false; // intersection should not be before A
		if (detCD * det < 0) return false; // intersection should not be before C
		if ((double)detCD / det > 1) return false; // intersection should not be past  D

		return true;
	}

}
