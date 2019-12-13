#include "const.h"
#include "class.h"
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include "methods.cpp"

main(){
	
	srand(time(NULL));
	initwindow(700, 700);
	

					 
	circleClass circleObg( 220 ,150 ,15 );
	circleClass *Circle = &circleObg;
					 
	rectangleClass rectangleObg( 200, 110,11);
	rectangleClass *Rectangle = &rectangleObg;
					 
	triangleClass triangleObg( 220, 49, 4);
	triangleClass *Triangle = &triangleObg;
					 
	triangleLeftClass triangleLObg( 241, 160, 1);				 		    
	triangleLeftClass *LTriangle = &triangleLObg;
	
	triangleRightClass triangleRObg(199, 160,  1);				 		    
	triangleRightClass *RTriangle = &triangleRObg;
	
	figures **array = new figures*[ARRAY_SIZE];
	int count = 0;
	for(int i = 0; i < ARRAY_SIZE; i++){
		switch(count){
        	case 0:  array[i] = Rectangle; break;
        	case 1:  array[i] = Circle; break;
        	case 2:  array[i] = Triangle; break;
        	case 3:  array[i] = LTriangle; break;
        	case 4:  array[i] = RTriangle; break;
   	    }
   	    count++;
   	    if(count == 5) count = 0;
	}

	while(true){
		cleardevice();
		for(int i = 0; i < ARRAY_SIZE; i++){
			array[i] -> draw();
			array[i] -> move();
		}
		delay(10);
	} 
	closegraph();
}
