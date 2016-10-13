/*
 * CTU Open 2015: Cheetah
 * Solution by: Josef Cibulka
 * Idea: Compute the upper and lower envelope by incrementally adding lines in
 * the order of increasing (decreasing) position at the moment when the last starts
 * running.
 * Time: O(n log(n)), where n is the number of cheetahs
*/
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <deque>
#include <algorithm>
 
using namespace std;
 
class Cheetah
{
public:
  int time;
  long long pos;
  int speed;
 
Cheetah(int time_in, int speed_in) : time(time_in), speed(speed_in)
  {}
 
  double get_pos_at_time(double time_query) const
  {  
    return pos + speed * time_query;
  }
 
  bool operator< (const Cheetah &ch2) const
  {
    if(pos != ch2.pos)
      return pos < ch2.pos;
    else
      return speed < ch2.speed;
  }
};
 
struct ChangeTime
{
  /// time 0 is the moment when the last cheetah starts running
  double time;
  Cheetah cheetah;
  ChangeTime(double time_in, Cheetah cheetah_in) : time(time_in), cheetah(cheetah_in)
  {}
};
 
 
deque<ChangeTime> find_last_position_changes(const vector<Cheetah> &chv)
{
  deque<ChangeTime> changes; 
  changes.push_back(ChangeTime(0, chv[0]));
  for(Cheetah ch : chv)
  {
    while(!changes.empty())
    {  
      ChangeTime cur_cht = changes.back();
      Cheetah cur_ch = cur_cht.cheetah;
      double cur_t = cur_cht.time;
      if(ch.get_pos_at_time(cur_t) < cur_ch.get_pos_at_time(cur_t))
      {
        changes.pop_back();
        continue;
      }
      if(ch.speed >= cur_ch.speed)
        break; // cheetah number i will never be last
      // cheetah number i will take the last place after cur_ch
      double inters_time = (ch.pos-cur_ch.pos) /
               static_cast<double>(cur_ch.speed-ch.speed);
      changes.push_back(ChangeTime(inters_time, ch));
    }
    assert(!changes.empty());
  }
  return changes;
}
 
 
int main(void)
{
  while(true)
  {
    int n = -1;
    scanf("%d", &n);
    if(n == 0)
      return 0;
    vector<Cheetah> chv;
    int start_time = 0;
    for(int i=0; i<n; i++)
    {
      int t,v;
      scanf("%d %d", &t, &v);
      chv.push_back(Cheetah(t,v));
      start_time = std::max(start_time, t);
    }
    for(int i=0; i<n; i++)
      chv[i].pos = (start_time - chv[i].time) * static_cast<long long>(chv[i].speed);
 
    sort(chv.begin(), chv.end());
    deque<ChangeTime> ch_low = find_last_position_changes(chv);
 
    vector<Cheetah> chv_mirrored = chv;
    std::reverse(chv_mirrored.begin(), chv_mirrored.end());
    for(Cheetah &ch: chv_mirrored)
    {
      ch.pos = -ch.pos;
      ch.speed = -ch.speed;
    }
    deque<ChangeTime> ch_top = find_last_position_changes(chv_mirrored);
 
    for(ChangeTime &cht: ch_top)
    {
      cht.cheetah.pos = -cht.cheetah.pos;
      cht.cheetah.speed = -cht.cheetah.speed;
    }
 
    auto cur_low = ch_low.begin();
    auto cur_top = ch_top.begin();
    double cur_time = 0;
    Cheetah cur_low_ch = cur_low->cheetah;
    Cheetah cur_top_ch = cur_top->cheetah;
    double best_len = cur_top_ch.pos - cur_low_ch.pos;
    cur_low++;
    cur_top++;
    while(cur_low != ch_low.end() || cur_top != ch_top.end())
    {
      if(cur_top == ch_top.end() || (cur_low != ch_low.end() && cur_low->time < cur_top->time))
      {
        cur_time = cur_low->time;
        cur_low_ch = cur_low->cheetah;
        cur_low++;
      }
      else
      {
        cur_time = cur_top->time;
        cur_top_ch = cur_top->cheetah;
        cur_top++;
      }
      double cur_len = cur_top_ch.get_pos_at_time(cur_time)
        - cur_low_ch.get_pos_at_time(cur_time);
      best_len = std::min(best_len, cur_len);
    }
    printf("%.3f\n", best_len);
  }
  return 0;
} 
