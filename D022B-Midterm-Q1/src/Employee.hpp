#pragma once
#include <iostream>

#include "Person.hpp"

using namespace std;

class Employee : public Person
{
private:
    static int m_Count;
    
    string m_JobTitle;
    double m_Salary; // Annual salary.
    bool m_Fulltime;
    
    
public:
    Employee();                                             // Default constructor.
    virtual ~Employee();                                    // Default destructor.
    Employee(const Employee& employee);                     // Copy constructor.
    virtual Employee& operator=(const Employee& employee);  // Assignment operator.
    
    Employee(const string& name, int age, const string& jobTitle, double salary, bool fulltime);
    
    
    static int GetCount();
    
    
    /* Getters */
    const string GetJobTitle() const;
    double GetSalary() const;
    bool GetFulltime() const;
    
    
    /* Setters */
    void SetJobTitle(const string& jobTitle);
    void SetSalary(double salary);
    void SetFulltime(bool fulltime);
    
    virtual void Set(const string& jobTitle, double salary, bool fulltime);
    virtual void Set(const string& name, int age, const string& jobTitle, double salary, bool fulltime);
    virtual void Set(const Employee& employee);
    
    
    virtual void Read();
    virtual void Print() const; // Print to screen.
    
    
    /* This is not a member (no this) but has access to private members */
    friend ostream& operator << (ostream& os, const Employee& employee);
};
