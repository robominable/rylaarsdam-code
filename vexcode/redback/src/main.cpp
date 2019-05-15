/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Todd Rylaarsdam                                           */
/*    Created:      Mon Apr 01 2019                                           */
/*    Description:  4454A National Program                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
vex::competition Competition = vex::competition();
vex::controller Controller = vex::controller();
vex::motor Ldrive = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1,true);
vex::motor Rdrive = vex::motor(vex::PORT2,vex::gearSetting::ratio18_1,true);
vex::motor Larm = vex::motor(vex::PORT10,vex::gearSetting::ratio36_1);
vex::motor Rarm = vex::motor(vex::PORT3,vex::gearSetting::ratio36_1,true);
vex::motor Claw = vex::motor(vex::PORT11,vex::gearSetting::ratio18_1);
vex::motor ClawRotate = vex::motor(vex::PORT16,vex::gearSetting::ratio18_1);
vex::motor Puncher = vex::motor(vex::PORT7,vex::gearSetting::ratio18_1);
vex::motor Intake = vex::motor(vex::PORT5,vex::gearSetting::ratio18_1);
vex::accelerometer LeftArmAccel = vex::accelerometer(Brain.ThreeWirePort.A);
vex::accelerometer RightArmAccel = vex::accelerometer(Brain.ThreeWirePort.B);
vex::motor L2drive = vex::motor(vex::PORT4,vex::gearSetting::ratio18_1,true);
vex::motor R2drive = vex::motor(vex::PORT8,vex::gearSetting::ratio18_1,true);// A global instance of vex::competition

// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
Claw.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    vex::task::sleep(250);
    Claw.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    vex::task::sleep(250);
    Claw.stop();
    
    //GO FORWARD HIT CAP
    Ldrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    L2drive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    Rdrive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    R2drive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    vex::task::sleep(1100);
    Ldrive.stop();
    Rdrive.stop();
    L2drive.stop();
    R2drive.stop();
    //GO BACKWARD HIT WALL
    Ldrive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    L2drive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    Rdrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    R2drive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    vex::task::sleep(1500);
    Ldrive.stop();
    Rdrive.stop();
    L2drive.stop();
    R2drive.stop();
    //ROTATE LEFT
    Ldrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    L2drive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    vex::task::sleep(450);
    Rdrive.stop();
    R2drive.stop();
    //GO FORWARD TO PLATFORM
   /* Ldrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    L2drive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    Rdrive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    R2drive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    vex::task::sleep(450);
    Ldrive.stop();
    Rdrive.stop();
    L2drive.stop();
    R2drive.stop();
    //ROTATE LEFT
    Ldrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    L2drive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    vex::task::sleep(500);
    Ldrive.stop();
    L2drive.stop();*/
    //RAISE ARM A TINY BIT
    Larm.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    Rarm.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    vex::task::sleep(250);
    Larm.stop(vex::brakeType::brake);
    Rarm.stop(vex::brakeType::brake);
    //GO ONTO PLATFORM
    Ldrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    L2drive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    Rdrive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    R2drive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    vex::task::sleep(1400);
    Ldrive.stop(vex::brakeType::brake);
    Rdrive.stop(vex::brakeType::brake);
    L2drive.stop(vex::brakeType::brake);
    R2drive.stop(vex::brakeType::brake);
    Larm.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    Rarm.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    vex::task::sleep(600);
    Larm.stop();
    Rarm.stop();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
  int Lspeed = 0;
           int Rspeed = 0;
           int LowSpeed = 0;
           
            if (Lspeed < Rspeed){
                LowSpeed = Lspeed;
            }
            if (Rspeed > Lspeed){
                LowSpeed = Rspeed;
            }
            if (Lspeed == Rspeed){
                LowSpeed = ((Lspeed + Rspeed)/2);
            }
           Lspeed = (Ldrive.velocity(vex::velocityUnits::pct) + L2drive.velocity(vex::velocityUnits::pct));
           Rspeed = (Rdrive.velocity(vex::velocityUnits::pct) + R2drive.velocity(vex::velocityUnits::pct));
        
        //driver control
        
        int creep;
        creep = float(0.05);
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep){
            Ldrive.spin(vex::directionType::rev,(Controller.Axis3.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
            L2drive.spin(vex::directionType::rev,(Controller.Axis3.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
            else{
                Ldrive.stop();
                L2drive.stop();
            }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep){
            Rdrive.spin(vex::directionType::rev,-(Controller.Axis2.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
            R2drive.spin(vex::directionType::rev,-(Controller.Axis2.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
            else{
                Rdrive.stop();
                R2drive.stop();
            }
        /*if(Controller.ButtonR1.pressing()){
            Larm.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
            Rarm.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        }
           else if(Controller.ButtonR2.pressing()){
               Larm.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
               Rarm.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
           }
           else{
               Larm.stop(vex::brakeType::brake);
               Rarm.stop(vex::brakeType::brake);
           }*/
        if(Controller.ButtonY.pressing()){
            Puncher.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        }
            else{
                Intake.stop();
            }
       // if(Controller.ButtonL1.pressing()){
    //        Claw.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
   //     }
   //         else if(Controller.ButtonL2.pressing()){
   //             Claw.spin(vex::directionType::fwd, 100 ,vex::velocityUnits::pct);
  //          }
  //          else{
   //             Claw.stop(vex::brakeType::brake);
   //         }
        if(Controller.ButtonUp.pressing()){
            
            ClawRotate.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
            while(Controller.ButtonUp.pressing() != 1)
            {
                ClawRotate.stop(vex::brakeType::brake);
            }
            
        }
            else if(Controller.ButtonLeft.pressing()){
                ClawRotate.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
                while(Controller.ButtonLeft.pressing() != 1)
                {
                    ClawRotate.stop(vex::brakeType::brake);
                }
            }
            else{
                ClawRotate.stop(vex::brakeType::brake);
            }
       
        if(LeftArmAccel.value(vex::percentUnits::pct) < -0.10 && Controller.ButtonR1.pressing() == false && Controller.ButtonR2.pressing() == false)
        {
ClawRotate.spin(vex::directionType::fwd);            
            
        }
            else if(LeftArmAccel.value(vex::percentUnits::pct) > 0.10 && Controller.ButtonR1.pressing() == false && Controller.ButtonR2.pressing() == false)
            {
ClawRotate.spin(vex::directionType::fwd);            
            }
            else if((Controller.ButtonR1.pressing() == false && Controller.ButtonR2.pressing() == false))
            {
                Larm.stop(vex::brakeType::brake);
            }
            else if(Controller.ButtonR1.pressing() == true)
            {
                Larm.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
            }
            else if(Controller.ButtonR2.pressing() == true)
            {
                Larm.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
            }
        if(RightArmAccel.value(vex::percentUnits::pct) < -0.10 && Controller.ButtonR1.pressing() == false && Controller.ButtonR2.pressing() == false)
        {
ClawRotate.spin(vex::directionType::fwd);            
            
        }
            else if(RightArmAccel.value(vex::percentUnits::pct) > 0.10 && Controller.ButtonR1.pressing() == false && Controller.ButtonR2.pressing() == false)
            {
ClawRotate.spin(vex::directionType::fwd);            
            }
            else if((Controller.ButtonR1.pressing() == false && Controller.ButtonR2.pressing() == false))
            {
                Rarm.stop(vex::brakeType::brake);
            }
            else if(Controller.ButtonR1.pressing() == true)
            {
                Rarm.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
            }
            else if(Controller.ButtonR2.pressing() == true)
            {
                Rarm.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
            }
        if(Controller.ButtonUp.pressing() == true){
            Claw.startRotateFor(960,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        }
        else if(Controller.ButtonLeft.pressing() == true){
            Claw.startRotateFor(-960,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        }
        else if(Controller.ButtonDown.pressing() == true){
            Claw.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);
        }
        else if(Controller.ButtonRight.pressing() == true){
            Claw.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
        }
        else if (Claw.isSpinning() == false){
            Claw.stop(vex::brakeType::hold);
        }
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}
int Lspeed;
           int Rspeed;
//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(300);
           int Lspeed;
           int Rspeed;
           int LowSpeed;
           while(true){
            if (Lspeed < Rspeed){
                LowSpeed = Lspeed;
            }
            if (Rspeed > Lspeed){
                LowSpeed = Rspeed;
            }
            if (Lspeed == Rspeed){
                LowSpeed = ((Lspeed + Rspeed)/2);
            }
           Lspeed = (Ldrive.velocity(vex::velocityUnits::pct) + L2drive.velocity(vex::velocityUnits::pct));
           Rspeed = (Rdrive.velocity(vex::velocityUnits::pct) + R2drive.velocity(vex::velocityUnits::pct));
           /*Brain.Screen.printAt(10,15,"v5 IS IN BETA!");
           Brain.Screen.printAt(20,35,"v5 IS COMING SOON!");
           Brain.Screen.printAt(24,55,"v5 IS IN BETA!");
               Brain.Screen.printAt(10,75,"v5 IS COMING SOON!");
           Brain.Screen.printAt(20,95,"v5 IS IN BETA!");
           Brain.Screen.printAt(24,115,"v5 IS COMING SOON!");
               Brain.Screen.printAt(10,135,"v5 IS IN BETA!");
           Brain.Screen.printAt(20,155,"v5 IS COMING SOON!");
           Brain.Screen.printAt(24,175,"v5 IS IN BETA!");
               Brain.Screen.printAt(10,195,"v5 IS COMING SOON!");
           Brain.Screen.printAt(20,215,"v5 IS IN BETA!");
           Brain.Screen.printAt(24,235,"v5 IS COMING SOON!");
               Brain.Screen.printAt(10,255,"v5 IS IN BETA!");
           Brain.Screen.printAt(20,275,"v5 IS COMING SOON!");
           Brain.Screen.printAt(24,295,"v5 IS IN BETA!");
               Brain.Screen.printAt(10,315,"v5 IS COMING SOON!");
           Brain.Screen.printAt(20,335,"v5 IS IN BETA!");
           Brain.Screen.printAt(24,355,"v5 IS COMING SOON!");
               Brain.Screen.printAt(10,375,"v5 IS IN BETA!");
           Brain.Screen.printAt(20,395,"v5 IS COMING SOON!");
           Brain.Screen.printAt(24,415,"v5 IS IN BETA!");
               Brain.Screen.printAt(10,435,"v5 IS COMING SOON!");
           Brain.Screen.printAt(20,455,"v5 IS IN BETA!");
           Brain.Screen.printAt(24,475,"v5 IS COMING SOON!");
               Brain.Screen.printAt(220,15,"v5 IS IN BETA!");
           Brain.Screen.printAt(220,35,"v5 IS COMING SOON!");
           Brain.Screen.printAt(224,55,"v5 IS IN BETA!");
               Brain.Screen.printAt(210,75,"v5 IS COMING SOON!");
           Brain.Screen.printAt(220,95,"v5 IS IN BETA!");
           Brain.Screen.printAt(224,115,"v5 IS COMING SOON!");
               Brain.Screen.printAt(210,135,"v5 IS IN BETA!");
           Brain.Screen.printAt(220,155,"v5 IS COMING SOON!");
           Brain.Screen.printAt(224,175,"v5 IS IN BETA!");
               Brain.Screen.printAt(210,195,"v5 IS COMING SOON!");
           Brain.Screen.printAt(220,215,"v5 IS IN BETA!");
           Brain.Screen.printAt(224,235,"v5 IS COMING SOON!");
               Brain.Screen.printAt(210,255,"v5 IS IN BETA!");
           Brain.Screen.printAt(220,275,"v5 IS COMING SOON!");
           Brain.Screen.printAt(224,295,"v5 IS IN BETA!");
               Brain.Screen.printAt(210,315,"v5 IS COMING SOON!");
           Brain.Screen.printAt(200,335,"v5 IS IN BETA!");
           Brain.Screen.printAt(204,355,"v5 IS COMING SOON!");
               Brain.Screen.printAt(210,375,"v5 IS IN BETA!");
           Brain.Screen.printAt(200,395,"v5 IS COMING SOON!");
           Brain.Screen.printAt(204,415,"v5 IS IN BETA!");
               Brain.Screen.printAt(90,435,"v5 IS COMING SOON!");
           Brain.Screen.printAt(100,455,"v5 IS IN BETA!");
           Brain.Screen.printAt(104,475,"v5 IS COMING SOON!");*/
          Brain.Screen.setFillColor(color::purple);
          Brain.Screen.drawRectangle(0, 0, 1000, 1000);
          Brain.Screen.setFont(vex::fontType::mono60);
          Brain.Screen.setPenColor(color::white);
          Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          Brain.Screen.setPenColor(color::green);
          vex::task::sleep(50);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          Brain.Screen.setFillColor(color::blue);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          vex::task::sleep(50);
          Brain.Screen.setFillColor(color::green);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          vex::task::sleep(50);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          Brain.Screen.setFillColor(color::purple);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          vex::task::sleep(50);
          Brain.Screen.setFillColor(color::orange);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          vex::task::sleep(50);
          Brain.Screen.setFillColor(color::green);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          vex::task::sleep(50);
          Brain.Screen.setFillColor(color::red);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          vex::task::sleep(50);
          Brain.Screen.setFillColor(color::yellow);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          vex::task::sleep(50);
          Brain.Screen.setFillColor(color::white);
                    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
Brain.Screen.printAt(20,70, "¡KEVIN!");
          Brain.Screen.printAt(20,140, "¡KEVIN!");
          Brain.Screen.printAt(20,210, "¡KEVIN!");
          Brain.Screen.printAt(220,70, "¡KEVIN!");
          Brain.Screen.printAt(220,140, "¡KEVIN!");
          Brain.Screen.printAt(220,210, "¡KEVIN!");
          

      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
    
}
}