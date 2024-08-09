#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string RollNumber,Name,FName,Address,search;
    fstream file;
    public:
    void addStudent();
    void viewStudent();
    void searchStudent();
}obj;

int main(){

    char choice;
    cout<<"---------------------------"<<endl;
    cout<<"1 -> Add Student Record"<<endl;
    cout<<"2 ->  View All The Students Record"<<endl;
    cout<<"3 -> Search Student Record"<<endl;
    cout<<"4 -> Exit"<<endl;
    cout<<"---------------------------"<<endl;
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.addStudent();
        break;
        case '2':
            cin.ignore();
            obj.viewStudent();
        break;
        case '3':
            cin.ignore();
            obj.searchStudent();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid Choice Entry!!!";
    }

}

void temp :: addStudent(){

    cout<<"Enter Student's Roll Number :: ";
    getline(cin,RollNumber);
    cout<<"Enter Student Name ::";
    getline(cin,Name);
    cout<<"Enter Student's Father Name ::";
    getline(cin,FName);
    cout<<"Enter Student Address ::";
    getline(cin,Address);

    file.open("stuData.txt",ios :: out | ios :: app);
    file<<RollNumber<<"*";
    file<<Name<<"*";
    file<<FName<<"*";
    file<<Address<<endl;
    file.close();
}

void temp :: viewStudent(){

    file.open("stuData.txt",ios :: in);
    getline(file,RollNumber,'*');
    getline(file,Name,'*');
    getline(file,FName,'*');
    getline(file,Address,'\n');
    while(!file.eof()){
        cout<<"\n";
        cout<<"Student Roll Number :: "<<RollNumber<<endl;
        cout<<"Student Name :: "<<Name<<endl;
        cout<<"Student's Father Name :: "<<FName<<endl;
        cout<<"Student Address :: "<<Address<<endl;

        getline(file,RollNumber,'*');
        getline(file,Name,'*');
        getline(file,FName,'*');
        getline(file,Address,'\n');
    }
    file.close();
}

void temp :: searchStudent(){

    cout<<"Enter Student Roll Number :: ";
    getline(cin,search);

    file.open("stuData.txt",ios :: in);
    getline(file,RollNumber,'*');
    getline(file,Name,'*');
    getline(file,FName,'*');
    getline(file,Address,'\n');
    while(!file.eof()){
        if(RollNumber == search){
            cout<<endl;
            cout<<"Student Roll Number :: "<<RollNumber<<endl;
            cout<<"Student Name :: "<<Name<<endl;
            cout<<"Student Father Name :: "<<FName<<endl;
            cout<<"Student Address :: "<<Address<<endl;
        }
        getline(file,RollNumber,'*');
        getline(file,Name,'*');
        getline(file,FName,'*');
        getline(file,Address,'\n');
    }
    file.close();
}
