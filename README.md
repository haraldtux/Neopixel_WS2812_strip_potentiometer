# Neopixel WS2812 strip controlled by potentiometer

Lighting control of a small Neopixel strip (8 LEDs) with an ATtiny85 microcontroller and a 10k potentiometer.
The potentiometer acts as a voltage divider and sends a range of 0 to 5 volts to the analog input A1 of the ATtiny85, converting this analog signal into digital (10-bit resolution). A map function will collect the data from input A1y and the 8 Neopixel LEDs will light up proportionally (circuit diagram in the last picture).
