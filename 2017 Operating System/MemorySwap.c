#include<stdio.h>
#include<stdlib.h>
/**
Justin Seda
This program displays a memory hole size order of 10 MB, 4 MB, 18 MB, 7 MB, 9 MB, 12 MB, and 15 MB.
H = hole size
Then the program goes through different MB and finds the best fit for it. 
Ex. 12 MB best fit would be 12 MB.
**/
struct Node* head; 
struct Node  
{
	int size;
	char letter;
	struct Node* next;
	struct Node* pre; //previous
};

struct Node* GetnNode(char y, int x) 
{
	struct Node* nNode = (struct Node*)malloc(sizeof(struct Node));
	nNode->letter = y;
	nNode->size = x;
	nNode->pre = NULL;
	nNode->next = NULL;
	return nNode;
}

void TailInsert(char y, int x) 
{
	struct Node* temp = head;
	struct Node* nNode = GetnNode(y, x);
	if(head == NULL) 
	{
		head = nNode;
		return;
	}
	while(temp->next != NULL) 
	{
		temp = temp->next;
	}
	temp->next = nNode;
	nNode->pre = temp;
} 

void Traverse(char y, int x)
{
	struct Node *currPt = head;
	struct Node *bestPt = NULL;
	int difcurrPt = 0;
	int difbestPt = 100;
	
	while (currPt != NULL)
	{
		if(currPt->letter == 'H')
		{
			difcurrPt = currPt->size - x;

			if(difcurrPt == 0)
			{
				currPt->size = x;
				currPt->letter = y;
				return;
			}

			else if(difcurrPt > 0)
			{
				if(difcurrPt < difbestPt)
				{
					difbestPt = difcurrPt;
					bestPt = currPt;
				}
			}
		}
		currPt = currPt->next;
	}
	if(bestPt != NULL)
	{
		bestPt-> size = x;
		bestPt->letter = y;
		return;
	}
	printf("This allocation failed\n");
}
	
	
void Display() 
{
	struct Node* temp = head;
	while(temp != NULL) 
	{
		printf("(%c, ", temp->letter);
		printf("%d) ",temp->size);
		temp = temp->next;
	}
	printf("\n");
}

int main() 
{
	head = NULL; 
	
	TailInsert('H',10);
	TailInsert('H', 4);   
	TailInsert('H',20); 
	TailInsert('H',18); 
	TailInsert('H',7);  
	TailInsert('H',9); 
	TailInsert('H',12); 
	TailInsert('H',15); 	
	Display();
	
	Traverse('A',12);
	Display();
	
	Traverse('B',10);
	Display();
	
	Traverse('C',9);
	Display();
	
	Traverse('D',25); //this will fail because the largest memory hole is 20 MB.
	Display();
	
	Traverse('E',6);
	Display();
	
	Traverse('F',10);
	Display();
	
	Traverse('G',7);
	Display();
}