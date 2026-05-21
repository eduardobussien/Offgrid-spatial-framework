#include "OffGrid/WaypointManager.h"
#include <fstream>
#include <sstream>

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
    
    const Waypoint* WaypointManager::getClosestWaypoint(const Coordinate& current_pos, PointType target_type) const {
        const Waypoint* closest_wp = nullptr; 
        double shortest_distance = -1.0; 

        for (const auto& wp : waypoints) {
            if (wp.type == target_type) {
                double dist = wp.location.distanceTo(current_pos);
                
                if (closest_wp == nullptr || dist < shortest_distance) {
                    closest_wp = &wp; 
                    shortest_distance = dist;
                }
            }
        }

        return closest_wp;
    }

    bool WaypointManager::exportToCSV(const std::string& filename) const {
        std::ofstream file(filename);

        if (!file.is_open()) {
            return false; 
        }

        file << "Name,Type_ID,X_cm,Y_cm,Z_cm\n";

        for (const auto& wp : waypoints) {
            file << wp.name << ","
                 << static_cast<int>(wp.type) << "," 
                 << wp.location.x_cm << ","
                 << wp.location.y_cm << ","
                 << wp.location.z_cm << "\n";
        }

        file.close();
        return true;
    }

    bool WaypointManager::importFromCSV(const std::string& filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            return false; 
        }

        std::string line;
        bool is_first_line = true;

        while (std::getline(file, line)) {
            if (is_first_line) {
                is_first_line = false;
                continue; 
            }

            std::stringstream ss(line);
            std::string name, type_str, x_str, y_str, z_str;

            std::getline(ss, name, ',');
            std::getline(ss, type_str, ',');
            std::getline(ss, x_str, ',');
            std::getline(ss, y_str, ',');
            std::getline(ss, z_str, ',');

            PointType type = static_cast<PointType>(std::stoi(type_str));
            long long x = std::stoll(x_str);
            long long y = std::stoll(y_str);
            long long z = std::stoll(z_str);

            Coordinate loc(x, y, z);
            Waypoint new_wp(name, loc, type);
            waypoints.push_back(new_wp);
        }

        file.close();
        return true;
    }
}