#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    cout<<"hi"<<endl; //This adds a '\n' to the string
    cout<<"hi!"<<ends; //This adds null element at the end of the buffer and then fkushes the output buiffer
    cout<<"hi!"<<flush; //This flushes the output buffer 

    //tie keyword
    cin.tie(&cout); //this makes a tie between cout and cin and makes sure that thay flush the buffers simultaneously
    ostream *old_tie = cin.tie(nullptr); //this breaks the tie b/w cout and cin
    cin.tie(old_tie);//this restablishes the same tie again

    
}