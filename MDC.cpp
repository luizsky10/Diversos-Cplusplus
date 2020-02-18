#include "MDC.h"
#include <iostream>

int MDC(int x, int y){
	    if(x%y == 0){
		    return y;
	    }else{
		    return MDC(y,x % y);
	    }
}

int MMC(int a, int b){
    int div;
    if(b == 0)
        return a;
    else{
     div = (a*b)/(MDC(a,b));
    return (div); 
}    				
}