#include <EEprom.h>
#include <Wire.h>

EEprom::EEprom(int deviceAddress)
{
	this->deviceAddress = deviceAddress;
	Wire.begin();
}

void EEprom::writeEEPROM(byte data)
{
	unsigned long currentMillis = millis();

	while(1)
		if (lastMillis - currentMillis >= 5)
		{
			lastMillis = currentMillis;

			Wire.beginTransmission(deviceAddress);
			Wire.write((int)(EEAddress >> 8));
			Wire.write((int)(EEAddress & 0xFF));
			Wire.write(data);
			Wire.endTransmission();
			EEAddress++;
			return;
		}
}

byte EEprom::readEEPROM()
{
	byte rdata = 0xFF;
	
	Wire.beginTransmission(deviceAddress);
	Wire.write((int)(EEAddress >> 8));
	Wire.write((int)(EEAddress & 0xFF));
	Wire.requestFrom(deviceAddress, 1);

	if (Wire.available())
		rdata = Wire.read();
	return rdata;
}

//	noteLength: 1 = 25ms
void EEprom::writeNote(byte noteLength, byte note)
{
	writeEEPROM(note);
	writeEEPROM(noteLength);
}

Note EEprom::readNote()
{
	return Note(readEEPROM(),readEEPROM());
}


void EEprom::selectSlot(byte slot)
{
	if (slot == 0)
		EEAddress = 0;
	else if (slot == 1)
		EEAddress = 8000;
	else if (slot == 2)
		EEAddress = 16000;
	else
		EEAddress = 24000;
}

