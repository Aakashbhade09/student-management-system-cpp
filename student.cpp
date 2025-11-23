#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<limits>
#include <algorithm>
using namespace std;

// Text Color functions
void Red ()          {   cout<<"\033[1;31m";   }
void Yellow()        {   cout<<"\033[1;33m";   }
void Blue()          {   cout<<"\033[0;34m";   }
void Green()         {   cout<<"\033[0;32m";   }
void Purple()        {   cout<<"\033[0;35m";   }
void White()         {   cout<<"\033[0;37m";   }
void Cyan()          {   cout<<"\033[0;36m";   }
void ResetTextColor(){   cout<<"\033[0m";      }


struct studentData  {
    string name;
    string rollNo;
    string branch;
    string course;
    string emailId;

    void printStudentData() {
        Purple();
        cout<<endl;
        cout<<"Student Name    : "<<name<<endl;       
        cout<<"Student RollNo  : "<<rollNo<<endl;
        cout<<"Student Branch  : "<<branch<<endl;
        cout<<"Student Course  : "<<course<<endl;
        cout<<"Student EmailId : "<<emailId<<endl;
        cout<<"---------------------------------"<<endl<<endl;
        ResetTextColor();
    }
};

class studentManagementSystem {
private:
    vector<studentData> listOfStudents;

protected:
    string fileName;
    void readStudentsRecordFromFile();
    void storeStudentRecordInFile();

public:
    void mainMenu();
    void addStudentData();
    void displayStudentRecords();
    void searchStudentUsingRollNo();
    void editStudentRecord();
    void deleteStudentRecord();
};

void studentManagementSystem::readStudentsRecordFromFile() {
    listOfStudents.clear();

    ifstream fin(fileName);
    studentData record;

    if (fin.is_open()) {
        while (
            getline(fin, record.name) &&
            getline(fin, record.rollNo) &&
            getline(fin, record.branch) &&
            getline(fin, record.course) &&
            getline(fin, record.emailId)
        ) {
            listOfStudents.push_back(record);
        }
        fin.close();        
    } else  {
        Red();
        cout<<"File "<<fileName<<" not found!"<<endl;
        ResetTextColor();
    }
}

void studentManagementSystem::storeStudentRecordInFile() {
    ofstream fout(fileName);
    if (fout.is_open()) {
        for(auto &record : listOfStudents) {
            fout<<record.name<<"\n";
            fout<<record.rollNo<<"\n";
            fout<<record.branch<<"\n";
            fout<<record.course<<"\n";
            fout<<record.emailId<<"\n";
        }
        fout.close();
    } else {
        Red();
        cout<<"Error: Unable to open file!"<<endl;
        ResetTextColor();
    }
}

void studentManagementSystem::mainMenu() {
    int choice;
    readStudentsRecordFromFile();

    while (true) {
        Yellow();
        cout<<"-------------------------------------"<<endl;
        cout<<"Enter 1 For Add Student"<<endl;
        cout<<"Enter 2 For Print all Student Records"<<endl;
        cout<<"Enter 3 For Search Student"<<endl;
        cout<<"Enter 4 For Edit Student Record"<<endl;
        cout<<"Enter 5 For Delete Student Record"<<endl;
        cout<<"Enter 6 For Logout"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        ResetTextColor();

        system("cls");

        switch (choice) {
            case 1: addStudentData(); break;
            case 2: displayStudentRecords(); break;
            case 3: searchStudentUsingRollNo(); break;
            case 4: editStudentRecord(); break;
            case 5: deleteStudentRecord(); break;
            case 6: storeStudentRecordInFile(); return;
            default: cout<<"Enter valid choice!"<<endl;
        }
    }
}

void studentManagementSystem::addStudentData() {
    studentData inputData;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<endl<<"--------------------------------"<<endl;
    cout<<"Enter Student Name    : ";
    getline(cin, inputData.name);
    cout<<"Enter Student rollNo  : ";
    getline(cin, inputData.rollNo);
    cout<<"Enter Student branch  : ";
    getline(cin, inputData.branch);
    cout<<"Enter Student course  : ";
    getline(cin, inputData.course);
    cout<<"Enter Student emailId : ";
    getline(cin, inputData.emailId);
    cout<<"--------------------------------"<<endl;

    listOfStudents.push_back(inputData);
}

