import java.util.Arrays;
import java.util.Scanner;

public class Main{
    class Point implements Comparable {
        double x, y;
        Point (double x, double y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Object o) {
            if(this.x == ((Point)o).x) return Double.compare(this.y, ((Point)o).y);
            return Double.compare(this.x, ((Point)o).x);
        }
        public double dis(Point p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }
    }
    void solve(Point[] points, int left, int right, Point[] ans) {
        if(left == right) return;
        int mid = (left + right) / 2;
        solve(points, left, mid, ans);
        solve(points, mid + 1, right, ans);

        double limit = ans[0].dis(ans[1]);
        double leftBound = points[mid].x - limit;
        double rightBound = points[mid].x + limit;
        int totPoints = 0;
        for(int i = left; i != right + 1; i++)
            if(leftBound <= points[i].x && points[i].x <= rightBound) totPoints++;
        Point[] temp = new Point[totPoints];
        for(int i = left; i != right + 1; i++)
            if(leftBound <= points[i].x && points[i].x <= rightBound) temp[--totPoints] = new Point(points[i].y, points[i].x);

        Arrays.sort(temp);
        for(int i = 0; i < temp.length; i++)
            for(int j = i + 1; j < temp.length; j++) {
                if(Math.abs(temp[i].x - temp[j].x) >= limit) break;
                if(temp[i].dis(temp[j]) < limit)  {
                    ans[0] = new Point(temp[i].y, temp[i].x);
                    ans[1] = new Point(temp[j].y, temp[j].x);
                    limit = ans[0].dis(ans[1]);
                }
            }
    }

    public Point[] ClosestPair(Point[] points) {
        Arrays.sort(points);
        Point[] ans = new Point[2];
        ans[0] = new Point(points[0].x, points[0].y);
        ans[1] = new Point(points[1].x, points[1].y);
        solve(points, 0, points.length - 1, ans);
        return ans;
    }

    void run() {
        Scanner in = new Scanner(System.in);
        while(true) {
            int n = in.nextInt();
            if(n == 0) break;
            Point[] points = new Point[n];
            for (int i = 0; i < n; i++) {
                double x, y;
                x = in.nextDouble();
                y = in.nextDouble();
                points[i] = new Point(x, y);
            }
            Point[] ans = ClosestPair(points);
            System.out.println(String.format("%.2f", ans[0].dis(ans[1]) / 2.0));
        }
    }

    public static void main(String args[]) {
        new Main().run();
    }
}

/*
2
0 0
1 1

2
1 1
1 1

3
-1.5 0
0 0
0 1.5

4
0 0
1 0
0 1
1 1

0


 */
