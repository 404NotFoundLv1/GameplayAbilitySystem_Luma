// Copyright (c) 2024, Nardoritos. All rights reserved.


#include "UI/Widget/Subwidget/SettingRowWidget_TexturesQuality.h"

#include "Luma/AuraLogChannels.h"
#include "Components/TextBlock.h"

void USettingRowWidget_TexturesQuality::ReceiveInitialValue(int32 InValue)
{
	CurrentSelectedValueIndex = AvailableTexturesQuality.Find(InValue);
	SetAppliedValue(CurrentSelectedValueIndex);

	SetCurrentTexturesQuality(InValue);
	AvailableOptions = AvailableTexturesQuality.Num();

	UE_LOG(LogAura, Log, TEXT("%s has %i options available, with the initial option selected being %i"), *GetClass()->GetName(), AvailableOptions, CurrentSelectedValueIndex)

}

#define LOCTEXT_NAMESPACE "UMG"

void USettingRowWidget_TexturesQuality::UpdateSettingValue(bool bOverrideValue)
{
	Super::UpdateSettingValue(bOverrideValue);

	if (bOverrideValue)
	{
		CurrentTexturesQuality = AvailableTexturesQuality[CurrentSelectedValueIndex];
	}
	FText TexturesQualityText;

	switch (CurrentTexturesQuality)
	{
	case 0:
		TexturesQualityText = FText(LOCTEXT("Settings.TexturesQuality.Low", "低"));
		break;
	case 1:
		TexturesQualityText = FText(LOCTEXT("Settings.TexturesQuality.Medium", "中"));
		break;
	case 2:
		TexturesQualityText = FText(LOCTEXT("Settings.TexturesQuality.High", "高"));
		break;
	case 3:
		TexturesQualityText = FText(LOCTEXT("Settings.TexturesQuality.Epic", "极高"));
		break;
	case 4:
		TexturesQualityText = FText(LOCTEXT("Settings.TexturesQuality.Cinematic", "电影级"));
		break;
	default:
		TexturesQualityText = FText::FromString("未定义");
		break;
	}
	Text_SettingValue->SetText(TexturesQualityText);
}

#undef LOCTEXT_NAMESPACE



void USettingRowWidget_TexturesQuality::NextValue()
{
	Super::NextValue();

	int32 NextTexturesQuality = AvailableTexturesQuality[CurrentSelectedValueIndex];
	SetCurrentTexturesQuality(NextTexturesQuality);
}

void USettingRowWidget_TexturesQuality::PreviousValue()
{
	Super::PreviousValue();

	int32 NextTexturesQuality = AvailableTexturesQuality[CurrentSelectedValueIndex];
	SetCurrentTexturesQuality(NextTexturesQuality);
}

void USettingRowWidget_TexturesQuality::SetCurrentTexturesQuality(int32 InTexturesQuality)
{
	CurrentTexturesQuality = InTexturesQuality;
	UpdateSettingValue();

	OnValueChanged.Broadcast(SettingInfo.SettingType, CurrentAppliedValueIndex != CurrentSelectedValueIndex);
}

