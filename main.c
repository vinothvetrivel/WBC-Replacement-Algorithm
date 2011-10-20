/* 
 * File:   main.c
 * Author: vels
 *
 * Created on October 20, 2011, 11:09 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_of_clusters;

struct page{
    char pname[20];
    struct page *nextpage;
    int isclean;
};

struct cluster{
    int  num_of_pages;
    char cname[20];
    struct cluster *nextcluster;
    struct page *pagelink;
}*cnode;

void create_page(struct cluster * clus){
    int n=0;
    struct page *pnode;
    printf("Enter the number of page want to insert:");
    scanf("%d",&clus->num_of_pages);
    n=clus->num_of_pages;
    clus->pagelink=pnode=calloc(clus->num_of_pages,sizeof(struct page));
    while(n>0){
        printf("Enter the page name & dirty/clean:");
        scanf("%s\t%d",(pnode)->pname,&(pnode)->isclean);
        (pnode)->nextpage=(pnode+1);
        n--;
        pnode++;

    }
}

void create_cluster(){
    int n,i=0;
    printf("\nEnter the number of cluster want to create: ");
    scanf("%d",&num_of_clusters);
    n=num_of_clusters;
    cnode=calloc(n,sizeof(struct cluster));
    while(n>0)
    {  
        printf("\nEnter the cluster name:");
        scanf("%s",(cnode+i)->cname);
        create_page(cnode+i);
        (cnode+i)->nextcluster=(cnode+i)+1;
        n--;
        i++;
    }
}

/*                      
 * 
 */
void display_pages(struct cluster * cnode){
    int i=0;
    struct page *pnode = cnode->pagelink;
    for(i=0;i< cnode->num_of_pages;i++)
    {
        printf("\t\t%s\n",(pnode+i)-> pname);
    }
}
void display_clusters(){
    int i=0;
    printf("cluster_name:");
    for(i=0;i<num_of_clusters;i++){
        printf("%s\n",(cnode+i)->cname);                                                                                             
        display_pages((cnode+i));
    }
}

void free_pages(struct cluster *cnode){
    free(cnode->pagelink);    
}
void free_clusters()
{
    int i=0;
    for(i=0;i<num_of_clusters;i++){
        free_pages(cnode+i);
       
    }
    free(cnode);
}
int large_cluster(struct cluster *cnode){
    int i=0,LCS=0;
    for(i=0;i<num_of_clusters;i++){
        if((cnode+i)->num_of_pages>=2)
        {
            LCS+=1;
        }
    }
    return(LCS);
}


int main(int argc, char** argv) {
    int LCS_threshold=0,n=0,i=0,j=0;
    char clustername[10];
    create_cluster();
    display_clusters();
    printf("NC_LCS=%d",((int)large_cluster(cnode)));
    printf("\nEnter the LCS threshold:");
    scanf("%d",&LCS_threshold);
    printf("\nEnter the cluster name:");
    scanf("%s",clustername);
    n=num_of_clusters;
    for(i=0;i<n;i++)
    {
       if((strcmp((cnode+i)->cname,clustername)==0))
       {
           for(j=0;j<((cnode+i)->num_of_pages);j++)
           {
               
               printf("\n%s",(((cnode+i)->pagelink)+j)->pname);
           }
       }
        
    }
  
    free_clusters();


    return (EXIT_SUCCESS);
}




