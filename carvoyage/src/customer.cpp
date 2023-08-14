#include "../headers/main.h"
using namespace std;
void customer::bookcar() {
    ofstream write2;
    show();
    string CarBrand;
    cout << "Enter The Car Brand : ";
    cin >> CarBrand;
    cout << "For How Many Hours Do You Need The Car For : ";
    cin >> carrent;

    ifstream read;
    ofstream write, write_return;

    write.open("../handler/carfiles/temp.txt");
    write_return.open("../handler/receipt/return/return.txt", ios::app);
    read.open("../handler/carfiles/carlog.txt", ios::in);

    if (read.fail()) {
        cerr << "Unable to read the file\n";
        return;
    } else {
        while (read >> car_brand >> car_model >> car_numberp >> car_rent) {
            if (CarBrand == car_brand) {
                show_car();
                write_return << endl << car_brand << endl << car_model << endl << car_numberp << endl << car_rent;
                print();
            } else {
                write << endl << car_brand << endl
                      << car_model << endl
                      << car_numberp << endl
                      << car_rent;
            }
        }
        read.close();  // Close the file after reading
        write.close();
        write_return.close();
        remove("../handler/carfiles/carlog.txt");
        rename("../handler/carfiles/temp.txt", "../handler/carfiles/carlog.txt");
    }
}

void customer::print() {
    ofstream write;

    write.open("../handler/receipt/" + car_brand + ".txt");
    string arr2[3] = {"Model", "NumberPlate", "Rent"};
    write << string(40, '-') << endl;
    write << "||" << string(15, ' ') << car_brand << setw(23 - car_brand.length()) << right << "||" << endl;
    write << string(40, '-') << endl;
    for (int i = 0; i < 3; i++) {
        write << "||" << arr2[i] << setw(36 - arr2[i].length()) << right;
        if (i == 0) {
            write << car_model << "||" << endl;
        }
        if (i == 1) {
            write << car_numberp << "||" << endl;
        }
        if (i == 2) {
            write << car_rent << "||" << endl;
        }
    }
    write << string(40, '-') << endl;
    write << "Name   : " << setw(30) << right << name << endl;
    write << "Status : " << setw(30) << right << "Booked" << endl;
    write << "Price  : " << setw(30) << right << car_rent * carrent << endl;
    write << string(40, '-') << endl;
    write.close();
}

void customer::show_car() {
    ifstream rad;
    rad.open("../handler/receipt/return/return.txt", ios::in);
    if (rad.fail()) {
        cerr << "Unable to read the file\n";
    } else {
        cout << string(44, '-') << endl;
        cout << "||" << "Brand" << setw(10) << "Model" << setw(17) << right << "NumberPlate" << setw(8) << right << "Rent" << "||" << endl;
        cout << string(44, '-') << endl;
        while (rad >> car_brand >> car_model >> car_numberp >> car_rent) {
            cout << car_brand << setw(18 - car_brand.length()) << right << car_model << setw(15) << car_numberp << setw(10) << car_rent << endl;
        }
        cout << string(44, '-') << endl;
        rad.close();
    }
}

void customer::returncar() {
    ifstream of, rad;
    ofstream write, re;

    rad.open("../handler/receipt/return/return.txt");
    write.open("../handler/carfiles/temp.txt", ios::app);
    re.open("../handler/receipt/return/temp.txt", ios::app);

    show_car();
    string choice;
    cout << "Enter Car Brand to Return: ";
    cin >> choice;

    while (rad >> car_brand >> car_model >> car_numberp >> car_rent) {
        if (choice == car_brand) {
            cout << "Returning Car:" << endl;
            cout << "Car Brand: " << car_brand << endl;
            cout << "Car Model: " << car_model << endl;
            cout << "Car Number: " << car_numberp << endl;
            cout << "Car Rent: " << car_rent << endl;
            write << endl << car_brand
                 << endl << car_model
                 << endl << car_numberp
                 << endl << car_rent;
        } else {
            re << endl << car_brand
               << endl << car_model
               << endl << car_numberp
               << endl << car_rent;
        }
    }

    rad.close();
    write.close();
    re.close();

    remove("../handler/receipt/return/return.txt");
    rename("../handler/receipt/return/temp.txt", "../handler/receipt/return/return.txt");

    ifstream temp("../handler/carfiles/temp.txt");
    ofstream carlog("../handler/carfiles/carlog.txt", ios::app);

    carlog << temp.rdbuf();

    temp.close();
    carlog.close();

    cout << "Car with Brand " << choice << " returned." << endl;
}
