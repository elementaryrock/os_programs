#include <stdio.h>
#include <stdlib.h>

struct process{
  int id;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
};

void main(){
  double atat=0,awt=0;
  int num;
  printf("\nEnter the no of processes:\n");
  scanf("%d",&num);
  struct process p[num];
  for(int i=0;i<num;i++)
  {
    printf("\nEnter id,at and bt of process %d\n",i+1);
    scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
  }
  for(int i=0;i<num;i++)
  {
    for(int j=0;j<num-1-i;j++)
    {
      if(p[j].at>p[j+1].at)
      {
        struct process temp = p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
      else if(p[j].at==p[j+1].at)
        {
          if(p[j].id>p[j+1].id)
          {
            struct process temp = p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
          }
        }
    }
  }
  p[0].ct=p[0].at+p[0].bt;
  p[0].tat=p[0].ct-p[0].at;
  p[0].wt=p[0].tat-p[0].bt;
  for(int i=1;i<num;i++)
  {
    p[i].ct=p[i-1].ct+p[i].bt;
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;	
  }
  for(int i=0;i<num;i++)
  {
    atat=atat+p[i].tat;
    awt=awt+p[i].wt;
  }
atat=atat/num;
awt=awt/num;
  for(int i=0;i<num;i++)
  {
    for(int j=0;j<num-i-1;j++)
    {
      if(p[j].id>p[j+1].id)
      {
        struct process temp = p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
    }
  }
  printf("\nid\tat\tbt\tct\ttat\twt\n");
  for(int i=0;i<num;i++)
  {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
  }
  printf("\natat:%f",atat);
  printf("\nawt:%f",awt);
}