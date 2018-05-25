#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>

struct node
{
	int id;

	node *kiri;
	node *kanan;
};

struct node *root = NULL;





void input_data()
{	
	struct node *curr = root;
	struct node *curr_parent;
	//struct node *new_node;

	int input = 0;
	printf("Input ID: ");
	scanf("%d",&input);fflush(stdin);


	node *new_node = (node *)malloc(sizeof(node));
	
	new_node->id = input;
	new_node->kanan = NULL;
	new_node->kiri = NULL;


	if(root == NULL)
	{	
		//Jika Head == NULL
		root = new_node;
		root->kanan = NULL;
		root->kiri = NULL;
	}
	else
	{
		//Jika Head Tidak Sama Dengan NULL
		while(curr != NULL)
		{
			curr_parent = curr;

			if(input<curr->id)
				curr = curr->kiri;
			else
				curr = curr->kanan;
		}


		if(input<curr_parent->id)
			curr_parent->kiri = new_node;
		else
			curr_parent->kanan = new_node;

	}
}

void search_data()
{
	int counter = 1;
	int data_search = 0;
	int flag = 0;

	struct node *curr = root;

	printf("Masukan ID Yang Mau Dicari: ");
	scanf("%d",&data_search);fflush(stdin);


	while(curr->id != data_search){
		
		if(data_search < curr->id){

			curr = curr->kiri;

		}else{

			curr = curr->kanan;

		}

		counter++;

	}


		printf("Data Ditemukan\nTotal Pencarian = %d\n\n",counter);

}


void exit(){


}


int main(){
	
	int input = 0;


	do{

		do{

			//system("clr");

			printf("1. Input Data\n");
			printf("2. Search\n");
			printf("3. Exit\n");


			printf("Masukan Input: ");
			scanf("%d",&input);fflush(stdin);

		}while(input<1 || input>3);


		switch(input){

		case 1:
			input_data();
			break;
		case 2:
			search_data();
			break;
		case 3:
			exit();
			break;

		}


	}while(input!=3);

}