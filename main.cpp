#include <iostream>
#include <string>
#include "iterativeCollage.h"
using namespace std;

string HI_THERE = "Hello there, welcome to TikZ Helper. What can I help you with today?\n";
string MAIN_MENU = "\nMAIN MENU\n1. Iterative collage\n0. Exit\nPlease make your choice.\n";
int main()
{
    cout << HI_THERE << flush;
    
    int choice = 1;
    while (choice)
    {
        cout << MAIN_MENU << flush;
        cin >> choice;
        switch (choice)
        {
        case 1:
            doIterativeCollage();
            break;
        
        default:
            break;
        }
    }
    cout << "Have a nice day.\n" << flush;
    return 0;
}