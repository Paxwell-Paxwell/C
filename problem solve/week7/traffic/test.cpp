#include "traffic.h"
#include <vector>
#include <iostream>
#include <utility>
using namespace std;
struct start_end
{
    int s_col, s_row, e_col, e_row;
};

int n, k;
vector<pair<int, int> > find_traffic_col(int col, int start, int end, vector<pair<int, int> > ans)
{
    int mid = (start + end) / 2;
    if (start == end - 1)
    {
        ans.push_back(make_pair(start, end));
        return ans;
    }
    if (traffic_query(col, start, col, mid) != mid - start)
    {
        //cout<<"col: "<<col<<" start: "<<start<<" mid: "<<mid<<" end: "<<end<<"\n";
        ans = find_traffic_col(col, start, mid, ans);
    }
    if (traffic_query(col, mid, col, end) != end - mid)
    {
        //cout<<"col: "<<col<<" start: "<<start<<" mid: "<<mid<<" end: "<<end<<"\n";
        ans = find_traffic_col(col, mid, end, ans);
    }
    return ans;
}
vector<pair<int, int> > find_traffic_row(int row, int start, int end, vector<pair<int, int> > ans)
{
    int mid = (start + end) / 2;
    if (start == end - 1)
    {
        ans.push_back(make_pair(start, end));
        return ans;
    }
    if (traffic_query(start, row, mid, row) != mid - start)
    {
        ans = find_traffic_row(row, start, mid, ans);
    }
    if (traffic_query(mid, row, end, row) != end - mid)
    {
        ans = find_traffic_row(row, mid, end, ans);
    }
    return ans;
}
vector<start_end> traffic_in_col_row()
{
    vector<pair<int, int> > ans;
    vector<start_end> all_ans;
    int col = 0;
    for (int i = 1; i <= n; i++)
    {

        if (traffic_query(i, 1, i, n) != n-1)
        {
            col = i;
            //cout<<col<<"\n";
            ans = find_traffic_col(col, 1, n, ans);

            start_end n_se;
            for(auto i:ans)
            {
                n_se.s_col = col;
                n_se.s_row = i.first;
                n_se.e_col = col;
                n_se.e_row = i.second;
                all_ans.push_back(n_se);
            }
            if(all_ans.size() == k)
            {
                return all_ans;
            }
        }
        

    }
    ans.clear();
    int row = 0;
    for (int i = 1; i <= n; i++)
    {
        if (traffic_query(1, i, n, i) != n-1)
        {
            row = i;
            //cout<<row<<"\n";
            ans = find_traffic_row(row, 1, n, ans);
            start_end n_se;
            for(auto i:ans)
            {
                n_se.s_col = i.first;
                n_se.s_row = row;
                n_se.e_col = i.second;
                n_se.e_row = row;
                all_ans.push_back(n_se);
            }
            if(all_ans.size() == k)
            {
                return all_ans;
            }
        }
    }
    
    return all_ans;

}

int main()
{
    traffic_init(&n, &k);
    vector<start_end> ans = traffic_in_col_row();
    //cout<<ans.size()<<"\n";
    if(ans.size()==1){
        traffic_report(ans[0].s_col, ans[0].s_row, ans[0].e_col, ans[0].e_row, 0, 0, 0, 0);
    }
    else{
        traffic_report(ans[0].s_col, ans[0].s_row, ans[0].e_col, ans[0].e_row, ans[1].s_col, ans[1].s_row, ans[1].e_col, ans[1].e_row);
    }
    return 0;
}
