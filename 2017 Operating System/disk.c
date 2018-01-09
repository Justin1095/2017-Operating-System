//Justin Seda

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
/**
Justin Seda
This program displays 9 different sequences and shows the SCAN and SSTF disk scheduling 
algorithms for each sequence
**/
void sort(int arr[]);
void scan(int arr[], int head);
void scan2(int rSide[], int lSide[], int index);
void travel(int arr[], int head);
void sstf(int arr[]); 

static  int SIZE = 20;

int main() 
{
	int arr1[SIZE], arr2[SIZE];
	int head, i, j, begin;
	srand(time(NULL));
	
	for(i = 0; i < 9; i++)
	{
		printf("\nSequence %d ,the numbers:\n", (i+1));		
		for (j = 0; j < SIZE; j++) 
		{
			arr1[j] = 0 + rand() % (999 + 1 - 0);
			arr2[j] = arr1[j];
			printf("%d, ", arr1[j]);
		}
		
		head = arr2[0];
		begin = arr2[0];
		printf("\n\nSCAN:\n");
    	sort(arr2);
      	scan(arr2, head);
		travel(arr2, begin);
		printf("\n");
		
		sstf(arr1);
	  	printf("\n//////////////////////////////\n");			
	}	
    return 0;
}


void sort(int arr[])
{
	 int tmp, min, loc;
	 int nSize = SIZE -1; 
      for(int i = 0; i < nSize; i++)
      {
            min= arr[i];
            loc = i;
            for(int j = i + 1; j < SIZE; j++)
            {
                  if(min> arr[j])
                  {
                        min= arr[j];
                        loc = j;
                  }
            }
            tmp = arr[loc];
            arr[loc] = arr[i];
            arr[i] = tmp;
      }
}


void scan(int arr[], int head)
{ 
	int i;
      int lSide[SIZE], rSide[SIZE];
      for(i = 0; i < SIZE; i++)
      {
            if(arr[i] > head)
            {
                  break;
            }
      }

     int one= 1,zero= 0,m = SIZE;
      lSide[0] = arr[0];
      while(one< i)
      {
            lSide[one] = arr[one];
            one++;
      }
     int tmp = i;
      while(tmp < m)
      {
            rSide[zero] = arr[tmp];
            zero++;
            tmp++;
      }
	scan2( lSide,  rSide, i);
	
}

void scan2(int lSide[], int rSide[], int count)
{
       int arr[SIZE];
      int l = count - 1, r = count + 1;
	 int a = 0, b = 0, i;
      while(l > -1)
      { 
            arr[b] = lSide[l];
            l--;
            b++;
      }
      arr[b] = 0;
      while(r < SIZE + 1)
      {
            arr[r] = rSide[a];
            a++;
            r++;
      }
      for(i = 0; i < SIZE + 1; i++)
      {
            printf("%d  ", arr[i]);
      }
	  
}


void travel(int arr[], int head) 
{
	int begin, travel = 0, a1, a2;
	for (int i = 0; i < SIZE; i++) {
		if (head == arr[i]) {
			begin = i;
		}
	}
	for (int j = begin; j > 0; j--) 
	{
		a1 =(arr[j] - arr[j - 1]);
		travel = travel + a1;
	}
	for (int k = 0; k < SIZE - 1; k++) 
	{
		a2 = (arr[k + 1] - arr[k]);
		travel = travel + a2;
	}
	
	int total = abs(travel);
	printf("\nThe total distance the disk arm needs to travel in SCAN: %d\n", total);
}


void sstf(int arr[]) 
{
	int min, a = arr[0], total = 0;	
	int cValue = 0, sLoc=0, travel=0;
	printf("SSTF\n");
	for(int i = 0; i < SIZE; i++) 
	{
		min= 1000;
		for(int j = 0; j < SIZE; j++)
		{
			travel = abs(a - arr[j]);
			if(arr[j] == 1000 || travel == 0)
			{	
			}
			else if(travel < min) 
			{
				sLoc = j;
				min = travel;
			}	
		}

		total = total + min;
		arr[0] = 1000;
		
		printf("%d, ", a);
		a = arr[sLoc];
		arr[sLoc] = 1000;
		cValue = sLoc;	
	}
	total = total - 1000;
	printf("\nThe total distance the disk arm needs to travel in SSTF: %d\n", total);
}

