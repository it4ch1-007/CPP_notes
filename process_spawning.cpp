#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>

int main(){
   
    HANDLE hChildStdinRead,hChildStdinWrite,hChildStdoutRead,hChildStdoutWrite;
    SECURITY_ATTRIBUTES saAttr = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };


    try {
        if (!CreatePipe(&hChildStdoutRead, &hChildStdoutWrite, &saAttr, 0) ||
            !CreatePipe(&hChildStdinRead, &hChildStdinWrite, &saAttr, 0)) {
            throw std::runtime_error("Error creating pipes");
        }
    } catch (const std::exception &e) {
        std::cerr << "Error while creating pipes: " << e.what() << std::endl;
        return 1;
    }
 
    //These statements definig the info of the handles control the properties and the way the child process communicate with the parent process
    SetHandleInformation(hChildStdinRead,HANDLE_FLAG_INHERIT,0);
    SetHandleInformation(hChildStdoutWrite,HANDLE_FLAG_INHERIT,0);

    STARTUPINFOW si = {sizeof(STARTUPINFOW)};
    PROCESS_INFORMATION pi;

    //The main logic of the program or simply the commands to be executed in the child process spawned
    LPWSTR command = L"cmd.exe";

    if(!CreateProcessW(
        NULL, //WE WILL USE THE COMMAND LINE AND NOT REFER TO ANY ALREADY EXISTING EXECUTABLE FOR THE CHILD PROCESS.
        command,
        NULL,
        NULL,
        TRUE, //HANDLES WILL BE INHERITED BY THE CHILD PROCESS FROM THE PARENT PROCESS
        0,
        NULL,
        NULL,
        &si, //STARTUP INFO STRUCTURE REFERENCE
        &pi //POINTER OR SIMPLY REFERENCE TO PROCESS INFORMATION STRUCTURE
    )){
        std::cerr<<"Error creating a child process!!!"<<std::endl;
        return 1;
    }


    const char* to_child = "echo Hello from the parent process!!";
    DWORD bytesWritten;
    WriteFile(hChildStdinWrite, to_child, strlen(to_child), &bytesWritten, NULL); //This is to write message to the child process
    std::cout<<"hello world"<<std::endl;
    CloseHandle(hChildStdinWrite); 
    //These handles are the controllers of the pipes for communication that makes us able to write the data through pipes if available.

    char Buffer[4096];
    DWORD bytesRead;
    ReadFile(hChildStdoutRead, Buffer, sizeof(Buffer), &bytesRead, NULL);
    Buffer[bytesRead] = '\0';

    WaitForSingleObject(pi.hProcess,INFINITE); //WAITS FOR THE CHILD PROCESS TO EXECUTE AND TERMINATE 

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);


    std::cout << "Parent received: " << Buffer << std::endl;
    return 0;

}