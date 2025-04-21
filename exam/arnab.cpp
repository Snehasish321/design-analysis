#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
#include<string>

using namespace std;

class Driver {
    public :
    int id ;
    string name ;
    float x , y ;
    bool available;

    Driver (int id , string name , float x , float y ) {
        this -> id = id ;
        this -> name = name ;
        this -> x = x ;
        this -> y = y ;
        this -> available = true ;
    }

    void display () {
        cout << "Driver ID : " << id << ", Name : " << name
            << ", Location : (" << x << "," << y << ")"
            << ", Available : " << (available ? "Yes" : "No") << endl;
    }
};

class Rider {
    public : 
    string name ;
    float x , y ;
    Rider (string name , float x , float y ) {
        this -> name = name ;
        this -> x = x ;
        this -> y = y ;
    }

    void display () {
        cout << "Rider : " << name << ", Location : (" << x << "," << y << ")" << endl;
    }
};

// RideMatching Service

