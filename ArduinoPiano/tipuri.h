#pragma once
struct buzzer {
	int pin;
	bool ocupat;
	buzzer(int pin) :pin(pin), ocupat(false) {}
};

struct nota {
	int frec, durata;
	nota(int frecventa, int durata) : frec(frecventa), durata(durata) {}
};

//const int frevente[] = {};