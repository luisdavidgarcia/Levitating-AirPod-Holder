# Levitating-AirPod-Holder 🎧

Feeling tired or just leaving your AirPods in random places, well no longer. Instead with this Rube Goldberg machine you have an airpod holder that is held via a electronic magnet. The airpods will remain magnetized to the 
magnet until you input the keyboard sequence in the carboard piano.

https://user-images.githubusercontent.com/87344382/159810264-3be7b63b-1494-4f92-8d15-21d4e4df96ad.mp4

## Overview

The levitating AirPod Holder is a Rube Goldberg machine project that lets you create a cardboard AirPod stand to hold you AirPods in mid air, until you enter a correct piano key sequence.

In total there are 5 circuits a piano keyboard, a strobe light, a light detector with a solenoid, a metal detector, and an electromagnet circuit. 

To demonstrate to the integration of all these circuits a video, along with brief descriptions of the circuits are provided below. 

The piano circuit is the cardboard piece with alumnium squares tapped onto it. The piano circuit is connected with an Arduino to detect the proper key sequence. The correct sequence makes the Arduino activate the piano circuit's relay switch to the alway's on state. 

As a result, the relay connects a 9V battery to the strobe light circuit, which causes the strobe light to flash and the light detector circuit to detect the light. 

The light detector circuit has a relay that is supplying current to a solenoid in a track piece. 

The solenoid is holding a steel marble and is waiting to launch it once the light detector detects light because this causes the relay switch to move and create an open circuit that stops current from flowing to the solenoid.

After the loss in current, the solenoid in it's cardboard and electrical tape track piece pushes the marble into the metal detector circuits inductor (large copper coil).

Before and after the marble enters the coil, the Arduino is actively monitoring the frequency of the metal detector circuit using a 555 timer's Vout pin

and the cardboard box on the right-side of the footage is the where AirPods are magnetizing onto using an electromagnet.

The Arduino detects if a correct piano key sequence is entered, which then activates a series of other circuits, and eventually cause the electromagnet to stop  magnetizing with the AirPods, so the AirPods drop and can be caught by the user. 

Check out the code for piano and frequency detector in the directories above, and feel free to use them.

<img width="1075" alt="Rube Goldberg Fully Assembled" src="Images/LiveSystem.png">

## Black Box Schematic with Integration Descriptions
<img width="700" src="Images/CAD-EE241-Circut.png">

## Piano
<img width="700" src="Images/piano.png">

## Strobe Light
<img width="700" src="Images/strobe.png">

## Light Detector PCB
<img width="700" src="Images/LightDetectorPCB.png">

### Presoldered Light Detector PCB
<img width="700" src="Images/PCBFront-Luis.png">

## Metal Detector Circuit
<img width="700" src="Images/MetalDetector.png">
