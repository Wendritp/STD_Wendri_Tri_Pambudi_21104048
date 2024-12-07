#include <iostream>
#include <string>
using namespace std;

struct Project {
    string name;
    int duration; 
    Project* next;

    Project(string pname, int pduration) : name(pname), duration(pduration), next(nullptr) {}
};


struct Employee {
    string name;
    string id;
    Project* projectHead;
    Employee* next;

    Employee(string ename, string eid) : name(ename), id(eid), projectHead(nullptr), next(nullptr) {}
};


class EmployeeProjectList {
private:
    Employee* head;

public:
    EmployeeProjectList() : head(nullptr) {}

    void addEmployee(string name, string id) {
        Employee* newEmployee = new Employee(name, id);
        newEmployee->next = head;
        head = newEmployee;
    }

    Employee* findEmployee(string id) {
        Employee* current = head;
        while (current) {
            if (current->id == id)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void addProjectToEmployee(string id, string projectName, int duration) {
        Employee* employee = findEmployee(id);
        if (employee) {
            Project* newProject = new Project(projectName, duration);
            newProject->next = employee->projectHead;
            employee->projectHead = newProject;
        }
    }

    void removeProjectFromEmployee(string id, string projectName) {
        Employee* employee = findEmployee(id);
        if (employee) {
            Project* current = employee->projectHead;
            Project* prev = nullptr;

            while (current) {
                if (current->name == projectName) {
                    if (prev)
                        prev->next = current->next;
                    else
                        employee->projectHead = current->next;
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    void display() {
        Employee* current = head;
        while (current) {
            cout << "Employee Name: " << current->name << ", ID: " << current->id << endl;
            Project* projectCurrent = current->projectHead;
            while (projectCurrent) {
                cout << "  Project Name: " << projectCurrent->name << ", Duration: " << projectCurrent->duration << " months" << endl;
                projectCurrent = projectCurrent->next;
            }
            current = current->next;
        }
    }

    ~EmployeeProjectList() {
        while (head) {
            Employee* temp = head;
            head = head->next;
            Project* projectHead = temp->projectHead;
            while (projectHead) {
                Project* tempProj = projectHead;
                projectHead = projectHead->next;
                delete tempProj;
            }
            delete temp;
        }
    }
};

int main() {
    EmployeeProjectList epList;

    // Add employees
    epList.addEmployee("Andi", "P001");
    epList.addEmployee("Budi", "P002");
    epList.addEmployee("Citra", "P003");

    epList.addProjectToEmployee("P001", "Aplikasi Mobile", 12);
    epList.addProjectToEmployee("P002", "Sistem Akuntansi", 8);
    epList.addProjectToEmployee("P003", "E-commerce", 10);

    epList.addProjectToEmployee("P001", "Analisis Data", 6);

    epList.removeProjectFromEmployee("P001", "Aplikasi Mobile");

    epList.display();

    return 0;
}
