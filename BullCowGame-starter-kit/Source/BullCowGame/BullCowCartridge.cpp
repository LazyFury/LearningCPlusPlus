// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    const FString filePath = FPaths::ProjectContentDir() / TEXT("HiddenWordList/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArrayWithPredicate(WordList, *filePath, [](const FString& word) {
        return word.Len() >= 4 && word.Len() <= 10 && HasRepeatLetter(word);
        });


    srand(time(nullptr));
    InitHideWord();
    HelloIntor();
    Lives = 5;

}

bool UBullCowCartridge::HasRepeatLetter(const FString& Str)
{
    for (int i = 0;i< Str.Len();i++)
    {
        for (int j = i+1;j<Str.Len();j++)
        {
            if (Str[i]==Str[j])
            {
                return false;
            }
        }
    }
    return true;
}



void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(1, 3, FColor::Blue, Input);
    }

    // check complete
    if (IsComplete) {
        // restart game
        if (Input == TEXT("r")) {
            RestartGame();
            IsComplete = false;
        }
        return;
    }
    if (Input.IsEmpty())
    {
        PrintLine(TEXT("the word is not emptu"));
        return;
    }

    if (!HasRepeatLetter(Input)) {
        PrintLine(TEXT("there is no repeat letter,try again"));
        return;
    }

    // check lives
    if (Lives >= 1) {

        // get right word count
        int count = 0; //相同的位置 相同的字母数量
        int otherCount = 0; //在不同的位置  相同的字母数量
        for (int i = 0; i < std::min(Input.Len(), HiddenWord.Len()); i++) {
            if (std::tolower(Input[i]) == std::tolower(HiddenWord[i])) {
                count++;
                continue;
            }

            for (int j = 0;j<HiddenWord.Len();j++)
            {
                if (std::tolower(Input[i]) == std::tolower(HiddenWord[j])) {
                    otherCount++;
                    break;
                }
            }
        }

        // is right
        if (count == HiddenWord.Len()) {
            PrintLine(TEXT("You are Won!"));
            PrintLine(TEXT("Press 'r' to restart!"));
            IsComplete = true;
        }
        // last lives
        else if (Lives == 1) {
            Lives--;
            GameOver();
        }
        // try again
        else {
            PrintLine(FString::Printf(TEXT("Has %d correct word in same location \nHas %d correct word in diffient location.\nTry Again"), count,otherCount));
            PrintLine(TEXT("The hidden word is: %s"),*HiddenWord);
            Lives--;
        }
    }
}


FString UBullCowCartridge::InitHideWord() 
{
    if (WordList.Num()<=0)
    {
        return "Hello";
    }
    int index = FMath::RandRange(0,WordList.Num()-1);
    HiddenWord = WordList[index];
    return HiddenWord;
}

void UBullCowCartridge::RestartGame()
{
    ClearScreen();
    InitHideWord();
    HelloIntor();
    Lives = 5;
}

void UBullCowCartridge::HelloIntor() const
{
    //继承自 Cartridge.cpp
    PrintLine("hello hi no");
}

void UBullCowCartridge::GameOver()
{
    PrintLine(TEXT("You Fail,Press 'r' to Restart"));
    IsComplete = true;
}

