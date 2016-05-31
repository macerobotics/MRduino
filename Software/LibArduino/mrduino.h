/**
  ******************************************************************************
  * @file    mrduino.cpp
  * @author  Mace Robotics
  * @version 0.2
  * @date    31/06/2016
  * @brief
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

float battery();
float temperature();

void forwardC(int speed, int distance);
void backC(int speed, int distance);
void turnRightC(int speed, int distance);
void turnLeftC(int speed, int distance);

void stop();

int readData();
float readFloatData();


#endif