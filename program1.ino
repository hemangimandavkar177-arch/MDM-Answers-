

1. Implement basic operations on arrays (insertion, deletion, search)


#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();
    int a[50], n, i, p, x, ch;

    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
        cin>>a[i];

    do
    {
        cout<<"\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n";
        cin>>ch;

        if(ch==1)
        {
            cout<<"Position and value: ";
            cin>>p>>x;
            if(n<50 && p>=1 && p<=n+1)
            {
                for(i=n;i>=p;i--)
                    a[i]=a[i-1];
                a[p-1]=x;
                n++;
            }
            else cout<<"Invalid\n";
        }
        else if(ch==2)
        {
            cout<<"Position: ";
            cin>>p;
            if(p>=1 && p<=n)
            {
                for(i=p-1;i<n-1;i++)
                    a[i]=a[i+1];
                n--;
            }
            else cout<<"Invalid\n";
        }
        else if(ch==3)
        {
            cout<<"Value: ";
            cin>>x;
            for(i=0;i<n && a[i]!=x;i++);
            if(i<n) cout<<"Found at position "<<i+1;
            else cout<<"Not found";
        }
        else if(ch==4)
        {
            for(i=0;i<n;i++)
                cout<<a[i]<<" ";
        }
    }while(ch!=5);

    getch();
}



2. Implement Stack and Queue using arrays and linked lists 


#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();
    int s[5],q[5],top=-1,f=0,r=-1,ch,x,i;

    do
    {
        cout<<"\n1.Push 2.Pop 3.Stack 4.Enqueue 5.Dequeue 6.Queue 7.Exit\n";
        cin>>ch;

        if(ch==1)
        {
            if(top==4) cout<<"Stack Full";
            else
            {
                cout<<"Value: ";
                cin>>x;
                s[++top]=x;
            }
        }
        else if(ch==2)
        {
            if(top==-1) cout<<"Stack Empty";
            else cout<<"Deleted: "<<s[top--];
        }
        else if(ch==3)
        {
            for(i=top;i>=0;i--) cout<<s[i]<<" ";
        }
        else if(ch==4)
        {
            if(r==4) cout<<"Queue Full";
            else
            {
                cout<<"Value: ";
                cin>>x;
                q[++r]=x;
            }
        }
        else if(ch==5)
        {
            if(f>r) cout<<"Queue Empty";
            else
            {
                cout<<"Deleted: "<<q[f++];
                if(f>r) { f=0; r=-1; }
            }
        }
        else if(ch==6)
        {
            for(i=f;i<=r;i++) cout<<q[i]<<" ";
        }
    }while(ch!=7);

    getch();
}



3. Implement Circular Queue and Priority Queue 

#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();
    int q[5],v[5],p[5],f=-1,r=-1;
    int n=0,ch,x,pr,i,j;

    do
    {
        cout<<"\n1.Circular Insert 2.Circular Delete 3.Show Circular";
        cout<<"\n4.Priority Insert 5.Priority Delete 6.Show Priority 7.Exit\n";
        cin>>ch;

        if(ch==1)
        {
            if((r+1)%5==f) cout<<"Full";
            else
            {
                cout<<"Value: ";
                cin>>x;
                if(f==-1) f=0;
                r=(r+1)%5;
                q[r]=x;
            }
        }
        else if(ch==2)
        {
            if(f==-1) cout<<"Empty";
            else
            {
                cout<<"Deleted: "<<q[f];
                if(f==r) f=r=-1;
                else f=(f+1)%5;
            }
        }
        else if(ch==3)
        {
            if(f!=-1)
            {
                i=f;
                while(1)
                {
                    cout<<q[i]<<" ";
                    if(i==r) break;
                    i=(i+1)%5;
                }
            }
            else cout<<"Empty";
        }
        else if(ch==4)
        {
            if(n==5) cout<<"Full";
            else
            {
                cout<<"Value and priority: ";
                cin>>x>>pr;
                i=n-1;
                while(i>=0 && p[i]>pr)
                {
                    v[i+1]=v[i];
                    p[i+1]=p[i];
                    i--;
                }
                v[i+1]=x;
                p[i+1]=pr;
                n++;
            }
        }
        else if(ch==5)
        {
            if(n==0) cout<<"Empty";
            else
            {
                cout<<"Deleted: "<<v[0];
                for(i=0;i<n-1;i++)
                {
                    v[i]=v[i+1];
                    p[i]=p[i+1];
                }
                n--;
            }
        }
        else if(ch==6)
        {
            for(i=0;i<n;i++) cout<<v[i]<<" ";
        }
    }while(ch!=7);

    getch();
}



