// Implements a dictionary's functionality

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH * 122);

// Hash table 
int total = 0 ;
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index =hash (word);
    node* cursor =table [index];
    while (cursor!= NULL)
    {
    if (strcmp(cursor->word,word)==0)
    return 0;
    cursor=cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int sum =0;
    for (int i =0;i<strlen(word); i++)
    {
     sum =sum+ tolower(word[i]);
     
    }
    return (sum %N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE* dic =fopen(dictionary,"r");
    if (dic == NULL)
        return false;
    
    char word [LENGTH + 1];
    
    while (fscanf (dic, "%s" ,word)!= EOF)
    {
        node *n = malloc(sizeof(node));
        if (n== NULL)
            return false;
        strcpy (n->word,word);
        n->next = NULL ;
    
        int index = hash(word);
        if (table [index]== NULL)
            table[index]=n;
        else 
        {
            n->next= table[index];
            table [index]=n;
        }
        total++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i=0; i<N ;i++)
    {
        node * head = table [i];
        node * cursor = head;
        node* tmp =head ;
        while (cursor != NULL)
        {
            cursor = cursor ->next;
            free(tmp);
            tmp= cursor;
        }
    }
    
    return false;
}
