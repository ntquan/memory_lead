#include "stdio.h"
#include "string.h"

typedef struct student
{
    char name[11];
    int age;
}student;


int main()
{
    student st; 
    st.age = 17; 
    strcpy(st.name, "UniversityOfScience");
    #####

    printf("st.name=%s\n", st.name);
    printf("st.age=%d\n", st.age);
    return 0;
}

Output
#############
st.name=UniversityOfScience
st.age=1701405523 <--- Wrong value => hex = 65696353

name[11]: 12 bytes. Because sizeof(int) is 4 bytes, 11 bytes can not algin memory with 4. Therefore, it will get 12 bytes (12/4=3)
age: 4 bytes

        name                   |     age    |
    1 2 3 4 5 6 7 8 9 10 11 12 |13 14 15 16 |17  ....
    U n i v e r s i t y  O  f   S  c  i  e  |n   ....
hex:                           |53 63 69 65 |



