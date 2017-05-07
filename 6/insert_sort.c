//
// insertion sort, several errors
//
// usage:  insert_sort num1 num2 num3 ..., where the numi are the numbers to
// be sorted
// corrected Namir Hassan 3/27/2017
#include <stdio.h>
// corrected Namir Hassan 3/27/2017
#include <stdlib.h>

int x[10],  // input array
    y[10],  // workspace array
    num_inputs,  // length of input array
    num_y = 0;  // current number of elements in y

void get_args(int ac, char **av)
{  int i;

   num_inputs = ac - 1;
   for (i = 0; i < num_inputs; i++)
      x[i] = atoi(av[i+1]);
}

//void scoot_over(int jj)
// corrected Namir Hassan 3/27/2017
void scoot_over(int j)
{  int k;

   //for (k = num_y-1; k > jj; k++)
   // corrected Namir Hassan 3/27/2017
   for (k = num_y; k > j; k--)

      y[k] = y[k-1];
}

void insert(int new_y)
{  int j;

   //if ((num_y = 0))  { // y empty so far, easy case
      // corrected Namir Hassan 3/27/2017
      if ((num_y == 0))  { // y empty so far, easy case
      y[0] = new_y;
      return;
   }
   // need to insert just before the first y
   // element that new_y is less than
   for (j = 0; j < num_y; j++)  {
      if (new_y < y[j])  {
         // shift y[j], y[j+1],... rightward
         // before inserting new_y
         scoot_over(j);
         y[j] = new_y;
         return;
      }
   }
   // corrected Namir Hassan 3/27/2017
   y[num_y] = new_y;
}

void process_data()
{
   for (num_y = 0; num_y < num_inputs; num_y++)
      // insert new y in the proper place
      // among y[0],...,y[num_y-1]
      insert(x[num_y]);
}

void print_results()
{  int i;

   for (i = 0; i < num_inputs; i++)
      printf("%d\n",y[i]);
}

int main(int argc, char ** argv)
{
   get_args(argc,argv);
   process_data();
   print_results();

   return 0;
}
