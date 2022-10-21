#ifndef INTERSECT_H
#define INTERSECT_H

// Library for testing intersection between geometrical shapes.
//  Supported shapes: rectangle and circle
//
// Author: Jumail
// Email: jumail@utm.my
// Created: 18 Dec 2017

// intersect: general function to test intersection.
//            Key idea: an intersection between  two shapes is detected when the distance
//                      between the center of the objects (d) is less than or equal to the sum
//                      of the "radius" of both objects.  Note that, distance and radius are given
//                      in both directions, i.e., horizontal and vertical. Thus, we have dx and dy  for distance, and rx and ry for radius
// Parameters: cx1, cy1= center of first object, 
//             rx1, ry1= radius of first object, 
//             cx2,cy2=center of second object
//             rx2, ry2= radius of second object
     
bool intersect(int cx1, int cy1, int rx1, int ry1, 
			   int cx2, int cy2, int rx2, int ry2);


// intersectRect: function to test intersection between two rectangles
// Parameters: x1, y1= top left corner of the first rectangle, 
//             w1,h1=dimension (width and height) of the first rectangle
// 	           x2, y2= top left corner of the second rectangle, 
//             w2,h2=dimension (width and height) of the second rectangle
   
bool intersectRect(int x1, int y1, int w1, int h1, 
			       int x2, int y2, int w2, int h2);



// intersectCircle: function to test intersection between two circles
// Parameters: cx1, cy1, r1 = center and radius of the first circle, 
//             cx2, cy2, r2 = center and radius of the second circle, 
     
bool intersectCircle(int cx1, int cy1, int r1, 
			       int cx2, int cy2, int r2);
			       
			       
			       
// intersectEllipse: function to test intersection between two ellipses
// Parameters: cx1, cy1 = center of the first circle,  
//             rx1, ry1 =  radius of the first circle, 
// 			   cx2, cy2 = center of the second circle, 
//             rx2, ry2 =  radius of the second circle 
     
bool intersectEllipse(int cx1, int cy1, int rx1, int ry1, 
			          int cx2, int cy2, int rx2, int ry2);



// intersectRectCircle: function to test intersection between a rectangle and a circle
// Parameters: x, y  = top left corner of the rectangle
//             w, h    = width and height of rectangle
//             cx, cy, r = center and radius of the circle
     
bool intersectRectCircle(int x, int y, int w, int h, 
			             int cx, int cy, int r     );



// intersectRectEllipse: function to test intersection between a rectangle and an ellipse
// Parameters: x, y  = top left corner of the rectangle
//             w, h    = width and height of rectangle
//             cx, cy = center of the ellipse 
//             rx, ry = radius of the ellipse
     
bool intersectRectCircle(int x, int y, int w, int h, 
			             int cx, int cy, int rx, int ry);



// intersectCircleEllipse: function to test intersection between a rectangle and an ellipse
// Parameters: cx1, cy1, r  = center and radius of the circle
//             cx2, cy2 = center of the ellipse 
//             rx, ry  = radius of the ellipse
     
bool intersectCircleEllipse(int cx1, int cy1, int r,  
			             int cx2, int cy2, int rx, int ry);




#endif
