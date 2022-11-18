//
// Created by daniel on 11/16/22.
//

#ifndef ELEVATOR_SYSTEM_ELEVATORS_MANAGER_HPP
#define ELEVATOR_SYSTEM_ELEVATORS_MANAGER_HPP

#include <vector>
#include <ElevatorClass/elevator.hpp>

class ElevatorsManager
{
private:
    bool is_ok_ = true;
    std::map<std::string, Elevator> elevators_map_by_id_;

public:
    ElevatorsManager() {};

    explicit ElevatorsManager(unsigned int number_of_elevators);

    ~ElevatorsManager() {};

private:


public:
    bool IsOk() const { return is_ok_; };

    void Run();
};


#endif //ELEVATOR_SYSTEM_ELEVATORS_MANAGER_HPP
