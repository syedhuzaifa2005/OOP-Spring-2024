#include <iostream>
#include <string>

using namespace std;

struct Event {
    string name;
    string date;
    string venue;
    string organizer;
};

void displayEvent(const Event& event) {
    cout << "Event Name: " << event.name << endl;
    cout << "Date: " << event.date << endl;
    cout << "Venue: " << event.venue << endl;
    cout << "Organizer: " << event.organizer << endl;
    cout << "------------------------" << endl;
}

int main() {
    int totalEvents;

    cout << "Enter the total number of events to manage: ";
    cin >> totalEvents;

    Event* events = new Event[totalEvents];

    for (int i = 0; i < totalEvents; ++i) {
        cout << "\nEnter details for Event " << i + 1 << ":" << endl;
        cout << "Event Name: ";
        cin.ignore();  
        getline(cin, events[i].name);

        cout << "Date: ";
        getline(cin, events[i].date);

        cout << "Venue: ";
        getline(cin, events[i].venue);

        cout << "Organizer: ";
        getline(cin, events[i].organizer);
    }

    cout << "\nAll Events:\n";
    for (int i = 0; i < totalEvents; ++i) {
        displayEvent(events[i]);
    }

    string searchDate;
    cout << "\nEnter the date to search events: ";
    cin.ignore();
    getline(cin, searchDate);

    cout << "\nEvents on " << searchDate << ":\n";
    bool found = false;
    for (int i = 0; i < totalEvents; ++i) {
        if (events[i].date == searchDate) {
            displayEvent(events[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "No events found on " << searchDate << endl;
    }

    delete[] events;

    return 0;
}