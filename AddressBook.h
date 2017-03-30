/* 
 * File:   AddressBook.h
 * Author: Claire
 *
 * Created on February 6, 2015, 12:38 PM
 */

#ifndef ADDRESSBOOK_H
#define	ADDRESSBOOK_H

#define BUFFER_SIZE 5

typedef struct entry {

    char lastName[21];
    char firstName[21];
    
    int birthMonth;
    int birthDay;
    int birthYear;
    
    char *address;
    
    int *phoneNumber;
    
    //string for everything except month day and year
    
    struct entry *next;
    
} entryType;

entryType *loadData();

entryType *insertNode(entryType *list, entryType *entry1);

void printContactInfo (entryType *list);

void printItem (entryType *node);

void freeList();
#endif	/* ADDRESSBOOK_H */

