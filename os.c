#include<stdio.h>
#include<semaphore.h>
sem_t s;
void intro();
void game();
void intro()
{
	printf("\t\t\t\t****ONLINE MULTIPLAYER**\n");
	printf("\t\t\t\t******GAME**\n");
	printf("This Online Multiplayer game is made according to the latest rules as a project for CSE316");
	printf("\n\n\t\t\t\t\t\tBy G Kiran\n\t\t\t\t\t\t   K17WP\n\t\t\t\t\t\t   A05\n\t\t\t\t\t\t   11711381\n");
}
void game()
{
	sem_wait(&s);
	printf("Game is running\n");
	sem_post(&s);
}

int main()
{
	intro();
	sem_init(&s,0,1);
	int p,i,k;
	m:
	printf("Enter the number of players:-\n");
	scanf("%d",&p);
	int p1[p],p2,p3,flag=0;
	if(p<3)
	{
		printf("There must be minimum 3 players for game\n");
		goto m;
	}
	int a[p];
	for(i=0;i<p;i++)      //constant complexity O(1) 
	{
		a[i]=i;
	}
	for(k=0;k<p;k++)      //constant complexity O(n)
	{
		p1[k]=a[k];
		flag++;
		if(flag%3==0)
		{
			game();
		}
	}
	if(flag%3!=0)
	{
		printf("\nNot sufficient players\n");
		printf("Waiting for more players to arrive\n");
	}
}
