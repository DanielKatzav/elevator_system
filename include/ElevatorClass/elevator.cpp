//
// Created by daniel on 11/16/22.
//

#include "elevator.hpp"

Elevator::Elevator(ElevatorParameters elevator_parameters) :
        elevator_parameters_(elevator_parameters)
{
    canbus_socket_ = std::make_unique<SocketCAN>();
}

int Elevator::GetCurrentFloor() const
{
    return current_floor_;
}

int Elevator::GetGoalFloor() const
{
    return goal_floor;
}

std::vector<int> Elevator::GetPossibleFloors() const
{
    return elevator_parameters_.possible_floors;
}

bool Elevator::AddFloorToPath(int new_floor)
{
    return false;
}

bool Elevator::AddFloorToPath(int new_floor, std::string floor_special_key)
{
    return false;
}

bool Elevator::PerformEmergencyStop()
{
    return false;
}

bool Elevator::SetElevatorControlMode(ElevatorControlMode elevator_control_mode)
{
    elevator_control_mode_ = elevator_control_mode;
    return true;
}

