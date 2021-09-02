#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

class Alien {
private:
    //data members
    int weight;
    int height;
    char gender;

public:
    //constructor
    Alien(int w = 100, int h = 100, char g = 'm') {
        weight = w;
        height = h;
        gender = g;
    }

    //member functions
    int getWeight() {
        return weight;
    }

    int getHeight() {
        return height;
    }

    char getGender() {
        return gender;
    }

    int getPrestige() {
        //declaring prestige and genderPoints variables
        int prestige;
        int genderPoints = 0;

        //if statement to assign genderPoints based on Alien gender
        if (gender == 'f') {
            genderPoints = 3;
        }
        else if (gender == 'm') {
            genderPoints = 2;
        }

        //calculating prestige points
        prestige = height * weight * genderPoints;

        return prestige;
    }

    //overloaded operators
    //The + Operator will return a new Alien object with averaged measurements and randomized gender
    Alien operator+(const Alien& a) { //defining operator overload with Alien object parameter
        //declaring new alien object
        Alien alien;

        //setting height and weight to the average of the Alien operands
        alien.weight = (this->weight + a.weight) / 2;
        alien.height = (this->height + a.height) / 2;
        
        //determining random gender for offspring
        int genderNum = (rand() % 2 + 1);

        if (genderNum == 1) {
            alien.gender = 'm';
        }
        else {
            alien.gender = 'f';
        }

        //return new alien object
        return alien;
    }

    //The following relational and logical operators will be used to compare the prestige value of 2 aliens
    bool operator==(Alien& a) {
        if (this->getPrestige() == a.getPrestige()) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator!=(Alien& a) {
        if (this->getPrestige() != a.getPrestige()) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator<(Alien& a) {
        if (this->getPrestige() < a.getPrestige()) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator<=(Alien& a) {
        if (this->getPrestige() <= a.getPrestige()) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator>(Alien& a) {
        if (this->getPrestige() > a.getPrestige()) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator>=(Alien& a) {
        if (this->getPrestige() >= a.getPrestige()) {
            return true;
        }
        else {
            return false;
        }
    }
};

int randomMeasurement() { //function to randomly generate an integer value from 75-125
    int w = (rand() % 51 + 75);
    return w;
}

int main()
{
    //declaring and initializing alien objects
    srand((unsigned)time(0));
    Alien alien1(randomMeasurement(), randomMeasurement(), 'm');
    Alien alien2(randomMeasurement(), randomMeasurement(), 'f');
    Alien alien3(randomMeasurement(), randomMeasurement(), 'm');
    Alien alien4(randomMeasurement(), randomMeasurement(), 'f');

    //alien5 and alien6 left as defaults because they'll be defined using overloaded operators later
    Alien alien5;
    Alien alien6;

    //intro
    cout << "\n\tWelcome to this Alien Breeder Simulator!\n\n";
    cout << "\tThis simulator will randomly generate 2 Alien breeding pairs, and will then generate offspring using the data of those breeding Aliens.\n\n";
    cout << "\tLet's continue on to generate your Alien breeding pairs!\n\n\t";
    system("PAUSE");

    //display aliens 1-4
    cout << "\n\tPAIR 1\n\n";
    cout << "\tAlien 1\t\t\t\t\tAlien 2\n";
    cout << "\tHeight: " << alien1.getHeight() << "cm\t\t\t\tHeight: " << alien2.getHeight() << "cm" << endl;
    cout << "\tWeight: " << alien1.getWeight() << "kg\t\t\t\tWeight: " << alien2.getWeight() << "kg" << endl;
    cout << "\tGender: " << alien1.getGender() << "\t\t\t\tGender: " << alien2.getGender() << endl;

    cout << "\n\tPAIR 2\n\n";
    cout << "\tAlien 3\t\t\t\t\tAlien 4\n";
    cout << "\tHeight: " << alien3.getHeight() << "cm\t\t\t\tHeight: " << alien4.getHeight() << "cm" << endl;
    cout << "\tWeight: " << alien3.getWeight() << "kg\t\t\t\tWeight: " << alien4.getWeight() << "kg" << endl;
    cout << "\tGender: " << alien3.getGender() << "\t\t\t\tGender: " << alien4.getGender() << "\n\n\t";

    system("PAUSE");

    //calculating alien5 and alien6 using overloaded operators
    alien5 = alien1 + alien2;
    alien6 = alien3 + alien4;

    //display aliens 5 & 6
    cout << "\n\tCreated Alien 5 and Alien 6 as offspring\n\n";
    cout << "\tAlien 5\t\t\t\t\tAlien 6\n";
    cout << "\tHeight: " << alien5.getHeight() << "cm\t\t\t\tHeight: " << alien6.getHeight() << "cm" << endl;
    cout << "\tWeight: " << alien5.getWeight() << "kg\t\t\t\tWeight: " << alien6.getWeight() << "kg" << endl;
    cout << "\tGender: " << alien5.getGender() << "\t\t\t\tGender: " << alien6.getGender() << endl;
    cout << "\tPrestige: " << alien5.getPrestige() << "\t\t\t\tPrestige: " << alien6.getPrestige() << endl;

    //comparing aliens 5 and 6 using using overloaded operators
    cout.setf(ios::boolalpha); //this line is used to print boolean values as true/false as opposed to 1/0
    cout << "\n\tAlien 5 == Alien 6:\t" << (alien5 == alien6);
    cout << "\n\tAlien 5 != Alien 6:\t" << (alien5 != alien6);
    cout << "\n\tAlien 5 < Alien 6:\t" << (alien5 < alien6);
    cout << "\n\tAlien 5 <= Alien 6:\t" << (alien5 <= alien6);
    cout << "\n\tAlien 5 > Alien 6:\t" << (alien5 > alien6);
    cout << "\n\tAlien 5 >= Alien 6:\t" << (alien5 >= alien6);

    return 0;
}