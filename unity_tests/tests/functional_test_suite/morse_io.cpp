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

TEST(Morse_encoder_test, Correct_string_encoding)
{
	const char * actual = string_to_morse("This");
	ASSERT_STREQ(actual ,"... .-.-.-");
	actual = string_to_morse("is");
	ASSERT_STREQ(actual ,".. ...");
	actual = string_to_morse("Morse");
	ASSERT_STREQ(actual ,"-- --- .-. ... .");
}


TEST(Morse_decoder_test, Correct_morse_decoding)
{
	const char * actual = morse_to_char("...");
	ASSERT_STREQ(actual ,"SOS");
}

