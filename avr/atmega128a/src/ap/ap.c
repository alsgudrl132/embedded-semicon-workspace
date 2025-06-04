// #include "../driver/sub_motor.h"
#include "../driver/main_motor.h"

void apInit()
{
}

// void apMain()
// {
//     subMotorInit();

//     while (1)
//     {
//         handleSubMotor();
//     }
// }


void apMain() {
    
    while (1)
    {
        mainMotorHandler();
    }
    
}