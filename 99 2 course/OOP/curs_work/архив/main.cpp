#include "constants.h"
#include "classes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <graphics.h>

main(){	
	srand(time(NULL));
	initwindow(750, 750);

					 
	circleCls circleObj( 220 ,150 ,15 );
	circleCls *Circle = &circleObj;
					 
	rectangleCls rectanObj( 200, 110,11);
	rectangleCls *Rectangle = &rectanObj;
					 
	triangleCls trianObj( 220, 49, 4);
	triangleCls *Triangle = &trianObj;
					 
	triangLCls trianLObj( 241, 160, 1);				 		    
	triangLCls *LTriangle = &trianLObj;
	
	trianRCls trianRObj(199, 160,  1);				 		    
	trianRCls *RTriangle = &trianRObj;
	
	shape **array = new shape*[ARR_SIZE];
	
			 array[0] = Rectangle; 
   			 array[1] = Circle; 
   			 array[2] = Triangle;
   			 array[3] = LTriangle;
   			 array[4] = RTriangle;
	while(true){
		cleardevice();
		for(int i = 0; i < ARR_SIZE; i++){
			array[i] -> draw();
			array[i] -> move();
		}
		delay(10);
	} 
	closegraph();
}
