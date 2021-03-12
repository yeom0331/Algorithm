#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct Planet {
    char name[10];
    double distance;
    double relativeMass;
};

struct TreeNodeHdr {
    struct Planet *planetPtr;
    struct TreeNodeHdr *left, *right;
};

struct TreeNodeHdr *head = NULL;
FILE *input, *output;

int search(struct TreeNodeHdr *tree, struct Planet *p) {
    if(tree == NULL) {
        return 0;
    }
    else {
        if(tree->planetPtr->distance == p->distance) return 1;
        search(tree->left,p);
        search(tree->right,p);
    }
}

struct TreeNodeHdr* createTreeNode(struct TreeNodeHdr *t, struct Planet *p) {
    struct TreeNodeHdr *newnode, *tree;
    if(search(t,p)==1) {
        printf("exist\n");
        return t;
    }
    else {
        newnode = (struct TreeNodeHdr *)malloc(sizeof(struct TreeNodeHdr));
        newnode->left = newnode->right = NULL;
        newnode->planetPtr = p;   
    }
    if(t==NULL) {
        t = newnode;
    }
    else {
        tree = t;
        while(tree) {
            if(p->distance < tree->planetPtr->distance) {
                if(tree->left == NULL) {
                    tree->left = newnode;
                    break;
                }
                else {
                    tree = tree->left;
                }
            }
            else {
                if(tree->right == NULL) {
                    tree->right = newnode;
                    break;
                }
                else {
                    tree = tree->right;
                }
            }
        }
    }
    return t;
}


void in_order(struct TreeNodeHdr *t) {
    if(t==NULL) {
        return;
    }
    else {
        in_order(t->left);
        printf("\n %s \t -> \t %lf \t %lf\n", t->planetPtr->name, t->planetPtr->distance, t->planetPtr->relativeMass);
        in_order(t->right);
    }
}

void reverse(struct TreeNodeHdr *t) {
    if(t==NULL) {
        return;
    }
    else {
        in_order(t->right);
        printf("\n %s \t -> \t %lf \t %lf\n", t->planetPtr->name, t->planetPtr->distance, t->planetPtr->relativeMass);
        in_order(t->left);
    }
}

int main() {
    struct Planet *p;
    int choice;
    input = fopen("solar_planet.txt", "r");
    if(input == NULL) {
        cout << "error input\n";
        return -1;
    }
    do {
        printf("1. Enter Planet\n");
        printf("2. Show Planets\n");
        printf("3. Show Planets In Reverse\n"); 
        printf("4. Exit\n");
        printf(" Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            p = (struct Planet *)malloc(sizeof(struct Planet));
            printf("enter name, distance\n");
            fscanf(input, "%s", p->name);
            fscanf(input, "%lf", &p->distance);
            fscanf(input, "%lf", &p->relativeMass);
            head = createTreeNode(head, p);
            break;
        case 2: 
            printf("\n The Planet List Is: \n");
            in_order(head);
            getch();
            break;
        case 3: 
            printf("\n The Planet List Is: \n");
            reverse(head);
            getch();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }while(1);
    
    printf("list : ");
    in_order(head);
    
    free(p);
    fclose(input);
}
