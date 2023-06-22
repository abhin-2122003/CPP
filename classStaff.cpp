/*30. An educational institution wishes to maintain a database of its employees. The database is
divided into a number of classes whose hierarchical relationships are shown in the following
figure.The figure also shows the minimum information required for each class. Specify all the classes
and define functions to create the database and retrieve individual information as and when
required.*/

#include <iostream>
#include <string>

using namespace std;

class Staff {
protected:
    string name;
    int eID;

public:
    Staff() : name(""), eID(0) {}
    Staff(const string& name, int eID) : name(name), eID(eID) {}

    void readInfo() {
        cout << "Name: ";
        cin >> name;
        cout << "Employee ID: ";
        cin >> eID;
    }

    virtual void dispInfo() {
        cout << "Employee ID: " << eID << endl
             << "Employee Name: " << name << endl;
    }

    int getID(){
        return eID;
    }
};

class Teacher : public Staff {
    string sub;

public:
    Teacher() : Staff(), sub("") {}
    Teacher(const string& name, int eID, const string& sub) : Staff(name, eID), sub(sub) {}

    void readInfo() {
        Staff::readInfo();
        cout << "Subject: ";
        cin >> sub;
    }

    void dispInfo() override {
        Staff::dispInfo();
        cout << "Employee Type: Teacher" << endl
             << "Subject: " << sub << endl << endl;
    }
};

class Typist : public Staff {
protected:
    int typSpeed;

public:
    Typist() : Staff(), typSpeed(0) {}
    Typist(const string& name, int eID, int typSpeed) : Staff(name, eID), typSpeed(typSpeed) {}

    void readInfo() {
        Staff::readInfo();
        cout << "Typing Speed: ";
        cin >> typSpeed;
    }

    void dispInfo() {
        Staff::dispInfo();
        cout << "Typing Speed: " << typSpeed << endl
             << "Employee Type: Typist";
    }
};

class Officer : public Staff {
    string pos;

public:
    Officer() : Staff(), pos("") {}
    Officer(const string& name, int eID, const string& pos) : Staff(name, eID), pos(pos) {}

    void readInfo() {
        Staff::readInfo();
        cout << "Position: ";
        cin >> pos;
    }

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type: Officer" << endl
             << "Position: " << pos << endl << endl;
    }
};

class Regular : public Typist {
public:
    Regular() : Typist() {}
    Regular(const string& name, int eID, int typSpeed) : Typist(name, eID, typSpeed) {}

    void readInfo(){
        Typist::readInfo();
    }

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Regular" << endl << endl;
    }
};

class Casual : public Typist {
    float Dwages;

public:
    Casual() : Typist(), Dwages(0.0) {}
    Casual(const string& name, int eID, int typSpeed, float Dwages)
        : Typist(name, eID, typSpeed), Dwages(Dwages) {}

    void readInfo(){
        Typist::readInfo();
        cout<<"Daily Wages : RS ";
        cin>>Dwages;
    }

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Casual" << endl
             << "Daily Wages: " << Dwages << " RS/-" << endl << endl;
    }
};

Staff* SearchEmp(int SearchID,Staff* employees , int totalSize){

    for(int i=0 ;i<totalSize ;i++){

        if(employees[i].getID() == SearchID){
            return &employees[i];
        }
    }
    return nullptr;
}

int main() {
    int nt, no, ntr, ntc;
    cout << "Enter the number of teachers: ";
    cin >> nt;
    cout << "Enter the number of officers: ";
    cin >> no;
    cout << "Enter the number of regular typists: ";
    cin >> ntr;
    cout << "Enter the number of casual typists: ";
    cin >> ntc;

    Regular* R = new Regular[ntr];
    Casual* C = new Casual[ntc];
    Officer* O = new Officer[no];
    Teacher* T = new Teacher[nt];

    for (int i = 0; i < nt; i++) {
        cout << "\n\nEnter Teacher " << (i + 1) << " details:" << endl;
        T[i].readInfo();
    }

    for (int i = 0; i < ntr; i++) {
        cout << "\n\nEnter Regular Typist " << (i + 1) << " details:" << endl;
        R[i].readInfo();
    }

    for (int i = 0; i < ntc; i++) {
        cout << "\n\nEnter Casual Typist " << (i + 1) << " details:" << endl;
        C[i].readInfo();
    }

    for (int i = 0; i < no; i++) {
        cout << "\n\nEnter Officer " << (i + 1) << " details:" << endl;
        O[i].readInfo();
    }

    int totalSize = nt + no + ntr + ntc;

    // Create an array to store all employees
    employees = new[totalSize];

    int empIndex = 0;
    // Copy all teachers to the employees array
    for (int i = 0; i < nt; i++) {
        employees[empIndex] = T[i];
        empIndex++;
    }

    // Copy all officers to the employees array
    for (int i = 0; i < no; i++) {
        employees[empIndex] = O[i];
        empIndex++;
    }

    // Copy all regular typists to the employees array
    for (int i = 0; i < ntr; i++) {
        employees[empIndex] = R[i];
        empIndex++;
    }

    //Copy all casual typist to the employees array
    for(int i = 0 ; i< ntc; i++){
        employees[empIndex] = C[i];
        empIndex++;
    }
    int terminate = 0;
    
    do{

    int SearchID;
    cout<<"Please enter the Employee ID to retrieve information : ";
    cin>>SearchID;

    Staff* employee = SearchEmp(SearchID,employees,totalSize);

    if(employee){
        cout<<"Employee Found!"<<endl;
        employee->dispInfo();
    }else{
        cout<<"Employee not Found!"<<endl;
    }

    
    cin>>terminate;
    }while(terminate != 9);

    return 0;
}
