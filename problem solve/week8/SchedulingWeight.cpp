#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct SchedulingWeight
{
    int id;
    int start;
    int end;
    int weight;
};

bool compare(SchedulingWeight a, SchedulingWeight b)
{
    return a.end < b.end;
}
vector<SchedulingWeight> all_sch;
int n;
void read_input()
{
    cin >> n;
    all_sch.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> all_sch[i].start >> all_sch[i].end >> all_sch[i].weight;
        all_sch[i].id = i + 1;
    }
    sort(all_sch.begin(), all_sch.end(), compare);
}
// find sum maxweight schedule

vector<int> dp(n + 1, 0);
int scheduleWeight(int s)
{
    for (int i = 1; i <= n; i++)
    {
        int j = i - 1;
        while (j >= 0 && all_sch[j].end > all_sch[i - 1].start)
        {
            j--;
        }
        // dp[i] = max(dp[i - 1], dp[j + 1] + all_sch[i - 1].weight);
        //
        if (dp[i - 1] > dp[j+1] + all_sch[i - 1].weight)
        {
            dp[i] = dp[i - 1];

        }
        else
        {
            dp[i] = dp[j+1] + all_sch[i - 1].weight;
            
        }

    }
    return dp[n];
}
// print schedule
vector<int> result;
void printSchedule(int s)
{
    if (s == 0)
    {
        return;
    }
    int j = s - 1;
    while (j >= 0 && all_sch[j].end > all_sch[s - 1].start)
    {
        j--;
    }
    if (dp[s] == dp[s - 1])
    {
        printSchedule(s - 1);
    }
    else
    {
        printSchedule(j + 1);
        result.push_back(all_sch[s - 1].id);
    }
}


int main()
{
    read_input();
    cout << scheduleWeight(n) << "\n";
    result.clear();
    printSchedule(n);
    cout<<result.size()<<"\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    return 0;
    
}


