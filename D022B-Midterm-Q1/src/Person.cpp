#include <iostream>
#include <string>

#include "Person.hpp"

using namespace std;

int Person::m_Count = 0;

Person::Person() {
    m_Name = " ";
    m_Age = 0;
    m_Count++;
}

Person::~Person() {
    m_Count--;
}

Person::Person(const Person& person) {
    Set(person);
    m_Count++;
}

Person& Person::operator=(const Person& person) {
    if (this == &person)
        return (*this);
    
    Set(person);

    return *this; //return current object
}

Person::Person(const string& name, int age) {
    m_Count++;
    Set(name, age);
}

ostream& operator << (ostream& os, const Person& person) {
    os << "name = " << person.m_Name << ", age = " << person.m_Age;
    return os;
}

void Person::Set(const string& name, int age) {
    m_Name = name;
    m_Age = age;
}

void Person::Set(const Person& person) {
    m_Name = person.m_Name;
    m_Age = person.m_Age;
    
}

//get function (getters); selectors; read only;  *this is const
const string Person::GetName() const {
    return m_Name;
}

int Person::GetAge() const {
    return m_Age;
}

//set functions (setters); modifiers; read/write; *this is not const
void Person::SetName(const string& name) {
    m_Name = name;
}

void Person::SetAge(int age) {
    m_Age = age;
}

//static (no this) 
int Person::GetCount() {
    return m_Count;
}


void Person::Read() {
    string name1;
    int age1;
    cin.ignore(); //works with getline to clear end of line
    cout << "Enter name of the person: ";
    std::getline(cin, name1);
    //getline used for more than one word
    //cin a string; reads one word
    cout << "Enter age of the person: ";
    cin >> age1;
    Person::Set(name1, age1);
}

void Person::Print() const {
    cout << "name = " << m_Name << ", age = " << m_Age << endl;
}
