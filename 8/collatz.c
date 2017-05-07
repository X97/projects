/**
* @file collatz.c
* @author Namir Hassan
* @date 04/17/2017
* @brief takes number from user input and checks if that number is even or odd.
* if the number is odd, it is divided by 2, otherwise it is multiplied by 3
* and 1 is added to it. It will repeat until the number equates to 1.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 32

struct node_t *create_node(int n);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
void print_list(struct node_t *head);
void print_node(struct node_t *node);
int count_nodes(struct node_t *head);
int coll(int n);
void delete_list(struct node_t *head);


struct node_t {

        int x;
        struct node_t *next;

};

int main()
{
        int n;
        char buffer[SIZE];
        struct node_t *node = NULL;
        struct node_t *head = NULL;
        struct node_t *tail = NULL;

        printf("Enter a number for n: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &n);
        printf("\n");

        printf("\nSequence is: ");

        printf("\nn = %d\n", n);
        do {
                node = create_node(n);

                if(head == NULL) {
                head = insert_tail(head, node);
                tail = node;

                } else {

                tail = insert_tail(tail, node);

                }
                n = coll(n); /* calculates n everytime */

        } while(n != 1);
        /* this is for n = 1 */
        node = create_node(n);
        tail = insert_tail(tail, node);

        printf("cycle length = %d\n", count_nodes(head));
        print_list(head);

        delete_list(head);
        head = NULL;
        tail = NULL;
        node = NULL;

        return 0;
}

/**
 * formulas and equations to solve each case for if number is even or odd
 * @param n
 * @return n
 */
int coll(int n){
        if(n % 2 == 0) {
                n = n/2;

        } else {

                n = 3*n + 1;

        }
        return n;
}

/**
 * memory allocated to create a node that stores a number
 * @param n
 * @return node
 */
struct node_t *create_node(int n)
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
 * prints the number located in the node
 * @param *node
 * @return nothing (void)
 */
void print_node(struct node_t *node)
{
        if(node != NULL) {
                printf("%d ", node->x);

        } else {

                printf("\nError: Can not print NULL node\n");

        }

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

        } else {

                while(tmp->next != NULL) {

                        tmp = tmp->next;

                }

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
 * deletes the entire existing list by traversing and freeing each
 * @param *head
 * @return nothing (void)
 */
void delete_list(struct node_t *head)
{
        struct node_t *tmp = head;

        while(head != NULL){

                head = head->next;
                free(tmp);
                tmp = head;
        }

}
