#ifndef DISPATCH_SYSTEM_H
#define DISPATCH_SYSTEM_H

#include "classes.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>

class DispatchSystem
{
private:
    vector<Driver> drivers;
    vector<Ambulance> ambulances;
    vector<Emergency> emergencies;
    vector<Hospital> hospitals;

public:
    void registerDriver();
    void registerAmbulance();
    void registerHospital();
    void registerEmergency();

    void assignAmbulance();
    void completeTrip();

    void viewDrivers();
    void viewAmbulances();
    void viewHospitals();
    void viewEmergencies();

    void saveRecords();
};

#endif