#include <iostream>

using namespace std;

int transform(string str, int b, int dig){
    int u;
    u=0;
    for(unsigned i=0; i<str.size(); ++i)
        u=(u*b+(str[i]-'0'))%dig;
    return u;
}

int main(void){
    int b,u,dig;
    string str;
    while((cin>>b)&&b){
        cin>>str;
        dig=0;
        for(unsigned i=0; i<str.size(); ++i)
            dig+=str[i]-'0';
        u=transform(str, b, dig);
        cout<<((u==0)?"yes":"no")<<endl;
    }
    return 0;
}
