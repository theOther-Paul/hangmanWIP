#include "hangman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include <windows.h>
#include <string.h> //i don't think i need both string and string.h, but i'm keeping it anyway

int main()
{
    system("cls");
    TitleDropBegin();
    Sleep(500);
    SmallTimer();
    system("cls");
    DisplayMenu();
}