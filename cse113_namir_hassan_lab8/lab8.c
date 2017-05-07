/**
* @file lab8.c
* @author Namir Hassan
* @date 04/17/2017
* @brief this program is designed to take a number as input from user and
* assign it to the head, tail or, middle of a list. other functions include:
* deleting a number, print all numbers, finding a number and count how many
* numbers there are in the list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 32

struct node_t {
        double x;
        struct node_t *next;
};

struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos);
int count_nodes(struct node_t *head);
struct node_t *find_node(struct node_t *head, double n);
struct node_t *delete_node(struct node_t *head, double n);
void delete_list(struct node_t *head);


int main()
{
        int choice = 0;
        char buffer[SIZE];
        int subchoice = 0;
        double number;
        struct node_t *node = NULL;
        struct node_t *head = NULL;
        int position = 0;

        do {

                printf("\n1.) Enter a number\n");
                printf("2.) Delete a number\n");
                printf("3.) Print all numbers\n");
                printf("4.) Tell how many items are in the list\n");
                printf("5.) Find if a number in the list\n");
                printf("6.) Quit\n");

                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &choice);


        switch(choice) {

                case 1:
                        printf("\nEnter the number for the list: ");
                        fgets(buffer, sizeof(buffer), stdin);
                        sscanf(buffer,"%lf", &number);
                        node = create_node(number);
                        printf("\n");
                do {
                        printf("\nEnter item at \n1.) Head\n2.) Tail\n3.) Middle\n");
                        fgets(buffer, sizeof(buffer), stdin);
                        sscanf(buffer, "%d", &subchoice);

                        switch(subchoice) {

                                case 1:
                                        printf("Assigning %.2lf to head.", number);
                                        head = insert_head(head, node);

                                        break;

                                case 2:
                                        printf("Assigning %.2lf to tail", number);
                                        head = insert_tail(head, node);


                                        break;

                                case 3:
                                        printf("\nEnter position: ");
                                        fgets(buffer, sizeof(buffer), stdin);
                                        sscanf(buffer, "%d", &position);
                                        create_node(position);
                                        head = insert_middle(head, node, position);

                                        printf("Assigning %.2lf to middle.", number);



                                        break;

                                default:
                                        printf("\nWrong choice.\n");

                                        break;
                        }
                } while(!(subchoice == 1 || subchoice == 2 || subchoice == 3));
                        break;

                case 2:
                        printf("\nEnter number to be deleted: ");
                        fgets(buffer, sizeof(buffer), stdin);
                        sscanf(buffer, "%lf", &number);
                        printf("\n");
                        head = delete_node(head, number);

                        break;

                case 3:
                        print_list(head);

                        break;

                case 4:
                        printf("\nNumber of items in the list: %d\n", count_nodes(head));

                        break;

                case 5:
                        printf("Enter number to find: ");
                        fgets(buffer, sizeof(buffer), stdin);
                        sscanf(buffer, "%lf", &number);
                        if(find_node(head, number) != NULL) {

                                printf("%.2lf has been found", number);


                        } else {

                                printf("%.2lf not found", number);

                        }

                        break;
                }

        } while(choice != 6);

        delete_list(head);
        head = NULL; /* makes sure that head is not pointing to freed memory */


        return 0;
}

/**
 * memory allocated to create a node that stores a number
 * @param n
 * @return node
 */
struct node_t *create_node(double n)
{
        struct node_t *node = (struct node_t *) malloc(sizeof(struct node_t));
        if(node != NULL){

                node->x = n;
                node->next = NULL;
        } else {

                printf("Cannot allocate memory.");
        }
        return node;

}

/**
 * prints the number located in the node up to 2 decimal places
 * @param *node
 * @return nothing (void)
 */
void print_node(struct node_t *node)
{
        if(node != NULL) {
                printf("%.2lf ", node->x);

        } else {

                printf("\nError: Can not print NULL node\n");

        }

}

/**
 * prints the numbers in the list as it traverses from head to tail
 * @param *head
 * @return nothing (void)
 */
void print_list(struct node_t *head)
{
        printf("\nList: ");
        while(head != NULL) {

                print_node(head);
                head = head->next;
        }
        printf("\n");
}

/**
 * points to the first element of head, node comes the first node of head
 * @param *head
 * @param *node
 * @return head
 */
struct node_t *insert_head(struct node_t *head, struct node_t *node)
{
        if(head == NULL) {

                head = node;

        } else {

                node->next = head;
                head = node;

        }
        return head;

}

/**
 * tmp will hold head, head will traverse end of list
 * @param *head
 * @param *node
 * @return head
 */
struct node_t *insert_tail(struct node_t *head, struct node_t *node)
{
        struct node_t *tmp = head;

        if(head == NULL){

                head = node;

        } else { /* there is atleast one element */

                while(tmp->next != NULL) {

                        tmp = tmp->next;

                }

                tmp->next = node;
        }
        return head;
}

/**
 * sets number to a certain position anywhere in the list
 * @param *head
 * @param *node
 * @param pos
 * @return head
 */
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos)
{
        int i;
        struct node_t *tmp = head;

        if(pos == 1) {

                head = insert_head(head, node);
        } else if (pos > count_nodes(head)) {

                head = insert_tail(head, node);
        } else if(pos > 1){

                for(i = 1; i < (pos - 1); i++){

                        tmp = tmp->next;

                }
                node->next = tmp->next; /* initialize node next first in order to make sure node in front will not get lost*/
                tmp->next = node;
        }

        return head;

}

/**
 * counts the number of nodes in the list
 * @param *head
 * @return count
 */
int count_nodes(struct node_t *head)
{
        int count = 0;

        while(head != NULL) {

                head = head->next;
                count++;
        }
        return count;
}

/**
 * traverses through the list in order to find a specified node
 * @param *head
 * @param n
 * @return head
 */
struct node_t *find_node(struct node_t *head, double n)
{
        while(head != NULL) {
                if(head->x == n){

                        break;
                } else {

                head = head->next;
                }
        }
        return head;
}

/**
 * deletes a certain specified node in the list
 * @param *head
 * @param n
 * @return head
 */
struct node_t *delete_node(struct node_t *head, double n)
{
        struct node_t *node = find_node(head, n);
        struct node_t *tmp = head;
        struct node_t *back = NULL;
        int found = 0;

        if(node == NULL) {
                printf("\nnumber not found.\n");
                return head;
        }
        if(head->x == n){ /* element is found at first node*/
                head = head->next;
                free(head);
                tmp = NULL;

        } else { /* else is somewhere in the else*/
                back = tmp;
                tmp = head->next;
                while(tmp != NULL) {
                        if(tmp->x == n) { /* tmp is pointing to previous node of node */

                                found = 1;
                                break;
                        }
                                back = back->next;
                                tmp = tmp->next;

                }
                if(found == 1) {

                        back->next = tmp->next;
                        free(tmp);
                        tmp = NULL;
                        back = tmp;
                }

        }
        return head;
}

/**
 * deletes the entire existing list by traversing and freeing each
 * @param *head
 * @return nothing (void)
 */
void delete_list(struct node_t *head)
{
        struct node_t *tmp = head; /* tmp and head points to the first node*/

        while(head != NULL){

                head = head->next;
                free(tmp);
                tmp = head;
        }

}
