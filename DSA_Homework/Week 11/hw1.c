#include <stdio.h>



int graph[6][6]= {
	
	{0,1,0,1,0,0},
	{1,0,1,0,0,0},
	{0,1,0,1,0,1},
	{1,0,1,0,1,0},
	{0,0,0,1,0,1},
	{0,0,1,0,1,0},
	
};

int visited[6] = {0};



int main(){
	
	int i;
	int degree;
	int color[6];
	int bipartite = 1;
	
	//bipartite calc.
	
	for(i = 0 ;i<6;i++){
		color[i]=-1;
	}
	
	color[0]=0;
	
	
	int queue[6];
	int front = 0, rear = 0;

	queue[rear++] = 0;
	
	while(front < rear){
		
		int node = queue[front++];
		
		for(i = 0;i<6;i++){
			
			if(graph[node][i]==1){
			
				if(color[i] == -1){
					
					color[i] = 1 - color[node];
					queue[rear++]= i;
					
				}
			
				else if(color[i] == color[node]){
					
					bipartite = 0;
					
					
				}
				
			}
			
			
		}
		
		
	}
	
	
	if(bipartite == 1) {
    printf("Bipartite.\n");
}
	else {
    printf("Not Bipartite");
}
	
	//degree calc.
	
	for(i=0;i<6;i++){
		
		degree=0;
		int j =0;
		for(j;j<6;j++){
			
			degree += graph[i][j];
			
		}
		
		
		printf("%c node degree is: %d \n", i+ 'A' , degree);
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
