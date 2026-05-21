#include "OffGrid/Coordinate.h"
#include <cmath>

namespace OffGrid {

    Coordinate::Coordinate(long long x, long long y, long long z) 
        : x_cm(x), y_cm(y), z_cm(z) {
    }

    double Coordinate::distanceTo(const Coordinate& other) const {
        double dx = static_cast<double>(other.x_cm - x_cm);
        double dy = static_cast<double>(other.y_cm - y_cm);
        double dz = static_cast<double>(other.z_cm - z_cm);

        return std::sqrt(dx*dx + dy*dy + dz*dz);
    }

}