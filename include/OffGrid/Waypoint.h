#pragma once
#include <string>
#include "OffGrid/Coordinate.h"

namespace OffGrid {

    enum class PointType {
        LANDMARK,
        RESOURCE,
        HAZARD,
        CAMP
    };

    struct Waypoint {
        std::string name;
        Coordinate location;
        PointType type;

        Waypoint(std::string wp_name, Coordinate loc, PointType wp_type);
    };

}