//
// Created by daniel on 11/16/22.
//

#include "elevator_class.hpp"

ElevatorClass::ElevatorClass(unsigned int elevator_id)
{
    canbus_socket_ = std::make_unique<SocketCAN>();
}
