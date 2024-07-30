# JarvisMarchingAlgorithm-For-convex-Hull-detection-circuit-

![DIGISIM_PS](https://github.com/user-attachments/assets/e55b40a8-4d90-44e3-b27c-7e011b2eaa71)


This algorithm helps in finding the outer hull that is convex hull points among a large set of points.

To obtain the points 
method
1. Find the left most point
2. Then take a random point assume it the next point ,and simultaneously take other points and find that the third point is clockwise or anti clockwise to the before points.
3. If the point is Clockwise then leave it else if it is CCW then take it as the 2nd point.Carry on in this way
4. By doing this method again and again we can find all the convex hull points
5. When will reach the first most point then the search will end.
   
