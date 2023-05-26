#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//18 sec
int main(){
	int k = 0;
	int t = 0;
	while (k <= 96559900){
		k++;
		t = t + sin(k) + 2*sin(k);
	}
	return 0;
}