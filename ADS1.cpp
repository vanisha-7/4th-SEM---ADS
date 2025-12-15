#include<stdio.h>

#define SIZE 10

int hashTable[SIZE];

//Initialize hash table
void init()
{
	for (int i=0;i<SIZE;i++)
	hashTable[i] = -1;
}

//Insert using Quadratic probing 
void insert (int key)
{
	int index = key%SIZE;
	
//If the solt is occupied, probe sequentially
while(hashTable[index]!=-1)
{
	index = (index+1)%SIZE;
	}	
	hashTable[index]=key;
}

//Display hashtable
	void display()
	{
		printf("\nHash Table:\n");
		for(int i=0;i<SIZE;i++)
		printf("%d --> %d\n",i,hashTable[i]);
	}
	
	int main()
	{
		int keys[] = {23,43,13,27,39};
		int n=6;
		init();
		for(int i=0;i<n;i++)
		{
			insert(keys[i]);
		}
		
	display();
	}
