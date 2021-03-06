//Assignment 6
//Name: Kaushal K
//stdID: 200436187

#include<iostream>
#include<stdio.h>
using namespace std;

#define INFINITY 9999 //defining infinity = 999
#define max 5 //max input 5

void djk(int G[max][max],int n,int s_node); //function definition of dijkstra

int main() //int main
{
   int G[max][max];
   for(int i=0;i<max;i++)
   {
       for(int j=0;j<max;j++)
       {
           cout<<"Please enter element at position "<<i<<","<<j<<" : ";
           cin>>G[i][j];
       }
   }
   int n=5;
   int u=0;
   djk(G,n,u);
   return 0;
}
void djk(int G[max][max],int n,int s_node) //function implementation
{
   int cost[max][max],distance[max],pred[max];
   int visited[max],count,mindistance,nextnode,i,j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) 
   {
      distance[i]=cost[s_node][i];
      pred[i]=s_node;
      visited[i]=0;
   }
   distance[s_node]=0;
   visited[s_node]=1;
   count=1;
   while(count<n-1) 
   {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) 
      {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) 
      {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      count++;
   }
   for(i=0;i<n;i++)
   if(i!=s_node) 
   {
      cout<<"\nDistance of node"<<i<<" = "<<distance[i];
      cout<<"\nPath = "<<i;
      j=i;
      do 
      {
         j=pred[j];
         cout<<" <- "<<j;
      }while(j!=s_node);
   }
}
