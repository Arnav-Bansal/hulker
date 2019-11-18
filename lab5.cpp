#include<iostream>
#include<math.h>

using namespace std;

struct hnode
{
    float x;
    float t;
    int r1, r2;
};
typedef struct hnode hnode;

    hnode meet[10000];
    int max;
    int siz00=-1;

    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    int heapify(int i)
    {
        if (left(i)>siz00){return i;}
       int l=left(i);
       int r=right(i);
       if(left(i)==siz00){swap(meet[i],meet[l]); return l;}
       if(meet[l].t<meet[r].t){swap (meet[i],meet[l]); return heapify(l);}
       else {swap (meet[i],meet[r]); return heapify(r);}
    }
    int insert0(float x, float t0, float r01, float r02)
    {
        siz00++;
        meet[siz00].x=x;
        meet[siz00].t=t0;
        meet[siz00].r1=r01;
        meet[siz00].r2=r02;
        int i=siz00;
        while(meet[parent(i)].t > meet[i].t && i!=0)
        {
            swap(meet[parent(i)],meet[i]);
            i=parent(i);
        }
        return i;
    }
    void delete0(int i)
    {
        meet[i]=meet[siz00];
        siz00--;
        //find in order predecessor from x tree and in order successor, using the index i modify the values of meet[i], and then satisfy the heap property.
        heapify(i);
    }
struct edgenode
{
    edgenode* next;
    int colour;
    int dest;
    float weight;
    edgenode()
    {
        next=NULL;
    }
};
typedef struct edgenode edgenode;

edgenode* newnode(int n, float weight0)
{
    edgenode* temp= new edgenode;
    temp->weight=weight0;
    temp->dest=n;
    temp->next=NULL;
    return temp;
}

void addedge(edgenode* e[], int n1, int n2, float weight, int c) 
{ 
    edgenode* temp = newnode(n2, weight); 
    temp->next = e[n1];
    temp->colour=c; 
    e[n1]=temp; 
    temp = newnode(n1, weight); 
    temp->next = e[n2];
    temp->colour=c; 
    e[n2] = temp; 
}

int main()
{
    float g;
    int k;
    cin>>g>>k;
    int n,m;
    cin>>n>>m;
    edgenode* a[n+1];
    int n1, n2, c;
    float p;
    while(m--)
    {
        cin>>n1>>n2>>p>>c;
        addedge(a,n1,n2,-1*log10(p),c);
    }

}









