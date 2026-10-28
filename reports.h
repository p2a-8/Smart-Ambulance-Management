#ifndef REPORTS_H
#define REPORTS_H

#include "dispatch_system.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Reports {
public:
    static void showProjectInformation();
    static void showEmergencyReport();
    static void saveReport(const string& filename);
};

#endif