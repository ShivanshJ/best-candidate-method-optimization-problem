#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

#define  F(i,a,b) for(int i = (int)(a) ; i<(int)(b); i++)

//Pre- define instead of taking an input
int dem[4]={10,15,12,15};
int sup[4]={14,10,15,12};
int c[4][4]={
{10,30,25,15},
{20,15,20,10},
{10,30,20,20},
{30,40,35,45}
};

int path[4][4]={0}; //For visited places or the places we can't tread 
int best_sum=10000 , best_s[4][4]; //Best sum for each combination like f(0,0) or f(0,1) or f(0,2) .. is different but stored here 
								   //best_s saves path matrix for the current best_sum of combination



void func(int g, int h, int sum)
{ 
   if(g>4 || g<0 ||h>4 ||h<0)
    return ;  
   if(path[g][h]==1||path[g][h]==2)
   return ;
   
   sum+=c[g][h];
   F(i,0,4)
   {
    path[g][i]=1;
	path[i][h]=1;
	}
	path[g][h]=2;
	if(g==3)
   { 
   		if(best_sum > sum)  //Saving this best_sum if better than sums of all combinations under the combos under func(0,0,sum)
   		{
   			best_sum=sum;
   			
   			//Saving path as best path found till now
			 F(k,0,4) 
			 F(j,0,4) 
				best_s[k][j]=path[k][j];

			//Printing the path   		
		   		F(k,0,4)
				{  F(j,0,4)
					{	
							cout<<best_s[k][j]<<" ";
					}
					cout<<endl;
				}
				
			cout<<endl;
   		}
   		
   	
   }
	//Recursive function selecting all columns for every next row	
	F(i,1,4)
	{
	func(g+1,(h+i)%4 , sum);
	}
	//Undo changes
	 F(i,0,4)
   {
    path[g][i]=0;
	path[i][h]=0;
	}
	F(k,0,4) 
	F(j,0,4)
	{ if(path[k][j]==2)
		F(i,0,4)
   		{
   			path[k][i]=1;
			path[i][j]=1;
			path[k][j]=2;
		}
	}
	
	return;
}

/////////////////////////////////////////////////////////////
///////////////////MAIN FUNCTION

int main()
{
	int best=10000, best_pos; //Best records best of all best_sums. and best_pos stores the position of that best starting point
	
F(i,0,4)
{  

//Re-Making path matrix as 0.
	F(k,0,4)
	F(j,0,4)
	path[k][j]=0;
	
	
	best_sum=10000 ;

	func(0,i,0);
	cout<<"\nBest sum is: "<<best_sum<<endl;
	if(best_sum < best)
	{   best=best_sum;
		best_pos=i;
	}


}

cout<<best_pos<<"\nBest out of best sums is: "<<best<<"\n";
func(0,best_pos,0);
F(k,0,4)
	{
	F(j,0,4)
	{	
	cout<<best_s[k][j]<<" ";
	}
	cout<<endl;
}
cout<<"\nBest combination/ candidates are: \n";
F(k,0,4)
	{
	F(j,0,4)
	{	if(best_s[k][j]==2)
	       cout<<"|"<<c[k][j]<<"|"<<" ";
	    else
		cout<<" "<<c[k][j]<<"  ";  
		   
	}
	cout<<endl;
}

//Function for BCM
//bcm(best_s);
	
return 0;

}

/*
void bcm(int ar[4][4])
{ int rank[4];
	F(k,0,4) 
	F(j,0,4)
	 if(ar[j][k]==2)
	 	rank[k]=c[j][k];
	
	int sorted[4];	
		
		F(i,0,4) 
	cout<<rank[i]<<endl;
	
	F(i,0,4) 
	sorted[i]=rank[i];
	//Bubble sort
	int temp;
	F(i,0,4) 
	F(j,0,3-i) 
	{ if(sorted[j]>sorted[j+1])
		{temp=sorted[j];
		sorted[j]=sorted[j+1];
		sorted[j+1]=temp;
		}
	}	
	
	
		F(i,0,4) 
	cout<<sorted[i]<<endl;
	
	F(i,0,4) 
	F(j,i+1,4)
	if(rank[i]==sorted[j])
	{
	 rank[i]=j;
	 
   }
	
	F(i,0,4) 
	cout<<rank[i];
		
} */
/*

int dem[4]={10,15,12,15};
int  sup[4]={14,10,15,12};
int c[4][4]={
{10,30,25,15},
{20,15,20,10},
{10,30,20,20},
{30,40,35,45}
};  

*/
