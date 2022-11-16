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
        include/ElevatorClass/elevator_class.hpp
        include/ElevatorsManager/elevators_manager_class.hpp
        )

set(SRC_FILES
        include/ElevatorClass/elevator_class.cpp
        include/ElevatorsManager/elevators_manager_class.cpp
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