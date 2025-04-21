#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <string>
using namespace std;

// Class for Driver
class Driver {
public:
    int id;
    string name;
    float x, y; // location
    bool available;

    Driver(int id, string name, float x, float y) {
        this->id = id;
        this->name = name;
        this->x = x;
        this->y = y;
        this->available = true;
    }

    void display() {
        cout << "Driver ID: " << id << ", Name: " << name
             << ", Location: (" << x << "," << y << ")"
             << ", Available: " << (available ? "Yes" : "No") << endl;
    }
};

// Class for Rider
class Rider {
public:
    string name;
    float x, y;

    Rider(string name, float x, float y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }

    void display() {
        cout << "Rider: " << name << ", Location: (" << x << "," << y << ")" << endl;
    }
};

// RideMatching Service
class RideService {
private:
    vector<Driver> drivers;

    float calculateDistance(float x1, float y1, float x2, float y2) {
        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }

public:
    void addDriver(int id, string name, float x, float y) {
        drivers.push_back(Driver(id, name, x, y));
    }

    void displayAllDrivers() {
        cout << "\n--- List of Drivers ---\n";
        for (auto &d : drivers) {
            d.display();
        }
    }

    void requestRide(Rider rider) {
        float minDistance = numeric_limits<float>::max();
        int matchedIndex = -1;

        for (int i = 0; i < drivers.size(); i++) {
            if (drivers[i].available) {
                float dist = calculateDistance(rider.x, rider.y, drivers[i].x, drivers[i].y);
                if (dist < minDistance) {
                    minDistance = dist;
                    matchedIndex = i;
                }
            }
        }

        if (matchedIndex != -1) {
            cout << " Ride Matched! Nearest Driver:\n";
            drivers[matchedIndex].display();
            drivers[matchedIndex].available = false; // mark driver as busy
        } else {
            cout << " Sorry, no available drivers found.\n";
        }
    }

    void makeDriverAvailable(int id) {
        for (auto &d : drivers) {
            if (d.id == id) {
                d.available = true;
                cout << "Driver ID " << id << " is now available again.\n";
                return;
            }
        }
        cout << "Driver ID not found.\n";
    }
};

// ----------------- Main -----------------
int main() {
    RideService app;

    // Sample drivers added to system
    app.addDriver(1, "Rahul", 1.0, 2.0);
    app.addDriver(2, "Anjali", 4.5, 6.3);
    app.addDriver(3, "Vikram", 2.1, 1.5);

    int choice;
    while (true) {
        cout << "\n---- CAB RIDE SERVICE ----\n";
        cout << "1. Show All Drivers\n";
        cout << "2. Request a Ride\n";
        cout << "3. Make Driver Available Again\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            app.displayAllDrivers();
        } else if (choice == 2) {
            string rName;
            float rx, ry;
            cout << "Enter Rider Name: ";
            cin >> rName;
            cout << "Enter Rider Location (x y): ";
            cin >> rx >> ry;

            Rider rider(rName, rx, ry);
            app.requestRide(rider);
        } else if (choice == 3) {
            int id;
            cout << "Enter Driver ID to make available: ";
            cin >> id;
            app.makeDriverAvailable(id);
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
