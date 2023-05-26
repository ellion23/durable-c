#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//11sec
int main(){
	int k = 0;
	int t = 0;
	while (k <= 59552000){
		k++;
		t = t + sin(k) + 2*sin(k);
	}
	return 0;
}