#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int i = 0; 
	int j = 0;
	struct node* current = head;
	while (current != NULL && j == 0) //goes through linked list and counts the number of nodes that are in the linked list, j = 0 accounts for the first NULL character that is the head
	{
		if (current == NULL)
		{
			j++; //increments the null so that it will only account for 1 NULL char
		}
		i++; //increments i by 1
		current = current -> next; //increments linked list
	}
	return i;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	struct node* current = head;
	int len = length(head);
	char* string = malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len && current != NULL; i++)
	{
		string[i] = current -> letter;
		current = current -> next;
	} 

	string[len] = '\0';
	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	struct node* current = *pHead;
    struct node* tmp = malloc(sizeof(struct node)); // Allocate memory for the new node
    tmp->letter = c;
    tmp->next = NULL;

    if (current == NULL) {
        // If the list is empty, make the new node the head
        *pHead = tmp;
    } else {
        // Traverse to the end of the list and add the new node
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = tmp;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	struct node* current = *pHead;
    struct node* next;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}