# ARDUINO-AND-DIGITAL-ADRESSABLE-LED-FUN
It is a fun project with arduino and neopixel led strips.
1-COMPONENTS
i. LDR (or Photo-resistor)
A LDR is used to detect the light from its surrounding and adjust the brightness
of LED strips accordingly.
(Calibration of LDR is needed in order to get best outcomes)
ii. Potentiometer
A potentiometer can vary the brightness manually (upto 10 units only)
iii. Push Button (Labelled as SWITCH)
By pressing the Push Button one can change the pattern running on the Led
strip.
iv. Cables
There are two cables
 Cable-1: It can be used for communicating directly with Arduino NANO
(tied with the enclosure. See figure-I)
 Cable-2: It can be used to power up the device.
(a Male DC power jack at one end. See figure-II)
Both contains USB TYPE A at one of their ends.
v. Wire of 3 meters
 Color Coding
 Red = Vcc
 Green = Data
 White = Ground
3 | P a g e
Figure-I
Figure-II
4 | P a g e
2-INSTALLATION
i- Calibration of LDR:
 Connect Cable-1 with your laptop.
 Download TeamViewer
 Give access to me through TeamViewer.
(I will do this for you)
ii- Input:
You have to buy a 5Vand 2/2.5A (Euro type) adapter and then plug it with Cable2 (see figure-II)
3-LIMITATIONS:
The only limitation we cannot combat with is DELAY. There is some delay between
the switch pressed and the change occur.
If one pattern is running and user wants to switch to the other pattern, then he/she
should wait for few seconds to see the change.
Furthermore, LEDs also indicate the execution of command. Read the following
example:
 Assume that the Pattern 3(Automatic Mode) is running and as you are in
Automatic Mode Green Led is ON, indicating that this is a part of
AUTOMATIC MODE.
 Someone press the button to switch to Pattern 4 (i.e. also Automatic
Mode). Now the Green LED will be off for couple of seconds, indication
that the controller receives a command from SWITCH.
 As soon as the previous pattern (i.e. Pattern 3) finishes the Green LED will
turn ON, indicating that command is executed perfectly and Pattern 4 will
start running on the LED strip.
