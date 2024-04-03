#include <iostream>
using namespace std;

class Weapons{
public:
    string weaponsList[5] = {"Sword", "Axe", "Bow", "Staff", "Dagger"};

    string use() {
        cout << "Available weapons: ";
        for (int i = 0; i < 5; ++i) {
            cout << i+1 << ". " << weaponsList[i] << " ";
        }
        cout << endl;
        
        cout << "Choose a weapon from (1-5): ";
        int choice;
        cin >> choice;
        if(choice >= 1  &&  choice <= 5){
        	cout << "Using " << weaponsList[choice - 1] << endl;
        	return weaponsList[choice -1];
		} else{
			cout << "Invlid choice. Using Fists" << endl;
			return "Fists";
		}
    }
};

class Player{
protected:
	int playerID;
	string playerName;
	int Health;
public:
	Player(int ID, string Name){
		playerID = ID;
		playerName = Name;
		Health = 100;
	}
	
	int get_health() const{
	return Health;
	}
	
	void set_health(int health){
		Health = health;
	}
	
	virtual void displayPlayer(){
		cout << "Player ID: " << playerID << endl;
		cout << "Player Name: " << playerName << endl;
		cout << "Health: " << Health << endl;
	}	
};

class Character: public Player{
private:
	int Level;
	string Experience;
	int Points;
public:
	Character(int ID, string Name): Player(ID, Name){
		Level = 0;
		Experience = "Beginner";
		Points = 0;
	}
	
	void levelUp(){
		if(Points >= 10){
			Level++;
			if(Experience == "Beginner"){
				Experience = "Intermediate";
			}
			else if(Experience == "Intermediate"){
				Experience = "Advanced";
			}
			else if(Experience == "Advanced"){
				Experience = "Expert";
			}
		}
		cout << "Levelled Up!! " << " Experience: " << Experience << " New Level: " << Level << endl;
	}
	
	void playGame(Weapons &weapon, Player &enemy){
        string weaponUsed = weapon.use();
		cout << "Attacking the enemy" << endl;
		enemy.set_health(enemy.get_health() - 5);
		
		Points += 10;
		levelUp();
		displayPlayer();
		enemy.displayPlayer();
	}
};

class Enemy: public Player{
private:
	int Damage;
public:
	Enemy(int ID, string Name, int damage): Player(ID, Name){
		if(damage >= 1  &&  damage <= 10){
			Damage = damage;
		}
	}
	
	void attack(Player &character, const string &weaponName){
		cout << "Enemy attacks with " << weaponName << " causing " << Damage << " damage" << endl;
		character.set_health(character.get_health() - Damage);
        character.displayPlayer();
	}
};

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
	
	Character hero(4, "HERO");
	Enemy enemy(2, "VILLAIN", 3);
	Weapons weapon;

	do{
		hero.playGame(weapon, enemy); 
        if (enemy.get_health() <= 0) {
            cout << "ENEMY defeated! PLAYER Wins" << endl;
            break;
        }
        enemy.attack(hero, "Katana"); 
        if (hero.get_health() <= 0) {
            cout << "PLAYER defeated! ENEMY Wins" << endl;
            break;
        }
	} while(hero.get_health() > 0 && enemy.get_health() > 0);
}