4. Implement Singly, Doubly, and Circular Linked Lists 

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    node *next;
    node *prev;
};

node *s=NULL,*d=NULL,*c=NULL;

void singly(int x)
{
    node *t=new node,*p;
    t->data=x;
    t->next=NULL;
    if(s==NULL) s=t;
    else
    {
        p=s;
        while(p->next!=NULL) p=p->next;
        p->next=t;
    }
}

void doubly(int x)
{
    node *t=new node,*p;
    t->data=x;
    t->next=NULL;
    t->prev=NULL;
    if(d==NULL) d=t;
    else
    {
        p=d;
        while(p->next!=NULL) p=p->next;
        p->next=t;
        t->prev=p;
    }
}

void circular(int x)
{
    node *t=new node,*p;
    t->data=x;
    if(c==NULL)
    {
        c=t;
        t->next=c;
    }
    else
    {
        p=c;
        while(p->next!=c) p=p->next;
        p->next=t;
        t->next=c;
    }
}

void main()
{
    clrscr();
    int ch,x;
    node *p;

    do
    {
        cout<<"\n1.SLL Insert 2.SLL Display";
        cout<<"\n3.DLL Insert 4.DLL Display";
        cout<<"\n5.CLL Insert 6.CLL Display 7.Exit\n";
        cin>>ch;

        if(ch==1 || ch==3 || ch==5)
        {
            cout<<"Value: ";
            cin>>x;
            if(ch==1) singly(x);
            if(ch==3) doubly(x);
            if(ch==5) circular(x);
        }
        else if(ch==2)
        {
            p=s;
            while(p!=NULL)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
        }
        else if(ch==4)
        {
            p=d;
            while(p!=NULL)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
        }
        else if(ch==6)
        {
            if(c!=NULL)
            {
                p=c;
                do
                {
                    cout<<p->data<<" ";
                    p=p->next;
                }while(p!=c);
            }
        }
    }while(ch!=7);

    getch();
}



5. Implement Binary Search Tree (BST) with insertion, deletion, and traversal

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    node *left,*right;
};

node* insert(node *t,int x)
{
    if(t==NULL)
    {
        t=new node;
        t->data=x;
        t->left=t->right=NULL;
    }
    else if(x<t->data)
        t->left=insert(t->left,x);
    else if(x>t->data)
        t->right=insert(t->right,x);

    return t;
}

node* minimum(node *t)
{
    while(t->left!=NULL) t=t->left;
    return t;
}

node* del(node *t,int x)
{
    node *p;
    if(t==NULL) return t;

    if(x<t->data)
        t->left=del(t->left,x);
    else if(x>t->data)
        t->right=del(t->right,x);
    else
    {
        if(t->left==NULL)
        {
            p=t->right;
            delete t;
            return p;
        }
        else if(t->right==NULL)
        {
            p=t->left;
            delete t;
            return p;
        }

        p=minimum(t->right);
        t->data=p->data;
        t->right=del(t->right,p->data);
    }
    return t;
}

void inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}

void preorder(node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<" ";
    }
}

void main()
{
    clrscr();
    node *root=NULL;
    int ch,x;

    do
    {
        cout<<"\n1.Insert 2.Delete 3.Inorder";
        cout<<"\n4.Preorder 5.Postorder 6.Exit\n";
        cin>>ch;

        if(ch==1)
        {
            cout<<"Value: ";
            cin>>x;
            root=insert(root,x);
        }
        else if(ch==2)
        {
            cout<<"Value: ";
            cin>>x;
            root=del(root,x);
        }
        else if(ch==3) inorder(root);
        else if(ch==4) preorder(root);
        else if(ch==5) postorder(root);

    }while(ch!=6);

    getch();
}

