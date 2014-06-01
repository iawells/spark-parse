// This provides a variable, colour, a function to set the variable from a hex
// string, set_colour, and programs the RGB LED on the spark core to reflect
// the RRGGBB value last programmed.  The default on reboot is black.

// BEWARE: British spelling ahead!

#include "spark-parse.h"

static int colour = 0;

int set_colour(String args)
{
    // parse_hex only likes uppercase
    args.toUpperCase();
        
    // Parse arg to colour settings
    int val = parse_hex(args);
    if (val != -1) {
        colour = val;
    }

    // Returns the value, if it took, or the previous colour setting, if
    // it didn't.
    return colour;
}

void setup() {
    RGB.control(true);

    Spark.function("set_colour", set_colour);
    Spark.variable("colour", &colour, INT);
}

void loop() {
    // Colour value is the standard RRGGBB layout, which we break up here.
    RGB.color((colour >> 16) & 255, (colour >> 8) & 255, colour & 255);
}

