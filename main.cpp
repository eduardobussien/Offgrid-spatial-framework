#include <iostream>
#include <string>
#include "OffGrid/WaypointManager.h"

using namespace OffGrid;

void printMenu() {
    std::cout << "\n--- COMMAND MENU ---\n";
    std::cout << "[ADD] Create Waypoint | [SEARCH] Radius Scan | [EXPORT] Save to CSV | [EXIT] Shutdown\n";
    std::cout << "Enter command: ";
}

void flushBadInput() {
    std::cin.clear(); 
    std::cin.ignore(10000, '\n'); 
    std::cout << "\n-> [SYSTEM WARNING] Invalid input detected. Resetting interface...\n";
}

void clearPipe() {
    std::cin.ignore(10000, '\n');
}

int main() {
    std::cout << "__________________________________________\n";
    std::cout << "   OFFGRID SPATIAL FRAMEWORK - CLI v1.3   \n";
    std::cout << "   Operating on strict metric standards.  \n";
    std::cout << "__________________________________________\n";

    WaypointManager engine;
    std::string command;
    
    engine.addWaypoint(Waypoint("Base_Camp", Coordinate(0, 0, 100), PointType::CAMP));
    std::cout << "-> System Initialized. Base_Camp loaded at Origin.\n";

    while (true) {
        printMenu();
        std::cin >> command;

        if (std::cin.fail()) {
            flushBadInput();
            continue;
        }
        clearPipe(); 

        for (auto &c : command) c = toupper(c);

        if (command == "EXIT") {
            std::cout << "-> Saving memory state... Shutting down.\n";
            break; 
        } 
        else if (command == "ADD") {
            std::string name;
            long long x, y, z;
            int type_id;
            
            std::cout << "Enter Waypoint Name (No spaces): ";
            std::cin >> name;
            clearPipe(); 

            std::cout << "Enter Type ID (0=Landmark, 1=Resource, 2=Camp, 3=Hazard): ";
            std::cin >> type_id;
            if (std::cin.fail()) { flushBadInput(); continue; }
            clearPipe();

            std::cout << "Enter X Y Z coordinates in cm (separated by spaces): ";
            std::cin >> x >> y >> z;
            if (std::cin.fail()) { flushBadInput(); continue; }
            clearPipe();
            
            engine.addWaypoint(Waypoint(name, Coordinate(x, y, z), static_cast<PointType>(type_id)));
            std::cout << "-> " << name << " secured in memory.\n";
        }
        else if (command == "SEARCH") {
            double radius;
            std::cout << "Enter search radius in cm from origin (0,0,0): ";
            std::cin >> radius;

            if (std::cin.fail()) { flushBadInput(); continue; }
            clearPipe(); 
            
            std::vector<Waypoint> found = engine.getWaypointsWithinRadius(Coordinate(0,0,0), radius);
            std::cout << "\n-> Found " << found.size() << " waypoints in sector:\n";
            for (const auto& wp : found) {
                 std::cout << "   - " << wp.name << " (X:" << wp.location.x_cm << ", Y:" << wp.location.y_cm << ")\n";
            }
        }
        else if (command == "EXPORT") {
            std::string filename = "cli_export.csv";
            if (engine.exportToCSV(filename)) {
                std::cout << "-> Map serialized to " << filename << " successfully.\n";
            } else {
                std::cout << "-> Error: Could not write to disk.\n";
            }
        }
        else {
            std::cout << "-> Error: Unrecognized command. Please try again.\n";
        }
    }

    return 0;
}