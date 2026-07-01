#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void registerUser(){
    string username,password;
    cout<<"Enter username:";
cin>>username;

cout<<"Enter Password:";
cin>>password;

ifstream checkfile(username +".txt");

if(checkfile){
    cout<<"Username already exist!\n";
    checkfile.close();
    return;
}
checkfile.close();

ofstream file(username +".txt");
file<<password;

cout<<"Registration successfully\n";

}
void loginUser(){
    string username,password,storedPassword;
cout<<"\nEnter username:";
cin>>username;
cout<<"Enter password:";
cin>>password; 

ifstream file(username +".txt");

if(!file){
    cout<<"User not found!\n";
    return;

}
getline(file,storedPassword);
file.close();

if(password == storedPassword){
    cout<<"login Successful!\n";

}else{
    cout<<"incorrect password!\n";
}

}int main(){
    int choice;
    do {
        cout<<"\n===== Login Systeam =====\n";
        cout<<"1.register\n";
        cout<<"2.login\n";
        cout<<"3.Exit\n";
        cout<<"Enter Choice:";
        cin>>choice;

        switch(choice){
case 1:
registerUser();
break;

case 2:
loginUser();
break;

case 3:
cout<<"thank you!\n";
break;

default:
cout<<"invalid Choice!\n";
        }
        
    }while(choice!=3);
    return 0;
}