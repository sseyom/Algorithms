'''
Created on Sep 18, 2017

@author: seyounghan
''' 

from __future__ import print_function
import random;

def getKnapsack(intNum, intLimit, price, weight):
	
	K = [[0]*(intLimit+1) for row in range(intNum+1)];
	
	for i in range(1, intNum+1):
		for w in range(1, intLimit+1):
			if(weight[i]>w):
				K[i][w] = K[i-1][w];
			else:
				intSelectedValue = K[i-1][w-weight[i]] + price[i];
				intUnselectedValue = K[i-1][w];
				K[i][w] = (intSelectedValue > intUnselectedValue) and intSelectedValue or intUnselectedValue;
	
	return K[intNum][intLimit];

def printArray(max_size, ary):
	for i in range(max_size):
		if(i!=max_size-1):
			print(ary[i], end=" ");
		else:
			print(ary[i], "\n");

def doMain():
	intNumOfItems = 4; intNumOfWeights = 4;
	
	aryPrice = [0 for p in range(intNumOfItems)];
	aryWeight = [0 for w in range(intNumOfWeights)];
	
	for i in range(intNumOfItems):
		aryPrice[i] = random.randint(1,10);
		aryWeight[i] = random.randint(1,10);
		
	print("Price :");
	printArray(intNumOfItems, aryPrice);
	
	print("Weight :");
	printArray(intNumOfWeights, aryWeight);
	
	intLimitWeightOfBag = 20;
	
	print("Limit :");
	print(intLimitWeightOfBag, "\n");
	
	intMaxValue = getKnapsack(intNumOfItems-1, intLimitWeightOfBag, aryPrice, aryWeight);
	
	print("Max Price : ", intMaxValue, "\n\n");	

if __name__ == '__main__':
	doMain()
	pass


