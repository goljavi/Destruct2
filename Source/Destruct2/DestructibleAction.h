// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "ConstructorHelpers.h"
#include "DestructibleComponent.h"
#include "Components/ActorComponent.h"
#include "DestructibleAction.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DESTRUCT2_API UDestructibleAction : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDestructibleAction();

	UPROPERTY(VisibleAnywhere)
		UMaterialInterface* myMat;

	UDestructibleComponent* destructibleComponent;

	void ChangeMat();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
