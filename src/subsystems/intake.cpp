#include "main.h"
#include "subsystems/intake.hpp"
#include "subsystems/ports.hpp"

#define FIRST_STAGE     12
#define SECOND_STAGE    11
#define LAST_STAGE      9
#define BUTTON_LONG_GOAL        pros::E_CONTROLLER_DIGITAL_L2
#define BUTTON_MIDDLE_GOAL      pros::E_CONTROLLER_DIGITAL_L1


extern int AC;

pros::Motor firstStage(FIRST_STAGE, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor secondStage(SECOND_STAGE, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor lastStage(LAST_STAGE, pros::E_MOTOR_GEAR_BLUE, false);

/*
pros::OpticalSensor color_sensor(OP_PORT,
                                OpticalSensorOutput ioutput = OpticalSensorOutput::hue,
                                bool idisableGestures = true,
                                std::unique_ptr<Filter> ifilter = std::make_unique<PassthroughFilter>()
)
*/

int speed = 12000;
int last_input=0;
int toggle = 12000;

bool color_disabled = false;

void update_intake() {
    int input_1 = controller.get_digital(BUTTON_INTAKE);
    int input_2 = controller.get_digital(BUTTON_OUTTAKE);
    int input_3 = controller.get_digital(BUTTON_LONG_GOAL);
    int input_4 = controller.get_digital(BUTTON_MIDDLE_GOAL);
    int input_5 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);

    if(input_5){
        if(toggle = 12000){
            toggle = -12000;
        }else{
            toggle = 12000;
        }
    }

    if (input_1) {
        firstStage.move_voltage(speed);
        secondStage.move_voltage(toggle);
        lastStage.move_voltage(speed);
    } else if (input_2){
        firstStage.move_voltage(-speed);
        secondStage.move_voltage(-speed);
    } else if (input_3){
        firstStage.move_voltage(speed);
        lastStage.move_voltage(-speed);
    } else if (input_4){
        firstStage.move_voltage(speed);
        secondStage.move_voltage(-speed);
        lastStage.move_voltage(speed);
    } else {
        firstStage.move_voltage(0);
        secondStage.move_voltage(0);
        lastStage.move_voltage(0);
    }
    last_input=input_3;
}

