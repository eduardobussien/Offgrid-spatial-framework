#pragma once
#include <vector>
#include <string> 
#include "OffGrid/Waypoint.h"

namespace OffGrid {

    class WaypointManager {
    private:
        std::vector<Waypoint> waypoints;

    public:
        void addWaypoint(const Waypoint& wp);
        std::vector<Waypoint> getWaypointsWithinRadius(const Coordinate& center, double radius_cm) const;
        const Waypoint* getClosestWaypoint(const Coordinate& current_pos, PointType target_type) const;

        bool exportToCSV(const std::string& filename) const;
        bool importFromCSV(const std::string& filename);
    };

}