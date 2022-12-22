#include <iostream>
#include <vector>
#include <string> 

using namespace std;
void show(vector<int> &v){
    vector<int>::iterator it;
    for (it=v.begin();it !=v.end();it++) {
        cout << *it << "\n";
    }
    cout<<"\n";
}
int main() {
    // Read input
    int n;
    vector<int> ic;
    string command;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>command;
        int num;
        if (command == "li") {
            cin >> num;
            ic.insert(ic.begin(), num);
            //show(ic);


        }
        else if (command == "ri") {
            cin >> num;
            ic.push_back(num);
            //show(ic);

        }
        else if (command == "lr") {
            if(ic.empty())
                continue;
            ic.push_back(ic.front());
            ic.erase(ic.begin());
            //show(ic);
        }
        else if (command == "rr") {
            if(ic.empty())
                continue;
            ic.insert(ic.begin(), ic.back());
            ic.pop_back();
            //show(ic);
        }
    }
    show(ic);
    return 0;
}