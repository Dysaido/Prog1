#ifndef PROG1_H
#define PROG1_H

/**
 * Our own type for (pointers to) strings.
 */
typedef char * string;

//////////////////////////////////////////////////////////////////////////////
//
//   Public Interface
//

string get_string(const char* prompt);

int my_lenght(const string str);

#endif    // PROG1_H