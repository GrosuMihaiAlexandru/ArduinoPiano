#pragma once

#define disk1 0x50

class EEprom
{
private:
	int deviceAddress;
	int EEAddress = 0;

	unsigned long lastMillis=0;
	unsigned int address;

	void writeEEPROM(byte data);
	byte readEEPROM();

public:

	EEprom(int deviceAddress);
	

	Note readNote();
	void writeNote(byte noteLength, byte note);

	void selectSlot(byte slot);

};