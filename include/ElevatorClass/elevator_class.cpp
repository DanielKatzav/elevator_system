//
// Created by daniel on 11/16/22.
//

#include "elevator_class.hpp"

ElevatorClass::ElevatorClass(ElevatorParameters elevator_parameters) :
        elevator_parameters_(elevator_parameters)
{
    canbus_socket_ = std::make_unique<SocketCAN>();
}

int ElevatorClass::GetCurrentFloor() const
{
    return current_floor_;
}

int ElevatorClass::GetGoalFloor() const
{
    return goal_floor;
}

std::vector<int> ElevatorClass::GetPossibleFloors() const
{
    return elevator_parameters_.possible_floors;
}

bool ElevatorClass::AddFloorToPath(int new_floor)
{
    return false;
}

bool ElevatorClass::AddFloorToPath(int new_floor, std::string floor_special_key)
{
    return false;
}

bool ElevatorClass::PerformEmergencyStop()
{
    return false;
}

bool ElevatorClass::SetElevatorControlMode(ElevatorControlMode elevator_control_mode)
{
    elevator_control_mode_ = elevator_control_mode;
    return true;
}

