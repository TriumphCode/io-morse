/*
 * morse_input.cpp
 *
 *  Created on: Aug 22, 2018
 *      Author: lukaszsx
 */

#include "morse_io.c"
#include "gtest/gtest.h"

TEST(Morse_encoder_test, Correct_char_encoding)
{
	const char * actual = char_to_morse('S');
	ASSERT_STREQ(actual ,"...");
	actual = char_to_morse('O');
	ASSERT_STREQ(actual ,"---");
	actual = char_to_morse('S');
	ASSERT_STREQ(actual ,"...");
}

