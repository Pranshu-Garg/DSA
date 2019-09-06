#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    int data;
    struct node * next;
};

typedef struct node Node;			//Typedef for easy use :)

Node* head=NULL;

void insert(int data){				//Insert function for inserting data in the linkedlist
	Node* t = (Node*)malloc(sizeof(Node));
	t->data=data;
	t->next=NULL;

	Node* temp=head;
	if(head==NULL){
		head=t;
		return;
	}
	else {
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=t;
		return;
	}
}

void printL(Node* temp){  			//Print function for printing the LL in reverse order.
	if(temp==NULL)
		return;
	
	printL(temp->next);
	printf("%d", temp->data);
}

void magic(int n, char k[4]){					//The N_Sharp function where the magic happens 8-)
	
	insert(1);
	int i,j;
	for(i=2;i<=n;i++){
		for(j=1;j<=i;j++){
			int carry =0;
			Node* temp=head;
			while(temp!=NULL){
				int mult = temp->data*i + carry;
				temp->data = mult%10;
				carry = mult/10;
				temp=temp->next;
				}
			while(carry){
				insert(carry%10);
				carry = carry/10;
			}
		}

	}
	

	int count_str = strlen(k);							//Noob method for finding the occurance of a pattern
	Node* temp_k = head;
	Node* temp_k2 =head;
	Node* temp_k3 =head;
	Node* temp_k4 =head;
	Node* temp_k5 =head;
	Node* temp_k6 =head;
	int counter=0;
	if(count_str==1){
		k[0]=k[0]-'0';
		while(temp_k!=NULL){
			if(k[0] == temp_k->data)
				counter++;
			temp_k=temp_k->next;
		}
	}
	
	else if(count_str == 2){
		k[0]=k[0]-'0';
		k[1]=k[1]-'0';
		while(temp_k2 != NULL){
			if(k[1] == temp_k2->data){
				temp_k3 = temp_k2->next;
				if(temp_k3)
				if(k[0]==temp_k3->data)
					counter++;
			}
			temp_k2=temp_k2->next;
		}
	}
	
	else{
		k[0]=k[0]-'0';
		k[1]=k[1]-'0';
		k[2]=k[2]-'0';
		while(temp_k4 != NULL){
			if(k[2] == temp_k4->data){
				temp_k5 = temp_k4->next;
				if(temp_k5)
				if(k[1]==temp_k5->data){
					temp_k6 = temp_k5->next;
					if(temp_k6)
					if(k[0] == temp_k6->data)
						counter++;
				}
		}
		temp_k4=temp_k4->next;
	}
}
	


	
	int count=0;
	Node* temp=head;
	while(temp->data == 0){
			count++;
			temp=temp->next;
	}
	printf("%d ", count);
	printf("%d ", counter);
	printL(head);
	head = NULL;
}


int main(){							//Driver without which our code cant run :(
	int t;
	
	printf("%s\n","Enter Number of Test Cases:" );
	scanf("%d", &t);
	printf("%s\n", "Enter Queries");

	while(t--){
		int n;
		char k[4];
		scanf("%d %s",&n, &k);

		magic(n,k);
		printf("\n");
	}
	
}