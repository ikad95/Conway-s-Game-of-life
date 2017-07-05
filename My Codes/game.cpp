#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#define MAX 60
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
	return count;
}

int add(int a[][MAX],int x,int y){
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
	cout<<"Insert options : \n 1. Add Glider\n 2. Randomize\n 3. Add 45 deg\n 4. Add M\n 5. Add circle\n";
	cin>>option;
	int X=MAX-10;
	if(option==1){
		add(a,1,X+7);
		add(a,2,X+6);
		add(a,3,X+6);
		add(a,3,X+7);
		add(a,3,X+8);
	}

	else if(option==2){
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < MAX; ++j)
			{
				if(rand() % 2 )
					add(a,i,j);
			}
		}
	}

	else if(option==3){
		int aa=25,bb=24,xx=0,yy=0;

		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);
		int x=2;
		add(a,aa - xx+x,aa - yy+x);
		add(a,bb - xx+x,aa - yy+x);
		add(a,aa - xx+x,bb - yy+x);
		add(a,bb - xx+x,bb - yy+x);
	}

	else if(option==4){

		int aa = 23,bb=24,xx=4,yy=-9;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);


		aa = 23,bb=24,xx=-9,yy=-9;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);

		aa = 23,bb=24,xx=-9,yy= 2;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);

		aa = 23,bb=24,xx=-9,yy= -3;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);

		aa = 23,bb=24,xx=-9,yy= 6;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);

		aa = 23,bb=24,xx=-9,yy=-9;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);
		
		aa = 23,bb=24,xx=4,yy= 2;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);

		aa = 23,bb=24,xx=4,yy= -3;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);

		aa = 23,bb=24,xx=4,yy= 6;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);

		aa = 23,bb=24,xx=1,yy=-6;

		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);
		int x=2;
		add(a,aa - xx+x,aa - yy-x);
		add(a,bb - xx+x,aa - yy-x);
		add(a,aa - xx+x,bb - yy-x);
		add(a,bb - xx+x,bb - yy-x);

		aa= 28,bb=27,xx=0,yy=0;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);
		x=2;
		add(a,aa - xx+x,aa - yy+x);
		add(a,bb - xx+x,aa - yy+x);
		add(a,aa - xx+x,bb - yy+x);
		add(a,bb - xx+x,bb - yy+x);

		add(a,1,X+7);
		add(a,2,X+6);
		add(a,3,X+6);
		add(a,3,X+7);
		add(a,3,X+8);

	}
	else if(option==5){
		int aa=25,bb=24,xx=0,yy=0;
		add(a,aa - xx,aa - yy);
		add(a,bb - xx,aa - yy);
		add(a,aa - xx,bb - yy);
		add(a,bb - xx,bb - yy);
		int x=2;
		add(a,aa - xx,aa - yy+x);
		add(a,bb - xx,aa - yy+x);
		add(a,aa - xx,bb - yy+x);
		add(a,bb - xx,bb - yy+x);
	}
}

int main(int argc, char **argv){
	int a[MAX][MAX];
	int count =MAX;
	int stat;
	int no;
	stat=0;
	srand (time(NULL));
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			a[i][j]=0;
		}
	}
	implant(a);
	int i=0;
	while(1){
		i++;
		if(i==100){
			i=0;
			int X=MAX-10;
			add(a,1,X+7);
			add(a,2,X+6);
			add(a,3,X+6);
			add(a,3,X+7);
			add(a,3,X+8);
		}
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
