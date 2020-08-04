/*
    A program that counts the number of instances of words from an input that consists of alphabetical characters and spaces.
    As the input grows so too will the dynamically built list of words; counting the number of instances of each word will
    grow as the number of words grow linearly when the list is unsorted. Sorting a list in an a flat array is a linear operation as well,
    since the whole array will have to be shifted in the worst case. This pogram is thus a good target for a tree like
    structure - structs! A binary search tree allows the processing of a new word in log(n).

    The purpose of doing this program is to practice with structs, and in particular poiters to structures - pointers
    are necessary to represent a recursive tree type like a BST, where a Node points to...other Nodes.
*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 1000

/*

*/
struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

struct node *addword(struct node *node, char *word);
struct node *talloc(void);
struct node *makenode(char *word, int count, struct node *left, struct node *right);
char *mystrdup(char *s);
void printtree(struct node *);

/*
    Purpose of this function is ancillary to the purpose of this count words - nothing here illuminates the usage and
    purpose of structs.

    Provided user input, get alphabetic words.

    Understanding:
        Input can consist of all sorts of characters. Let's define a word as a contiguous block of alphabetic
        characters separated on both ends by spaces. Annnnd lets assume just these characters for simplicity sake.

    Plan:
        Skip space characters.
        Grab alpha characters until space is reached.
    
    API
       Fill in each character string arg with word, return first char of word (since the return type needs to be a int like EOF)
       Return EOF when reached. 
*/
int getword(char *word, int maxword);

int main()
{
    printf("Count my words...\n");

    struct node *tree = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        tree = addword(tree, word);
        
    printtree(tree);
    return 0;
}

struct node *talloc(void)
{
    return (struct node *) malloc(sizeof(struct node));
}

char *mystrdup(char *s)
{
    char *p;
    
    p = (char *) malloc(strlen(s) + 1) /* +1 for the '\0' */;
    for (int i = 0; (p[i] = s[i]) != '\0'; i++)
        ;
    return p;
}

struct node *makenode(char *word, int count, struct node *left, struct node *right)
{
    struct node *n = talloc();

    n->word = mystrdup(word);
    n->count = count;
    n->left = left;
    n->right = right;
    return n;
}
/*
    Print tree in alphabetical order.

    Understanding:
        The left most node is first.
        Followed by parent.
        Followed by right node.
*/
void printtree(struct node *n) 
{
    if (n == NULL)
        return;
    
    printtree(n->left);
    printf("%s: %d\n", n->word, n->count);
    printtree(n->right);
}

struct node *addword(struct node *node, char *word)
{
    if (node == NULL)
        return makenode(word, 1, NULL, NULL);

    int compare = strcmp(node->word, word);

    if (compare == 0)
        node->count++;
    else if (compare > 0)
        node->left = addword(node->left, word);
    else
        node->right = addword(node->right, word);
    
    return node;
}

/*
    Note per above desrciption, this function expects input chars to be either alpha or spaces, and nothing else!
*/
int getword(char *word, int maxword)
{
    int c, i = 0;

    while (isspace(c = getchar()))
        ;
    
    do {
        word[i++] = c;
    } while (isalpha(c = getchar()));

    word[i] = '\0';

    if (c == EOF)
        return c;

    return word[0];
}

