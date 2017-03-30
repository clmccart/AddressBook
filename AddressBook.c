/* 
 * File:   main.c
 * Author: Claire McCarthy clmccart
 *
 * Created on February 6, 2015, 12:38 PM
 * 
 * AddressBook.c
 * AddressBook.c source code for CSCI2101 Lab 2.
 * 
 * Functional Description:
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AddressBook.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    entryType *list = loadData();
    printContactInfo(list);
    
    return (EXIT_SUCCESS);
}

entryType *loadData() {
    
    FILE *inputf;
    char buffer[BUFFER_SIZE];

    //
	// Open the input file; could be NULL!!
    //
    
    inputf = fopen("input", "r"); 
    
       
    //declare the head of the list
    entryType *list = NULL;
    entryType *entry1 = NULL;
	while (fgets(buffer, BUFFER_SIZE, inputf) != NULL) {

        // create a node; could be NULL!!
        // let's say it's called "working"
            
    
            
            entry1 = (entryType *) malloc(sizeof(entryType));
            if (entry1 == NULL) {
                printf("error: malloc returned NULL");
                return EXIT_FAILURE;
            }   
            sscanf(buffer, "%[^,],%[^,],%d,%d,%d",
                entry1->lastName, 
                entry1->firstName,
                &entry1->birthMonth,
                &entry1->birthDay,
                &entry1->birthYear);
            
            entry1->next = NULL;
        
            list = insertNode(list, entry1);
        }
    
            
        // scan the data into the node from the file
            
		
        // Now add it to the list. “insertNode” function


	fclose(inputf);
        
            
        return list;
        
}

void printContactInfo (entryType *list) {
    entryType *curr = list;
    while (curr != NULL) {
        printItem(curr);
        curr = curr->next; 
    }

}

void printItem (entryType *node) {
    
    printf ("Name: %s, %s\n", node->lastName, node->firstName);
    printf ("Birth Day: %d/%d/%d\n", node->birthMonth, node->birthDay, 
            node->birthYear);
    
}

entryType *insertNode(entryType *list, entryType *entry1) {
//    entryType *headPtr, *workingPtr, *thirdPtr; //in the main.c file
//    headPtr = NULL;
//    workingPtr = (myStruct *) malloc(sizeof(myStruct));
//    workingPtr->next = headPtr; //sets headptr to point to the beginning of the list
//    headPtr = workingPtr; 
//
//    thirdPtr = headPtr; //makes workingPtr to point to the end
//    while(thirdPtr->next != NULL) {
//        thirdPtr = thirdPtr->next;
//    }
//    workingPtr->next = NULL;
//    thirdPtr->next = workingPtr;
//
//    while (thirdPtr->next != NULL) { // makes workingPtr point to somewhere in the middle
//        if (workingPtr->myData1 < thirdPtr->next->myData1) {
//            thirdPtr = thirdPtr->next;
//        break; //forces program to exit the while loop once it finds where to put thirdPtr (continue; goes to the next iteration of the while loop)
//
//    workingPtr->next = NULL;
//    thirdPtr->next = workingPtr;
    
    
    if (list == NULL) {
        list = entry1;
    }
    else {
        entry1->next = list;
        list = entry1;
    }
    
    return list;
}



void freeList() {
    
}




//loadData function - loads data into the linked list
//printContactInfo - send it a node and prints out the function in that node
//insertNode 
//freeList - frees all the memory in the list
//printList function - optional 