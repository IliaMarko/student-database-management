
#include "database.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    WorkingDatabase d1;
    int choice;

    while (1)
    {
        system("clear");
        cout << "\nChoose one of the actions: \n";
        cout << "1.Add New Student\n";
        cout << "2.Modify Data of Student\n";
        cout << "3.Delete Student\n";
        cout << "4.Search And Display Student\n";
        cout << "5.Display the Grades for a Specific Course\n";
        cout << "6.Display the Pass Percentage in a Course\n";
        cout << "7.Display Number of Students Enrolled for every Course.\n";
        cout << "8.Exit\n";

        cout << "\nEnter your choice: \n";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            d1.add();
            break;

        case 2:
            d1.edit();
            break;

        case 3:
            d1.delete_student();
            break;

        case 4:
            d1.search();
            break;

        case 5:
            d1.grades();
            break;

        case 6:
            d1.pass_percentage();
            break;

        case 7:
            d1.no_students();
            break;

        case 8:
            return 0;

        default:
            cout << "\nInvalid Choice\nTRY AGAIN!\n";
        }
        
    }
    return 0;
}