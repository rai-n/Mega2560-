# RGB-LED 

**Add information about RGB LED and how it works here, and maybe circuit schematic**

Used PWM -- Pulse Width Modulation for controlling power. In this instance, it is used to control the brightness of each LED. 

Every 1/500 of a second, the PWM output produces a pulse. The length of this pulse is controlled by `analogWrite` method.

## Test expectations:

| Analog(value) | Result                  |   
|--------------|-------------------------| 
| 0            | No pulse                |  
| 255          | Pulse, until next pulse |   
|              |                         |  

A parameter value of between (0-255) produces a pulse. 

If such output pulse is only HIGH 5% of the time, the component will only receive 5% of the power. 



## Hooked up a 9v power supply to breadboard 

Picture here

 
