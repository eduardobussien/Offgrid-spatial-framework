#include <gtest/gtest.h>
#include "OffGrid/WaypointManager.h"
#include "OffGrid/Coordinate.h"

using namespace OffGrid;

TEST(SpatialMathTest, DistanceCalculation) {
    Coordinate a(0, 0, 0);
    Coordinate b(0, 0, 100);
    Coordinate c(300, 400, 0); 

    EXPECT_DOUBLE_EQ(a.distanceTo(b), 100.0);
    EXPECT_DOUBLE_EQ(a.distanceTo(c), 500.0);
}

TEST(EngineMemoryTest, RadiusSearchLogic) {
    WaypointManager engine;
    
    engine.addWaypoint(Waypoint("Point_A", Coordinate(0, 0, 10), PointType::LANDMARK));
    engine.addWaypoint(Waypoint("Point_B", Coordinate(0, 0, 1000), PointType::LANDMARK));

    std::vector<Waypoint> found = engine.getWaypointsWithinRadius(Coordinate(0, 0, 0), 50.0);

    ASSERT_EQ(found.size(), 1);
    EXPECT_EQ(found[0].name, "Point_A");
}