#pragma once

namespace OffGrid {

    // Represents a localized point in 3D space.
    // Base unit is strictly centimeters (cm) for precision.
    struct Coordinate {
        long long x_cm; 
        long long y_cm;
        long long z_cm; // Elevation

        // Initialize the point
        Coordinate(long long x = 0, long long y = 0, long long z = 0);
        
        // --- Future Framework Methods ---
    };

}