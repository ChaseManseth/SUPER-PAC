/*
* Author: Zachary Steudel, Chase Manseth, Meghan Bibb,
* Will Rhoden, Bailey Stone
* Assignment Title:  Pacman Group Project
* Assignment Description: User can play a faithfully recreated
* version of pacman.
* Due Date: 12/4/2017
* Date Created: 11/1/2017
* Date Last Modified: 12/2/2017
*/

/*
Data Abstraction:
    7 Mix_Chunks to hold the sound files used in the game.
    int nums[][][], lets[][][], and graphic[][][] to hold font and graphical values.
    bool releaseCalled for checking if a ghost has been released from box.
    bool rando for sending in to releaseGhost.
    int numEaten for counting the number of pellets eaten.
    int counter to start a timer when an energizer is eaten.
    SDL_Plotter g for holding the game window and graphics.
    Pacman pac to hold the pacman object that the user plays as.
    Tile map[][] to hold every tile of the game.
    color blink, pink, ink, cly for the colors of each respective ghost.
    ghosts inky, blinky, pinky and clyde for each ghost object.

Input: User can input directional keys in order to move
pacman around the game map.

Process: Game handles pacman movement and ghost movement
in order to have ghosts chase pacman while the user moves pacman in normal state.
When in scared state, the ghosts will run away from pacman as the user chases them.

Output: program displays pacman game through SDL_Plotter window.
program outputs pacman and ghost movement, score updating, and
various uses of font to print messages to the user.

Assumptions: no assumptions are made.
*/
#include <iostream>
#include <fstream>
#include "pacman.h"
#include "tile.h"
#include "ghosts.h"
#include "init.h"
#include "font.h"

using namespace std;

/*
Description: function resets the ghosts into
their monster box.
Return: none
Precondition: all ghost objects are valid, g and map are valid.
Postcondition: ghost positions are moved.
*/
void rePositionGhosts(SDL_Plotter& g, Ghost& a, Ghost& b, Ghost& c, Ghost& d, Tile map[36][28]);
/*
Description: function releases one ghost from monster box
Return: none
Precondition: ghost object, map, and bool r are valid.
Postcondition: ghost position is changed and ghost is set to active.
*/
void releaseGhost(Ghost& a, Tile map[36][28], bool& r);

