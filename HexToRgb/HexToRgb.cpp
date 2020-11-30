// HexToRgb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <map>
using namespace std;

map<char, int> hexValues = {
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
};

int HexToRgb(string hexPart)
{
    char c1 = toupper(hexPart[0]);
    char c2 = toupper(hexPart[1]);

    int c1Out;
    int c2Out;

    if (hexValues.find(c1) != hexValues.end())
    {
        c1Out = hexValues[c1];
    }

    if (hexValues.find(c2) != hexValues.end())
    {
        c2Out = hexValues[c2];
    }

    return c1Out * c2Out;
}

int main()
{
    string hex = "";

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 10);
    cout << "Please enter a HEX string -> ";
    
    SetConsoleTextAttribute(hConsole, 15);
    cout << "#";
    cin >> hex;

    if (hex.length() != 6)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Please pass in a valid 6-digit HEX string." << endl;
        return 0;
    }

    string R = hex.substr(0, 2);
    string G = hex.substr(1, 2);
    string B = hex.substr(3, 2);

    SetConsoleTextAttribute(hConsole, 10);
    cout << "RGB -> ";

    SetConsoleTextAttribute(hConsole, 15);
    cout << HexToRgb(R) << ", " << HexToRgb(G) << ", " << HexToRgb(B) << endl;
}
