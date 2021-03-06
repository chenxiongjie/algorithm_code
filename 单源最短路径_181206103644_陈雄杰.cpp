#include <stdio.h>
 
#define M	65535 
#define N	5 
 
void Dijkstra(int Cost[][N], int v, int Dist[], int prev[])
{
    int s[N];
    int mindis,dis;
    int i, j, u;
    
    for(i=0; i<N; i++)
    {
        Dist[i] = Cost[v][i];
        s[i] = 0;
        if(Dist[i] == M)
			prev[i] = -1;
        else
			prev[i] = v;
    }
    Dist[v] = 0;
    s[v] = 1; 
    for(i=1; i < N; i++)
    {
        mindis = M;
        u = v;
        for (j=0; j < N; j++) 
			if(s[j]==0 && Dist[j]<mindis)
			{
				mindis = Dist [j];
				u = j;
			} 
        s[u] = 1;
        for(j=0; j<N; j++) 
        if(s[j]==0 && Cost[u][j]<M)
        { 
            dis = Dist[u] +Cost[u][j];
           
 
            if(Dist[j] > dis)
            {
                Dist[j] = dis;
                prev[j] = u;
            }
        }
    } 
}


void PrintPrev(int prev[],int v,int vn)
{
    int tmp = vn;
    int i, j;
    
    int tmpprv[N];
    
    for(i=0; i < N; i++)
		tmpprv[i] = 0;
 
    
    tmpprv[0] = vn+1;
    
    for(i =0, j=1; j < N ;j++)
    {
        if(prev[tmp]!=-1 && tmp!=0)
        {
            tmpprv[i] = prev[tmp]+1;
            tmp = prev[tmp];
            i++;
        }
        else break;
    }
 
   
   
    for(i=N-1; i >= 0; i--)
    {
        if(tmpprv[i] != 0)
        { 
            printf("S%d", tmpprv[i]);
            if(i) 
                printf("-->");
        }
    }
	printf("-->S%d", vn+1);
}

int main()
{
   
    char *Vertex[N]={"S1", "S2", "S3", "S4", "S5"};
 
    int Cost[N][N]={
		{0, 10, M, 30, 100},
        {M, 0, 50, M, M},
        {M, M, 0, 20, 10},
        {M, M, 20, 0, 60},
        {M, M, M, M, 0},
    };
    int Dist[N];
    int prev[N];  
	int i;
    
    
    Dijkstra(Cost, 0, Dist, prev);
    for(i=0; i < N; i++)
    {
       
        printf("path %s-->%s:%d\t", Vertex[0], Vertex[i], Dist[i]);
       
        PrintPrev(prev, 0, i);
        printf("\n");
       
    }
 	
    return 0;
    
}
 
