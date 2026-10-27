#include "dispatch_system.h"

void DispatchSystem::registerDriver()
{
    int id;
    string name, phone, license;

    cout << "Enter Driver ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Driver Name: ";
    getline(cin, name);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter License Number: ";
    getline(cin, license);

    drivers.emplace_back(id, name, phone, license);

    cout << "Driver registered successfully!\n";
}

void DispatchSystem::registerAmbulance()
{
    int id;
    string number, type;

    cout << "Enter Ambulance ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Vehicle Number: ";
    getline(cin, number);

    cout << "Enter Ambulance Type: ";
    getline(cin, type);

    ambulances.emplace_back(id, number, type);

    cout << "Ambulance registered successfully!\n";
}

void DispatchSystem::registerHospital()
{
    int id, beds;
    string name, location;

    cout << "Enter Hospital ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Hospital Name: ";
    getline(cin, name);

    cout << "Enter Location: ";
    getline(cin, location);

    cout << "Enter Available Beds: ";
    cin >> beds;

    hospitals.emplace_back(id, name, location, beds);

    cout << "Hospital registered successfully!\n";
}

void DispatchSystem::registerEmergency()
{
    int id, severity;
    string patient, location;

    cout << "Enter Emergency ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, patient);

    cout << "Enter Location: ";
    getline(cin, location);

    cout << "Enter Severity (1-5): ";
    cin >> severity;

    emergencies.emplace_back(id, patient, location, severity);

    cout << "Emergency registered successfully!\n";
}

void DispatchSystem::viewDrivers()
{
    for (const auto &driver : drivers)
    {
        driver.display();
        cout << "------------------\n";
    }
}

void DispatchSystem::viewAmbulances()
{
    for (const auto &ambulance : ambulances)
    {
        ambulance.display();
        cout << "------------------\n";
    }
}

void DispatchSystem::viewHospitals()
{
    for (const auto &hospital : hospitals)
    {
        hospital.display();
        cout << "------------------\n";
    }
}

void DispatchSystem::viewEmergencies()
{
    for (const auto &emergency : emergencies)
    {
        emergency.display();
        cout << "------------------\n";
    }
}

void DispatchSystem::assignAmbulance()
{
    auto ambulance = find_if(
        ambulances.begin(),
        ambulances.end(),
        [](const Ambulance &a)
        {
            return a.isAvailable();
        });

    if (ambulance == ambulances.end())
    {
        cout << "No ambulance available!\n";
        return;
    }

    auto emergency = find_if(
        emergencies.begin(),
        emergencies.end(),
        [](const Emergency &e)
        {
            return e.getSeverity() >= 1;
        });

    if (emergency == emergencies.end())
    {
        cout << "No emergency found!\n";
        return;
    }

    ambulance->setAvailable(false);

    cout << "Ambulance assigned successfully!\n";
    cout << "Vehicle: "
         << ambulance->getVehicleNumber() << "\n";

    cout << "Emergency Location: "
         << emergency->getLocation() << "\n";
}

void DispatchSystem::completeTrip()
{
    cout << "Trip completion requires tracking "
         << "the assigned ambulance and emergency.\n";

    // Implement assignment tracking before
    // marking a specific trip as completed.
}

void DispatchSystem::saveRecords()
{
    ofstream file("records.txt");

    if (!file)
    {
        throw runtime_error("Unable to open records.txt");
    }

    file << "=== Drivers ===\n";

    for (const auto &driver : drivers)
    {
        file << "Driver ID: " << driver.getId()
             << ", Name: " << driver.getName() << "\n";
    }

    file << "\n=== Ambulances ===\n";

    for (const auto &ambulance : ambulances)
    {
        file << "Ambulance ID: " << ambulance.getId()
             << ", Vehicle: "
             << ambulance.getVehicleNumber() << "\n";
    }

    file << "\n=== Emergencies ===\n";

    for (const auto &emergency : emergencies)
    {
        file << "Emergency ID: " << emergency.getId()
             << ", Location: "
             << emergency.getLocation() << "\n";
    }

    file.close();

    cout << "Records saved successfully!\n";
}