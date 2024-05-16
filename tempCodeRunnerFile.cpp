#include <Windows.h>
#include <iostream>
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
    MessageBoxW(NULL, L"Random Text to appear", L"Window Name", 0);
    return 0; // Return an integer value indicating successful execution
}
