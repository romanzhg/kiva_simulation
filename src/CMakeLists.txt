include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    third_party/include
)

link_directories(
    ${LIBRARY_OUTPUT_PATH}
    third_party/lib
)

set(
    BASE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(
    ks

    ks_runner.cpp
    ks_map.cpp
    ks_wms.cpp
    ks_scheduler.cpp
    ks_simulator.cpp
    ks_robotmanager.cpp
    ks_actiongraph.cpp
    utilities.cpp

    path_finder/sipp_solver.cpp
    path_finder/sipp_astar.cpp
)

add_executable(
    local_test_main

    local_test_main.cpp
)

target_link_libraries(
    local_test_main

    ks
    pthread
    hiredis
)

# Tests.
add_executable(
    sipp_test

    path_finder/sipp_astar.cpp
    path_finder/sipp_solver.cpp
    path_finder/sipp_solver_test.cpp
)

target_link_libraries(
    sipp_test

    ks
    gmock
    gtest
    pthread
)