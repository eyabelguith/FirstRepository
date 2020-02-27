#include "main.h"

#include "/usr/include/SDL/SDL_ttf.h"


int main ( int argc, char** argv )
{
// text
TTF_Font *police=NULL;
SDL_Color couleurNoire = {255,255, 0};



    SDL_Surface *screen=NULL;
    SDL_Surface *background=NULL;
SDL_Surface *texte =NULL;//t
    buttons b;
 SDL_Init(SDL_INIT_VIDEO);
 TTF_Init();

    screen=SDL_SetVideoMode (990,690,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("ESCAPE ON MARS",NULL);//titre de la fenetre
    SDL_WarpMouse(screen->w / 2, screen->h / 2);
    SDL_EnableKeyRepeat(100,100);
    background =SDL_LoadBMP("menu.BMP");

    SDL_Rect background_pos;
    SDL_Rect pxy,pxin,pxset,pxexit,postxt;
    SDL_Event event;
    background_pos.x=0;
    background_pos.y=0;
    pxy.x=250;
pxy.y=200;

    pxin.x=250;
    pxin.y=300;

    pxset.x=250;
    pxset.y=400;

    pxexit.x=250;
    pxexit.y=500;

postxt.x=100;
postxt.y=50;

    int pp=2,op=0,ex=0,ins=0,t;
    int done=1;
    int motion=330;
 b.play[0]=SDL_LoadBMP("play0.BMP");
    b.play[1]=SDL_LoadBMP("play1.BMP");
    b.play[2]=SDL_LoadBMP("play2.BMP");
    b.instructions[0]=SDL_LoadBMP("instruction0.BMP");
    b.instructions[1]=SDL_LoadBMP("instruction1.BMP");
    b.instructions[2]=SDL_LoadBMP("instruction2.bmp");
    b.setting[0]=SDL_LoadBMP("settings0.BMP");
    b.setting[1]=SDL_LoadBMP("settings1.BMP");
    b.setting[2]=SDL_LoadBMP("settings2.BMP");
    b.exit[0]=SDL_LoadBMP("quit0.BMP");
    b.exit[1]=SDL_LoadBMP("quit1.BMP");
    b.exit[2]=SDL_LoadBMP("quit2.BMP");
 
  police = TTF_OpenFont("arial.ttf",100);
   if(police!=NULL){
  texte=TTF_RenderText_Blended(police, "Escape on Mars", couleurNoire);

}




// code musique

 
   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer



 {
      printf("%s", Mix_GetError());
   }
   Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
   musique = Mix_LoadMUS("game.mp3"); //Chargement de la musique
 Mix_Music *clic;
clic=Mix_LoadWAV("popup.wav");
   Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

// code musique 
while (done!=0)
{
        SDL_BlitSurface(background,NULL,screen,NULL);
        SDL_BlitSurface(b.play[pp],NULL,screen,&pxy);
        SDL_BlitSurface(b.instructions[ins],NULL,screen,&pxin);
        SDL_BlitSurface(b.setting[op],NULL,screen,&pxset);
        SDL_BlitSurface(b.exit[ex],NULL,screen,&pxexit);


SDL_BlitSurface(texte,NULL, screen ,&postxt);
SDL_Flip(screen);
        t=0;
        if (SDL_WaitEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT :
                if (quit(screen)==1)
                    done=0;
                break;
            case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                   if (quit(screen)==1)
                        done=0;
                 break;
                case SDLK_UP:
                    if (pp==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);
                        ex=1;
                        pp=0;
                        op=0;
                        ins=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);

                        pp=1;
                        op=0;
                        ex=0;
                        ins=0;
            t=1;
                    }
                    else if (op==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);

                        ins=1;
                        ex=0;
                        pp=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);

                        op=1;
                        ex=0;
                        pp=0;
                     ins=0;
                        t=0;
                    }
                    break;
                case SDLK_DOWN:
                    if (pp==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);

                        ins=1;
                        ex=0;
                        op=0;
                        pp=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);
                    pp=0;
                        op=1;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);

                        ex=1;
                        pp=0;
                        ins=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    { Mix_PlayChannel(1 ,clic, 0);
        pp=1;
                        op=0;
                        ins=0;
                        ex=0;
                        t=1;
                    }
                    break;
                case SDLK_RETURN:
                    if (pp==1)
                    { Mix_PlayChannel(1 ,clic, 0);

                        SDL_BlitSurface(b.play[2],NULL,screen,&pxy);
                        SDL_Flip(screen);
                  //    SDL_Delay(1);// nahit com
                        //return NEW_GAME;
}





 else if (ins==1)
                    { Mix_PlayChannel(1 ,clic, 0);

                         SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                      instructions(screen);
                       ins=0;

                    //    SDL_Delay(1);// nahit delay

                        //return OPTION;
                    }
                    else if (op==1)
                    {
                        SDL_BlitSurface(b.setting[2],NULL,screen,&pxset);
                        SDL_Flip(screen);
 Mix_PlayChannel(1 ,clic, 0);
      //  SDL_Delay(1);//nahit delay
                        option(screen);
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
 Mix_PlayChannel(1 ,clic, 0);

                        SDL_Flip(screen);
                    if (quit(screen)==1)
                            done=0;
                       // SDL_Delay(1); // nahit delay 
                    }
                    break;
                }
                break;
      case SDL_MOUSEMOTION:
                ex=0;
                pp=0;
                op=0;
                t=0;
                if ((event.motion.x>motion)&&(event.motion.y>motion-117)&&(event.motion.x<motion+131)&&(event.motion.y<motion-40) && (t==0) && (pp==0))
                { Mix_PlayChannel(1 ,clic, 0);

                    pp=1;
                    ex=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>motion)&&(event.motion.y>motion+0)&&(event.motion.x<motion+130)&&(event.motion.y<motion+10) &&(t==0)&& (ins==0))
                { Mix_PlayChannel(1 ,clic, 0);
      ex=0;
                    pp=0;
                    ins=1;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>motion)&&(event.motion.y>motion+80)&&(event.motion.x<motion+140)&&(event.motion.y<motion+140)&&(t==0)
 && (op==0))               { Mix_PlayChannel(1 ,clic, 0);

                    ex=0;
                    pp=0;
                    ins=0;
                    op=1;
                    t=1;
                }
                else if ((event.motion.x>motion)&&(event.motion.y>motion+231)&&(event.motion.x<motion+228)&&(event.motion.y<motion+259)&&(t==0)
&& (ex==0))                { Mix_PlayChannel(1 ,clic, 0);
                    ex=1;
                    pp=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if ((event.motion.x>motion) && (event.motion.y>motion+117) && (event.motion.x<motion+131) && (event.motion.y<motion+145)&&(pp==1))
                    { Mix_PlayChannel(1 ,clic, 0);

                        pp=2;
                       // SDL_Delay (1);// delay naht
                        //play(screen);
  //return NEW_GAME;
                    }
                    else if ((event.motion.x>motion) && (event.motion.y>motion+155) && (event.motion.x<motion+152) && (event.motion.y<motion+183)&&(ins==1))
                    {

                        SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                        instructions(screen);
                       //ins=0;
 Mix_PlayChannel(1 ,clic, 0);



                       // SDL_Delay (200);// delay
                        //return OPTION;
                    }
                    else if ((event.motion.x>motion) && (event.motion.y>523) && (event.motion.x<520) && (event.motion.y<551)&&(op==1))
   {
                        op=2;
                        option(screen);
                       // SDL_Delay (1);//dleay
                        //return OPTION;
 Mix_PlayChannel(1 ,clic, 0);

                    }
                    else if (ex==1)
                    { Mix_PlayChannel(1 ,clic, 0);

                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                       // SDL_Delay (1);//delay
                        if (quit(screen)==1)
                            done=0;
                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);

Mix_FreeMusic(musique); //Libération de la musique
Mix_CloseAudio(); //Fermeture de l'API
TTF_CloseFont(police);
TTF_Quit();
    SDL_Quit();
  return 0 ;
    }

void cleanmenu(SDL_Surface *background,SDL_Surface *texte)
{
    buttons b;
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);
    SDL_FreeSurface(texte);
}

