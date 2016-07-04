/**
  ******************************************************************************
  * @file    mrduino.cpp
  * @author  Mace Robotics (www.macerobotics.com)
  * @version 0.5
  * @date    04/07/2016
  * @brief   lib for MRduino robot
  *
 *******************************************************************************/


#include <Arduino.h>
#include "mrduino.h"


static boolean  state_control = false;

void initRobot()
{
  Serial.begin(115200);
  controlDisable();
}


/**********************************************************
 * @brief  led
 * @param  None
 * @retval None
**********************************************************/
void led(int led, int state)
{
String  commande;
 
  commande = "#LED," + String(led) + "," + String(state) + "!";
  Serial.println(commande); 
  
}


/**********************************************************
 * @brief  ledToggle
 * @param  None
 * @retval None
**********************************************************/
void ledToggle(int led)
{
String  commande;
 
  commande = "#LEDT," + String(led) + "!";
  Serial.println(commande); 
}


/**********************************************************
 * @brief  firmwareVersion
 * @param  None
 * @retval None
**********************************************************/
float firmwareVersion()
{
String  commande;
 
  commande = "#FV!";
  Serial.println(commande); 
  
  return(readFloatData());

}


/**********************************************************
 * @brief  battery
 * @param  None
 * @retval None
**********************************************************/
float battery()
{
String  commande;
 
  commande = "#BAT!";
  Serial.println(commande); 
  
  return(readFloatData());
}


/**********************************************************
 * @brief  battery
 * @param  None
 * @retval None
**********************************************************/
float temperature()
{
String  commande;
 
  commande = "#TE!";
  Serial.println(commande); 
  
  return(readFloatData());
}


/**********************************************************
 * @brief  readSwitch
 * @param  None
 * @retval None
**********************************************************/
int readSwitch()
{
String  commande;
 
  commande = "#SW!";
  Serial.println(commande); 
  
  return(readData());

}


/**********************************************************
 * @brief  irReceiver
 * @param  None
 * @retval None
**********************************************************/
int irReceiver()
{
String  commande;
 
  commande = "#RC5!";
  Serial.println(commande); 
  
  return(readData());

}



/**********************************************************
 * @brief  forward
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void forward(int speed)
{
String  commande;
 
  commande = "#MF," + String(speed) + "!";
  Serial.println(commande); 
  
}


/**********************************************************
 * @brief  forwardC (forward with control)
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void forwardC(int speed, int distance)
{
String  commande;
int  state = 0;
 
  commande = "#MFC," + String(distance) + "," + String(speed) + "!";
  Serial.println(commande); 
  
  while(state != 3)
  {
    Serial.println("#TGS,1!"); 
    Serial.println(state);
    state = readData();
    
  }
  
}


/**********************************************************
 * @brief  backC (back with control)
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void backC(int speed, int distance)
{
String  commande;
int  state = 0;
 
  commande = "#MBC," + String(distance) + "," + String(speed) + "!";
  Serial.println(commande); 
  
  while(state != 3)
  {
    Serial.println("#TGS,1!"); 
    Serial.println(state);
    state = readData();
    
  }
  
}



/**********************************************************
 * @brief  back
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void back(int speed)
{
String  commande;
 
  commande = "#MB," + String(speed) + "!";
  Serial.println(commande); 
  
}


/**********************************************************
 * @brief  turnLeft
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void turnLeft(int speed)
{
String  commande;
 
  commande = "#TL," + String(speed) + "!";
  Serial.println(commande); 
  
}


/**********************************************************
 * @brief  turnLeftC
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void turnLeftC(int speed, int distance)
{
String  commande;
int  state = 0;
 
  commande = "#TLC," + String(distance) + "," + String(speed) + "!";
  Serial.println(commande); 
  
  while(state != 3)
  {
    Serial.println("#TGS,2!"); 
    Serial.println(state);
    state = readData();
  }
  
}


/**********************************************************
 * @brief  turnRight
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void turnRight(int speed)
{
String  commande;
 
  commande = "#TR," + String(speed) + "!";
  Serial.println(commande); 
  
}


/**********************************************************
 * @brief  turnRightC
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
void turnRightC(int speed, int distance)
{
String  commande;
int  state = 0;
 
  commande = "#TRC," + String(distance) + "," + String(speed) + "!";
  Serial.println(commande); 
  
  while(state != 3)
  {
    Serial.println("#TGS,2!"); 
    Serial.println(state);
    state = readData();
  }
  
}


/**********************************************************
 * @brief  proxSensor
 * @param  speed ( 0 to 100 )
 * @retval None
**********************************************************/
int proxSensor(int number)
{
String  commande;
int data;
 
  commande = "#PROX," + String(number) + "!";
  Serial.println(commande); 

  data = readData();
  
  return data;
}


