//
// Created by daniel on 11/16/22.
//

#ifndef ELEVTAOR_SYSTEM_ELEVATOR_CLASS_HPP
#define ELEVTAOR_SYSTEM_ELEVATOR_CLASS_HPP

#include <memory>
#include <SocketCAN.h>

class ElevatorClass
{
private:
    std::unique_ptr<SocketCAN> canbus_socket_;
public:
    ElevatorClass(unsigned int elevator_id);

private:

public:

};


#endif //ELEVTAOR_SYSTEM_ELEVATOR_CLASS_HPP
