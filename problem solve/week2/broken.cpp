#include <iostream>
#include <list>
#include <string>
using namespace std;
int main() {
    string ch;
    list<char> word;
    list<char>::iterator it;
    while(getline(cin,ch))
    {
        word.clear();
        it = word.begin();
        for(int i=0;i<ch.size();++i)
        {
            if(ch[i]=='[')
                it = word.begin();
            if(ch[i]==']')
                it = word.end();
            if(ch[i]!='[' && ch[i]!=']')
                word.insert(it,ch[i]);
        }
        for(it=word.begin();it!=word.end();it++)
            cout<<*it;
        printf("\n");
    }
    return 0;
}