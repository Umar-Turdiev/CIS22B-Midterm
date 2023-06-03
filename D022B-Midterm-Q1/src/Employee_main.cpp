#include <iostream>
#include <vector>

#include "Person.hpp"
#include "Employee.hpp"

using namespace std;

int main_employee(void) {
    cout << "Welcome to the employee program!" << endl;
    string name = "employee one";
    Employee employee_1(name, 30, "PM", 80000, true);
    Employee employee_2, employee_3;
    employee_2.Set(name, 30, "PM", 80000, true);
    cout << employee_1 << endl;
    cout << employee_2 << endl;

    cout << "objects count = " << Employee::GetCount() << endl;


    cout << employee_1.GetName() << endl; //get_name public
    employee_1.SetName("Employee Ten");
    cout << "employee_1 name = " << employee_1.GetName() << endl;
    employee_1.SetAge(40);
    cout << "employee_1 age=  " << employee_1.GetAge() << endl;
    employee_1.SetJobTitle("Sales");
    cout << "employee_1 job title = " << employee_1.GetJobTitle() << endl;
    employee_1.SetSalary(100000);
    cout << "employee_1 year = " << employee_1.GetSalary() << endl;
    employee_1.SetFulltime(true);
    cout << "employee_1 fulltime = " << employee_1.GetFulltime() << endl;
    
    cout << employee_1 << endl;
    employee_1.Set(employee_2);
    employee_1.Print();

    while (true)
    {
        int num = 0;
        cout << "Enter number of emplyees: ";
        cin >> num;
        if (num <= 0)
            break;
        
        vector<Employee> pa(num);
        
        for (size_t i = 0; i < num; i++) {
            pa[i].Read();
        }
        
        for (size_t i = 0; i < num; i++) {
            cout << pa[i] << endl;
        }
    }
    return 0;
}

int main(void) {
    main_employee();
    
    return 0;
}
