#include "classes.h"

// Person
Person::Person(int id, string name, string phone)
    : id(id), name(name), phone(phone) {}

Person::~Person() {}

// Driver
Driver::Driver(int id, string name, string phone,
               string licenseNumber)
    : Person(id, name, phone),
      licenseNumber(licenseNumber),
      available(true) {}

void Driver::display() const
{
    cout << "Driver ID: " << id
         << "\nName: " << name
         << "\nPhone: " << phone
         << "\nLicense: " << licenseNumber
         << "\nAvailable: "
         << (available ? "Yes" : "No")
         << "\n";
}

bool Driver::isAvailable() const
{
    return available;
}

void Driver::setAvailable(bool status)
{
    available = status;
}

string Driver::getName() const
{
    return name;
}

int Driver::getId() const
{
    return id;
}

// Ambulance
Ambulance::Ambulance(int id, string vehicleNumber,
                     string type)
    : id(id), vehicleNumber(vehicleNumber),
      type(type), available(true) {}

void Ambulance::display() const
{
    cout << "Ambulance ID: " << id
         << "\nVehicle Number: " << vehicleNumber
         << "\nType: " << type
         << "\nAvailable: "
         << (available ? "Yes" : "No")
         << "\n";
}

bool Ambulance::isAvailable() const
{
    return available;
}

void Ambulance::setAvailable(bool status)
{
    available = status;
}

int Ambulance::getId() const
{
    return id;
}

string Ambulance::getVehicleNumber() const
{
    return vehicleNumber;
}

string Ambulance::getType() const
{
    return type;
}

// Emergency
Emergency::Emergency(int id, string patientName,
                     string location, int severity)
    : id(id), patientName(patientName),
      location(location), severity(severity) {}

void Emergency::display() const
{
    cout << "Emergency ID: " << id
         << "\nPatient: " << patientName
         << "\nLocation: " << location
         << "\nSeverity: " << severity
         << "\n";
}

Emergency::~Emergency() {}

int Emergency::getId() const
{
    return id;
}

int Emergency::getSeverity() const
{
    return severity;
}

string Emergency::getLocation() const
{
    return location;
}

// CriticalEmergency
CriticalEmergency::CriticalEmergency(
    int id, string patientName, string location,
    int severity, string condition)
    : Emergency(id, patientName, location, severity),
      condition(condition) {}

void CriticalEmergency::display() const
{
    Emergency::display();
    cout << "Condition: " << condition << "\n";
}

// Hospital
Hospital::Hospital(int id, string name,
                   string location, int availableBeds)
    : id(id), name(name), location(location),
      availableBeds(availableBeds) {}

void Hospital::display() const
{
    cout << "Hospital ID: " << id
         << "\nName: " << name
         << "\nLocation: " << location
         << "\nAvailable Beds: " << availableBeds
         << "\n";
}

int Hospital::getId() const
{
    return id;
}

string Hospital::getName() const
{
    return name;
}

string Hospital::getLocation() const
{
    return location;
}

int Hospital::getAvailableBeds() const
{
    return availableBeds;
}

void Hospital::setAvailableBeds(int beds)
{
    availableBeds = beds;
}