#include <stdio.h>

int arr[100], n, rot, i, j;

void display(){
	for(i = 0; i < n; i++){printf("%d\t", arr[i]);}
	printf("}\n");
}

void rightRotation(){
	printf("Enter The Number Of Rotations: ");
	scanf("%d", &rot);
	
	for (i = 0; i < rot; i++){
		int en = arr[n-1];
		for(j = n-2; j >= 0 ; j--)
			arr[j+1] = arr[j];
		arr[0] = en;
	}
	
	printf("Rotated Array: {\t");
	display();
}

void leftRotation(){
	printf("Enter The Number Of Rotations: ");
	scanf("%d", &rot);
	
	for(i = 0; i < rot; i++){
		int e0 = arr[0];
		
		for(j = 0; j < n-1; j++)
			arr[j] = arr[j+1];
		arr[n-1] = e0;
	}
	
	printf("Rotated Array: {\t");
	display();
}

void main(){
	int menuFlag = 1;
	
	printf("\nEnter The Number Of Elements: ");
	scanf("%d", &n);
	
	printf("\n");
	for(i = 0; i < n; i++){
		printf("Enter Element array[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("\nDeclared Array: {\t");
	display();
	
	while (menuFlag == 1){
		printf("\n\t\t ============= MENU =============");
		printf("\n\t\t 1) Left Rotation");
		printf("\n\t\t 2) Right Rotation");
		printf("\n\t\t 3) Exit");
		printf("\n\t\t ================================\n");
		
		int o;
		printf("\nEnter Your Option: ");
		scanf("%d", &o);
		
		switch(o){
			case 1:
				leftRotation();
				break;
			case 2:
				rightRotation();
				break;
			case 3:
				printf("\nClosing...\n");
				menuFlag = 0;
				break;
			default:
				printf("Please Enter A Valid Option!");
				break;
		}
	}
}