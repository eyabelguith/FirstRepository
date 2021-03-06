#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
#include "/usr/include/SDL/SDL_ttf.h"
/**
* @struct buttons
* @brief struct for buttons 
*/

typedef struct
{
    SDL_Surface *play[3]; /*!< Surface. */
    SDL_Surface *instructions[3]; /*!< Surface. */
    SDL_Surface *setting[3]; /*!< Surface. */
    SDL_Surface *exit[3]; /*!< Surface. */
}buttons;

int main ( int argc, char** argv );
void cleanmenu(SDL_Surface *background,SDL_Surface *texte);

#endif // MAIN_H_INCLUDED
