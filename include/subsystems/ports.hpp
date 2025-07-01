#ifndef __PORTS_H__
#define __PORTS_H__

//----------drive----------
#define RIGHT_FRONT     15
#define RIGHT_MIDDLE    5
#define RIGHT_BACK      16

#define LEFT_FRONT      14
#define LEFT_MIDDLE     -19
#define LEFT_BACK       17
//-------------------------

//----------first-stage---------
#define FIRST_STAGE     12
#define SECOND_STAGE    11
#define LAST_STAGE      9
//-------------------------

//----------storage---------
#define STORAGE         11
//-------------------------

//---------sensors----------
#define IMU_PORT        2
#define OP_PORT         19
//--------------------------

//---------pneumatics----------
#define SCRAPER_ADI       'A'
//-----------------------------

//-------------------------buttons----------------------------
#define BUTTON_INTAKE           pros::E_CONTROLLER_DIGITAL_R1
#define BUTTON_OUTTAKE          pros::E_CONTROLLER_DIGITAL_R2

#define BUTTON_LONG_GOAL        pros::E_CONTROLLER_DIGITAL_L1
#define BUTTON_MIDDLE_GOAL      pros::E_CONTROLLER_DIGITAL_L2

#define SCRAPER_ACT             pros::E_CONTROLLER_DIGITAL_B
//------------------------------------------------------------

#endif
