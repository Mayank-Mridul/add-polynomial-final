#include<stdio.h>
#include<stdlib.h>

struct node* poly(int x, int y, struct node *star);
void display(struct node *start);
struct node* add_poly(struct node *h1, struct node *h2, struct node *h3);

struct node{
int coeff;
int exp;
struct node *next;

} *start = NULL, *start2 = NULL, *start3 = NULL;


int main(){
printf("WELCOME TO THE WORLD OF PLOYNOMIAL\n");

printf("ENTER THE NUMBER OF ELEMENTS OF THE POLYNOMIAL\n\n");

int n,a,b,n1,a1,b1;

scanf("%d", &n);

for(int i=0;i<n;i++){
printf("ENTER THE COEFF AND THEN THE EXPONENT\n\n");

scanf("%d %d", &a, &b);

start = poly(a,b,start);
} 

printf("ENTER THE NUMBER OF ELEMENTS OF THE 2nd POLYNOMIAL\n\n");


scanf("%d", &n1);

for(int i=0;i<n1;i++){
printf("ENTER THE COEFF AND THEN THE EXPONENT\n\n");

scanf("%d %d", &a1, &b1);

start2 = poly(a1,b1,start2);
} 

display(start);
display(start2);

start3 =  add_poly(start,start2,start3);

display(start3);
}

struct node* poly(int x, int y, struct node *star)
{
struct node *ptr, *temp;
ptr = (struct node*)malloc(sizeof(struct node));

//ptr->next = NULL;

ptr->coeff = x;

ptr->exp = y;

ptr->next = NULL;

if( star == NULL ){
		star = ptr;
		//ptr->next = NULL;
}
else{
		temp = star;
		
		while(temp->next!=NULL){
		temp = temp->next;
		}
		
		temp->next = ptr;
}

		return star;
}
void display(struct node *star){
	struct node *temp;
	int z= 1;
	
	
	printf("\nPOLYNOMIAL IS \n");
	
	
	if(star == NULL){
	printf("LIST IS EPMTY");
	}
	else{
	
	temp = star;
	
	
	while(temp!=NULL){
	if(z!=1){
	printf("+");
	}
	printf("%dX^%d", temp->coeff, temp->exp);
	temp = temp->next;
	z=2;
	}
	}
	
	printf("\n");
}

//This function helps to add two POLYNOMIAL
//NOT WORKING IF THE LENGTH OF SECOND PIOLYNOMIAL IS GREATER THAN THE FIRST POLYNOMIAL

struct node* add_poly(struct node *h1, struct node *h2, struct node *h3){
struct node *ptr, *t1, *t2, *prev;

ptr = (struct node*)malloc(sizeof(struct node));

h3 = ptr;

t1 = h1;

t2 = h2;

while(t1!=NULL && t2!=NULL){
if(t1->exp>t2->exp){
ptr->coeff = t1->coeff;
ptr->exp = t1->exp;
t1 = t1->next;
}
else if(t1->exp<t2->exp){
ptr->coeff = t2->coeff;
ptr->exp = t2->exp;
t2 = t2->next;
}
else if(t1->exp == t2->exp){
ptr->coeff = t1->coeff + t2->coeff;
ptr->exp = t1->exp;
t1 = t1->next;
t2 = t2->next;
}

ptr->next = (struct node*)malloc(sizeof(struct node));
prev = ptr;
ptr = ptr->next;
}

while(t1!=NULL){

	ptr->coeff = t1->coeff;
	ptr->exp = t1->exp;
	
	ptr->next = (struct node*)malloc(sizeof(struct node));
	
	prev = ptr;
	
	ptr = ptr->next;
	}
	
	while(t2!=NULL){

	ptr->coeff = t2->coeff;
	ptr->exp = t2->exp;
	
	ptr->next = (struct node*)malloc(sizeof(struct node));
	
	prev = ptr;
	
	ptr = ptr->next;
	}
	
	
	
	free(ptr);
	prev->next = NULL;
	
	
	return h3;
}