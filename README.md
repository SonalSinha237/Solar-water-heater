# Solar Water Heater

As the name indicates, this heater uses solar energy to heat the water. It converts the solar energy captured using the solar panel to electrical energy, which is stored in the rechargable Lithium battery. The features are:
* It allows the user to enter the themperature upto which they want the water to be heated to.
* The auto-cut system stops the process automatically when the required temperature is reached. This helps avoiding wastage of energy.
* The LED indicates completion of task.

This heater doesn't require plug points to heat the water and there is no need of recharging it also. It solely depends on solar energy and the amount of energy left in the battery.

## Components required for this project:
1. Arduino UNO 
1. Solar Panel (Here, we have used the 6V panel)
1. Solar Power Management Module 
1. Rechargeable Lithium Battery (3.7V)
1. DC-DC Step up Rectifier 
1. 12V PTC Heating Element 
1. DS18B20 Water Proof Temperature Probe 
1. 5VDC Relay 
1. Breadboard 
1. Keypad 
1. LCM1602ic 
1. LCD screen
1. Red LED
1. Resistors and capacitors
1. Jumper Wires

## Working:

- A black absorbing surface that is present inside the collector absorbs solar energy when the Sun’s rays strike the solar panel. In reaction to a cell’s internal electrical field, this energy generates electrical charges that migrate, generating electricity and transferring it to the solar power management module’s battery.
- The 6V–24V solar panel is the intended use for this solar power management module. The PTC heating element will be heated using the energy that is kept in reserve by the rechargeable lithium ion battery.
- In solar power management module, red light will turn on which indicates that the module is getting charged by solar panel and green light will turn on when the module is fully charged.
- As long as it is turned on, electricity continues to flow into the heating components. The heating element takes 12V of input while the Solar Power Management Module outputs 5V.
- To get 12V dc, a DC-DC step up converter is used. It is a power electronics device which receives a DC input voltage and outputs the required DC voltage.
- The heating element is managed by an Arduino Uno, which is also used to read sensor data.
- The keypad is linked to digitals and used to collect user input. The heating element will switch on when the user enters the temperature.
- The water temperature probe maintains track of the water’s temperature, and when it reaches the correct temperature, it uses the relay module(that serves as a switch) to turn off the heating element.
- The user will be informed when the water has reached the specified temperature with a red LED. Along with that, "Process Finished" message will appear on the LCD.

Images of block diagram, circuit diagram and circuit implimentation can be found in this repository.

### Some useful links for making the circuit:
- [Interfacing temperature sensor with Arduino UNO](https://arduinogetstarted.com/tutorials/arduino-temperature-sensor#google_vignette)
- [Heating element](https://arduinogetstarted.com/tutorials/arduino-controls-heating-element)

## Future Scope
Although, we have used a bottle in this project but it is still not that portable. The whole circuit if implemented on a smaller scale using PCB or IC will make it more portable and easy to use. Using a thermally insulated bottle instead of a plastic one will ensure that water stays hot for longer duration.




