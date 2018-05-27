//
//  main.c
//  DynamicMemoryAllocation
//
//  Created by mac on 5/27/18.
//  Copyright © 2018 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char* name;
    char* phone;
    char* birthDate;
}*Sptr;

void swap(struct Student *a, struct Student *b)
{
    struct Student temp;
    
    temp.name = calloc(strlen(a->name)+1, sizeof(char));
    strcpy(temp.name, a->name);
    temp.birthDate =calloc(strlen(a->birthDate)+1, sizeof(char));
    strcpy(temp.birthDate, a->birthDate);
    temp.phone =calloc(strlen(a->phone)+1, sizeof(char));
    strcpy(temp.phone, a->phone);
    
    
    a->name = calloc(strlen(b->name)+1, sizeof(char));
    strcpy(a->name, b->name);
    a->birthDate =calloc(strlen(b->birthDate)+1, sizeof(char));
    strcpy(a->birthDate, b->birthDate);
    a->phone =calloc(strlen(b->phone)+1, sizeof(char));
    strcpy(a->phone, b->phone);
    
    b->name = calloc(strlen(temp.name)+1, sizeof(char));
    strcpy(b->name, temp.name);
    b->birthDate =calloc(strlen(temp.birthDate)+1, sizeof(char));
    strcpy(b->birthDate, temp.birthDate);
    b->phone =calloc(strlen(temp.phone)+1, sizeof(char));
    strcpy(b->phone, temp.phone);
    
    //free(temp.birthDate);
    //free(temp.name);
    //free(temp.phone);
    
}

void sortStudents(Sptr *student, int size)
{
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
        {
            if(strcmp(student[0][i].name, student[0][j].name) > 0)
            {
                swap(student[0]+i, student[0] +j);
            }
        }
}


void insert(Sptr *students, int *size)
{
    students = realloc(students, sizeof(Sptr*) * (++(*size)));
    
    students[*size - 1] = calloc(1, sizeof(Sptr));
    
    char name[100];
    gets(name);
    students[0][*size-1].name = malloc(sizeof(char) * (sizeof(name)+1));
    strcpy(students[0][*size-1].name, name);
    
    char bDate[100];
    gets(bDate);
    students[0][*size-1].birthDate = malloc(sizeof(char) * (sizeof(bDate)+1));
    strcpy(students[0][*size-1].birthDate, bDate);
    
    char cell[100];
    gets(cell);
    students[0][*size-1].phone = malloc(sizeof(char) * (sizeof(cell)+1));
    strcpy(students[0][*size-1].phone, cell);
    
    sortStudents(students, *size);
    
}

void print(Sptr *students, int size)
{
    for(int i=0;i<size;i++)
        printf("%s %s %s\n", students[0][i].name, students[0][i].birthDate, students[0][i].phone);
    
}

void deleteStudent(Sptr *students, int *size)
{
    char temp[100];
    gets(temp);
    
    for(int i=0;i<*size;i++)
    {
        if(strcmp(students[0][i].name, temp)==0)
        {
            for(int j=i;j<*size-1;j++)
                swap(students[0]+j, students[0]+(j+1));
            free(students[*size - 2]);
            (*size)--;
        }
    }
    
    
}




int main() {
    
    Sptr *students;
    int size=0, *pSize = &size;
    
    
    students = calloc(1, sizeof(Sptr*));
    
    int i=3;
    while(i--)
        insert(students, pSize);
    
    deleteStudent(students, pSize);
    
    print(students, size);
    
    
    
    
    
    return 0;
}
