#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Abstract Base Class
class Person
{
protected:
    int id;
    string name;
    string phone;

public:
    Person(int id, string name, string phone);
    virtual void display() const = 0;
    virtual ~Person();
};

// Driver Class
class Driver : public Person
{
private:
    string licenseNumber;
    bool available;

public:
    Driver(int id, string name, string phone,
           string licenseNumber);

    void display() const override;

    bool isAvailable() const;
    void setAvailable(bool status);

    string getName() const;
    int getId() const;
};

// Ambulance Class
class Ambulance
{
private:
    int id;
    string vehicleNumber;
    string type;
    bool available;

public:
    Ambulance(int id, string vehicleNumber, string type);

    void display() const;

    bool isAvailable() const;
    void setAvailable(bool status);

    int getId() const;
    string getVehicleNumber() const;
    string getType() const;
};

// Emergency Class
class Emergency
{
protected:
    int id;
    string patientName;
    string location;
    int severity;

public:
    Emergency(int id, string patientName,
              string location, int severity);

    virtual void display() const;
    virtual ~Emergency();

    int getId() const;
    int getSeverity() const;
    string getLocation() const;
};

// Critical Emergency Class
class CriticalEmergency : public Emergency
{
private:
    string condition;

public:
    CriticalEmergency(int id, string patientName,
                      string location, int severity,
                      string condition);

    void display() const override;
};

// Hospital Class
class Hospital
{
private:
    int id;
    string name;
    string location;
    int availableBeds;

public:
    Hospital(int id, string name, string location,
             int availableBeds);

    void display() const;

    int getId() const;
    string getName() const;
    string getLocation() const;

    int getAvailableBeds() const;
    void setAvailableBeds(int beds);
};

#endif