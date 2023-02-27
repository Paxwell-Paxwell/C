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
vector<int> selected_ids;

int scheduleWeight(int s)
{
    selected_ids.clear(); // initialize selected_ids as an empty vector
    int last_selected = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i - 1;
        while (j >= 0 && all_sch[j].end > all_sch[i - 1].start)
        {
            j--;
        }
        if (dp[i - 1] > dp[j + 1] + all_sch[i - 1].weight)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = dp[j + 1] + all_sch[i - 1].weight;
            selected_ids.push_back(all_sch[i - 1].id);
            last_selected = i;
        }
    }

    // Construct the selected schedule ids by backtracking from the last selected schedule
    while (last_selected > 0)
    {
        if (dp[last_selected] != dp[last_selected - 1])
        {
            selected_ids.push_back(all_sch[last_selected - 1].id);
        }
        last_selected--;
    }

    reverse(selected_ids.begin(), selected_ids.end()); // reverse the order of selected schedule ids
    return dp[n];
}

int main()
{
    read_input();
    cout << scheduleWeight(n) << "\n";
    cout << selected_ids.size() << "\n";
    for (int i = 0; i < selected_ids.size(); i++)
    {
        cout << selected_ids[i] << " ";
    }
    return 0;
}
