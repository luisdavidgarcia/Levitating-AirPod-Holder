# Levitating-AirPod-Holder 🎧
An Airpod holder that makes your AirPods levitate. You can charge you Airpods while theyhang free in the air without worry of them falling or coming off easily if the Airpods are pushed since the Airpods are held by an electromagnet similar to [Apple Watch magnetic charger](https://www.apple.com/shop/product/MLWJ3AM/A/apple-watch-magnetic-fast-charger-to-usb-c-cable-1-m?fnode=2208a3f74724fa33198e29a17b1f3a3c42954541e1e18d408c15ce020bbe1ffb7f20a725ff6803d451b2b2cf065861b37722565385e5e1ae812c66dc35fa952064c5414a95d16900b6f75cc4df8177f9f0c4c5d48c881cd8cf9d78b46305a820999709c1c824e5f8bf7be8a9189ac629&fs=fh%3D4595%252B559a0f%252B45d4), expect this charger makes your airpods levitate.

Just stick the airpods to the magnet and watch them be in mid-air. 

However, there is also a security component to the AirPod holder. 

To elaborate one cannot simply remove the Airpods from the electromagnet instead one must know the proper keyboard sequence to have the AirpPods stop magnetizing. 

The AirPod holder is considered a Rube Goldberg machine. The entire system contains 5 circuits running on Arudino Code. The circuits involved were an electromagnet, piano keyboard, metal detector, light detector, and strobe light circuit.

The first circuit needed which creates the trigger for the system is the cardboard piano. 

In the piano circuit you need to use the aluminum foil and tape to create the keys for the circuit, but then you also have to create the code necessary for a keyboard sequence to be detected and send 5V to the relay that opens the strobe light circuit. 

The strobe light circuit comes from this kit, and all that was needed was a soldering iron, soldering paste, wires, wire clippers, wire strippers, and a soldering pump. Instructions came with how to construct the circuit, but in the case that you accidently solder a component to a wrong position use the soldering pump to take the component out and try again. 

The relay from the cardboard piano circuit causes the strobe light to flash (turn on) once 5V is supplied since the relay's switch turns to its other pin, which then connects the 9V battery with the strobe light circuit.

The light flash is detected by the light detector which contains a photoresistor that detects the light and contains a relay that stops supplying current to the solenoid in its circuit.

When the solenoid loses power it pushes the the steel ball into the metal detector's copper coil.

As soon as the ball enters the coil the Arduino detects a frequency change from the Vout output of the metal detector circuit. 

This change in frequency then causes the final relay to stop supplying current to the electromagnet that is holding the AirPods, that way you can catch them and use them as you please. 

The electromagnet then magnetizes once again and waits for you to enter the correct sequence to stop magnetizing. 
