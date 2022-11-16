//
// Created by daniel on 11/16/22.
//

#ifndef ELEVTAOR_SYSTEM_ELEVATORS_MANAGER_CLASS_HPP
#define ELEVTAOR_SYSTEM_ELEVATORS_MANAGER_CLASS_HPP

#include <vector>
#include <ElevatorClass/elevator_class.hpp>

class ElevatorsManagerClass
{
private:
    bool is_ok_ = true;
    std::vector<ElevatorClass> elevators_;

public:
    ElevatorsManagerClass() {};

    ElevatorsManagerClass(const unsigned int number_of_elevators);

    ~ElevatorsManagerClass() {};

private:


public:
    bool IsOk() const { return is_ok_; };

    void Run();
};


#endif //ELEVTAOR_SYSTEM_ELEVATORS_MANAGER_CLASS_HPP
