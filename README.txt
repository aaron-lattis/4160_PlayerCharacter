My program is a simple game that involves a player that can run and jump from left to right. Pressing and holding the 'a' key will cause the player to move to the left. Pressing and holding the 'd' key will cause the player to move to the right. And simply pressing and releasing the space bar will cause the player to jump.

My program can be run by typing 'make' and then './my_game'. This will cause a window to pop up dipslaying my game. 

I use a sprite class, and a sprite sheet that I got off the internet, to animate my player. This is a link to the download: 'https://w7.pngwing.com/pngs/471/483/png-transparent-character-sprite-animation-computer-software-texture-mapping-sprite-game-photography-team.png'. Because of the way the school of computing computers handle a button being held down as a burst of key presses, my player will enter the idle state as he is running when the 'a' and 'd' keys are held. I have discussed this with Dr. Zordan, and pressing any other key while continuing to hold the direction key will fix the issue. Additionally, jumping while running will fix this issue until the run key is released. The jumping animation looks a little bit similar to the running animation but it is different, and is pulled from a different section of the sprite sheet. 

I have created a tile handler class that I use to place many instances of three unique props in the path of my character. All of these props are placed to the right of the characters starting position, thus holding down the 'd' key will cause the player to run towards them, causing them to appear within the screen until the player runs past them. The tile sheet I used was downloaded from: 'https://www.hiclipart.com/free-transparent-background-png-clipart-vzkst/download'. 

I have used a set of 4 moving background images with alpha to give the paralax effect. I downloaded these images from the following link: 'https://raventale.itch.io/parallax-background?download'.

Finally, I have created an ImageHandler class that I use to handle images. 



