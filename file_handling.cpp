#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>


//EACH WORD AS A SEPARATE ELEMENT
std::vector<std::string> readFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if(!file.is_open())
    {
        std::cout<<"error opening the file"<<std::endl;
    }

    std::vector<std::string> words;
    std::string word;
    while(file >> word) //This will act as a cin function as it will take input of only one word
    {
        words.push_back(word);
    }

    

    return words;
}

//FUNCTION THAT IS SIMILAR TO READLINE() IOF PYTHON
std::vector<std::string> readFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if(!file.is_open())
    {
        std::cout<<"error opening the file"<<std::endl;
    }

    std::vector<std::string> lines;
    std::string line;
    while(std::getline(file,line))
    {
        lines.push_back(line);
    }

    // Use istringstream to read each word from the vector
    std::cout << "\nWords from the vector:" << std::endl;
    for (const auto& l : lines) {
        std::istringstream iss(l); //an instance of istringstream is made for each of the line in the lines vector
        std::string word;

        while (iss >> word) { //this takes all the strings from each line to the word variable
            std::cout << word << std::endl;
        }
    }

    

    return lines;
}
int main() {
    // Open the file in binary read-write mode with truncation
    std::fstream fstrm("hello.txt", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
    //If we want to take input from the file and also use it as an output file

    if (!fstrm.is_open()) {
        std::cerr << "Error opening file: hello.txt" << std::endl;
        return 1;
    }

    

    fstrm.close(); // Close the file when done

    return 0;
}
