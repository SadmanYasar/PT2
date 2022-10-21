// Program : This program demonstrates how to deal with keyboard keys
//
// ? There are two types keys:
//
//  1). Printable keys like a s d f, etc.
//  2). Control keys like the arrow keys, function keys F1 F2 F3, etc.
//
//  ? Reading the key pressed   by the user can be with the winbgim function, getch()
//  Eg.
//
//   char ch;
//   ch = getch();
//
//   the function returns the ASCII code for the key. However, for any control keys,
//   it always return 0. This only tells that the key is a control key. If you want to know
//   the exact key, e.g. whether is an up arrow key or down arrow key, you need to call to
//   the getch() once more.
//
// ?  the structure of you code should look like this:
//   char ch;
//   ch = getch();
//
//   if (ch>0){
//      // this means a printable key is pressed
//   }
//   else{ // otherwise, it means a control key is pressed.
//         ch = getch();  // call again getch() to get the actual key
//
//         switch (ch){
//              case 75: // the left arrow key is pressed
//                     break;
//
//              case 77: // the right arrow key is pressed
//                     break;
//         }
//
//   }
//
//? besides, there is a function called kbhit(). This function is very usefull. It determines whether the user
//?  has pressed the keyboard.
//
// ?  by using getch(), it similar to cin,  getline() and so on, in which it waits for the user to complete entering the
// ?  input.  That means, during ch=getch(), other objects needs to hold / freeze their actions. And of course we
// ?  don't want this situations.
//
// ? To solve this, control the user input such that:
// ?  only execute or invoke the getch() if the user has pressed the keyboard, otherwise don't do getch()
//
//?  The code should look like this:
//
//  char ch;
//
//  if (kbhit()) ch = getch();  // See? we control the execution of this command, whereby it will only be executed when
//   there is a keyboard press.
//
// ! Warning of Using this code:
//     You are allowed to re-use the code to your assignments and projects.
//     However it is limited only to code snippet.
//     Re-using the entire (or almost entire) of this code is strictly prohibited.
//     Assignments and Projects that violate  this requirement will be disqualified .
//
// jumail@utm.my
// 19 April 2018

#include <graphics.h>

class Player{
	private:
		static const int SIZE  = 50;
		static const int OUTLINE_COLOR = WHITE;
		static const int FILL_COLOR = YELLOW;

		int x, y;

		// an helper method
		void draw(int outline, int fill) const{
			setcolor(outline);
			setfillstyle(SOLID_FILL, fill);
			fillellipse(x,y, SIZE, SIZE);
		}

	public:
		Player(int _x=0, int _y=0){
			x = _x; y=_y;
		}


	void show() const{draw(OUTLINE_COLOR, FILL_COLOR); }
	void clear() const{draw(BLACK, BLACK); }

	void setPos(int _x=0, int _y=0){ x = _x; y=_y;}

	void move(int dx=0, int dy=0){
		clear();
		x += dx; y += dy;
		show();
	}

};

using namespace std;

int main( )
{
    // Open a graphical window
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width,height, "Program Example: Working with keyboard keys.");

	string lines[] = { "Press Left Arrow Key or A or a to move to the left",
	                   "Press Right Arrow Key or D or d to move to the right",
	                   "Press Up Arrow Key or W or w to move to the top",
	                   "Press Down Arrow Key or S or s to move to the bottom",
	                   "Press F1 to move to the center of the screen",
	                   "Press Del to exit"
	                 };

	for (int i=0, y=10; i<6; i++, y+=30)
		outtextxy (10,y, (char*)lines[i].c_str());


	Player player(0, height / 2);
	player.show();

	char ch = 0;

	while ( true){

		if (kbhit()){
			// do key processing only if the user has pressed the keyboard, otherwise

			ch = getch();

			if (ch>0){ // if it is a printable character (for our case we want to press the key a s d w)
				ch = toupper(ch);  // for convience, convert the key to only one case so that you don't have to compare whether it lower or upper case key

				if (ch=='A') player.move(-10,0);   // move the player to the left
				else if (ch=='D') player.move(10,0);   // move the player to the right
				else if (ch=='W') player.move(0,-10);   // move the player to the top
				else if (ch=='S') player.move(0,10);   // move the player to the bottom
		    } else{
		    	// if the keys pressed was a control key
		    	ch = getch();
				if (ch==75) player.move(-10,0);       // Left Arrow Key: move the player to the left
				else if (ch==77) player.move(10,0);   // Right Arrow Key: move the player to the right
				else if (ch==72) player.move(0,-10);  // Up Arrow Key: move the player to the top
				else if (ch==80) player.move(0,10);   // Down Arrow Key: move the player to the bottom
				else if (ch==59){                     // F1 Key: position the player to the center
					player.clear();
					player.setPos(width/2, height/2);
					player.show();
				}

		    	else if (ch==83) break;                              // Del Key: end the program
			}

			// Notes: to identify the code for each key, see the documentation for getch() in winbgim website
			// https://www.cs.colorado.edu/~main/bgi/doc/getch.html
	}
   }

   return 0;
}
