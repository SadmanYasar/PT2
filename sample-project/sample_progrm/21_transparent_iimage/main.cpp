
#include <graphics.h>

#include "player.hpp"

//! To run this program, use debug mode "Multi-File Graphic Project"

// Press Enter to start or stop moving
// Press Space bar - reverse movement

int main()
{
    int screenHeight = getmaxheight();
    int screenWidth = getmaxwidth();


    initwindow(screenWidth, screenHeight, "Player Testing (with Transparent Image)- Enter to start/stop, Space bar to reverse, ESC to exit");

    // create background with image
    readimagefile("images/background.jpg", 1, 1, screenWidth, screenHeight);

    Player player;
    
    int y = screenHeight - player.getHeight() - 100;
    int x = screenWidth / 2;

    player.setTop(y);
    player.setLeft(x);

    player.init();


    char key = 0;

    

    // press the ESC key (i.e, ASCII code 27) to terminate the program
    while (key != 27)
    {
        key = 0;

        player.draw();
        delay(200);
        player.undraw();
        player.move();

        // auto reverse if the player reaches the edge of the screen
        if ((player.getRight() >= screenWidth) || (player.getLeft() <= 0))
            player.reverse();

        if (kbhit())
        {
            key = getch();
            if (key == 0)
                key = getch(); // Twice getch() is to handle special keys like arrow keys.
        }

        switch (toupper(key))
        {
        case ' ': // press space bar, to reverse
            player.reverse();
            break;

        case 13: // press Enter key, to start or stop moving

            if (player.getMovement() != 0)
                player.setMovement(0);
            else
                player.setMovement(50);
            break;
        }
    }

    return 0;
}