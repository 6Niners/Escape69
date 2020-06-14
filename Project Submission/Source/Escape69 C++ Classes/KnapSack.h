// All copyrights reserved. 6Niners organization.

#pragma once
#include<vector>
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "KnapSack.generated.h"
class Item {
public:
	int price, weight;
	
	Item() {
		price = 0;
		weight = 0;
	}
	Item(int Price, int Weight) {
		price = Price;
		weight = Weight;

	}
	bool operator==(const Item& rhs) const { return (this->price == rhs.price && this->weight == rhs.weight); }
};
class knapsack {
private:
    int KnapsackMaxWeight = 0;
    //vector for all items that a person can put in the knapsack
    std::vector<Item> AllItems ;
    //vector for the items that will make him win
    std::vector<Item> WinningItems;
public:
    //setters and getters
    void SetKnapsackMaxWeight(int Max) { KnapsackMaxWeight = Max; }
    int GetKnapsackMaxWeight() { return KnapsackMaxWeight; }
    std::vector<Item> GetAllItems() { return AllItems; }
    //constructor
    knapsack() {
        KnapsackMaxWeight = 0;
    }
    knapsack(int W) {
        KnapsackMaxWeight = W;
    }
    //insert item in the AllItems vector
    void InsertItem(Item tmp) {
        if (!(tmp.price == 0 || tmp.weight == 0)) { AllItems.push_back(tmp);}
        
           
    }
    // A utility function that returns maximum of two integers  
    int max(int a, int b) { return (a > b) ? a : b; }
    // Returns the maximum value that can be put in a knapsack of capacity (KnapsackMaxWeight)
    int knapSackMaxValue()
    {
        int i, w;
        std::vector<std::vector<int>> K(AllItems.size() + 1, std::vector<int>(KnapsackMaxWeight + 1, 0));
        // Build table K[][] in bottom up manner 
        for (i = 0; i <= AllItems.size(); i++)
        {
            for (w = 0; w <= KnapsackMaxWeight; w++)
            {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (AllItems[i - 1].weight <= w)
                    K[i][w] = max(AllItems[i - 1].price + K[i - 1][w - AllItems[i - 1].weight], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }
        // stores the result of Knapsack 
        int res;
        res = K[AllItems.size()][KnapsackMaxWeight];

        w = KnapsackMaxWeight;
        for (i = AllItems.size(); i > 0 && res > 0; i--) {
            if (res == K[i - 1][w])
                continue;
            else {
                // This item is included.
                WinningItems.push_back(AllItems[i - 1]);
                // Since this weight is included its  
                // value is deducted 
                res = res - AllItems[i - 1].price;
                w = w - AllItems[i - 1].weight;
            }
        }
        return K[AllItems.size()][KnapsackMaxWeight];
    }
    int winningWeight() {
        knapSackMaxValue();
        int sum = 0;
        for (int i = 0; i < WinningItems.size(); i++) { sum = sum + WinningItems[i].weight; }
        return (sum);
    }
    void insert_items(std::vector<Item> temp) {
        for (int i = 0;i < temp.size();i++) { InsertItem(temp[i]); }
    }
    void clear() {
        AllItems.clear();
        WinningItems.clear();
    }
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorRequest1);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UKnapSack : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKnapSack();
    
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintAssignable)
		FDoorRequest1 OpenDoorRequest1;

	UPROPERTY(BlueprintAssignable)
		FDoorRequest1 CloseDoorRequest1;



private:
    
	void OpenDoor();
	void CloseDoor();
	float ReturnTotalMassOnTrigger();

	AActor* Owner = nullptr;
    UPROPERTY(EditAnywhere)
        int MaxWeight = 50;

    UPROPERTY(EditAnywhere)
        int item_price_1 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_1 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_2 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_2 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_3 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_3 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_4 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_4 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_5 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_5 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_6 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_6 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_7 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_7 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_8 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_8 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_9 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_9 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_10 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_10 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_11 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_11 = 0;
    UPROPERTY(EditAnywhere)
        int item_price_12 = 0;
    UPROPERTY(EditAnywhere)
        int item_weight_12 = 0;

    
    int Triggerprice;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* TriggerVolume = nullptr;

		
};
