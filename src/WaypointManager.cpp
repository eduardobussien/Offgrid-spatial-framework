#include "OffGrid/WaypointManager.h"

namespace OffGrid {

    void WaypointManager::addWaypoint(const Waypoint& wp) {
        waypoints.push_back(wp); 
    }

    std::vector<Waypoint> WaypointManager::getWaypointsWithinRadius(const Coordinate& center, double radius_cm) const {
        std::vector<Waypoint> found_points; 

        for (const auto& wp : waypoints) {
            if (wp.location.distanceTo(center) <= radius_cm) {
                found_points.push_back(wp);
            }
        }

        return found_points;
    }

}