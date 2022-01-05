// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	int Lives;
public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	FString InitHideWord() ;
	void RestartGame();
	void HelloIntor() const;
	void GameOver();


	static bool HasRepeatLetter(const FString& Str);

	bool IsComplete;

	TArray<FString> WordList;
	// Your declarations go below!
private:
	FString HiddenWord;
};
