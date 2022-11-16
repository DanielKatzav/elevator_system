#include <iostream>
#include <ElevatorsManager/elevators_manager_class.hpp>

int main()
{
    ElevatorsManagerClass elevators_manager;

    try
    {
        while (elevators_manager.IsOk())
        {
            elevators_manager.Run();
        }
    }
    catch (const std::exception &e)
    {

    }

    return 0;
}
