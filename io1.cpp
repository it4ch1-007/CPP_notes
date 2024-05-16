#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int main()
{
    string s,s1,s2;
    getline(cin,s);
    cout<<s<<endl;
    getline(cin,s1);
    cout<<s1<<endl;
    cin>>s2;
    cout<<s2<<endl;
    //cin is used to take a single word from the input while getline function is used to get a whole line from the input until the '\n' keyword is not found.
    //wide characters are the characters that consist of the larger dqtatype than the normal ones.

    //The 'badbit' indicates system failure  and the program cannot be recovered.
    //The 'goodbit' indicates completion of the program and i guaranteed ot return the value 0.
    //The 'failbit' can be recovered and indicates a small error like numeric data entered as input when character is expected.
    //When the pointer reaches the EOF then both eofbit and failbit is triggered.


    





}