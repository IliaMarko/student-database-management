#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <map>
#include <vector>
#include <iomanip>
#include <dirent.h>
#include <sys/types.h>

//you need to define the path where the folder is.
#define PATH "/home/iliamarko/Desktop/ikubINFO/folder"

#include "database.h"

using namespace std;

void WorkingDatabase::add()
{
    WorkingPerson student;
    cin >> student;
    std::fstream outt("folder/" + student.getId() + ".txt", ios::out);
    system("clear");
    outt << student;
    void close();
}

void WorkingDatabase::edit()
{
    std::string id, name, idnew, name1, name2, name3;
    int choice;
    double number;
    WorkingPerson student;

    cout << "Enter the id of the student: " << endl;
    cin >> id;

    std::fstream in("folder/" + id + ".txt", ios::in);
    in >> student;

    std::fstream outt("folder/" + id + ".txt", ios::out);

    cout << "Give the number of the part you want to change: " << endl
         << "1. id \n"
         << "2. name \n"
         << "3. surname \n"
         << "4. course \n"
         << "5. grade \n"
         << endl;

    cin >> choice;
    cout << "\n";

    switch (choice)
    {

    case 2:
        cout << "Enter the new name: ";
        cin >> name1;
        student.setname(name1);
        outt << student;
        break;

    case 3:
        cout << "Enter the new surname: ";
        cin >> name2;
        student.setsurname(name2);
        outt << student;
        break;

    case 4:
        cout << "Enter the new course name: ";
        cin >> name3;
        student.setcourse(name3);
        outt << student;
        break;

    case 5:
        double number;
        cout << "Enter the new grade: ";
        cin >> number;
        student.setgrade(number);
        outt << student;
        break;

    case 1:
        cout << "Enter the new ID: (Be careful, if an existing ID is entered the student currently holding this ID will be deleted.)\n";
        cin >> idnew;

        id = student.getId();
        id = "folder/" + id + ".txt";
        remove(id.c_str());

        student.setID(idnew);
        fstream o("folder/" + idnew + ".txt", ios::out);
        o << student;
        void close();
        break;
    }
}

void WorkingDatabase::delete_student()
{
    string id;

    cout << "Enter the ID of the student you want to remove: ";
    cin >> id;
    id = "folder/" + id + ".txt";

    remove(id.c_str());
}

void WorkingDatabase::search()
{
    std::string id;
    WorkingPerson student;

    cout << "Enter ID: ";
    cin >> id;
    cout << endl;

    std::fstream in("folder/" + id + ".txt", ios::in);
    in >> student;

    cout << student;
    cout << endl;
    in.close();
    do
    {
        cout << '\n'
             << "Press Enter to continue...";
        getchar();
    } while (cin.get() != '\n');
}

void WorkingDatabase::grades()
{
    WorkingPerson student;
    DIR *dir;
    struct dirent *ent;
    string course;
    map<string, double> grades;

    cout << "Enter the name of the course: (Be careful, it is case sensitive.) " << endl;
    cin >> course;

    if ((dir = opendir(PATH)) != NULL)
    {
        cout << "\nID "
             << "\t\tCourse "
             << "\t\tStudent Grade " << endl;
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL)
        {
            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
                continue;
            //  cout << ent->d_name << endl;

            char id[256] = "folder/";
            strcat(id, ent->d_name);

            std::ifstream in;
            in.open(id);
            in >> student;

            if (student.getcourse() == course)
            {
                grades[student.getId()] = student.getgrade();
            }
            else
            {
                continue;
            }

            cout << student.getId() << "\t\t" << course
                 << "\t\t" << grades[student.getId()] << endl;

            in.close();
        }

        closedir(dir);

        do
        {
            cout << '\n'
                 << "Press Enter to continue...";
            getchar();
        } while (cin.get() != '\n');
    }
    else
    {
        perror("Directory Error!");
    }
}

void WorkingDatabase::pass_percentage()
{
    WorkingPerson student;
    DIR *dir;
    struct dirent *ent;
    string course;
    double total = 0, passed = 0;

    cout << "Enter the name of the course: (Be careful, it is case sensitive.) " << endl;
    cin >> course;

    if ((dir = opendir(PATH)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
                continue;
            // cout << ent -> d_name <<endl;
            char id[256] = "folder/";
            strcat(id, ent->d_name);

            std::ifstream in;
            in.open(id);
            in >> student;
            if (student.getcourse() == course)
            {
                if (student.getgrade() >= 4.5)
                    passed++;
                total++;
            }
            in.close();
        }
        cout << "Pass Percentage for " << course << " course: "
             << fixed << setprecision(2) << (passed / total) * 100 << "%" << endl;

        closedir(dir);

        do
        {
            cout << '\n'
                 << "Press Enter to continue...";
            getchar();
        } while (cin.get() != '\n');
    }

    else
    {
        perror("Directory Error!");
    }
}

void WorkingDatabase::no_students()
{
    WorkingPerson student;
    DIR *dir;
    struct dirent *ent;
    vector<string> courses;
    map<string, int> no_student;
    bool same = false;

    if ((dir = opendir(PATH)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {

            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
                continue;

            char id[256] = "folder/";
            strcat(id, ent->d_name);

            std::ifstream in;
            in.open(id);
            in >> student;

            for (int i = 0; i < courses.size(); i++)
            {
                if (courses[i] == student.getcourse())
                    same = true;
            }

            if (same == true)
            {
                no_student[student.getcourse()]++;
                same = false;
                continue;
            }
            else
            {
                courses.push_back(student.getcourse());
                no_student[student.getcourse()] = 1;
            }
            
            in.close();
        }
        // cout << courses.size() << endl;
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "Number of students enrolled for "
                 << courses[i] << " course:  " << no_student[courses[i]] << endl;
        }

        closedir(dir);

        do
        {
            cout << "\nPress Enter to continue...";
            getchar();
        } while (cin.get() != '\n');
    }

    else
    {
        perror("Directory Error!");
    }
}