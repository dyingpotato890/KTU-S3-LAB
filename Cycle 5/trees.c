#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
};
struct node *new, *root = NULL, *ptr, *qptr, *queue[20];

int d, n, rear = -1, front = -1;

void enqueue(struct node *root){
    if(front==-1){
        queue[++rear] = root;
        front++;
    }
    else
        queue[++rear] = root;
}

struct node* dequeue() {
    if (front != rear)
        return (queue[front++]);
    else {
        int temp = front;
        front = rear = -1;
        return (queue[temp]);
    }
    return NULL;
}

struct node* findMin(struct node * root) {
    while (root -> lchild != NULL)
        root = root -> lchild;
    return root;
}

struct node* createNode(int d){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = d;
    temp -> lchild = temp -> rchild = NULL;
    return temp;
}

struct node* insert(struct node *root, int val){
    if (root == NULL){
        new = createNode(val);
        root = new;
    }
    else if (d <= (root -> data))
        root -> lchild = insert(root -> lchild, val);
    else
        root -> rchild = insert(root -> rchild, val);
    return root;
}

struct node* inorder(struct node *ptr){
    if (ptr != NULL){
        inorder(ptr -> lchild);
        printf(" %d ", ptr -> data);
        inorder(ptr -> rchild);
    }
}

struct node* preorder(struct node *ptr){
    if (ptr != NULL){
        printf(" %d ", ptr -> data);
        preorder(ptr -> lchild);
        preorder(ptr -> rchild);
    }
}

struct node* postorder(struct node *ptr){
    if (ptr != NULL){
        postorder(ptr -> lchild);
        postorder(ptr -> rchild);
        printf(" %d ", ptr -> data);
    }
}

void levelorder(struct node * root) {
    if (root == NULL)
        return;
    enqueue(root);

    while (front != -1) {
        struct node * temp = dequeue();

        printf(" %d ", temp -> data);
        if (temp -> lchild != NULL)
            enqueue(temp -> lchild);
        if (temp -> rchild != NULL)
            enqueue(temp -> rchild);
    }
}

struct node * delete(struct node * root, int n) {
    if (root == NULL)
        return NULL;
    if (n < root -> data)
        root -> lchild = delete(root -> lchild, n);
    else if (n > root -> data)
        root -> rchild = delete(root -> rchild, n);
    else {
        if (root -> lchild == NULL && root -> rchild == NULL) {
            free(root);
            return NULL;
        } else if (root -> lchild == NULL) {
            struct node * temp = root -> rchild;
            free(root);
            return temp;
        } else if (root -> rchild == NULL) {
            struct node * temp = root -> lchild;
            free(root);
            return temp;
        } else {
            struct node * temp = findMin(root -> rchild);
            temp -> lchild = root -> lchild;
            return root -> rchild;
        }
    }
    return root;
}

void main(){
	int o, menuFlag = 1;
	
    printf("\t\t ============= MENU =============");
    printf("\n\t\t 1) Insert Element(s)");
	printf("\n\t\t 2) Inorder Traversal");
	printf("\n\t\t 3) Preorder Traversal");
	printf("\n\t\t 4) Postorder Traversal");
	printf("\n\t\t 5) Levelorder Traversal");
	printf("\n\t\t 6) Delete Element");
	printf("\n\t\t 7) Exit");
	printf("\n\t\t ================================\n");

	while (menuFlag == 1){
		printf("\n\nEnter Your Option: ");
		scanf("%d", &o);
		
		switch(o){
            case 1:
                printf("\nEnter The Number Of Elements: ");
                scanf("%d", &n);
                for (int _ = 0; _ < n; _++){
                    printf("Enter The Data: ");
                    scanf("%d", &d);
				    root = insert(root, d);
                }
				break;
			case 2:
                printf("Inorder Traversal: ");
				inorder(root);
				break;
			case 3:
                printf("Preorder Traversal: ");
				preorder(root);
				break;
			case 4:
                printf("Postorder Traversal: ");
				postorder(root);
				break;
			case 5:
                printf("Levelorder Traversal: ");
				levelorder(root);
				break;
            case 6:
                printf("Enter The Element To Be Deleted: ");
                scanf("%d", &n);
                delete(root, n);
                printf("Element Deleted!\n");
                break;
			case 7:
				printf("Closing...\n");
				menuFlag = 0;
				break;
			default:
				printf("Please Enter A Valid Option!\n");
				break;
		}
	}
}