/**********************************************************
 * @brief  ambiantLight
 * @param  
 * @retval None
**********************************************************/
int ambiantLight(int number)
{
String  commande;
int data;
 
  commande = "#AL," + String(number) + "!";
  Serial.println(commande); 

  data = readData();
  
  return data;
}


/**********************************************************
 * @brief  groundSensor
 * @param  
 * @retval None
**********************************************************/
int groundSensor(int number)
{
String  commande;
int data;
 
  commande = "#GR," + String(number) + "!";
  Serial.println(commande); 

  data = readData();
  
  return data;
}


/**********************************************************
 * @brief  controlEnable
 * @param  
 * @retval None
**********************************************************/
void controlEnable()
{
  if(state_control == false)
  {
    Serial.println("#CRE!"); 
    state_control = true;
  }
  else
  {
    // error
  }
  
}


/**********************************************************
 * @brief  controlDisable
 * @param  
 * @retval None
**********************************************************/
void controlDisable()
{
  Serial.println("#CRD!"); 
  state_control = false;
}


/**********************************************************
 * @brief  stop
 * @param  
 * @retval None
**********************************************************/
void stop()
{
  Serial.println("#STP!"); 
}


/**********************************************************
 * @brief read encoder left
 * @param  
 * @retval None
**********************************************************/
int encoderLeft()
{
String  commande;
int data;
 
  commande = "#EDL!";
  Serial.println(commande); 

  data = readData();
  
  return data;
}

/**********************************************************
 * @brief read encoder right
 * @param  
 * @retval None
**********************************************************/
int encoderRight()
{
String  commande;
int data;
 
  commande = "#EDR!";
  Serial.println(commande); 

  data = readData();
  
  return data;
}


/**********************************************************
 * @brief  acceleroX
 * @param  None
 * @retval None
**********************************************************/
float acceleroX()
{
String  commande;
 
  commande = "#ACCX!";
  Serial.println(commande); 
  
  return(readFloatData());
}


/**********************************************************
 * @brief  acceleroY
 * @param  None
 * @retval None
**********************************************************/
float acceleroY()
{
String  commande;
 
  commande = "#ACCY!";
  Serial.println(commande); 
  
  return(readFloatData());
}


/**********************************************************
 * @brief  acceleroZ
 * @param  None
 * @retval None
**********************************************************/
float acceleroZ()
{
String  commande;
 
  commande = "#ACCZ!";
  Serial.println(commande); 
  
  return(readFloatData());
}


/**********************************************************
 * @brief  readData
 * @param  
 * @retval None
**********************************************************/
int readData()
{ 
char c=0;        
String readString;

  while (c != '\n')
  {
    if (Serial.available() >0)
    {
      c = Serial.read();  //gets one byte from serial buffer
      if ( c != '$')
        readString += c; //makes the string readString
    } 
  }    

  return readString.toInt();
}

/**********************************************************
 * @brief  readFloatData
 * @param  
 * @retval None
**********************************************************/
float readFloatData()
{ 
char c=0;        
String readString;

  while (c != '\n')
  {
    if (Serial.available() >0)
    {
      c = Serial.read();  //gets one byte from serial buffer
      if ( c != '$')
        readString += c; //makes the string readString
    } 
  }    

  return readString.toFloat();
}

// end file