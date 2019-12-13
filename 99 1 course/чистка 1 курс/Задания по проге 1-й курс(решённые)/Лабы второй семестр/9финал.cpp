#include <stdlib.h>
#include<clocale>
#include <stdio.h>
#include <string.h>
#include <time.h>
//english text only; 4 marks ; 2 -неуд
const int N=4;

typedef struct st {
    char surname[12];
    int grades[N];
    int dele;
    struct st *next;
} slist;

int more(char* s1, char* s2){
    int x=0;
    while(s1[x]==s2[x] && x<strlen(s1) && x<strlen(s2)){
        x++;
    }
    if (x==strlen(s1)) return 0;
    if (x==strlen(s2)) return 1;
    if (s1[x]>s2[x]) return 1;
    return 0;
}

void del(slist *head){
    slist *cur;
    cur=head;
    while(cur!=NULL){
        for(int i=0;i<N;i++){
            if (cur->grades[i]<3){
                cur->dele=1;
                break;
            }
        }
        cur=cur->next;
    }
}

void sl(slist *head){
    int all=0,t;
    slist *cur;
    char tmp[12];

    cur=head;
    while (cur!=NULL) cur=cur->next,all++;
    slist *arr[all];
    cur=head;
    for (int i=0;i<all;i++){
        arr[i]=cur;
        cur=cur->next;
    }
    for(int i=0;i<all-1;i++)
        for(int j=all-2;j>=i;j--){
            if (more(arr[j]->surname,arr[j+1]->surname)){
                strcpy(tmp,arr[j]->surname);
                strcpy(arr[j]->surname,arr[j+1]->surname);
                strcpy(arr[j+1]->surname,tmp);
                for(int k=0;k<N;k++){
                    t=arr[j]->grades[k];
                    arr[j]->grades[k]=arr[j+1]->grades[k];
                    arr[j+1]->grades[k]=t;
                }
            }
        }
}

slist* create(){
    int i=1,tot;
    slist *cur,*prev,*first;
    first=prev=new slist;
    printf("Сколько студентов: ");
    scanf("%d",&tot);
    printf("Фамилия студента: ");
    scanf("%s",prev->surname);
    printf("Оценки %s: ",prev->surname);
    for(int j=0;j<N;j++) scanf("%d",&prev->grades[j]);
    prev->dele=0;
    while(i<tot){
        cur=new slist;
        printf("Фамилия студента:");
        scanf("%s",cur->surname);
        printf("Оценки %s: ",cur->surname);
        for(int j=0;j<N;j++) scanf("%d",&cur->grades[j]);
        cur->dele=0;
        prev->next=cur;
        prev=cur;
        i++;
    }
    printf("\n");
    cur->next=NULL;
    return first;
}

void pl(slist *head){

    slist *cur;
    cur=head;
    while (cur!=NULL){
        if(!cur->dele){
            printf("%s оценки ",cur->surname);
            for (int i=0;i<N;i++) printf(" %d ",cur->grades[i]);
            printf("\n");
        }
        cur=cur->next;
    }
}

void dl(slist *head){
    slist *p,*q;
    q=p=head;
    while (p!=NULL){p=q->next;
           delete q;
q=p;
    }
head=NULL;
}

int main(){
	setlocale( LC_ALL, "Russian" );
    srand(time(NULL));
    system("cls");
    slist *head;
    head=create();
    sl(head);
    pl(head);
    del(head);
    printf("\n");
    printf("\n");
    printf("\n");
    pl(head);
    dl(head);
    system("PAUSE");
    return 0;
}
