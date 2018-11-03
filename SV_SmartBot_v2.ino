/*
 * Makers Nässjö have 2 working smartbots.
 * They are similiar to the littlebot except
 * that these have a pan and a tilt servo.
 * They step forward to next reading angle. Measure distance 
 * and move accordingly. 
 * 
 * 
 * 
 */


#include <ultra.h>
#include <Servo.h>

Servo pan_servo;
Servo tilt_servo;


/*
  SmartBot V2 Studieförbundet vuxenskolan by William Lehmus
  Connection instructions:
  
  Motor controller L298N (5v to 40v, can drive Arduino on 5v output if supplied 7 volt)
  IN1 to digital 2 
  IN2 to digital 3 
  IN3 to digital 4
  IN4 to digital 5
  Echo to digital 8
  Trig to digital 9
  Pan Servo to pin 10
  Tilt Servo to pin 11

  
            //Include OneSheld library.
*/

//Setup variables
int ml_forward = 2;
int ml_reverse = 3;
int mr_forward = 5;
int mr_reverse = 4;

//Ultrasonic scanner
int trig = 9;
int echo = 8;

//Servo angles
int pan_angle = 90;
int pan_speed = 3;                                     //Panning speed in degrees
int tilt_angle = 90;                                   //Not used yet

int distance = 20; // Set this distance manually to avoid strange behaviour at start
ultra ultrasonic(trig,echo,150);                       //Create UltraSonic object. Name=right_scanner. Trig pin, Echo pin, Max distance 100cm



void setup() {
  Serial.begin(115200);
  Serial.println("Booting up");
  pan_servo.attach(10);                        //Attach pan servo to pin 10
  tilt_servo.attach(11);                        //Attach tilt servo to pin 11
  pan_servo.write(pan_angle);
  tilt_angle.write(tilt_angle);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  pinMode(ml_forward, OUTPUT);
  pinMode(ml_reverse, OUTPUT);
  pinMode(mr_forward, OUTPUT);
  pinMode(mr_reverse, OUTPUT);
  ultrasonic.begin();                            //Initialize ultrasonic scanner with chosen pins
  Serial.println("Setup Complete");

}

void loop() {
  ultra_scan();
  move_servos();
  decision();
  prints();
  
}

