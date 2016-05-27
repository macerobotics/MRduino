


#ifndef _MRduino_H
#define _MRduino_H

void led(int led, int state);
void ledToggle(int led);

void firmwareVersion();


void forward(int speed);
void back(int speed);
void turnLeft(int speed);
void turnRight(int speed);

int proxSensor(int number);
int ambiantLight(int number);

void controlEnable();
void controlDisable();

void stop();

int readData();


#endif