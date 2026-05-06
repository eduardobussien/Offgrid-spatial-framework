#pragma once

namespace OffGrid {

    struct Coordinate {
        long long x_cm; 
        long long y_cm;
        long long z_cm; 

        // Initialize the point
        Coordinate(long long x = 0, long long y = 0, long long z = 0);
        
    };

}