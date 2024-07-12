#include<stdio.h>
#include<conio.h>
int cost[10][10],d[10], p[10], n;
void dij(int source,int dest)
{
int i,j,u,v,min,S[10];
for(i=0;i<n;i++)
 {
 d[i]=cost[source][i];
 S[i]=0;
 p[i]=source;
 }
S[source]=1;
for(i=1;i<n;i++)
 {
 min=999;
 u=-1;
 for(j=0;j<n;j++)
 {
 if(d[j]<min &&S[j]==0)
 {
 min=d[j];
 u=j;
 }
 }
if(u==-1)
 return;
S[u]=1;
if(u==dest)
 return;
for(v=0;v<n;v++)
 {
 if((d[u]+cost[u][v]<d[v]) &&S[v]==0)
 {
 d[v]=d[u]+cost[u][v];
 p[v]=u;
 }
 }
 }
}
void print_path(int source)
{
int destination,i;
for(destination=0;destination<n; destination++)
 {
 dij(source,destination);
 if(d[destination]==999)
 printf("\n %d is not reachable from %d",destination,source);
 else
 {
 printf("\nThe shortest path from source to every other vertices are:\n");
 i=destination;
 while(i!=source)
 {
 printf("%d <-- ",i);
 
i=p[i];
 }
printf("%d=%d\n",i, d[destination]);
 }
 }
}
int main()
{
int i,j,source;
printf("\n Enter the number of nodes:");
scanf("%d",&n);
printf("\n Enter the cost adjacency matrix:\n");
for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
 scanf("%d",&cost[i][j]);
 }
 }
printf("\n Enter the source Vertex:");
scanf("%d",&source);
print_path(source);
getch();
}