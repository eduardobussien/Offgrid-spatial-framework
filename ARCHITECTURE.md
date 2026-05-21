# Architecture & Technical Decisions

This document outlines the core computer science concepts and technical decisions behind the Offgrid Spatial Framework. It serves as a guide for understanding how the engine manages data, memory, and performance.

### 1. The Coordinate System Integers vs. Floating-Point
The foundational `Coordinate` structure deliberately uses `long long` integers representing centimeters, rather than standard `float` or `double` types representing meters. 

In spatial and geospatial computing, floating-point precision loss occurs when tracking extremely large distances, causing data to degrade the further it gets from the origin. By establishing a strict, metric-based integer system, a 1cm distance remains perfectly deterministic whether it is measured at the origin or hundreds of kilometers away. We only cast to `double` at the exact moment of calculating the distance via the Pythagorean theorem to ensure safe math without integer overflow.

### 2. Object-Oriented Design Encapsulation
The framework strictly separates declarations (`.h` header files) from implementations (`.cpp` source files). 
 Headers Act as the public API. If a researcher or downstream developer wants to utilize the framework, they only need to interface with the `include` directory.
 Source Files Hide the complex mathematical logic. 
This encapsulation ensures that the framework can be dropped into a larger engine (like a geospatial visualizer) without exposing the internal logic to accidental modification. Furthermore, everything is wrapped in the `OffGrid` namespace to prevent naming collisions with external libraries.

### 3. Memory Management Pointers and Efficiency
When searching for specific data, such as the `getClosestWaypoint` algorithm, the engine utilizes C++ pointers (`const Waypoint`) and memory addresses (`&`) rather than returning data copies.

If a researcher scans a massive dataset for a specific resource, returning a copy of that data structure is computationally expensive. Returning a memory address costs almost zero processing power. Additionally, using pointers allows the engine to safely return a `nullptr` if a search yields no results, preventing runtime crashes.

### 4. Build System
The project utilizes CMake (`CMakeLists.txt`) as its build configuration system. This ensures the framework is platform-agnostic and can be natively compiled on Windows, macOS, or Linux environments without requiring manual compiler flags.