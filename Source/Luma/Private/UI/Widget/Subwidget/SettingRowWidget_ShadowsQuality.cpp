// Copyright (c) 2024, Nardoritos. All rights reserved.


#include "UI/Widget/Subwidget/SettingRowWidget_ShadowsQuality.h"

#include "Luma/AuraLogChannels.h"
#include "Components/TextBlock.h"

void USettingRowWidget_ShadowsQuality::ReceiveInitialValue(int32 InValue)
{
	CurrentSelectedValueIndex = AvailableShadowsQuality.Find(InValue);
	SetAppliedValue(CurrentSelectedValueIndex);

	SetCurrentShadowsQuality(InValue);
	AvailableOptions = AvailableShadowsQuality.Num();

	UE_LOG(LogAura, Log, TEXT("SettingRowWidget_ShadowsQuality has %i options available, with the initial option selected being %i"), AvailableOptions, CurrentSelectedValueIndex)

}

#define LOCTEXT_NAMESPACE "UMG"

void USettingRowWidget_ShadowsQuality::UpdateSettingValue(bool bOverrideValue)
{
	Super::UpdateSettingValue(bOverrideValue);

	if (bOverrideValue)
	{
		CurrentShadowsQuality = AvailableShadowsQuality[CurrentSelectedValueIndex];
	}
	FText ShadowsQualityText;

	switch (CurrentShadowsQuality)
	{
	case 0:
		ShadowsQualityText = FText(LOCTEXT("Settings.ShadowsQuality.Low", "低"));
		break;
	case 1:
		ShadowsQualityText = FText(LOCTEXT("Settings.ShadowsQuality.Medium", "中"));
		break;
	case 2:
		ShadowsQualityText = FText(LOCTEXT("Settings.ShadowsQuality.High", "高"));
		break;
	case 3:
		ShadowsQualityText = FText(LOCTEXT("Settings.ShadowsQuality.Epic", "极高"));
		break;
	case 4:
		ShadowsQualityText = FText(LOCTEXT("Settings.ShadowsQuality.Cinematic", "电影级"));
		break;
	default:
		ShadowsQualityText = FText::FromString("未定义");
		break;
	}
	Text_SettingValue->SetText(ShadowsQualityText);
}

#undef LOCTEXT_NAMESPACE



void USettingRowWidget_ShadowsQuality::NextValue()
{
	Super::NextValue();

	int32 NextShadowsQuality = AvailableShadowsQuality[CurrentSelectedValueIndex];
	SetCurrentShadowsQuality(NextShadowsQuality);
}

void USettingRowWidget_ShadowsQuality::PreviousValue()
{
	Super::PreviousValue();

	int32 NextShadowsQuality = AvailableShadowsQuality[CurrentSelectedValueIndex];
	SetCurrentShadowsQuality(NextShadowsQuality);
}

void USettingRowWidget_ShadowsQuality::SetCurrentShadowsQuality(int32 InShadowsQuality)
{
	CurrentShadowsQuality = InShadowsQuality;
	UpdateSettingValue();

	OnValueChanged.Broadcast(SettingInfo.SettingType, CurrentAppliedValueIndex != CurrentSelectedValueIndex);
}

