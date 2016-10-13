/*
Author: Mimino
Solution: O(N)
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Vector {
    int x, y;
    Vector(int _x=0, int _y=0): x(_x), y(_y) { }
    Vector operator-(const Vector & v) const { return Vector(x-v.x, y-v.y); }
    double size() const { return sqrt((double)x*x + (double)y*y); }
};

inline int cross_product(const Vector & v1, const Vector & v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

// negative - if point is on the right side of vector v1->v2
// positive - if point is on the left side of vector v1->v2
// zero - if point lies on the line v1->v2
inline int direction(const Vector & v1, const Vector & v2, const Vector & point) {
	return cross_product(v2-v1, point-v1);
}

const int MAXN = 100;
int N;
Vector track[2], rects[MAXN][4];
typedef pair<double, double> Interval;
vector<Interval> intervals;  // intervals blocking the view

// intersection of lines A + t1 * (B-A) and C + t2 * (D-C). Return true, if intersection exists.
bool intersection(Vector A, Vector B, Vector C, Vector D, double & t1, double & t2) {
	double det = (D.y-C.y) * (B.x-A.x) - (B.y-A.y) * (D.x-C.x);
	if (!det) return false;
	t1 = ((D.y-C.y) * (C.x-A.x) + (D.x-C.x) * (A.y-C.y)) / det;
	t2 = ((B.y-A.y) * (C.x-A.x) + (B.x-A.x) * (A.y-C.y)) / det;
	return true;
}

// return true, if the base is completely visible from the point and not (even partially) blocked by the rect
bool is_base_completely_visible(Vector point, Vector base[4], Vector rect[4]) {
	// find the rightmost and leftmost points of the rect
	Vector D1 = rect[0], D2 = rect[0];
	for (int i = 0; i < 4; ++i) {
		if (direction(point, D1, rect[i]) < 0)
			D1 = rect[i];
		if (direction(point, D2, rect[i]) > 0)
			D2 = rect[i];
	}
	// any of the base points is strictly inside the shadow
	for (int i = 0; i < 4; ++i)
		if (direction(point, D1, base[i]) > 0 && direction(point, D2, base[i]) < 0 && direction(D1, D2, base[i]) < 0)
			return false;
	// any side of the base if covered by shadow
	for (int i = 0; i < 4; ++i) {
		double t1, t2, s1, s2;
		if (intersection(point, D1, base[i], base[(i+1)%4], t1, t2) &&
				intersection(point, D2, base[i], base[(i+1)%4], s1, s2) &&
				t1 >= 1 && s1 >= 1 && 0 <= t2 && t2 <= 1 && 0 <= s2 && s2 <= 1)
			return false;
	}
	return true;
}

// return true, if the whole track is blocked by some aviary
bool is_whole_track_blocked() {
	for (int i = 1; i < N; ++i)
		if (!is_base_completely_visible(track[0], rects[0], rects[i]) &&
				!is_base_completely_visible(track[1], rects[0], rects[i]))
			return true;
	return false;
}

// return true, if the track is completely visible from the point and not (even partially) blocked by the rect
bool is_track_completely_visible(Vector point, Vector track[2], Vector rect[4]) {
	// find the rightmost and leftmost points of the rect
	Vector D1 = rect[0], D2 = rect[0];
	for (int i = 0; i < 4; ++i) {
		if (direction(point, D1, rect[i]) < 0)
			D1 = rect[i];
		if (direction(point, D2, rect[i]) > 0)
			D2 = rect[i];
	}
	// any of the track points is strictly inside the shadow
	for (int i = 0; i < 2; ++i)
		if (direction(point, D1, track[i]) > 0 && direction(point, D2, track[i]) < 0 && direction(D1, D2, track[i]) < 0)
			return false;
	// track if covered by shadow somewhere in the middle
	double t1, t2, s1, s2;
	if (intersection(point, D1, track[0], track[1], t1, t2) &&
			intersection(point, D2, track[0], track[1], s1, s2) &&
			t1 >= 1 && s1 >= 1)
		return false;
	return true;
}

void create_interval(Vector base[4], Vector rect[4]) {
    vector<double> intersections;
    for (int i = 0; i < 4; ++i) {
		// if the track is completely visible from the i-th corner
		if (is_track_completely_visible(base[i], track, rect))
			continue;
		for (int j = 0; j < 4; ++j) {
			double t1, t2;
			if (intersection(track[0], track[1], base[i], rect[j], t1, t2) && t2 >= 1.0)
				intersections.push_back(t1);
		}
	}

    sort(intersections.begin(), intersections.end());
    if (intersections.size() && intersections.front() <= 1.0 && intersections.back() >= 0.0)
        intervals.push_back(Interval(intersections.front(), intersections.back()));
}

int main() {
    while (true) {
        scanf("%d", &N);
        if (!N) break;
        for (int i = 0; i < 2; ++i)
            scanf("%d%d", &track[i].x, &track[i].y);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%d%d", &rects[i][j].x, &rects[i][j].y);

		// the whole track is blocked by some aviary
		if (is_whole_track_blocked()) {
			printf("0.000000\n");
            continue;
		}

        // create blocking intervals
        intervals.clear();
        for (int i = 1; i < N; ++i)
            create_interval(rects[0], rects[i]);

        // calculate the length of the non-blocked view
        sort(intervals.begin(), intervals.end());
        double length = 0.0, last = 0.0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].first > 1.0) break;
            length += max(intervals[i].first - last, 0.0);
            last = max(last, intervals[i].second);
        }
        length += max(1.0 - last, 0.0);
        printf("%.6f\n", length * (track[1]-track[0]).size());
    }

    return 0;
}
