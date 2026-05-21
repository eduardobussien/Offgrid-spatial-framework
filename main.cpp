#include <iostream>
#include "OffGrid/WaypointManager.h"

using namespace OffGrid;

int main() {
    std::cout << "--- Offgrid Spatial Framework v1.1 ---\n\n";
    std::string filename = "offgrid_export.csv";

    WaypointManager engineA;
    engineA.addWaypoint(Waypoint("Base Camp", Coordinate(0, 0, 100), PointType::CAMP));
    engineA.addWaypoint(Waypoint("Excavation Site", Coordinate(500, 200, 90), PointType::RESOURCE));
    engineA.addWaypoint(Waypoint("Ancient Ruin", Coordinate(15000, -8000, 120), PointType::LANDMARK));
    
    std::cout << "Engine A: Exporting map data to disk...\n";
    engineA.exportToCSV(filename);
    std::cout << "Engine A: Shutting down. Memory cleared.\n\n";

    WaypointManager engineB;
    std::cout << "Engine B: Booting empty and loading from disk...\n";

    if (engineB.importFromCSV(filename)) {
        std::cout << "  -> SUCCESS! Data parsed into RAM.\n\n";

        Coordinate search_center(0, 0, 0);
        std::cout << "Engine B: Scanning map for the nearest LANDMARK...\n";
        const Waypoint* closest = engineB.getClosestWaypoint(search_center, PointType::LANDMARK);
        
        if (closest != nullptr) {
            std::cout << "  -> Found: " << closest->name << "\n";
            std::cout << "  -> Coordinates: X:" << closest->location.x_cm 
                      << " Y:" << closest->location.y_cm 
                      << " Z:" << closest->location.z_cm << "\n";
        }
    } else {
        std::cout << "  FAILED to load file.\n";
    }

    std::cout << "\n Engine Shutdown \n";
    return 0;
}