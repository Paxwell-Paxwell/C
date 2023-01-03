#include <vector>
#include <iostream>
#include<string>
using namespace std;
int main(){
    string command;
    getline(cin,command);
    string direct="NESW";
    string robot="";
    int max= command.size(),n=0,spin=0;
    while(n<max){
        if(command[n]=='Z'){
            robot += 'Z';
            n++;
            spin=0;
            continue;
        }
        spin = spin%4;
        if(direct[spin] == command[n]){
            robot += 'F';
            n++;
            continue;
        }
        else{
            spin++;
            robot +='R';
            }
    }
    cout<<robot;
}