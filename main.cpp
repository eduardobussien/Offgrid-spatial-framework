#include <iostream>
#include "OffGrid/WaypointManager.h"

using namespace OffGrid;

int main() {
    std::cout << "--- Offgrid Spatial Framework v1.0 ---\n\n";

    // 1. Initialize engine
    WaypointManager engine;

    // 2. Load the engine with some test data
    std::cout << "Loading waypoints into memory...\n";
    engine.addWaypoint(Waypoint("Base Camp", Coordinate(0, 0, 100), PointType::CAMP));
    engine.addWaypoint(Waypoint("Water Source", Coordinate(500, 200, 90), PointType::RESOURCE));
    engine.addWaypoint(Waypoint("Ancient Ruin", Coordinate(15000, -8000, 120), PointType::LANDMARK));
    engine.addWaypoint(Waypoint("Steep Dropoff", Coordinate(600, 300, -500), PointType::HAZARD));

    Coordinate search_center(0, 0, 0);

    // 3. Test the Radius Search (Searching within 1000 cm)
    double search_radius = 1000.0;
    std::cout << "\nScanning for waypoints within " << search_radius << "cm of origin...\n";
    
    std::vector<Waypoint> nearby = engine.getWaypointsWithinRadius(search_center, search_radius);
    for (const auto& wp : nearby) {
        std::cout << "  -> Found nearby: " << wp.name << "\n";
    }

    // 4. Test the Nearest Neighbor Algorithm 
    std::cout << "\nScanning map for the nearest RESOURCE...\n";
    const Waypoint* closest_resource = engine.getClosestWaypoint(search_center, PointType::RESOURCE);
    
    if (closest_resource != nullptr) {
        std::cout << "  -> Closest resource is: " << closest_resource->name << "\n";
    } else {
        std::cout << "  -> No resources found on this map.\n";
    }

    // 5. Test the CSV Exporter
    std::string filename = "offgrid_export.csv";
    std::cout << "\nExporting engine memory to hard drive...\n";
    
    if (engine.exportToCSV(filename)) {
        std::cout << "  -> SUCCESS! " << filename << " has been created in your folder.\n";
    } else {
        std::cout << "  -> FAILED to create file.\n";
    }

    std::cout << "\n--- Engine Shutdown ---\n";
    return 0;
}