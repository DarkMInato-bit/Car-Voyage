#include "../headers/main.h"
using namespace std;


void car::save(){
        write.open("../handler/carfiles/carlog.txt", ofstream::app);
        if(write.fail()){
            cerr << "Unable To Write to file\n";
            exit(9);
        }else{
            write<<car_brand<<endl
            <<car_model<<endl
            <<car_numberp<<endl
            <<car_rent<<endl;
        }
        cout << "File Data Saved: \n";
        write.close();
    }
void car::show_car(){
        string arr2[3]= {"1.Model","NumberPlate","Rent"};
        cout <<string(40,'-')<<endl;
        cout <<"||"<<string(15,' ')<<car_brand<<setw(23-car_brand.length())<<right<<"||"<<endl;
        cout <<string(40,'-')<<endl;
        for(int i=0;i<3;i++)
        {
            cout <<"||"<<arr2[i]<<setw(36-arr2[i].length())<<right;
            if(i==0){
                cout << car_model<<"||"<<endl;
            }
            if(i==1){
                cout << car_numberp<<"||"<<endl;
            }if(i==2){
                cout << car_rent<<"||"<<endl;
            }
        }
        cout << string(40,'-')<<endl;
    }
void car::show() {
    read.open("../handler/carfiles/carlog.txt", ios::in);
    if (read.fail()) {
        cerr << "Unable to read the file\n";
    }
    else {
        cout <<string(44,'-')<<endl;
        cout <<"||"<<"Brand"<<setw(10)<<"Model"<<setw(17)<<right<<"NumberPlate"<<setw(8)<<right<<"Rent"<<"||"<<endl;
        cout <<string(44,'-')<<endl;
        while(read >> car_brand >> car_model >> car_numberp >> car_rent){
        cout << car_brand << setw(18-car_brand.length())<<right<<car_model << setw(15)<<car_numberp <<setw(10) << car_rent<<endl;
        }
        cout <<string(44,'-')<<endl;
        read.close();
    }
}
void car_manage::add(){
    cout << "Enter Brand Of The Car: ";
    cin >> car_brand;
    cout << "Enter Model of the Car: ";
    cin >>car_model;
    cout << "Enter NumberPlate Of the Car: ";
    cin >> car_numberp;
    cout << "Enter The Amount You WAnt TO Rent YOur Car At: ";
    cin >> car_rent;
    save();
}
void car_manage::removee(){
    show();
    cout << "Enter The Brand of The Car You Want To Delete: ";
    string choice;
    cin >> choice;
    write.open("../handler/carfiles/temp.txt",ios::out);
    read.open("../handler/carfiles/carlog.txt",ios::in);
    if(read.fail()){
        cerr << "Unable to read the file\n";
    }
    else{
        while(read >> car_brand >>car_model >> car_numberp >> car_rent){
            if(choice != car_brand){
                write<<car_brand<<endl
                <<car_model<<endl
                <<car_numberp<<endl
                <<car_rent<<endl;
            }
        }
    }
    read.close();
    write.close();
    remove("../handler/carfiles/carlog.txt");
    rename("../handler/carfiles/temp.txt","../handler/carfiles/carlog.txt");    
    system("clear");
    show();
    cout << "Successfully Deleted " << choice << endl;
}
void car_manage::edit(){
    string brand,model,plate;
    int rent;
    show();
    cout << "Enter The Brand of The Car You Want To Edit: ";
    cin >> brand;
    cout << "Update The Model:";
    cin >> model;
    cout << "Update The NumberPlate: ";
    cin >> plate;
    cout << "Update The Rent Price: ";
    cin >> rent;
    write.open("../handler/carfiles/temp.txt",ios::out);
    read.open("../handler/carfiles/carlog.txt",ios::in);
    if(read.fail()){
    cerr << "Unable to read the file\n";
    }
    else{
    while(read >> car_brand >>car_model >> car_numberp >> car_rent){
        if(brand != car_brand){
        write<<car_brand<<endl
        <<car_model<<endl
        <<car_numberp<<endl
        <<car_rent<<endl;
    }else{
        write<<brand<<endl
        <<model<<endl
        <<plate<<endl
        <<rent<<endl;
        }
    }
}
    read.close();
    write.close();
    std::remove("../handler/carfiles/carlog.txt");
    rename("../handler/carfiles/temp.txt","../handler/carfiles/carlog.txt");    
    system("clear");
    show();
    cout << "Successfully Edited " << brand << endl;
}