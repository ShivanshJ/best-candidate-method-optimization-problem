#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

#define  F(i,a,b) for(int i = (int)(a) ; i<(int)(b); i++)



////////////////////////////////////////////////////////////////////////////////////////////////


/*
int c[20][20],sup[20],dem[20];
*/
 int m,n; 
 int M,N;



void sort(int a[],int n)
{ int temp,j,k;
  for(j=0;j<n;j++)
  { for(k=j+1;k<n;k++)
    { if(a[j]>a[k])
      { temp=a[j];
	a[j]=a[k];
	a[k]=temp;
      }
    }
  }
}

/////////////////////////////////////////
//Supporting function for BCM

//Pre- define instead of taking an input


int dem[4]={200,225,275,250};
int sup[4]={250,300,400};
int c[20][20]={
{11,13,17,14},
{16,18,14,10},
{21,24,13,10}
};
/*

int dem[20]={10,15,12,15};
int sup[20]={14,10,15,12};
int c[20][20]={
{10,30,25,15},
{20,15,20,10},
{10,30,20,20},
{30,40,35,45}
}; */

int path[4][4]={0}; //For visited places or the places we can't tread 
int best_sum=10000 , best_s[4][4]; //Best sum for each combination like f(0,0) or f(0,1) or f(0,2) .. is different but stored here 
								   //best_s saves path matrix for the current best_sum of combination


  /* F(j,0,n)
    path[g][j]=1;
   F(i,0,m) 
	path[i][h]=1;*/
	
void func(int g, int h, int sum)
{ 
   if(g>4 || g<0 ||h>4 ||h<0)
    return ;  
   if(path[g][h]==1||path[g][h]==2)
   return ;
   
   sum+=c[g][h];
   
   F(j,0,n)
    path[g][j]=1;
   F(i,0,m) 
	path[i][h]=1;
	
	
	path[g][h]=2;
	
	if(g==m-1)
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
	F(i,1,n)
	{
	func(g+1,(h+i)%4 , sum);
	}

	//Undo changes
	F(j,0,n)
    	path[g][j]=0;
    F(i,0,m) 
		path[i][h]=0;
		
	F(k,0,4) 
	F(j,0,4)
	{ if(path[k][j]==2)
		{
		    F(i,0,n)
    			path[k][i]=1;
    		F(i,0,m) 
				path[i][j]=1;
				
			path[k][j]=2;
		}
	}
	
	return;
}

//////////////////////
///////////////////Function for getting best candidate
int bcm()
{
	int best=10000, best_pos; //Best records best of all best_sums. and best_pos stores the position of that best starting point
	
F(i,0,n)
{  

//Re-Making path matrix as 0.
	F(k,0,m)
	F(j,0,n)
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
F(k,0,m)
	{
	F(j,0,n)
	{	
	cout<<best_s[k][j]<<" ";
	}
	cout<<endl;
}
cout<<"\nBest combination/ candidates are: \n";
F(k,0,M)
	{
	F(j,0,N)
	{	if(best_s[k][j]==2)
	       cout<<"|"<<c[k][j]<<"|"<<" ";
	    else
		cout<<" "<<c[k][j]<<"  ";  
		   
	}
	cout<<endl;
}

	
return 0;

}

//////////////////////////////////////////
///////////////////////////


///////////////////////////////////////////MAIN TRANSPORTATION PROBLEM

int main()
{ int i,j,b,p,d,k;

  int cf[20],rf[20],a[20],cp[20],rp[20];
  
  int max,min,s,t,sum=0;
  system("cls");
  
  printf("Enter the number of rows & columns respectively:");
  scanf("%d%d",&m,&n);
  
  
  //For balancing the matrix to perform BCM
  if(m<n)
  	{   M=m;
	    N=n;
	    
  		F(i,m,n)
  		F(j,0,n)
  			c[i][j]=0;
  			
  			m=n;	
	}
	else
  	{    M=m;
	    N=n;
  		F(i,0,m)
  		F(j,n,m)
  			c[i][j]=0;
  			
  			n=m;	
	}

 /* printf("\nEnter the cost:");
  for(i=0;i<m;i++)
  { for(j=0;j<n;j++)
     scanf("%d",&c[i][j]);
  }
  printf("\nEnter the demand:");
  for(i=0;i<n;i++)
   scanf("%d",&dem[i]);
  printf("\nEnter the supply:");
  for(i=0;i<m;i++)
   scanf("%d",&sup[i]);*/
   
   
  printf("\nMatrix:\n");
  for(i=0;i<m;i++)
  { for(j=0;j<n;j++)
     printf(" %d ",c[i][j]);
    printf(".%d",sup[i]);
    printf("\n");
  }
  for(j=0;j<n;j++)
   printf(".%d ",dem[j]);
   
   cout<<"\n\n ///////////////////////////////////////////////////////////// \n\n";
	//BCM
	bcm();
	 cout<<"\n\n ///////////////////////////////////////////////////////////// \n\n";
   
   
   
  for(i=0;i<m;i++)
   rf[i]=0;
  for(i=0;i<n;i++)
   cf[i]=0;
  b=m,d=n;
  while(b>0&&d>0)
  { for(i=0;i<m;i++)
     rp[i]=-1;
    for(i=0;i<n;i++)
     cp[i]=-1;
    for(i=0;i<m;i++)
    { k=0;
      if(rf[i]!=1)
      { for(j=0;j<n;j++)
	{ if(cf[j]!=1)
	    a[k++]=c[i][j];
	}
	if(k==1)
	 rp[i]=a[0];
	else
	{ sort(a,k);
	  rp[i]=a[1]-a[0];
	}
      }                     
    }
    for(i=0;i<n;i++)
    { k=0;
      if(cf[i]!=1)
      { for(j=0;j<m;j++)
	{ if(rf[j]!=1)
	   a[k++]=c[j][i];
	}
        if(k==1)
	 cp[i]=a[0];
	else
	{ sort(a,k);
	  cp[i]=a[1]-a[0];
	}
      }
    }
    for(i=0;i<m;i++)
     a[i]=rp[i];
    for(j=0;j<n;j++)
     a[i+j]=cp[j];
    max=a[0];
    p=0;
    for(i=1;i<m+n;i++)
    { if(max<a[i])
      {	max=a[i];
	p=i;
      }
    }
    printf("\n\n     %d %d",max,p);
    min=1000;
    if(p>m-1)
    { p=p-m;
      if(cf[p]!=1)
      { for(i=0;i<m;i++)
	{ if(rf[i]!=1)
	  { if(min>c[i][p])
	    { min=c[i][p];
	      s=i;
	      t=p;
	    }
	  }
	}
      }
    }
    else
    { if(rf[p]!=1)
      { for(i=0;i<n;i++)
	{ if(cf[i]!=1)
	  { if(min>c[p][i])
	    { min=c[p][i];
	      s=p;
	      t=i;
	    }
	  }
	}
      }
    }
    printf("\n\n      %d %d %d",min,s,t);
    if(sup[s]<dem[t])
    { sum+=c[s][t]*sup[s];
      dem[t]-=sup[s];
      rf[s]=1;
      b--;
    }
    else
    if(sup[s]>dem[t])
    { sum+=c[s][t]*dem[t];
      sup[s]-=dem[t];
      cf[t]=1;
      d--;
    }
    
    else
    if(sup[s]==dem[t])
    { sum+=c[s][t]*dem[t];
      cf[t]=1;
      rf[s]=1;
      b--;
      d--;
    }
  }
  printf("\n\nThe final approximated cost using BCM is : %d ",sum);
  
  return 0;
}
