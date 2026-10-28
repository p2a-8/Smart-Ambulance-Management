#include "reports.h"

void Reports::showProjectInformation() {
    cout << "\n====================================\n";
    cout << " SMART AMBULANCE MANAGEMENT SYSTEM\n";
    cout << "====================================\n";

    cout << "Language: C++17\n";
    cout << "Project Type: OOP Console Application\n";

    cout << "Features:\n";
    cout << "1. Driver Management\n";
    cout << "2. Ambulance Management\n";
    cout << "3. Hospital Management\n";
    cout << "4. Emergency Management\n";
    cout << "5. Ambulance Dispatch\n";
    cout << "6. Reports and File Handling\n";

    cout << "====================================\n";
}

void Reports::showEmergencyReport() {
    cout << "\nEmergency Report\n";
    cout << "Emergency information is managed by "
         << "the DispatchSystem class.\n";

    cout << "Use the system's emergency listing "
         << "function to view registered emergencies.\n";
}

void Reports::saveReport(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Unable to create report file.");
    }

    file << "SMART AMBULANCE MANAGEMENT SYSTEM\n";
    file << "Project Report\n";
    file << "Language: C++17\n";
    file << "Features: Driver, Ambulance, Hospital, "
         << "Emergency Management\n";

    file.close();

    cout << "Report saved to " << filename << "\n";
}