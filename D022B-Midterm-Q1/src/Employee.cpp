#include <iostream>
#include <algorithm>
#include <string>

#include "Employee.hpp"

using namespace std;

//initialize static date here
int Employee::m_Count = 0;

Employee::Employee() {
    Person();
    Set(" ", 0, false);
}

Employee::~Employee() {
    m_Count--;
}

Employee::Employee(const Employee& employee) {
    //create and object and make it like s
    Person::Set(employee); //should be first line
    Set(employee);
    m_Count++;
}

Employee& Employee::operator=(const Employee& employee) {
    //you have an object *this make it = s
    //this is a pointer to the current object
    //*this is the object
    if (this == &employee)
        return (*this);
    
    Person::operator=(employee);
    Set(employee);
    return *this;
}

Employee::Employee(const string& name, int age, const string& job_title, double salary, bool fulltime) {
    Person(name, age); //should be first line
    Set(job_title, salary, fulltime);
    m_Count++;
}


/* Getters */
const string Employee::GetJobTitle() const {
    return m_JobTitle;
}

double Employee::GetSalary() const {
    return m_Salary;
}

bool Employee::GetFulltime() const {
    return m_Fulltime;
}


//this is not a member; no Student::; no "this" pointer
ostream& operator << (ostream& os, const Employee& employee) {
    os << Person(employee) <<", job title = " << employee.m_JobTitle << ", salary = " << employee.m_Salary << ", fulltime = " << (employee.m_Fulltime ? "true" : "false");
    return os;
}


/* Setters */
void Employee::SetJobTitle(const string& jobTitle) {
    m_JobTitle = jobTitle;
}

void Employee::SetSalary(double salary) {
    m_Salary = salary;
}

void Employee::SetFulltime(bool fulltime) {
    m_Fulltime = fulltime;
}

void Employee::Set(const string& jobTitle, double salary, bool fulltime) {
    SetJobTitle(jobTitle);
    SetSalary(salary);
    SetFulltime(fulltime);
}

void Employee::Set(const string& name, int age, const string& jobTitle, double salary, bool fulltime) {
    Person::Set(name, age);
    Set(jobTitle, salary, fulltime);
}

void Employee::Set(const Employee& employee) {
    Person::Set(employee);
    Set(employee.m_JobTitle, employee.m_Salary, employee.m_Fulltime);
}

int Employee::GetCount() {
    //no "this" in static; no object
    return m_Count;
}

void Employee::Print() const {
    Person::Print();
    cout << "job title = " << m_JobTitle << ", salary = " << m_Salary << ", fulltime = " << (m_Fulltime ? "true" : "false") << endl;
}

//read an object from the keyboard and construct it
void Employee::Read() {
    Person::Read();
    
    string jobTitle;
    double salary;
    char fulltimeFlag;
    
    cin.ignore(); // Works with getline to clear EOL.
    cout << "Enter the job title of the employee: ";
    std::getline(cin, jobTitle);
    
    cout << "Enter the salary of the employee: ";
    cin >> salary;
    
    cout << "Is the employee working fulltime? (y/n): ";
    cin >> fulltimeFlag;
    fulltimeFlag = tolower(fulltimeFlag);
    
    
    Set(jobTitle, salary, (fulltimeFlag == 'y' ? true : false));
}
