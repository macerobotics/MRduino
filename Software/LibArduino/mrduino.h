/**
  ******************************************************************************
  * @file    mrduino.cpp
  * @author  Mace Robotics
  * @version 0.9
  * @date    15/05/2017
  * @brief   lib for MRduino robot an MRduino Wireless
  *
 *******************************************************************************/

#ifndef _MRduino_H
#define _MRduino_H

void initRobot();

void led(int led, int state);
void ledToggle(int led);

float firmwareVersion();


void forward(int speed);
void back(int speed);
void turnLeft(int speed);
void turnRight(int speed);

int proxSensor(int number);
int ambiantLight(int number);
int groundSensor(int number);

void controlEnable();
void controlDisable();

int readSwitch();

int irReceiver();

float battery();
float temperature();

// move
void forwardC(int speed, int distance);
void forward_mm(int speed, int distance);
void backC(int speed, int distance);
void back_mm(int speed, int distance);
void turnRightC(int speed, int distance);
void turnLeftC(int speed, int distance);

void turnRight_degree(int speed, int angle);
void turnLeft_degree(int speed, int angle);

void stop();

// encoder
int encoderLeft();
int encoderRight();

int readData();
float readFloatData();

// accelerometer
float acceleroX();
float acceleroY();
float acceleroZ();

//speaker
void speakerEnable();

#endif