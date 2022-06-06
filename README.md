**Lane_Following_Car** 🚗 🚗
<br>

This an Arduino Uno R3 Project. The projects Successfully achieves its aim in differentiating between White & Black lanes and following one of them as refrence path. 
<br>

**Logic** 🧠 🧠
<br>

Calibration-
 - Left & Right LDR Reading are store over black and white respectively in 5s(2.5s over both black & White)
 - mean left = (left ldr(black)  + left ldr(white))/2
 - mean right = (right ldr(black)  + right ldr(white))/2
 - If LDR Reading > mean value black
 - else white 
<br>

**IDE** ✍️ ✍️

- Arduino IDE
<br>

**Library** <br> 📖

- <AFMotor.h>
<br>

**Hardware** :electron: :electron

- Arduino Uno R3
- Motor Shield
- x2 LDR sensors
- x2 White LEDS
- Male to Female, Male to Male Wires
- 5v Power source
- x2 Motors
- Castor Wheel
- Buzzer
- Resistor
- x2 Wheels

