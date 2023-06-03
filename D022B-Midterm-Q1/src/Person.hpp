#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
    static int m_Count;
    
    string m_Name;
    int m_Age;
    
    
public:
    Person();                                   // Default constructor
    virtual ~Person();                          // Default destructor
    Person(const Person& person);               // Copy constructor
    Person& operator=(const Person& person);    // Assignment operatpr
    
    Person(const string& name_i, int age_i);
    
    
    static int GetCount();


    /* Getters */
    const string GetName() const;
    int GetAge() const;
    
    
    //set functions (setters); modifiers; read/write; *this is not const
    void SetName(const string& name_i);
    void SetAge(int age_i);
    virtual void Set(const string& name_i, int age_i);
    virtual void Set(const Person& person);
    
    
    virtual void Read();
    virtual void Print() const; //print to screen


    /* This is not a member (no this) but has access to private members */
    friend ostream& operator << (ostream& os, const Person& person);
};
