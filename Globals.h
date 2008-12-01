

// Output preparation function
// See the "snprintf" documentation in a C language reference.
// Note: This function does not actually output any text to the screen.
//		 All it does is collect input into a single string which may then
//		 be passed to a method such as TethysGame::AddMessage to actually
//		 output the text.
OP2 int __cdecl scr_snprintf(char* writeBuffer, unsigned int bufferLength, const char* formatString, ...);


// Note: Here is the only exported variable from Outpost2.exe used for
//		 level programming. It consists of an array of 7 players
//		 (numbered 0-6) which can be used to manipulate all the players
//		 in the level. See Player.h for details.

OP2 class _Player Player[7];



