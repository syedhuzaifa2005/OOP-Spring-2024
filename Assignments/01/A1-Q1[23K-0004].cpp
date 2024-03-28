/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <limits>
#include <sstream>
using namespace std;

class Pet {
public:
    string name;

private:
    string species;
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    list<string> specialSkills;

public:
    // Parametrized constructor
    Pet(string petName, string petSpecies, list<string> petSkills)
        : name(petName), species(petSpecies), healthStatus("Healthy"), hungerLevel(0), happinessLevel(10), specialSkills(petSkills) {}

    // Display details function
    void displayPetDetails() const {
        cout << "PET DETAILS: " << endl;
        cout << "Pet Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Happiness Level: " << happinessLevel << endl;
        cout << "Special Skills: ";
        for (const string &skill : specialSkills) {
            cout << skill << " ";
        }
        cout << endl;
    }

    // Update happiness function
    void updateHappiness(string action) {
        if (action == "feed") {
            happinessLevel++;
            if (happinessLevel > 10) {
                happinessLevel = 10;
            }
        } else if (action == "ignore") {
            happinessLevel--;
            if (happinessLevel < 0) {
                happinessLevel = 0;
            }
        }
    }

    // Update health function
    void updateHealth() {
        if (hungerLevel < 5) {
            healthStatus = "Healthy";
        } else if (hungerLevel > 5 && hungerLevel <= 10) {
            healthStatus = "Sick";
        }
    }

    // Update hunger function
    void updateHunger(string action) {
        if (action == "feed") {
            hungerLevel--;
            if (hungerLevel < 0) {
                hungerLevel = 0;
            }
        } else if (action == "ignore") {
            hungerLevel++;
            if (hungerLevel > 10) {
                hungerLevel = 10;
            }
        }
    }

    // Action function
    void action(string action) {
        if (action == "feed") {
            updateHunger("feed");
            updateHappiness("feed");
        } else if (action == "ignore") {
            updateHunger("ignore");
            updateHappiness("ignore");
        }
        updateHealth();
    }
};

class Adopter {
public:
    string adopterName;
    long long int adopterMobileNum;
    list<Pet> adoptedPetRecords;

    // Parametrized constructor
    Adopter(string name, long long int mobileNum)
        : adopterName(name), adopterMobileNum(mobileNum) {}

    // Adopt pet function
    void adoptPet(string petName, string petSpecies, list<string> petSkills) {
        Pet newPet(petName, petSpecies, petSkills);
        adoptedPetRecords.push_back(newPet);
        cout << petName << " has been adopted by " << adopterName << endl;
    }

    // Return pet function
    void returnPet(string petName) {
        auto it = find_if(adoptedPetRecords.begin(), adoptedPetRecords.end(),
                          [petName](const Pet &pet) { return pet.name == petName; });

        if (it != adoptedPetRecords.end()) {
            adoptedPetRecords.erase(it);
            cout << petName << " has been returned by " << adopterName << endl;
        } else {
            cout << "Pet not found in the records of " << adopterName << endl;
        }
    }

    // Display all pets function
    void displayAllPets() const {
        cout << "ALL PETS: " << endl;
        for (const Pet &pet : adoptedPetRecords) {
            pet.displayPetDetails();
            cout << "---------------------------------------------" << endl;
        }
    }

    // Display adopted pets function
    void displayAdoptedPets() const {
        cout << adopterName << "'s ADOPTED PETS: " << endl;
        for (const Pet &pet : adoptedPetRecords) {
            pet.displayPetDetails();
            cout << "---------------------------------------------" << endl;
        }
    }
};

int main() {
    cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl << endl;

    Adopter adopter("Huzaifa", 123456789);

    cout << "Press 1 to adopt a pet" << endl;
    cout << "Press 2 to return a pet" << endl;
    cout << "Press 3 to display adopted pets" << endl;
    cout << "Press 4 to add a pet" << endl;
    cout << "Press 5 to interact with a pet" << endl;
    cout << "Press 6 to display all pets" << endl;
    cout << "Press 7 to exit" << endl;

    int choice;
    do {
        cin >> choice;
        switch (choice) {
        case 1: {
            string petName, petSpecies;
            list<string> petSkills;
            cout << "Enter pet name: ";
            cin >> petName;
            cout << "Enter pet species: ";
            cin >> petSpecies;
            cin.ignore(); 
            cout << "Enter pet skills (separated by spaces): ";
            string skillLine;
            getline(cin, skillLine);

            istringstream iss(skillLine);
            string skill;
            while (iss >> skill) {
                petSkills.push_back(skill);
            }

            adopter.adoptPet(petName, petSpecies, petSkills);
            break;
        }
        case 2: {
            // Return a pet
            string petName;
            cout << "Enter pet name to return: ";
            cin >> petName;
            adopter.returnPet(petName);
            break;
        }
        case 3: {
            adopter.displayAdoptedPets();
            break;
        }
        case 4: {
            string petName, petSpecies;
            list<string> petSkills;
            cout << "Enter pet name: ";
            cin >> petName;
            cout << "Enter pet species: ";
            cin >> petSpecies;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore(); 
            cout << "Enter pet skills (separated by spaces): ";
            string skillLine;
            getline(cin, skillLine);

            istringstream iss(skillLine);
            string skill;
            while (iss >> skill) {
                petSkills.push_back(skill);
            }

            Pet newPet(petName, petSpecies, petSkills);
            cout << "Pet '" << petName << "' has been added." << endl;
            break;
        }
        case 5: {
            string petName, action;
            cout << "Enter pet name to interact with: ";
            cin >> petName;
            cout << "Enter action ('feed' or 'ignore'): ";
            cin >> action;

            auto it = find_if(adopter.adoptedPetRecords.begin(), adopter.adoptedPetRecords.end(),
                              [petName](const Pet &pet) { return pet.name == petName; });

            if (it != adopter.adoptedPetRecords.end()) {
                it->action(action);
                cout << "Interaction with pet '" << petName << "' completed." << endl;
            } else {
                cout << "Pet not found in the records of " << adopter.adopterName << endl;
            }
            break;
        }
        case 6: {
            adopter.displayAllPets();
            break;
        }
        case 7: {
            exit(0);
            break;
        }
        default:
            cout << "Invalid input" << endl;
        }
    } while (choice != 7);

    return 0;
}

