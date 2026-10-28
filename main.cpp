#include "dispatch_system.h"
#include "reports.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    DispatchSystem system;
    int choice = -1;

    Reports::showProjectInformation();

    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Register Driver\n";
        cout << "2. Register Ambulance\n";
        cout << "3. Register Hospital\n";
        cout << "4. Register Emergency\n";
        cout << "5. View Drivers\n";
        cout << "6. View Ambulances\n";
        cout << "7. View Hospitals\n";
        cout << "8. View Emergencies\n";
        cout << "9. Assign Ambulance\n";
        cout << "10. Save Records\n";
        cout << "11. Save Project Report\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";

            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            continue;
        }

        try {
            switch (choice) {
                case 1:
                    system.registerDriver();
                    break;

                case 2:
                    system.registerAmbulance();
                    break;

                case 3:
                    system.registerHospital();
                    break;

                case 4:
                    system.registerEmergency();
                    break;

                case 5:
                    system.viewDrivers();
                    break;

                case 6:
                    system.viewAmbulances();
                    break;

                case 7:
                    system.viewHospitals();
                    break;

                case 8:
                    system.viewEmergencies();
                    break;

                case 9:
                    system.assignAmbulance();
                    break;

                case 10:
                    system.saveRecords();
                    break;

                case 11:
                    Reports::saveReport("project_report.txt");
                    break;

                case 0:
                    cout << "Exiting application...\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}