/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Character{
protected:
    int Health;
    int Damage;

public:
    Character(int health, int damage){
        Health = health;
        Damage = damage;
    }

    void displayCharacter(){
        cout << "Character Details: " << endl;
        cout << "Health: " << Health << endl;
        cout << "Damage: " << Damage << endl;
    }
};

class Enemy: public Character{
public:
    Enemy(int health, int damage): Character(health, damage){

    }

    void displayEnemy(){
        cout << "Enemy: " << endl;
        Character::displayCharacter();
    }
};

class Player: public Character{
public:
    Player(int health, int damage): Character(health, damage){

    }

    void displayPlayer(){
        cout << "Player: " << endl;
        Character::displayCharacter();
    }
};

class Wizard: public Player{
private:
    int magicPower;
    string Spells;

public:
    Wizard(int health, int damage, int magicpower, string spells): Player(health, damage){
        magicPower = magicpower;
        Spells = spells;
    }

    void displayWizard(){
        cout << "Wizard: " << endl;
        Player::displayPlayer();
        cout << "Magic Power: " << magicPower << endl;
        cout << "Spells: " << Spells << endl;
    }
};

int main(){
    Wizard wizard(100, 50, 200, "Fireball, Ice Shard");
    wizard.displayWizard();
}