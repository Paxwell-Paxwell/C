#include <vector>
#include <iostream>
#include <string>
using namespace std;
string text,name;

void readInput(){
    getline(cin,name);
    getline(cin,text);
}

void findName(){
    int i=0;
    int j=0;
    int count=0;
    while(i<text.size()){
        if(text[i]==name[j]){
            j++;
            if(j==name.size()){
                count++;
                j=0;
            }
        }
        i++;
    }
    cout<<count;
}
int main(){
    readInput();
    findName();
    return 0;
}