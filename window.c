/**
 * window.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Draws a window.
 */

// Stanford Portable Library
#include "gwindow.h"

int main(void)
{
    // instantiate window
    GWindow window = newGWindow(320, 240);
 
    // let's look at it for a while
    pause(5000);

    // that's all folks
    closeGWindow(window);
    return 0;
}

















GEvent event = getNextEvent(MOUSE_EVENT);
     if(event != NULL)
     {
     if(getEventType(event) == MOUSE_MOVED)
    
     setLocation(paddle,getX(event),560);
     }
      
      
      
      
      
      
      
      
      
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
        velocityy = -velocityy;
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
