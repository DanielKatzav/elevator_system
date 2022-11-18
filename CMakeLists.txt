cmake_minimum_required(VERSION 3.23)
project(elevator_system)

add_subdirectory(include/3rd_party/libcan)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        include
        include/3rd_party/libcan/include
        include/ElevatorClass
        include/ElevatorsManager
)

set(HEADER_FILES
        include/ElevatorsManager/elevators_manager.hpp
        include/ElevatorClass/elevator.hpp
        include/ElevatorClass/ElevatorComponents/ElevatorCabin/elevator_cabin.hpp
        include/ElevatorClass/ElevatorComponents/ElevatorShaft/elevator_shaft.hpp
        )

set(SRC_FILES
        include/ElevatorsManager/elevators_manager.cpp
        include/ElevatorClass/elevator.cpp
        include/ElevatorClass/ElevatorComponents/ElevatorCabin/elevator_cabin.cpp
        include/ElevatorClass/ElevatorComponents/ElevatorShaft/elevator_shaft.cpp
        )

add_library(${PROJECT_NAME}_lib
        ${HEADER_FILES}
        ${SRC_FILES}
        )

add_executable(${PROJECT_NAME} src/main.cpp
        )

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAME}_lib
        canbus_lib
        )