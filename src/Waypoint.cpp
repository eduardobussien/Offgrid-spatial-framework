#include "OffGrid/Waypoint.h"
#include <utility> 

namespace OffGrid {

    Waypoint::Waypoint(std::string wp_name, Coordinate loc, PointType wp_type) 
        : name(std::move(wp_name)), location(loc), type(wp_type) {
    }

}