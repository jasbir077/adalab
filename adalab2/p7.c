#include<stdio.h>
int max(int a,int b)
{
return a>b?a:b;
}
void knapsack(int n,int w[],int m,int v[][10],int p[])
{
int i,j;
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
if(i==0||j==0)
v[i][j]=0;
else if(j<w[i])
v[i][j]=v[i-1][j];
else
v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
}
}
}
void print_optimal_sol(int n,int m,int w[],int v[10][10])
{
int i,j,x[10];
printf("\nThe optimal solution is %d:\n",v[n][m]);
/*Initially no object is selected*/
for(i=0;i<n;i++)
x[i]=0;
i=n; /*number of objects*/
j=m;/*capacity of knapsack*/
while(i!=0 && j!=0)
{
if(v[i][j]!=v[i-1][j])
{
x[i]=1;
j=j-w[i];
}
i=i-1;
}
/*output the objects selected*/
for(i=1;i<=n;i++)
{
printf("x[%d]",i);
}
printf("=");
for(i=1;i<=n;i++)
{
printf("%d ",x[i]);
}
}
int main()
{
int m,n,i,j;
int p[10];
int w[10],v[10][10];
printf("\n Enter the number of objects\n");
scanf("%d",&n);
printf("\nEnter the weights of n objects:");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("Enter the profits of n objects\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("\nEnter the capacity of knapsack\n");
scanf("%d",&m);
knapsack(n,w,m,v,p);
printf("The output is\n");
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
printf("%d ",v[i][j]);
}
printf("\n");
}
print_optimal_sol(n,m,w,v);
}