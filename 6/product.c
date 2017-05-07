#include<stdio.h>

//returns the product(5,10) = 5 * 6 * 7 * 8 * 9 * 10;

int product(int a, int b)
{
    // corrected Namir Hassan 3/27/2017
    int mid;
    int n = 1;
    int h = 1;
    if (a == b)
       return a;
    else if (b != a + 1){
      //else {
      mid = (a + b) / 2;
      //return product(a, mid) + product(mid, b);
      // corrected Namir Hassan 3/27/2017
      n = product(a, mid);
      h = product(mid,b);

      return n*h;
   }
   else {
           return a;

   }
}

int main() {

	int p;
        //p = product(5,10);
        // corrected Namir Hassan 3/27/2017
	p = product(5,10) * 10;
	printf("product is %d\n", p);

	return 0;

}
