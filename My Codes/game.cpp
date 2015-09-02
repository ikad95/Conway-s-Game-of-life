#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#define MAX 50
#define INIT 1000
using namespace std;

int find_no_of_neighbours(int a[][MAX],int i,int j){
int count =0;

if(i<MAX-1)
{
	if(a[i+1][j]==1||a[i+1][j]==3)
	count++;
if(j<MAX-1)
	if(a[i+1][j+1]==1||a[i+1][j+1]==3)
	count++;
}
if(j<MAX-1)
{
	if(a[i][j+1]==1||a[i][j+1]==3)
	count++;
if(i>0)
	if(a[i-1][j+1]==1||a[i-1][j+1]==3)
	count++;
}
if(i>0){
	if(a[i-1][j]==1||a[i-1][j]==3)
	count++;
if(j>0)
	if(a[i-1][j-1]==1||a[i-1][j-1]==3)
	count++;
}
if(j>0){
	if(a[i][j-1]==1||a[i][j-1]==3)
	count++;
if(i<MAX-1)
	if(a[i+1][j-1]==1||a[i+1][j-1]==3)
	count++;
}

//
/*
if(a[(i+1)%MAX][j]==1||a[(i+1)%MAX][j]==3)
	count++;
if(a[i][(j+1)]==1||a[i][(j+1)]==3)
	count++;
if(a[i-1][j]==1||a[i-1][j]==3)
	count++;
if(a[i][j-1]==1||a[i][j-1]==3)
	count++;

if(a[(i+1)%MAX][(j+1)]==1||a[(i+1)%MAX][(j+1)]==3)
	count++;
if(a[i-1][j-1]==1||a[i-1][j-1]==3)
	count++;
if(a[(i+1)%MAX][j-1]==1||a[(i+1)%MAX][j-1]==3)
	count++;
if(a[i-1][(j+1)]==1||a[i-1][(j+1)]==3)
	count++;
*/
return count;
}
int add(int a[][MAX]){
	int x,y;
	cout<<"Enter x & y coordinate :";
	cin>>x>>y;
	a[x][y]=1;
}

int add(int a[][MAX],int x,int y){
//	int x,y;
//	cout<<"Enter x & y coordinate :";
//	cin>>x>>y;
	a[x][y]=1;
}
int pregnant(int a[][MAX],int x,int y){
	a[x][y]=2;
}
int birth_of_babies(int a[][MAX]){
	int count=MAX;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if(a[i][j]==2)
				a[i][j]=1;
		}
	}
}
int death_of_elders(int a[][MAX]){
	int count=MAX;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if(a[i][j]==3)
				a[i][j]=0;
		}
	}
}

void view(int a[][MAX]){
	int count=MAX;
	for (int i = count-3; i >=2; --i)
	{
		for (int j = 2; j <=count-3; ++j)
		{
			if(a[j][i]==0) cout<<"  ";
			else cout<<"* ";
		}
		cout<<endl;
	}
}
int implant(int a[][MAX]){
	int option;
	cout<<"Insert options : \n 1. Add Glider\n";
	cin>>option;
	int X=MAX-10;
	if(option==1){
		add(a,1,X+7);
		add(a,2,X+6);
		add(a,3,X+6);
		add(a,3,X+7);
		add(a,3,X+8);
	}
}

int main(int argc, char **argv)
{
	int a[MAX][MAX];
	int count =MAX;
	int stat;
	int no;
	stat=0;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			a[i][j]=0;
		}
	}
	implant(a);

	while(1){

	if(fork()==0){
		execvp("clear",argv);
		exit(1);
	}
	wait(&stat);
	view(a);
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			no=find_no_of_neighbours(a,i,j);
			if(no<2){
				//under populated
				if(a[i][j]==1)
					a[i][j]=3; //almost dead :W
				//else if dead, good
			}
			
			else if(no==3){
				if(a[i][j]==0)
					pregnant(a,i,j);
			}

			else if(no>3){
				if(a[i][j]==1)
					a[i][j]=3; //died of overcrowding
			}
			

		}
	}
	//cout<<"pregnant"<<endl;
	//view(a);
	birth_of_babies(a);
	death_of_elders(a);
	//cout<<"Birth"<<endl;
	//view(a);
	usleep(60000);
	cout<<endl;
	
}
	return 0;
}
