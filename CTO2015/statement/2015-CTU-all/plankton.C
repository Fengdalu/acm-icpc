/*
 * CTU Open 2015: Plankton
 * Solution by: Josef Cibulka
 * Idea: F iterations of Bellman-Ford (to get at least one vertex in each negative cycle) followed by BFS.
 * Time: O(F * T), where F is the number of vertices and T is the number of edges
 */
 
#include <cstdlib>
#include <vector>
#include <string>
#include <deque>
#include <iostream>
#include <sstream>
 
#define FRAC_DIGITS 3 // the max. number of digits after the decimal point
#define INFTY 1000000000000000000LL
 
using namespace std;
 
struct Edge
{
  int to;
  long long w;
  Edge(int to_in, long long w_in) : to(to_in), w(w_in)
  {}
};
 
int main(void)
{
  while(true)
  {
    int f=-1, t=-1;
    int start=-1, fin=-1;
    cin >> t >> f >> start >> fin;
    if(f == 0 && t==0 && start==0 && fin==0)
      return 0;
    start--;
    fin--;
    vector<vector<Edge> > e(f);
    for(int i=0; i<t; i++)
    {
      int a,b;
      string wstr;
      cin >> a >> b >> wstr;
 
      // read the value w into a string (instead of a double) to be 100.000001% sure there are no rounding errors
      size_t pt_pos = wstr.find('.');
      if(pt_pos == string::npos)
        wstr += "000";
      else
      {
        int places_after = wstr.length() - pt_pos - 1;
        wstr = wstr.substr(0, pt_pos) + wstr.substr(pt_pos+1);
        for(int j=places_after; j<FRAC_DIGITS; j++)
          wstr+="0";
      }
      istringstream isstr (wstr);
      long long w = 0;
      isstr >> w;
      a--;
      b--;
      e[a].push_back(Edge(b, w));
    }
 
    // Bellman-Ford from start, n iterations.
    // Some vertices will get improved during the last iteration -> they are reachable from 
    // a negative cycle reachable from start.
    // Vertices to which an infinitely negative walk exists are those that are reachable from one of 
    // the vertices improved in the last step.
    vector<long long> dst (f, -INFTY);
    vector<long long> dst_prev (f, -INFTY);
    dst[start] = 0;
    for(int i=0; i<f; i++)
    {
      for(int v=0; v<f; v++)
        dst_prev[v] = dst[v];
 
      for(int v=0; v<f; v++)
      {
        for(const Edge &ed: e[v])
        {
          if(dst_prev[v] == -INFTY)
            continue;
          long long new_dst = dst_prev[v] + ed.w;
          dst[ed.to] = std::max(dst[ed.to], new_dst);
        }
      }
    }
 
    // BFS to find the vertices reachable from the vertices improved in the last iteration.
    deque<int> q;
    vector<bool> inq(f, false);
    for(int v=0; v<f; v++)
    {
      if(dst[v] > dst_prev[v])
      {
        q.push_back(v);
        inq[v] = true;
      }
    }
    while(q.size() > 0)
    {
      int cur = q.front();
      q.pop_front();
      for(const Edge &ed: e[cur])
      {
        int v2 = ed.to;
        if(!inq[v2])
        {
          inq[v2] = true;
          q.push_back(v2);
        }
      }
    }
 
    cout << (inq[fin]?"TRUE":"FALSE") << endl;
  }
  return 0;
} 
