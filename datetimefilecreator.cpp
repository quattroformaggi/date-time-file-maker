#include <iostream>
#include <time.h> //based code
#include <cstdio> //messing with files
#include <conio.h> //getch
using namespace std;

int main()
{
    char choice;
    unsigned const short SIZE = 18; //varies, 18 for this format: YYYYMMDD_HHMM.xxx
    system("title Date_time text file maker @quattroformaggi & color 0e");

    /////////////////////////////////////// based code, gets the Date_Time in this format: YYYYMMDD_HHMM
    time_t rawtime;
    struct tm* timeinfo;
    char filenamebuffer[SIZE];                                      // for current time
    time(&rawtime);                                                 // date in seconds
    timeinfo = localtime(&rawtime);                                 // localtime in a struct
    strftime(filenamebuffer, SIZE, "%Y%m%d_%H%M.txt", timeinfo);    // format: YYYYMMDD_HHMM.xxx
    ///////////////////////////////////////

    cout << "A file is about to be created with the name: " << filenamebuffer << endl 
         << "Confirm?" << endl
         << "[Y] Continue" << endl
         << "[N] Cancel & Exit" << endl
         << "=> ";
    cin >> choice;
	
    if((choice == 'Y') || (choice == 'y'))
    {
        FILE* file = fopen(filenamebuffer, "w");
        cout << "File was created successfully!" << endl;
        _getch();
        return 1;
    }
    else if ((choice == 'N') || (choice == 'n'))
    {
        cout << "Cancelled file creating." << endl;
        _getch();
        return 0;
    }
    else
    {
        cerr << "Error with the choice input: other characters give this error. Shutting down...";
        _getch();
        return -1;
    }
}
