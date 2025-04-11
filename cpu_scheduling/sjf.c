#include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void main(){
    double awt=0,atat=0;
    int num;
    printf("\nEnter the number of processes:\n");
    scanf("%d",&num);
    struct process p[num];
    for(int i=0;i<num;i++){
        printf("\nEnter id,at and bt of process %d\n",i+1);
        scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
    }
    for (int i=0;i<num;i++){
        for(int j=0;j<num-1-i;j++){
            if(p[j].at>p[j+1].at){
                struct process temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            else if(p[j].at==p[j+1].at){
                if(p[j].id>p[j+1].id){
                     struct process temp = p[j];
                     p[j]=p[j+1];
                     p[j+1]=temp;
                }
            }
    }
    }
    int time=0,count=0,over=0;
    while(over<num){
        count=0;
        for(int i=over;i<num;i++){
            if(p[i].at<=time){
                count++;
            }
        }
        if(count>1){
            for(int i=over;i<over+count;i++){
                for(int j=over;j<over+count-1;j++){
                    if(p[j].bt>p[j+1].bt){
                        struct process temp = p[j];
                        p[j]=p[j+1];
                        p[j+1]=temp;
                    }
                }
            }
        }
        time = time+p[over].bt;
        p[over].ct=time;
        p[over].tat=p[over].ct-p[over].at;
        p[over].wt=p[over].tat-p[over].bt;
        over++;
    }
    for(int i=0;i<num;i++){
        atat=atat+p[i].tat;
        awt=awt+p[i].wt;
    }
    atat=atat/num;
    awt=awt/num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num-1-i;j++){
            if(p[j].id>p[j+1].id){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("\nid\tat\tbt\tct\ttat\twt\n");
    for(int i=0;i<num;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("\natat:%f",atat);
    printf("\nawt:%f",awt);
}