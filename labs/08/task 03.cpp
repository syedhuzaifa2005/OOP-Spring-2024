/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Position{
protected:
    float x;
    float y;
    float z;

public:
    Position(float a, float b, float c){
        x = a;
        y = b;
        z = c;
    }

    void displayPosition(){
        cout << "Postion: " << endl;
        cout << "X: " << x << "\t\tY: " << y << "\tZ: " << z << endl;
    }
};

class Health{
protected:
    int health;

public:
    Health(int h){
        health = h;
    }

    void displayHealth(){
        cout << "Health: " << health << endl;
    }
};

class Character: public Position, Health{
private:
    int Damage;
    string Name;

public:
    Character(float a, float b, float c, int h, int damage, string name): Position(a, b, c), Health(h){
        Damage = damage;
        Name = name;
    } 

    void displayCharacter(){
        cout << "Character: " << endl;
        cout << "Name: " << Name << endl;
        Health::displayHealth();
        cout << "Damage: " << Damage << endl;
        Position::displayPosition();
    }
};

int main(){
    Character hero(7.8, 39.45, -20.6, 500, 120, "Hero");
    hero.displayCharacter();
}
