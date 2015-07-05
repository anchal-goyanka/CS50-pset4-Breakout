//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);
    
    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
     double velocity = drand48();
        double velocityy = 0.6;
    while (lives > 0 && bricks > 0)
    {
   
    // first part
 
        move(ball,velocity, velocityy);

        
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velocity = -velocity;
        }

        
        else if (getX(ball) <= 0)
        {
            velocity = -velocity;
        }
       
        
         else if(getY(ball)+20 >= getHeight(window))
        {
        lives = lives - 1;
         GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    setLocation(label,200,300);
    char s[3];
     sprintf(s, "%i", lives);


    setLabel(label,s);
    velocityy = -velocityy;
    pause(500);
      
        }
        pause(5);
        //second part
        
        
        GEvent event = getNextEvent(MOUSE_EVENT);
     if(event != NULL)
     {
     if(getEventType(event) == MOUSE_MOVED)
    
     setLocation(paddle,getX(event),560);
     }
     // collision with paddle
     
     GObject object = detectCollision(window,ball);
     if(object != NULL)
     {
   
     velocityy = -velocityy;
      if(object != paddle)
    
      removeGWindow(window,object);
    
      }
   
     
     
     }
     
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    for(int i = 0; i<5;i ++)
    {
    for(int j= 0;j<10;j++)
    {
    GRect brick = newGRect(12+j*35 + j*2,25+i*10,35,8);
      setColor(brick, "BLUE");
    
    setFilled(brick, true);
    add(window, brick);
    }
    }
    
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(190,290,10,10);
      setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{

 
      GRect paddle = newGRect(150,560,100,20);
      setColor(paddle, "RED");
    setFilled(paddle, true);
    add(window, paddle);
    
    
    
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    return NULL;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
