#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

typedef pair<int, int> pos_t;

pos_t diff[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char directions[4] = {'N', 'S', 'E', 'W'};

int energy(string &com, vector<int> &walk)
{
    pos_t now = {0, 0};
    for (size_t i = 0; i < walk.size(); i++)
    {
        int dir = find(directions, directions + 4, com[walk[i] - 1]) - directions;
        now.first += diff[dir].first;
        now.second += diff[dir].second;
    }
    return (abs(now.first) + abs(now.second)) * 2;
}

int main()
{
    string command;
    int loss;
    getline(cin, command);
    cin >> loss;

    priority_queue<int, vector<int>, greater<int>> pq;
    int max_energy = 0;

    function<void(int, int, vector<int>)> recursive_combinations;
    recursive_combinations = [&](int start, int remaining, vector<int> combination) {
        if (remaining == 0)
        {
            int e = energy(command, combination);
            if (e > max_energy)
            {
                max_energy = e;
            }
            return;
        }

        for (int i = start; i <= command.size() - remaining; i++)
        {
            combination.push_back(i);
            recursive_combinations(i + 1, remaining - 1, combination);
            combination.pop_back();
        }
    };

    vector<int> combination;
    recursive_combinations(0, command.size() - loss, combination);

    cout << max_energy;
}
