#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 15

int no_vertices;
struct node {
    int data;
    struct node *next;
};

void readgraph(struct node *ad[]) {
    struct node *newnode;
    int i, j, k, data;

    for (i = 0; i < no_vertices; i++) {
        struct node *last = NULL;
        printf("\nEnter the Number of Neighbours Of %d: ", i);
        scanf("%d", & k);

        for (j = 0; j < k; j++) {
            printf("Enter the Value Of %d The Neighbour Of %d: ", j, i);
            scanf("%d", & data);
            newnode = (struct node * ) malloc(sizeof(struct node * ));
            newnode -> data = data;
            newnode -> next = NULL;
            if (ad[i] == NULL) 
                ad[i] = newnode;
            else
                last -> next = newnode;
            last = newnode;
        }
    }
}

void bfsList(struct node *ad[], int start, int visited[]) {
	int queue[no_vertices],front=-1,rear=-1;
	printf("BFS (List): ");
	queue[++rear] = start;
	visited[start]=1;
	front++;
	while(front <= rear){
		printf("%d ",queue[front]);
		struct node *ptr;
		ptr =  ad[queue[front++]];
		while(ptr != NULL){
			if(visited[ptr->data]!=1){
				queue[++rear] = ptr->data;
				visited[ptr->data] = 1;
            }
			ptr = ptr -> next;
		}
	}
}

void bfsMatrix(int startVertex, int visited[MAX_SIZE], int adjacencyMatrix[MAX_SIZE][MAX_SIZE], int vertexCount) {
    int queue[vertexCount], front = -1, rear = -1, vertex;
    queue[++rear] = startVertex;
    visited[startVertex] = 1;
    printf("BFS (Matrix): ");
    while (front != rear) {
        vertex = queue[++front];
        printf(" %d ", vertex);
        for (int i = 0; i < vertexCount; i++) {
            if (adjacencyMatrix[vertex][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfsList(struct node * ad[], int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);
    struct node * ptr;
    ptr = ad[start];
    while (ptr != NULL) {
        if (visited[ptr -> data] == 0)
            dfsList(ad, ptr -> data, visited);
        ptr = ptr -> next;
    }
}

void dfsMatrix(int vertex, int visited[MAX_SIZE], int adjacencyMatrix[MAX_SIZE][MAX_SIZE], int vertexCount) {
    printf(" %d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < vertexCount; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i])
            dfsMatrix(i, visited, adjacencyMatrix, vertexCount);
    }
}

void DFSListMain() {
    int i, j, k, ch, start;
    printf("Enter the Total Number of Vertex: ");
    scanf("%d", & no_vertices);
    int visited[no_vertices];
    struct node *adj[no_vertices];
    for (i = 0; i < no_vertices; i++)
        adj[i] = NULL;
    readgraph(adj);

    printf("Enter the Vertex From Which Do You Wanted to Start: ");
    scanf("%d", & start);
    for (int k = 0; k < no_vertices; k++)
        visited[k] = 0;

    printf("DFS (List): ");
    dfsList(adj, start, visited);
}

void DFSMatrixMain(){
    int visited[MAX_SIZE] = {0};
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
    int vertexCount;
    printf("Enter the Total Number of Vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter Adjacency Matrix (1 for Connection and 0 for No Connection):\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }
    printf("DFS (Matrix): ");
    for (int i = 0; i < vertexCount; i++) {
        if (visited[i] == 0)
            dfsMatrix(i, visited, adjacencyMatrix, vertexCount);
    }
}

void BFSListMain(){
	int i,j,k,ch,start;
	printf("Enter the Total Number of Vertices: ");
	scanf("%d",&no_vertices);
	int visited[no_vertices];
	struct node *adj[no_vertices];
	for(i=0;i<no_vertices;i++)
		adj[i] = NULL;
	readgraph(adj);

    printf("Enter the Vertex From Which Do You Wanted to Start:");
	scanf("%d",&start);
	for(int k=0;k<no_vertices;k++)
		visited[k]=0;
	bfsList(adj,start,visited);
}

void BFSMatrixMain(){
    int visited[MAX_SIZE] = {0};
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
    int vertexCount;
    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);
    printf("Enter Adjacency Matrix (1 for Connection and 0 for No Connection): \n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }
    for (int i = 0; i < vertexCount; i++) {
        if (visited[i] == 0)
            bfsMatrix(i, visited, adjacencyMatrix, vertexCount);
    }
}

void main(){
    int menuFlag = 1, o;
    printf("\n\t\t ============= MENU =============");
    printf("\n\t\t 1) DFS - Adjacency Matrix");
    printf("\n\t\t 2) DFS - Adjacency List");
    printf("\n\t\t 3) BFS - Adjacency Matrix");
    printf("\n\t\t 4) BFS - Adjacency List");
    printf("\n\t\t 5) Exit");
    printf("\n\t\t ================================\n");
	
    while (menuFlag == 1){
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                DFSMatrixMain();
                break;
            case 2:
                DFSListMain();
                break;
            case 3:
                BFSMatrixMain();
                break;
            case 4:
                BFSListMain();
                break;
            case 5:
                printf("\nClosing...\n");
                menuFlag = 0;
                break;
            default:
                printf("\nPlease Enter A Valid Option!\n");
        }
    }
}