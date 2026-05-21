# OffGrid Spatial Framework

A lightweight, high-performance C++ engine designed for handling localized geospatial logic, topographic waypoint management, and off-grid routing. 

This framework was built to provide deterministic, precision-safe spatial processing for remote environments, bypassing floating-point degradation by strictly utilizing a metric-based integer coordinate architecture.

## Core Features
* **Metric-Strict Architecture:** Base coordinates are managed as `long long` centimeters to prevent precision loss over vast topographies.
* **Encapsulated Memory Management:** Utilizes pointer-driven searches to locate nearest-neighbor waypoints without unnecessary memory allocation.
* **Radius Filtering:** Efficiently scan and filter datasets within a defined geographic radius.
* **Data Serialization:** Built-in I/O support for exporting live engine memory to `.csv` format for external analysis.

## Getting Started

### Prerequisites
* CMake (3.10 or higher)
* A C++17 compatible compiler (GCC, MSVC, Clang)

### Build Instructions
```bash
mkdir build
cd build
cmake ..
cmake --build .