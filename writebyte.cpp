"//writing a byte, bit-by-bit to an external device using 1-wirw protocol"
#include <iostream>
#include <arduino.h>

using namespace std;

void byte_write( byte command, byte pin ){
	for (int i =0;i<8;i++){
		if (command>>i & 0x01){
			pinMode(pin, OUTPUT);
			digitalWrite(pin, LOW);
			delay microseconds(1);
			pinMode(pin, INPUT);
			delay microseconds(60);

		} else if (!command>>i& 0x01){
			pinMode(pin, OUTPUT);
			digitalWrite(pin,LOW);
			delay microseconds(60);
			pinMode(pin, INPUT);
			delay microseconds(1);
		}
	}

}
int main(){
	return 0;
} 