void studentManagementSystem::displayStudentRecords() {
    if(listOfStudents.empty()) {
        Red();
        cout<<"|----------------------------------|"<<endl;
        cout<<"| Student DataBase is Empty        |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        ResetTextColor();
    } else {
        int count = 1;
        for(auto &Data : listOfStudents) {
            cout<<"Record No : "<<count++<<endl;
            Data.printStudentData();
        }
    }
}

void studentManagementSystem::searchStudentUsingRollNo() {
    string rollNo;
    bool found = false;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter Student rollNo : ";
    getline(cin, rollNo);

    for(auto &data : listOfStudents) {
        if(data.rollNo == rollNo) {
            data.printStudentData();
            found = true;
            break;
        }
    }

    if(!found) {
        Red();
        cout<<"|----------------------------------|"<<endl;
        cout<<"| Student Not Found                |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        ResetTextColor();
    }
}

void studentManagementSystem::editStudentRecord() {
    string rollNo;
    bool found = false;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter Student rollNo : ";
    getline(cin, rollNo);

    for(int x=0; x<listOfStudents.size(); x++) {
        if(listOfStudents[x].rollNo == rollNo) {
            cout<<"Enter Name      : ";
            getline(cin, listOfStudents[x].name);
            cout<<"Enter Branch    : ";
            getline(cin, listOfStudents[x].branch);
            cout<<"Enter Email Id  : ";
            getline(cin, listOfStudents[x].emailId);

            found = true;
            break;
        }
    }

    if(!found) {
        Red();
        cout<<"Record Not Found!"<<endl;
        ResetTextColor();
    }
}

void studentManagementSystem::deleteStudentRecord() {
    string rollNo;
    bool found = false;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter Student rollNo : ";
    getline(cin, rollNo);

    for(auto it = listOfStudents.begin(); it != listOfStudents.end(); it++) {
        if(it->rollNo == rollNo) {
            listOfStudents.erase(it);
            Red();
            cout<<"Record Deleted Successfully!"<<endl;
            ResetTextColor();
            found = true;
            break;
        }
    }
    
    if(!found) {
        Red();
        cout<<"Record Not Found!"<<endl;
        ResetTextColor();
    }
}

class Authentication : public studentManagementSystem {
private:
    string userName, password, fullName, emailId;

public:
    void login() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string uName, pass;

        cout<<"Login Tab....!"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Enter Username : ";
        getline(cin, uName);

        ifstream fin(uName + ".txt");

        if(fin.is_open()) {
            getline(fin, fullName);
            getline(fin, emailId);
            getline(fin, userName);
            getline(fin, password);
            fin.close();

            cout<<"Enter Password : ";
            getline(cin, pass);

            if(pass == password) {

                string f = fullName;
                replace(f.begin(), f.end(), ' ', '-');
                fileName = f + "01.txt";

                ifstream check(fileName);
                if(!check.is_open()) {
                    ofstream make(fileName);
                    make.close();
                }

                mainMenu();
            }
            else cout<<"Invalid Password!"<<endl;
        }
        else {
            cout<<"Wrong Username!"<<endl;
        }
    }

    void registration() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Registration Tab....!"<<endl;
        cout<<"--------------------------"<<endl;

        cout<<"Enter Full Name : ";
        getline(cin, fullName);
        cout<<"Enter Email Id  : ";
        getline(cin, emailId);
        cout<<"Enter Username  : ";
        getline(cin, userName);
        cout<<"Enter Password  : ";
        getline(cin, password);

        ofstream fout(userName + ".txt");

        if(fout.is_open()) {
            fout<<fullName<<"\n";
            fout<<emailId<<"\n";
            fout<<userName<<"\n";
            fout<<password<<"\n";
            fout.close();

            string file = fullName;
            replace(file.begin(), file.end(), ' ', '-');
            file += "01.txt";
            ofstream fout2(file);
            fout2.close();

            system("cls");
            Green();
            cout<<"Registration Successful!"<<endl;
            ResetTextColor();
        }
    }
};

int main() {
    Authentication a1;
    int choice;

    while (true) {
        cout<<"-------------------------------"<<endl;
        cout<<"Enter 1 For Login"<<endl;
        cout<<"Enter 2 For Registration"<<endl;
        cout<<"Enter 3 For Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        system("cls");

        switch (choice) {
            case 1: a1.login(); break;
            case 2: a1.registration(); break;
            case 3: exit(0);
            default: cout<<"Enter valid choice!"<<endl;
        }
    }
}


