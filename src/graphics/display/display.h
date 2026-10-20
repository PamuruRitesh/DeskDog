#ifndef DISPLAY_H
#define DISPLAY_H

#include "display_interface.h"

void init_display();
void clear_display();
void update_display();

DisplayInterface& get_display();

#endif