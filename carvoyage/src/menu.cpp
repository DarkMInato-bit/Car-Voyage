#include "../headers/main.h"
using namespace std;
customer c1;
car_manage car1;
log l1;
string spacer(20,' ');
void logo() {
    ifstream inputFile("../art/art.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << "\n";
        }
        inputFile.close();
    } else {
        cerr << "Unable to open file:\n";
    }
}
menuLogics::menuLogics(){
    choice1();
}
void menuLogics::pauser(){
    std::cout << spacer<<"Press Enter to continue...";
    std::cin.get();
}
void menuLogics::menu(string arr[],int n){
        string line(43,'-');
        
        cout << spacer<<line << endl;
        cout << spacer<<"||" << string(10,' ')<<right <<"Welcome To Car Voyage" <<string(8,' ')<<"||" << endl;
        cout << spacer<<line << endl;
        for(int i=0; i<n; i++){
            cout << spacer<<i+1 << arr[i] << endl;
        }
        cout <<spacer<< line << endl;
}
void menuLogics::choice1(){
    do {
        system("clear||cls");
        logo();
        menu(arr, 3);
        cout << spacer;
        cin >> choice;
        switch (choice) {
            case 1:
                system("clear||cls");
                l1.login();
                if (l1.validaotr()) {
                    cin.ignore();
                    pauser();
                    choice2();
                    break;
                } else {
                    cin.ignore();
                    pauser();
                    choice3();
                    break;
                }
                break;
            case 2:
                system("clear||cls");
                l1.regis();
                cin.ignore();
                pauser();
                choice1();
                
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice. Please choose again." << endl;
                choice1();
                break;
        }
    }while (choice != 3);
    }
void menuLogics::choice2(){
        do {
        system("clear||cls");
        logo();
        menu(renter, 5);
        cout << spacer;
        cin >> choice;
        switch (choice) {
            case 1:
                cin.ignore();
                pauser();
                system("clear||cls");
                car1.add();
                break;
            case 2:
                cin.ignore();
                pauser();
                system("clear||cls");
                car1.removee();
                break;
            case 3:
                cin.ignore();
                pauser();
                system("clear||cls");
                car1.edit();
                break;
            case 4:
                cin.ignore();
                pauser();
                system("clear||cls");
                choice1();
            case 5:
                exit(0);
            default:
                cout <<spacer<< "Invalid choice. Please choose again." << endl;
                choice2();
                break;
        }
    }while (choice != 5);
    }
void menuLogics::choice3(){
        do {
        system("clear||cls");
        logo();
        menu(booker, 5);
        cout << spacer;
        cin >> choice;
        switch (choice) {
            case 1:
                cin.ignore();
                pauser();
                system("clear||cls");
                c1.bookcar();
                
                break;
            case 2:
                cin.ignore();
                pauser();
                system("clear||cls");
                c1.print();
                break;
            case 3:
                cin.ignore();
                pauser();
                system("clear||cls");
                c1.returncar();
                break;
            case 4:
                cin.ignore();
                pauser();
                system("clear||cls");
                choice1();
            case 5:
                exit(0);
            default:
                cout<<spacer << "Invalid choice. Please choose again." << endl;
                choice3();
                break;
        }
    }while (choice != 5);   
}
menuLogics::~menuLogics(){
    cout << "Ending Program :";
    pauser();
}