
#include <stdlib.h>
#include <stdio.h> 
#include <time.h>
#include <conio.h>

#include "studentname.h"
#include "subjectname.h"

char randchar[] = "¿¡¬√ƒ≈» ÀÃÕŒœ–—“”◊›";
int randcharsize = (sizeof(randchar) / sizeof(char)) - 1;
    
char GetRandomChar()
{
    return randchar[rand()%randcharsize];
}

char* GenerateFacultyName()
{
    char* facultyname;
    facultyname = new char[4];
    facultyname[3] = '\0';
    facultyname[0] = GetRandomChar();
    do { facultyname[1] = GetRandomChar(); } while (facultyname[0]==facultyname[1]);
    do { facultyname[2] = GetRandomChar(); } while (facultyname[1]==facultyname[2]);
    return facultyname;
}

char* GenerateGroupName()
{
    char* groupname;
    groupname = new char[3];
    groupname[2] = '\0';
    groupname[0] = GetRandomChar();
    do { groupname[1] = GetRandomChar(); } while (groupname[0]==groupname[1]);
    return groupname;
}

template <typename T>
void shuffle(T *array, int n)
{
    int i;
    for (i=0; i<n-1; i++)
    {
        int j = i + rand() / (RAND_MAX/(n-i) + 1);
        T temp   = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

char* ConvertToString(int a)
{
    char* str;
    str = new char[3];
    str[0] = a/10 + '0';
    str[1] = a%10 + '0';
    str[2] = '\0';
    return str;
}

int main()
{
	srand(time(0));
    int maxfaculty = 5;    
    int maxcourse = 4;
    int maxstudentname = sizeof(studentname) / sizeof(void*);
    int maxsubjectname = sizeof(subjectname) / sizeof(void*);
    int* subjectindex = new int[maxsubjectname];
    shuffle(studentname, maxstudentname);
    shuffle(subjectname, maxsubjectname);
	maxsubjectname = maxsubjectname/4 + (rand()%(maxsubjectname/8)); // LOLOLOOLOLLOLL	
    int globalstudent = 0;
    for (int t=0; t<maxsubjectname; t++) subjectindex[t] = t;
    
	freopen("data.xml", "w", stdout);
	
	printf("<?xml version=\"1.0\" encoding=\"WINDOWS-1251\"?>\n");
	
    printf("<university>\n");  
    for (int faculty = 0; faculty < maxfaculty; faculty++)
    {
        char* facultyname = GenerateFacultyName();
        printf("    <faculty>\n");
        printf("        <caption>%s</caption>\n",facultyname);
        int grouptypes = 2 + rand()%3;
        char** groupname = new char*[grouptypes];
        for (int type = 0; type < grouptypes; type++) groupname[type] = GenerateGroupName();
        for (int course = 0; course < maxcourse; course++)
        {
            printf("        <course>\n");
            printf("            <caption>%d</caption>\n",course+1);
            for (int type = 0; type < grouptypes; type++)
            {
                shuffle(subjectindex, maxsubjectname);
                int maxgroups = 2 + rand()%2; 
                int maxsubject = 6 + rand()%3;
                for (int group = 0; group < maxgroups; group++)
                {
                    printf("            <group>\n");
                    printf("                <caption>%s-%d%d</caption>\n",groupname[type],course+1,group+1);
                    int maxstudent = 8 + rand()%8;
                    for (int student = 0; student < maxstudent; student++)
                    {
                        if (globalstudent >= maxstudentname)
                        {
                            printf("\n================================");
                            printf("\nERROR: Not enough student names!");
                            printf("\n================================");
                            printf("\n\n");
                            exit(0);
                        }
                        printf("                <student>\n");
                        printf("                    <caption>%s</caption>\n",studentname[globalstudent++]);
                        for (int subject = 0; subject < maxsubject; subject++)
                        {
                            char* str = ConvertToString(subjectindex[subject] + 1);
                            printf("                    <subject_%s>%d</subject_%s>\n",str,rand()%3,str);
                            delete str;
                        }
                        printf("                </student>\n");
                    }
                    printf("            </group>\n"); 
                }
            }
            printf("        </course>\n");
        }
        printf("    </faculty>\n");    
        printf("\n\n");
        for (int type = 0; type < grouptypes; type++) delete groupname[type];
        delete groupname;
        delete facultyname;    
    }
    for (int k=0; k<maxsubjectname; k++)
    {
        char* str = ConvertToString(k + 1);
        printf("    <subject_%s>%s</subject_%s>\n",str,subjectname[k],str);
        delete str;            
    }
    printf("</university>\n"); 

    return 0;
}
