#include <mrduino.h>

// variable init
int prox1;
int prox2;
int prox3;
int prox4;
int prox5;
int prox6;
int speed = 50;// speed init

// obstacle limit
int limit_obs = 300;

void setup() 
{
  // init serial interface
  Serial.begin(115200);         
  
}

void loop()
{
  // read sensors
  prox1 = proxSensor(1); 
  prox2 = proxSensor(2); 
  prox3 = proxSensor(3); 
  prox4 = proxSensor(4); 
  prox5 = proxSensor(5); 
  prox6 = proxSensor(6); 

  delay(100);

  if((prox1 > limit_obs) and (prox2 > limit_obs)and (prox3 > limit_obs) and (prox4 > limit_obs) and (prox5 > limit_obs)  and (prox6 > limit_obs))
  {
    back(speed);
  }
  else
  {
    if((prox1 > limit_obs) and (prox2 > limit_obs))
    {
      turnRight(speed);
    }
    else
    {
       if((prox6 > limit_obs) or (prox5 > limit_obs) or (prox4 > limit_obs))
       {
         turnLeft(speed);
       }
       else
       {
          if((prox1 > limit_obs) or (prox2 > limit_obs) or (prox3 > limit_obs))
          {
           turnRight(speed);
          }
          else
          {
            forward(speed);
          }
        
       }
    }
  }
}

// end of file


