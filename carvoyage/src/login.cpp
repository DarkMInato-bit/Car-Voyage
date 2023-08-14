#include "../headers/main.h"
#include <conio.h>
using namespace std;

bool log::validaotr(){
    bool vali;
    if(role == "Renter"){
        vali=true;
    }else{
        vali=false;
    }
    return vali;
}

void log::regis(){
    system("clear||cls");
    int rle;
    regist:
    cout << "Enter Your UserName : ";
    cin >> name;
    cout << "Enter Your Password : ";
    cin >> password;
    cout << "Enter How You Want To Register \n1.User\n2.Renter\n";
    cin >>rle;
    if(rle > 2 || rle <0){
        cout << "Wrong Choice\n";
        goto regist;
    }else{
        if(rle == 1){
            role = "User";
        }else if(rle == 2){
            role = "Renter";
        }
    }
    saving();
}
void log::saving(){
    ofstream sav;
    sav.open("../handler/log/"+name+".txt");
    sav<<name << endl <<password << endl<<role;
    sav.close();
    cout << "Information Saved:\n";
}
void log::print(){
    cout << string(43,'-')<<endl;
    cout << "|| Username : "<<string(23,'-') << name;
    cout << "|| Password : "<<string(23,'-') << password;
    cout << "|| Role : "<<string(27,'-') << role;
    cout << string(43,'-')<<endl;
}
void log::login(){
    ifstream ldata;
    string pass,uname;
    cin.ignore();
    cout << "Enter UserName : ";
    cin >> uname;
    cout << "Enter Password : ";
    cin >> pass;
    int found=0;
    ldata.open("../handler/log/"+uname+".txt");
    if(!ldata.is_open()){
        cerr << "File not Found\n";
        cout << "Press Enter to Register:";
        cin.ignore();
        cin.get();
        regis();
    }else{
   while(ldata >> name >> password >> role){
            if(name == uname){
                if(pass == password){
                    found++;
                    break;
                }else{
                    cout << "Wrong Password:";
                    login();
                }
            }else{
                found=0;
            }
        }
        if(found == 0){
            cout << "Wrong Username: \n";
            cout << "Try Again : ";
            sleep(1000);
            system("pause");
            login();
        }
    }
}