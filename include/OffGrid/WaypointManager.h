#pragma once
#include <vector>
#include "OffGrid/Waypoint.h"

namespace OffGrid {

    class WaypointManager {
    private:
        std::vector<Waypoint> waypoints;

    public:
        void addWaypoint(const Waypoint& wp);
        std::vector<Waypoint> getWaypointsWithinRadius(const Coordinate& center, double radius_cm) const;
    };

}