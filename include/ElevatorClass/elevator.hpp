//
// Created by daniel on 11/16/22.
//

#ifndef ELEVATOR_SYSTEM_ELEVATOR_HPP
#define ELEVATOR_SYSTEM_ELEVATOR_HPP

#include <memory>
#include <vector>
#include <SocketCAN.h>
#include <map>

/*
 * Assumptions:
 *  1. Elevator current floor determines the floor that it can also be immediately stopped
 *  2. There is a correlation between the max acceleration and velocity of the elevator to reach a designated time to stop, begin and pass a single floor
 * */

enum ElevatorCurrentState
{
    STOPPED,
    GOING_UP,
    GOING_DOWN
};

enum ElevatorShaftCommands
{
    STOP,
    GO_UP,
    GO_DOWN
};

enum ElevatorControlMode
{
    STANDBY,
    ELEVATOR_CONTROL,
    REMOTE_CONTROL,
    EMERGENCY
};

struct ElevatorParameters
{
    uint32_t elevator_id_;

    std::vector<int> possible_floors;
    std::vector<int> special_floors;
    std::map<int, std::string> floor_special_keys_map_;

    int opened_doors_time_window_in_ms_ = 8000;

    float max_acceleration_in_meters_per_second_square_ = 3;
    float max_velocity_in_meters_per_second_ = 6;

    int floor_in_meters_ = 3;
    int lowest_floor_ = -2;
    int highest_floor_ = 10;
};

class Elevator
{
private:
    std::unique_ptr<SocketCAN> canbus_socket_;

    int current_floor_ = 0;
    int goal_floor = 0;
    std::vector<int> floor_path;

    const ElevatorParameters elevator_parameters_;

    ElevatorControlMode elevator_control_mode_ = ElevatorControlMode::STANDBY;

public:
    Elevator(ElevatorParameters elevator_parameters);

private:

public:
    int GetCurrentFloor() const;
    int GetGoalFloor() const;
    std::vector<int> GetPossibleFloors() const;

    bool AddFloorToPath(int new_floor);
    bool AddFloorToPath(int new_floor, std::string floor_special_key);

    bool PerformEmergencyStop();
    bool SetElevatorControlMode(ElevatorControlMode elevator_control_mode);

};


#endif //ELEVATOR_SYSTEM_ELEVATOR_HPP
