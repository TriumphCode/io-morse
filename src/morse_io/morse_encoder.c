/*
 * morse_encoder.c
 *
 *  Created on: Aug 22, 2018
 *      Author: lukaszsx
 */


// Morse encoder , (C)2016 Radu Motisan , www.pocketmagic.net
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const char *latins = "**ETIANMSURWDKGOHVF*L*PJBXCYZQ**"; //32

void dash() { printf("-"); }
void dot() { printf("."); }

char conv(uint8_t decimal) {
	if (decimal) {
		conv(decimal/2);
		if (decimal != 1) decimal%2 ? dash() : dot();
	}
}

char * morse(char c) {
	char * morse_enoder;
	if (c >= 'a' && c <= 'z') c -= 32; // convert to uppercase
	if (c < 'A' || c > 'Z') return morse_enoder;
	uint8_t i = 0;
	uint8_t n = 0;
	while (latins[++i] != c)
	{
		morse_enoder[n++]=conv(i);
	}
	return  morse_enoder;
}


char *  morse_string(const char* s)
{
	char * morse_string;
	int i = 0;
    while (*s)
    	morse_string[i++]= morse(*s++);

    return morse_string;
}
