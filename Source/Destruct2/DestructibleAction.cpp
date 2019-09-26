// Fill out your copyright notice in the Description page of Project Settings.

#include "DestructibleAction.h"


// Sets default values for this component's properties
UDestructibleAction::UDestructibleAction()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	auto objectToLoad = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/Resources/TranslucentMat.TranslucentMat'"));
	if (objectToLoad.Object) {
		myMat = objectToLoad.Object;
	}
}


// Called when the game starts
void UDestructibleAction::BeginPlay()
{
	Super::BeginPlay();
	UDestructibleComponent* destComp = GetOwner()->FindComponentByClass<UDestructibleComponent>();
	if (destComp) destructibleComponent = destComp;
}


// Called every frame
void UDestructibleAction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDestructibleAction::ChangeMat() {
	if(destructibleComponent) destructibleComponent->SetMaterial(0, myMat);
}
