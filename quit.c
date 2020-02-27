#include "quit.h"

/**
* @file quit.c
* @brief Testing quit.
* @author OH my code 
* @version 0.1
* @date may 01, 2019
*
* Testing program for quit from the game 
*
*/


int quit(SDL_Surface *screen)
{
    SDL_Surface *background=NULL;
    quitter q;
    int done=1;
    int n=2,t=0;
    SDL_Rect pos,posyes,posno;
    SDL_Event event;
    pos.x=130;
    pos.y=200;

    posyes.x=350;
    posyes.y=300;

    posno.x=350;
    posno.y=400;
    int x=500;
    background=SDL_LoadBMP("menu.BMP");
    q.exit[6]=SDL_LoadBMP("exit.bmp");
    q.exit[0]=SDL_LoadBMP("yes0.BMP");
    q.exit[1]=SDL_LoadBMP("no0.BMP");
    q.exit[2]=SDL_LoadBMP("yes1.BMP");
    q.exit[3]=SDL_LoadBMP("no1.BMP");
    q.exit[4]=SDL_LoadBMP("yes2.BMP");
    q.exit[5]=SDL_LoadBMP("no2.BMP");
    while(done!=0)
    {
        SDL_BlitSurface(background,NULL,screen,NULL);
        if (n==2)
        {
            SDL_BlitSurface(q.exit[6],NULL,screen,&pos);
            SDL_BlitSurface(q.exit[n],NULL,screen,&posyes);
            SDL_BlitSurface(q.exit[1],NULL,screen,&posno);
            SDL_Flip(screen);
        }
        else if (n==3)
        {
            SDL_BlitSurface(q.exit[6],NULL,screen,&pos);
            SDL_BlitSurface(q.exit[n],NULL,screen,&posno);
            SDL_BlitSurface(q.exit[0],NULL,screen,&posyes);
            SDL_Flip(screen);
        }
        else
        {
            SDL_BlitSurface(q.exit[6],NULL,screen,&pos);
            SDL_BlitSurface(q.exit[0],NULL,screen,&posyes);
            SDL_BlitSurface(q.exit[1],NULL,screen,&posno);
            SDL_Flip(screen);
        }
        SDL_WaitEvent(&event);
        t=0;
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done=0;
                break;
            case SDLK_UP:

                if (n==2 && t==0)
                {
                    n++;
                    t=1;
                }
                else if (n==3 && t==0)
                {
                    n--;
                    t=1;
                }
                break;
            case SDLK_DOWN:
                if (n==2 && t==0)
                {
                    n++;
                    t=1;
                }
                else if (n==3 && t==0)
                {
                    n--;
                    t=1;
                }
                break;
            case SDLK_RETURN:
                if (n==2)
                {
                    SDL_BlitSurface(q.exit[4],NULL,screen,&posyes);
                    SDL_Flip(screen);
                    //SDL_Delay (200);
                    SDL_FreeSurface(background);
                    SDL_FreeSurface(q.exit[n]);
                    return 1;
                }
                else if (n==3)
                {
                    SDL_BlitSurface(q.exit[5],NULL,screen,&posno);
                    SDL_Flip(screen);
                    //SDL_Delay (200);
                    SDL_FreeSurface(background);
                    SDL_FreeSurface(q.exit[n]);
                    return 0;
                }
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            n=6;
            //printf("%d,%d\n",event.motion.x,event.motion.y);
            if ((event.motion.x>x-100) && (event.motion.y>x-180) && (event.motion.x<x+150) && (event.motion.y<380))
            {
                n=2;
            }
            else if ((event.motion.x>x-100) && (event.motion.y>x-180) && (event.motion.x<x+80) && (event.motion.y<500))
            {
                n=3;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if ((event.motion.x>x-100) && (event.motion.y>x-180) && (event.motion.x<x-150) && (event.motion.y<380))
            {
                SDL_BlitSurface(q.exit[4],NULL,screen,&posyes);
                SDL_Flip(screen);
                //SDL_Delay (200);
                return 1;
            }
            else if ((event.motion.x>x-100) && (event.motion.y>x-180) && (event.motion.x<x+80) && (event.motion.y<500) )
            {
                SDL_BlitSurface(q.exit[5],NULL,screen,&posno);
                SDL_Flip(screen);
                SDL_Delay (50);
                return 0;
            }
            break;
        }
    }

}

