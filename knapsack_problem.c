//
//  main.c
//  0-1 knapsack problem
//
//  Created by 한세영 on 18/09/2017.
//  Copyright © 2017 한세영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int K[5][21]; //num of items, limit weight of bag

int getKnapsack(int intNum, int intLimit, int price[], int weight[]){
    // Initializing array
    for(int i=0;i<=intNum;i++){
        K[i][0] = 0;
    }
    for(int w=0;w<=intLimit;w++){
        K[0][w] = 0;
    }
    
    // Checking maximum value
    for(int i=1;i<=intNum;i++){
        for(int w=1;w<=intLimit;w++){
            
            // When the weight of item i is heavier than the limit of weight left
            if(weight[i]>w)
                K[i][w] = K[i-1][w];
            
            else{
                // Value When making decision to put item i in the bag
                int intSelectedValue = K[i-1][w-weight[i]] + price[i];
                
                // Value When making decision not to put item i in the bag
                int intUnselectedValue = K[i-1][w];
                
                // Select the maximum value
                K[i][w] = intSelectedValue > intUnselectedValue ? intSelectedValue : intUnselectedValue;
            }
        }
    }
    return K[intNum][intLimit];
}

void printArray(int max_size, int ary[max_size])
{
    for(int i=0;i<max_size;i++){
        printf("%d ", ary[i]);
        if(i==max_size-1)
            printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
    int intNumOfItems = 4, intNumOfWeights = 4;
    
    int aryPrice[intNumOfItems];
    int aryWeight[intNumOfWeights];
    
    srand(time(NULL));
    
    for(int i=0; i<intNumOfItems; i++){
        aryPrice[i] = (rand()%10) + 1;
        aryWeight[i] = (rand()%10) + 1;
    }
    
    printf("Prices :\n");
    printArray(intNumOfItems, aryPrice);
    
    printf("Weights :\n");
    printArray(intNumOfWeights, aryWeight);
    
    // Limit of knapsack is 20 kg
    int intLimitWeightOfBag = 20;
    
    printf("Limit :\n%d\n", intLimitWeightOfBag);

    int intMaxValue = getKnapsack(intNumOfItems-1, intLimitWeightOfBag, aryPrice, aryWeight);
    
    printf("Max Price: %d\n\n", intMaxValue);
    
    return 0;
}




