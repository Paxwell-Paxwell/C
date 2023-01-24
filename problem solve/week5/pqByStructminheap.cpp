#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int value;
    int id;
};

struct ComparePairSomeValue {//1
    bool operator() (const Node &a, const Node &b) {
        return a.value > b.value;
    }
};

int main() {
    priority_queue<Node, vector<Node >, ComparePairSomeValue> pq;//1
    
    Node n1;
    n1.value = 5;
    n1.id = 1;
    pq.push(n1);

    Node n2;
    n2.value = 3;
    n2.id = 2;
    pq.push(n2);

    Node n3;
    n3.value = 7;
    n3.id = 3;
    pq.push(n3);

    while (!pq.empty()) {
        Node top = pq.top();
        std::cout << "Node with id " << top.id << " has value " << top.value << std::endl;
        pq.pop();
    }

    return 0;
}
