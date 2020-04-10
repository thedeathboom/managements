#include  <iostream> 
#include  <string> 
#include  <stdio.h> 
#include  <stdlib.h> 
#include  <string.h> 
#include<locale.h>

using  namespace  std; 
struct course{
       char cname[10];
       float grade;
};
 struct ssystem{
     int cla;
     char ID[10];
     char name[10];
     int x;
     struct course cour[10];
     float allgrade=0.0;
     float ave=0.0;
     struct ssystem *next;
 };
 
void welcome(int n){
    printf ("\t*************We have %d student in system***************\n",n);
    printf ("\t-----------Welcome to our student grade system----------\n");
    printf ("\t*                     1.input a student                *\n");
    printf ("\t*                     2.delet a student                *\n");
    printf ("\t*                     3.display                        *\n");
    printf ("\t*                     4.exit                           *\n");
    printf ("\t--------------------------------------------------------\n");
}
int input(ssystem *&L,int a){
    if(a==0){
        ssystem *end;
        end=(ssystem *)malloc(sizeof(ssystem));
        L->next=end;
        end->next=NULL;
        cout<<"Please input class"<<'\n';
        cin>>end->cla;
        cout<<"Please input ID"<<'\n';
        cin>>end->ID;
        cout<<"Please input name"<<'\n';
        cin>>end->name;
        cout<<"Please input the num of course"<<'\n';
        cin>>end->x;
        cout<<"Please enter all subjects and grade of the student"<<'\n';
        for(int i=0;i<end->x;i++){
            cin>>end->cour[i].cname>>end->cour[i].grade;
            end->allgrade+=end->cour[i].grade;
        }
        end->ave=end->allgrade/end->x;
        a++;
        return a;
    }
    else {
        ssystem *end;
        end=L;
        while(end->next!=NULL){
            end=end->next;
        }
        ssystem *node;
        node=(ssystem *)malloc(sizeof(ssystem));
        end->next=node;
        node->next=NULL;
        cout<<"Please input class"<<'\n';
        cin>>node->cla;      
        cout<<"Please input ID"<<'\n';
        cin>>node->ID;
        cout<<"Please input name"<<'\n';
        cin>>node->name;
        cout<<"Please input the num of course"<<'\n';
        cin>>node->x;
        cout<<"Please enter all subjects and grade of the student"<<'\n';
        for(int i=0;i<node->x;i++){
            cin>>node->cour[i].cname>>node->cour[i].grade;
            node->allgrade+=node->cour[i].grade;
        }
        node->ave=node->allgrade/node->x;
        a++;
        return a;
    }

}
int dt(ssystem *L,int a){
    char na[10];
    int k=0;
    ssystem *p,*q;
    p=L;
    q=L->next;
    cout<<"Please enter the name of the student you want to delete"<<'\n';
    cin>>na;
    while(q!=NULL){
        if(strcmp(na,q->name)==0){
            a--;
            k++;
            p->next=q->next;
            q=q->next;
        }
        else {
        p=p->next;
        q=q->next;
        }
    }
    if(k==0){
    cout<<"Didn't find the student! Please re-enter!"<<'\n';
    return a;
    }
    else {cout<<"We have delet"<<na<<'\n';
    return a;
    }


}
void display(ssystem *L){
     ssystem *p;
     p=L->next;
     int cla,y=0;
     cout<<" Please input class"<<'\n';
     cin>>cla;
     cout<<" the following are names,ID,academic records,total scores and average scores."<<'\n';
     while(p!=NULL){
         if(cla==p->cla){
             y++;
        cout<<p->name<<' '<<p->ID<<' ';
        for(int i=0;i<p->x;i++){
            cout<<p->cour[i].cname<<':';
            printf("%.1f ",p->cour[i].grade);
        }
        printf("total scores:%.1f average scores:%.1f\n",p->allgrade,p->ave);
         }
        //cout<<p->allgrade<<' '<<p->ave<<'\n';
        p=p->next;
     }
     if(y==0)cout<<"Not found class,please return";
     return;
}

 int main(){
    setlocale(0,"zh-Hans");
    int sign,cho,n=0;
    ssystem *h;
    h=(ssystem *)malloc(sizeof(ssystem));
    h->next=NULL;
    while(1){
    welcome(n);
    cin>>sign;
    if(sign==1)n=input(h,n);
    if(sign==2){
      n=dt(h,n);
    }
    if(sign==3){
        if(h->next==NULL){
            cout<<"There is no student information in the table. Please re-enter the instructions."<<'\n';
        }
        else display(h);
    }
    if(sign==4)return 0;
    printf ("Return please enter 1\n");
    scanf ("%d", &cho);
    pin:if (1 == cho)
        {
            continue;
        }
        else
        {
            printf ("Your input is error!please enter 1\n");
            scanf ("%d", &cho);
            goto pin;
        }
    }
    system("pause");
    return 0;
}
