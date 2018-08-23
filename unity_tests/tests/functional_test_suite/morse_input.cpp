/*
 * morse_input.cpp
 *
 *  Created on: Aug 22, 2018
 *      Author: lukaszsx
 */

#include "morse_encoder.c"
#include "gtest/gtest.h"

TEST(Morse_encoder_test, Correct_encoding)
{
	char * actual = morse('S');
	ASSERT_STREQ(actual ,"...");
}



