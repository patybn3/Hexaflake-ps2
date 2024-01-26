# PS2: Hexaflake

## Contact
Name: Patricia Antlitz
Section: 202
Time to Complete: days =/


## Description
This program draws a snowflake to the screen using only hexagons. I have named it Hexaflakes.The goal is to use a recursive function to draw each hexagon depending on the size and depth passed through the console. The recursive function of this project is called drawHex(...). It works by drawing the center hexagon using a ConvexShape and the surrounding hexagons using another ConvexShape. It checks if the depth is equal to 1 in order to draw a snowflake of 7 hexagons only, that means that when the program is called as ./hexagon 100 1, 7 hexagons will appear on the page. Each of those 7 hexagons are replaced by 7 more hexagons arranged the same way once the depth increase. It the program is ran with ./hexagon 100 2, 49 hexagons should show on the page. Increasing the depth will always "multiply" the current amount of hexagons by 7.

### Features
Recursion = The recursive function is called over and over again depending on the number passed as depth. This allows hexagons to continue to be added generating the desired image.
This project is easy to use, the user just need to type the name of the program ./hexagon, followed by the desired length for the size of the base hexagon and the desired depth for the recursion.
Tests are run as ./test.

### Issues
I had several issues while developing this. Based on the class example for the snowflake, my initial program had hexagons that decreased as they were added to the screen. I didnt find many resources out there to help me out with this, and I reached out to some classmates with no luck either. I had two for loops initially handling this recursion and all hexagons being generated at one ConvexShape. Adding a second ConvexShape to handle the middle hexagon only, allowed the hexagons to be shown with the same measurements. However, when generating snowflakes with more than 7 hexagons, the new hexagons would be drawn inside of the original 7. This took some trial and error, it wasn't straight forward since, like I said I couldn't find resources online, and the class code ended up not having anything to do with what I did.
Colors = I really wanted to add the gradient color, but I tried many times and I couldn't make it happen. Actually, I was able to add gradient colors for each individual hexagon, which is not the desired output. I deleted that code since it was not what I wanted. Since Im running out of time, I decided to turn the project in without that.

### Extra Credit
Anything special you did.  This is required to earn bonus points.


## Acknowledgements
center hexagon:
https://stackoverflow.com/questions/21292910/centering-shapes-objects-in-sfml-for-c

Hexaflake rotation:
https://www.sfml-dev.org/tutorials/2.6/graphics-transform.php

ConvexShape:
https://www.sfml-dev.org/documentation/2.6.0/classsf_1_1ConvexShape.php

Recursion:
https://stackoverflow.com/questions/54719752/c-sfml-printing-convex-shapes-to-the-screen-using-two-recursive-calls-only



