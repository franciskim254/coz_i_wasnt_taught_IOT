//writing a byte, bit-by-bit to an external device using 1-wirw protocol
// this follows a write 1 = LOW (1µs) → HIGH (59µs idle)
//  ...           write 0 = LOW (60µs) → HIGH (1µs idle)


#include <Arduino.h>

void byte_write( byte command, byte pin ){
	for (int i =0;i<8;i++){
		if ((command>>i) & 0x01){
			pinMode(pin, OUTPUT);
			digitalWrite(pin, LOW);
			delayMicroseconds(1);
			pinMode(pin, INPUT);
			delayMicroseconds(60);

		} else {
			pinMode(pin, OUTPUT);
			digitalWrite(pin,LOW);
			delayMicroseconds(60);
			pinMode(pin, INPUT);
			delayMicroseconds(1);
		}
	}

}
void setup() {
    byte data = 0b10101010; // Example byte to send
    byte pin = 7; // Example pin
    byte_write(data, pin);
}

void loop() {
    // Keep looping if needed
}
