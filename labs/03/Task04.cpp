/*
Programmer: Syed Huzaifa Ali
Roll no: 23K-0004
Description: implementation of smart phone 
*/

#include <iostream>
#include <string>

using namespace std;


class Smartphone{
private:
    string Brand;
    string Model;
    string DisplayResolution;
    int RAM;
    int ROM;
    int Storage;

public:
    string getBrand(){
        return Brand;
    }
    string getModel(){
        return Model;
    }
    string getDisplayResolution(){
        return DisplayResolution;
    }
    int getRAM(){
        return RAM;
    }
    int getROM(){
        return ROM;
    }
    int getStorage(){
        return Storage;
    }

    void setBrand(string brand){
        Brand = brand;
    }
    void setModel(string model){
        Model = model;
    }
    void setDisplayResolution(string Resolution){
        DisplayResolution = Resolution;
    }
    void setRAM(int ram){
        RAM = ram;
    }
    void setROM(int rom){
        ROM = rom;
    }
    void setStorage(int storage){
        Storage = storage;
    }

    void Call(string Name){
        cout << "Calling " << Name << endl;
    }
    void Message(string Name){
        cout << "Message sent to " << Name << endl;
    }
    void Wifi(string Network){
        cout << "Connecting to " << Network << endl;
    }
    void Browsing(string Website){
        cout << "Searching for " << Website << endl;
    }

    void DisplayDetails(){
        cout << "Brand: " << Brand << endl;
        cout << "Model: " << Model << endl;
        cout << "Display Resolution: " << DisplayResolution << endl;
        cout << "RAM: " << RAM << "GB" << endl;
        cout << "ROM: " << ROM << "GB" << endl;
        cout << "Storage: " << Storage << "GB" << endl;
    }
};

int main(){
    Smartphone Android;

    Android.setBrand("Oppo");
    Android.setModel("F21 Pro");
    Android.setDisplayResolution("1080 x 2400");
    Android.setRAM(8);
    Android.setROM(128);
    Android.setStorage(256);

    Android.DisplayDetails();
}