#include <stdio.h>



int graph[5][5] = {

	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,0,0},
	{1,0,0,0,1},
	{0,1,0,1,0},

};


int visited[5] = {0};


void BFS(int start){
	
	int queue[5];
	int front = 0;
	int rear = 0;
	
	visited[start] = 1;
	queue[rear++] = start;
	
	while(front < rear){
		
		int node = queue[front++];
		
		printf("%c ", node + 'A');
		
		int i = 0;
		for(i;i<5;i++){
			
			if(graph[node][i]==1 && !visited[i]){
				
				visited[i] = 1;
            	queue[rear++] = i;
				
				
			}
			
			
			
			
			
		}
		
	}
	
}


void DFS(int node){
	
	visited[node]=1;	
	
	printf("%c ",node + 'A');
	
	for(int i = 0;i<5;i++){
		
		if(graph[node][i]==1 && !visited[i]){
			
			DFS(i);
			
			
		}
		
		
		
		
	}
	
}



int main(){
	
	
	printf("BFS: ");	
	BFS(0);

    for (int i = 0; i < 5; i++){
    	
    	visited[i] = 0;
    	
	}
        

    printf("\n");

    printf("DFS: ");
    DFS(0);
	
	
	
	
	
	return 0;
}
