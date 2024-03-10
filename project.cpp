// //management system 
// add student
// view all the list of students
// search
// fs module // os bateen

#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string rollNum,name,fName,address,search;
    fstream file;
    public:
        void addStu();
        void viewStu();
        void searchStu();
        void updateStu();
        void deleteStu();
        void StuRecord();
        
} obj;

int main(){
    
    char choice;
    cout<<"---------------------------"<<endl;
    cout<<"1-Add student Record"<<endl;
    cout<<"2-view All students record"<<endl;
    cout<<"3-search Student From the Record"<<endl;
    cout <<"4-to update the record"<<endl;
    cout<<"5-to delete the record"<<endl;
    cout<<"6-to view total count of record"<<endl;
    cout<<"7-exit"<<endl;
    cout<<"----------------------------"<<endl;
    cin>>choice;
    
    switch(choice){
        case '1':
            cin.ignore();
            obj.addStu();
            break;
        
        case '2':
            cin.ignore();
            obj.viewStu();
            break;
        
        case '3':
            cin.ignore();
            obj.searchStu();
            break;
        
        case '4':
            cin.ignore();
            obj.updateStu();    
            break;
        
        case '5':
            cin.ignore();
            obj.deleteStu();
        
        case '6':
            cin.ignore();
            obj.StuRecord();
            
        case '7':
            return 0;
            break;
        
        default:
            cout<<"andha hai kya !!!!!"<<endl;
    }

}

void temp :: addStu(){
     cout<<"enter student ka Roll no."<<endl;
     getline(cin,rollNum);
     cout<<"enter student ka name"<<endl;
     getline(cin,name);
     cout<<"enter student ke baap ka name"<<endl;
     getline(cin,fName);
     cout<<"enter student ka ghar ka pta"<<endl;
     getline(cin,address);
     
     file.open("studentData.txt",ios :: out | ios :: app);
     file<<rollNum<<"*";
     file<<name<<"*";
     file<<fName<<"*";
     file<<address<<"\n";
     file.close();
    
}
void temp :: viewStu(){
    file.open("studentData.txt",ios :: in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    
    while(!file.eof()){
        cout<<"\n";
        cout<<"student ka roll number is "<<rollNum<<endl;
        cout<<"student ka nam is "<<name<<endl;
        cout<<"student ka baap ka naam is "<<fName<<endl;
        cout<<"student ka ghar ka pta is "<<address<<endl;
        
            getline(file,rollNum,'*');
            getline(file,name,'*');
            getline(file,fName,'*');
            getline(file,address,'\n');
    }
    file.close();//last entry is missing
}
void temp :: searchStu(){
    cout<<"Enter Student Roll Number to search "<<endl;
    getline(cin,search);
    
    file.open("studentData.txt",ios :: in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    
    while(!file.eof()){
        if(rollNum==search){
        cout<<endl;
        cout<<"student ka roll number is "<<rollNum<<endl;
        cout<<"student ka nam is "<<name<<endl;
        cout<<"student ka baap ka naam is "<<fName<<endl;
        cout<<"student ka ghar ka pta is "<<address<<endl;
        }
        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
    }
    file.close();
    
}
void temp :: updateStu(){
    cout<<"enter the roll number you want to update"<<endl;
    string updateRollNumber;
    getline(cin,updateRollNumber);
    
    file.open("studentData.txt",ios :: in);
    ofstream tempFile("tempStuData.txt");
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    
    while(!file.eof()){
        if(rollNum==updateRollNumber){
            cout<<"enter student ka name"<<endl;
            getline(cin,name);
            cout<<"enter student ke baap ka name"<<endl;
            getline(cin,fName);
            cout<<"enter student ka ghar ka pta"<<endl;
            getline(cin,address);
        }
        tempFile<<rollNum<<"*";
        tempFile<<name<<"*";
        tempFile<<fName<<"*";
        tempFile<<address<<endl;
        
        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
        
    }
    file.close();
    tempFile.close();
    
    remove("studentData.txt");
    rename("tempStuData.txt","studentData.txt");
    
    cout<<"record updated successfully!!!!"<<endl;
    

}

void temp :: deleteStu(){
    cout<<"enter the roll number you want to delete"<<endl;
    string deleteRollNumber;
    getline(cin,deleteRollNumber);
    
    file.open("studentData.txt",ios :: in);
    ofstream tempFile("tempStuData.txt");
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    
    while(!file.eof()){
        if(rollNum!=deleteRollNumber){
        tempFile<<rollNum<<"*";
        tempFile<<name<<"*";
        tempFile<<fName<<"*";
        tempFile<<address<<endl;
        }
        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
        
    }
    file.close();
    tempFile.close();
    
    remove("studentData.txt");
    rename("tempStuData.txt","studentData.txt");
    
    cout<<"record deleted successfully!!!!"<<endl;
}
void temp :: StuRecord(){
    int count=0;
    file.open("studentData.txt",ios :: in);
    while(!file.eof()){
        count++;
        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
    }
    file.close();
    cout<<"Number of Records are "<<count-1<<endl;
}









