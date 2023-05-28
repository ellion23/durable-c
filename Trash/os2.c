#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//14sec
int main(){
	int k = 0;
	int t = 0;
	while (k <= 76552900){
		k++;
		t = t + sin(k) + 2*sin(k);
	}
	
	return 0;
}