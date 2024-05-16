#include <bits/stdc++.h>
#include <vector>

int main(){
    std::vector<int> A= {0,1,2,34,5,5,4,5,1,0,2,1,0};
    A.erase(A.begin()+1);
    //erase is used to erase an element inside the vector and then the vector is adjusted to have the next element at the same index the erased element was.

    std::cout<<A[1]<<std::endl;

    std::cout<<accumulate(A.begin(),A.end())<<std::endl;
    //accumulate function gives the sum of a given vector


    
}