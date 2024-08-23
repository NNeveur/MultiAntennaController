# Multi Antennas Switcher and Controler
# from VE2NNX Nicolas
 Controler to switch from up to 8 Antennas types MagLoop, VariLenght (Poorman StepR) Slopper and Dipole, Yeasu ATAS and Modules control for them.
 
 Main controler is a Teensy 4.0 with a Nextion tactil screen and a rotary encoder.
 
 It talk to Antenna control module via a RS485/RS422 bus with a 12v supply tru a RJ45 and network cable ( preferably sheilded) pair 1 =+12V, pair 2 = RS485 A/B, pair 3 = RS485 X/Y, pair 4 = Ground
 RS485/RS422 can handle 115kbits/s on a 2500 feets long cable, fast enough to control step motor with acknowledged command, two wires are used so it is half duplex bus and and up to 32 units can plug to the bus.
 
 It also have a TTL RS232 CAT Radio control, I2C if need, Frequency counter to read Frequency from sampled TX and Standing wave Bridge Forward / Reverse
 
 Everything Customiable, from naming tag antenna, to type of antenna and what band covered by it.
 
 Antenna selection can be manualy selected or fully automated from reading CAT or Frequency counter.
 
 When an antenna is selected, antenna switcher relay is activated and also power to it RS485 is given.
 
 So Antenna Module control is powered.
 
 Typical Antenna Module controle is a Arduino Nano based with is TTL to RS485/RS422 module interface and a 5v regulated supply for 12V
 
 The Magnetic Loop Antenna module control have Sparkfun.com Big Easy Step motor driver.
 
 Mag Loop Controler software is greatly inspired by Loftur TF3LJ/VE2AO Mag Loop Controler
 
 The VariLength (Poorman StepR) Antenna module control have one or two L298N DC motor driver and one or two photo counter for a wheel encoder to count length of the wire.

 I have couple of boards in production, I need to do hardware debuging
 
 Software for Main Controler (Teensy 4.0) is not fully done.

 Special Thanks to Rabby S21RC who inspired me with is great and nice SSPA Controler 

- Main Controller
- Antennas Switch Module
- Magnetic Loop Antenna Module
- VariLenght (Poorman StepR) Antenna Module
- Yeasu ATAS Antenna Module

![IMG_1670](https://github.com/user-attachments/assets/ba0e0b99-8176-4418-924c-b44c9a60dfff)
![IMG_1671](https://github.com/user-attachments/assets/f32b2e2c-bac4-4b84-9242-889db57d662e)
![IMG_1672](https://github.com/user-attachments/assets/ab00cb9b-be40-42ff-91cd-fd59ae25800f)
![IMG_1673](https://github.com/user-attachments/assets/bdf118b8-10fb-4b7e-b318-145de197d539)
![IMG_1674](https://github.com/user-attachments/assets/f4ed7f05-7ae7-4d0c-b06a-bbcf22fa88ec)
![IMG_1675](https://github.com/user-attachments/assets/5a2f8ea2-6b22-4241-8a90-53570e8b02f5)
![IMG_1676](https://github.com/user-attachments/assets/4e4f5b1a-e65d-42c2-b409-29b523ac0b5b)
![IMG_1677](https://github.com/user-attachments/assets/7c1a802e-daa8-4a03-9cf5-1ad404de5a8a)
![IMG_1678](https://github.com/user-attachments/assets/72f70a29-1c91-4386-9ae1-99d5d4427dd5)
![IMG_1679](https://github.com/user-attachments/assets/20f589e6-5a96-43a7-90fc-2ae5a14c80b4)