int main(int argc, char** argv)
{
    //data abstraction
    Mix_Chunk *gEat         = NULL;
    Mix_Music *gAmbient     = NULL;
    Mix_Chunk *gDeath       = NULL;
    Mix_Chunk *gGhostDead   = NULL;
    Mix_Chunk *gPowerPellet = NULL;
    Mix_Chunk *gGame_Over   = NULL;
    Mix_Chunk *gBegin       = NULL;
    char key;
    // Graphic Arrays
    int nums[10][25][25];
    int lets[26][25][25];
    int graphic[31][25][25];

    bool releaseCalled = false;
    bool rando    = false;
    int numEaten  = 0;
    int counter   = 0;
    SDL_Plotter g(900,700);

    Pacman pac(26,13);
    Tile map[36][28];
    // Initialize map and everything in it
    init(map, g, nums, lets, graphic);

    Color blink(255,20,20);
    Ghost blinky(blink, map);

    Color pink(255,102,178);
    Ghost pinky(pink, map);

    Color ink(0, 255, 255);
    Ghost inky(ink, map);

    Color cly(255, 165, 0);
    Ghost clyde(cly, map);

    //initialize audio functionality
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    //initialize sound files
    gEat = Mix_LoadWAV("wakka_wakka1.wav");
    gDeath = Mix_LoadWAV("life_lost.wav");
    gGhostDead = Mix_LoadWAV("ghost_eaten.wav");
    gAmbient = Mix_LoadMUS("ghosts_ambient.wav");
    gPowerPellet = Mix_LoadWAV("power_pellet_eaten.wav");
    gGame_Over = Mix_LoadWAV("game_over.wav");
    gBegin = Mix_LoadWAV("pacman_beginning.wav");

    //process & output to screen
    //prints score, initializes numbers and font
    initLetter();
    initNumber();

    drawLetter(g, 2, 1, s);
    drawLetter(g, 3, 1, c);
    drawLetter(g, 4, 1, o);
    drawLetter(g, 5, 1, r);
    drawLetter(g, 6, 1, e);

    updateScore(pac.getScore(), g, map);

    rePositionGhosts(g, blinky, pinky, inky, clyde, map);

    pac.drawPac(g);

    pinky.draw(g, map);
    inky.draw(g, map);
    blinky.draw(g, map);
    clyde.draw(g, map);

    g.update();

    Mix_PlayChannel( -1, gBegin, 0 );
    g.Sleep(4000);

    //ambient ghost noise in background
    Mix_PlayMusic(gAmbient, -1 );

    Mix_VolumeMusic(24);

    //master loop of game
    while(!g.getQuit())
    {
        for(int i = 0; i < 60; i++)
        {
            //maximum number of pellets, this signifies a win
            if(numEaten == 244)
            {
                //you win
                Mix_PauseMusic();
                //make temporary score and lives int to hold previous pacman data
                int score = pac.getScore();
                int lives = pac.getLives();
                //make new pacman
                pac = Pacman(26, 13);
                init(map, g, nums, lets, graphic);
                pac.setScore(score);
                pac.setLives(lives + 1);

                pac.setState(NORMAL);

                pac.drawPac(g);

                rePositionGhosts(g, blinky, inky, pinky, clyde, map);

                blinky.setColor(blink);
                inky.setColor(ink);
                pinky.setColor(pink);
                clyde.setColor(cly);

                pinky.draw(g, map);
                inky.draw(g, map);
                blinky.draw(g, map);
                clyde.draw(g, map);

                drawLetter(g, 2, 1, s);
                drawLetter(g, 3, 1, c);
                drawLetter(g, 4, 1, o);
                drawLetter(g, 5, 1, r);
                drawLetter(g, 6, 1, e);

                g.update();

                Mix_PlayChannel( -1, gBegin, 0 );
                g.Sleep(4000);

                numEaten = 0;

                Mix_ResumeMusic();
            }
            map[35][0].drawTile(g);
            map[35][1].drawTile(g);
            map[35][2].drawTile(g);
            map[35][3].drawTile(g);
            map[35][4].drawTile(g);
            map[35][5].drawTile(g);

            //print the lives of pacman at bottom left
            for(int c = 0; c < pac.getLives(); c++)
            {
                Pacman p = Pacman(35, c);
                p.setWaka(FULL_WAKA);
                p.drawPac(g);
            }

            //handle pacman animation
            if(pac.getWaka() == HALF2 && i % 8 == 0)
            {
                pac.setWaka(CLOSED_WAKA);
            }
            else if(i % 8 == 0)
            {
                pac.setWaka(pac.getWaka() + 1);
            }
            //erase the old position of ghosts
            pinky.erase(g, map);
            map[pinky.getR()][pinky.getC()].drawTile(g);
            blinky.erase(g, map);
            map[blinky.getR()][blinky.getC()].drawTile(g);
            inky.erase(g, map);
            map[inky.getR()][inky.getC()].drawTile(g);
            clyde.erase(g, map);
            map[clyde.getR()][clyde.getC()].drawTile(g);

            if(pac.getState() == NORMAL)
            {
                //handles ghost movement & collision
                //+ pacman death, death sounds
                pinky.target(pac);
                //pinky is slowest
                if(i % 2 == 0)
                {
                    pinky.move(map, g);
                }
                pinky.draw(g, map);
                blinky.target(pac);
                //blinky is fastest
                if(i % 3 == 0)
                {
                    blinky.move(map, g);
                }
                blinky.move(map, g);
                blinky.draw(g, map);
                inky.target(pac);
                //inky is normal speed
                inky.move(map, g);
                inky.draw(g, map);
                clyde.target(pac);
                //clyde is second fastest
                if(i % 5 == 0)
                {
                    clyde.move(map, g);
                }
                clyde.move(map, g);
                clyde.draw(g, map);
                //check collision with any ghosts
                if(clyde.isCollide(map, pac, g) || inky.isCollide(map, pac, g)
                   || blinky.isCollide(map, pac, g) || pinky.isCollide(map, pac, g))
                {
                    Mix_PauseMusic();
                    Mix_PlayChannel( -1, gDeath, 0 );
                    g.Sleep(1500);
                    Mix_ResumeMusic();
                    rePositionGhosts(g, blinky, pinky, inky, clyde, map);
                    pac.setR(26);
                    pac.setC(13);

                    pac.setLives(pac.getLives() - 1);

                    pac.setCenter(map[26][13].getCenter());
                }
                //if pacman dies, reset game, TODO: print game over
                if(pac.getLives() == 0)
                {
                    Mix_PauseMusic();
                    Mix_PlayChannel( -1, gGame_Over, 0 );
                    g.Sleep(4000);
                    pac = Pacman(26, 13);
                    init(map, g, nums, lets, graphic);
                    Mix_ResumeMusic();

                    drawLetter(g, 2, 1, s);
                    drawLetter(g, 3, 1, c);
                    drawLetter(g, 4, 1, o);
                    drawLetter(g, 5, 1, r);
                    drawLetter(g, 6, 1, e);

                    numEaten = 0;
                }
            }
            else if(pac.getState() == SUPERPAC)
            {
                if(i == 59)
                {
                    counter++;
                }

                //set ghosts dark blue
                blinky.setColor(Color(0, 0, 205));
                inky.setColor(Color(0, 0, 205));
                pinky.setColor(Color(0, 0, 205));
                clyde.setColor(Color(0, 0, 205));

                blinky.target(pac);
                inky.target(pac);
                pinky.target(pac);
                clyde.target(pac);

                //all ghosts are now slower
                if(i % 8 == 0)
                {
                    blinky.moveFrightened(map, g, pac);
                }
                blinky.moveFrightened(map, g, pac);
                if(i % 2 == 0)
                {
                    pinky.moveFrightened(map, g, pac);
                }
                inky.moveFrightened(map, g, pac);
                if(i % 10 == 0)
                {
                    clyde.moveFrightened(map, g, pac);
                }
                clyde.moveFrightened(map, g, pac);
                //check for ghost dying, play death noise
                //increment score
                if(blinky.isCollide(map, pac, g))
                {
                    Mix_PlayChannel( -1, gGhostDead, 0 );
                    g.Sleep(250);
                    releaseGhost(blinky, map, rando);
                    pac.setScore(pac.getScore() + 200);

                    updateScore(pac.getScore(), g, map);

                }
                if(inky.isCollide(map, pac, g))
                {
                    Mix_PlayChannel( -1, gGhostDead, 0 );
                    g.Sleep(250);
                    releaseGhost(inky, map, rando);
                    pac.setScore(pac.getScore() + 200);

                    updateScore(pac.getScore(), g, map);

                }
                if(pinky.isCollide(map, pac, g))
                {
                    Mix_PlayChannel( -1, gGhostDead, 0 );
                    g.Sleep(250);
                    releaseGhost(pinky, map, rando);
                    pac.setScore(pac.getScore() + 200);


                    updateScore(pac.getScore(), g, map);

                }
                if(clyde.isCollide(map, pac, g))
                {
                    Mix_PlayChannel( -1, gGhostDead, 0 );
                    g.Sleep(250);
                    releaseGhost(clyde, map, rando);
                    pac.setScore(pac.getScore() + 200);

                    updateScore(pac.getScore(), g, map);

                }

                blinky.draw(g, map);
                inky.draw(g, map);
                pinky.draw(g, map);
                clyde.draw(g, map);

                //after some seconds, set pacman back to vulnerable
                if(counter == 12)
                {
                    pac.setState(NORMAL);

                    blinky.setColor(blink);
                    inky.setColor(ink);
                    pinky.setColor(pink);
                    clyde.setColor(cly);

                    counter = 0;
                }

            }

            if(pac.eat(map, counter))
            {
                //eat function sets counter to 0 to show
                //that big pellet was eaten to play sound
                if(counter == -1)
                {
                    Mix_PlayChannel( -1, gPowerPellet, 0 );
                    counter = 0;
                }
                releaseCalled = false;
                numEaten++;
                Mix_PlayChannel( -1, gEat, 0 );
                updateScore(pac.getScore(), g, map);
            }

            //releasing ghosts based on pellet eating
            if(numEaten % 5 == 0 && !releaseCalled && numEaten != 0)
            {
                if(!blinky.getActive())
                {
                    map[blinky.getR()][blinky.getC()].drawTile(g);
                    releaseGhost(blinky, map, releaseCalled);
                }
                else if(!inky.getActive())
                {
                    map[inky.getR()][inky.getC()].drawTile(g);
                    releaseGhost(inky, map, releaseCalled);
                }
                else if(!pinky.getActive())
                {
                    map[pinky.getR()][pinky.getC()].drawTile(g);
                    releaseGhost(pinky, map, releaseCalled);
                }
                else if(!clyde.getActive())
                {
                    map[clyde.getR()][clyde.getC()].drawTile(g);
                    releaseGhost(clyde, map, releaseCalled);
                }
            }

            pac.drawPac(g);
            g.update();

            if(g.kbhit())
            {
                key = g.getKey();

                switch(key)
                {
                    case RIGHT_ARROW: if(map[pac.getR()][pac.getC() + 1].isPath() && abs(pac.getCenter().y - (pac.getR() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(RIGHT);
                                      }
                                      pac.setNextDir(RIGHT);
                                      break;
                    case LEFT_ARROW:  if(map[pac.getR()][pac.getC() - 1].isPath() && abs(pac.getCenter().y - (pac.getR() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(LEFT);
                                      }
                                      pac.setNextDir(LEFT);
                                      break;
                    case UP_ARROW:    if(map[pac.getR() - 1][pac.getC()].isPath() && abs(pac.getCenter().x - (pac.getC() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(UP);
                                      }
                                      pac.setNextDir(UP);
                                      break;
                    case DOWN_ARROW:  if(map[pac.getR() + 1][pac.getC()].isPath() && abs(pac.getCenter().x - (pac.getC() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(DOWN);
                                      }
                                      pac.setNextDir(DOWN);
                                      break;
                }

            }

            pac.erasePac(g);
            //redraw tiles around pacman in case he overlaps any of those tiles
            map[pac.getR()][pac.getC()].drawTile(g);
            if(map[pac.getR() + 1][pac.getC()].isPath())
            {
                map[pac.getR() + 1][pac.getC()].drawTile(g);
            }
            if(map[pac.getR() - 1][pac.getC()].isPath())
            {
                map[pac.getR() - 1][pac.getC()].drawTile(g);
            }
            if(map[pac.getR()][pac.getC() + 1].isPath())
            {
                map[pac.getR()][pac.getC() + 1].drawTile(g);
            }
            if(map[pac.getR()][pac.getC() - 1].isPath())
            {
                map[pac.getR()][pac.getC() - 1].drawTile(g);
            }
            pac.movePosition(pac.getDirection(), map, g);

            //dictates pacman speed, adds extra moving
            if(i % 2 == 0)
            {
                pac.movePosition(pac.getDirection(), map, g);
            }
            g.Sleep(15);
        }
    }

    return 0;
}

void rePositionGhosts(SDL_Plotter& g, Ghost& a, Ghost& b, Ghost& c, Ghost& d, Tile map[36][28])
{
    a.erase(g, map);
    b.erase(g, map);
    c.erase(g, map);
    d.erase(g, map);

    //blinky
    a.setActive(true);

    a.setR(14);
    a.setC(16);
    a.setCenter(map[14][16].getCenter());

    //pinky
    b.setR(16);
    b.setC(15);
    b.setCenter(map[16][15].getCenter());
    b.setActive(false);

    //inky
    c.setR(16);
    c.setC(14);
    c.setCenter(map[16][14].getCenter());
    c.setActive(false);

    //clyde
    d.setR(16);
    d.setC(16);
    d.setCenter(map[16][16].getCenter());
    d.setActive(false);

}
void releaseGhost(Ghost& a, Tile map[36][28], bool& r)
{
    r = true;
    a.setActive(true);

    a.setR(14);
    a.setC(16);
    a.setCenter(map[14][16].getCenter());
}
