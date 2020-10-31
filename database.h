
#ifndef _SHAPES_H
#define _SHAPES_H
#include <string>
#include <iostream>

class WorkingPerson
{
private:
    std::string id;
    std::string name;
    std::string surname;
    std::string course;
    double grade;

public:
    friend std::ostream &operator<<(std::ostream &out, const WorkingPerson &obj)
    {

        out << obj.id << std::endl;
        out << obj.name << std::endl;
        out << obj.surname << std::endl;
        out << obj.course << std::endl;
        out << obj.grade << std::endl;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, WorkingPerson &obj)
    {
        in >> obj.id;
        in >> obj.name;
        in >> obj.surname;
        in >> obj.course;
        in >> obj.grade;
        return in;
    }

    void setID(std::string id)
    {
        this->id = id;
    }

    void setname(std::string name)
    {
        this->name = name;
    }
    void setsurname(std::string surname)
    {
        this->surname = surname;
    }
    void setcourse(std::string course)
    {
        this->course = course;
    }
    void setgrade(double grade)
    {
        this->grade = grade;
    }

    std::string getId() { return id; }
    std::string getname() { return name; }
    std::string getsurname() { return surname; }
    std::string getcourse() { return course; }
    double getgrade() { return grade; }
};

class WorkingDatabase
{
private:
public:
    void add();
    void edit();
    void delete_student();
    void search();
    void grades();
    void pass_percentage();
    void no_students();
};

#endif