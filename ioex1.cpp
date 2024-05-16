#include <bits/stdc++.h>



//EX1
    //     Write a function that takes and returns an istream&. The function
    // should read the stream until it hits end-of-file. The function should print what it reads
    // to the standard output. Reset the stream so that it is valid before returning the stream
std::istream& fn(std::istream& input)
{
    while(input)
    {
        char ch;
        input.get(ch);

        if(input.eof())
        {
            break;
        }
        std::cout<<ch;

    }

    input.clear();
    //This resets the stream to the valid state
    return input;
}

int main()
{
    fn(std::cin);
    //This takes my input and then prints it simultaneously
    
}