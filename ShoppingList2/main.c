//  ShoppingList with internal functions

#include <stdio.h>

struct articleType{
    int number;
    double price;
    char designation[30];
};

void inputStructure(struct articleType *typePointer,int i){
    printf("Article %i,number: ",i+1);
    scanf("%i",&typePointer->number);
    printf("Article %i,price: ",i+1);
    scanf("%lf",&typePointer->price);
    printf("Article %i,designation:",i+1);
    scanf("%s",typePointer->designation);
}

void outputStructure(struct articleType art){
    printf("%i %.2lf %s \n",art.number,art.price,art.designation);
}

void inputStructureArray(struct articleType *artArray,int content){ // internal function
    int i;
    for(i=0;i<content;i++){
        inputStructure(&artArray[i],i);
    }
}

void outputStructureArray(struct articleType *artArray,int content){ // internal function
    int i;
    for(i=0;i<content;i++){
        outputStructure(artArray[i]);
    }
}

double sumInvoice(struct articleType *artArray,int content){
    int i;
    double sum = 0.0;
    for(i=0;i<content;i++)
        sum = sum + artArray[i].number*artArray[i].price;
        return sum;
    
}


int main(){
    
    struct articleType articleArray[3];
    
    inputStructureArray(articleArray,3);
    outputStructureArray(articleArray,3);
    printf("Summe: %.2lf Euro \n",sumInvoice(articleArray,3));
    
    return 0;
}

