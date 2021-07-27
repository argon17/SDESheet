#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
    int pos;
};

bool comp(meeting meet1, meeting meet2)
{
    if (meet1.end < meet2.end)
        return true;
    else if (meet1.end > meet2.end)
        return false;
    else
        return meet1.pos < meet2.pos;
}

class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for (int i = 0; i < n; ++i)
        {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i;
        }
        sort(meet, meet + n, comp);
        int cnt = 0;
        int last = meet[0].end;
        ++cnt;
        for (int i = 1; i < n; ++i)
        {
            if (last < meet[i].start)
            {
                ++cnt;
                last = meet[i].end;
            }
        }
        return cnt;
    }
};