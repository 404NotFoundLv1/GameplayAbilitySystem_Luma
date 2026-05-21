// Copyright (c) 2024, Nardoritos. All rights reserved.


#include "UI/Widget/Subwidget/SettingRowWidget_AAQuality.h"

#include "Luma/AuraLogChannels.h"
#include "Components/TextBlock.h"

void USettingRowWidget_AAQuality::ReceiveInitialValue(int32 InValue)
{
	CurrentSelectedValueIndex = AvailableAAQualityOptions.Find(InValue);
	SetAppliedValue(CurrentSelectedValueIndex);

	SetCurrentAAQuality(InValue);
	AvailableOptions = AvailableAAQualityOptions.Num();

	UE_LOG(LogAura, Log, TEXT("%s has %i options available, with the initial option selected being %i"), *GetClass()->GetName(), AvailableOptions, CurrentSelectedValueIndex)
}


#define LOCTEXT_NAMESPACE "UMG"

void USettingRowWidget_AAQuality::UpdateSettingValue(bool bOverrideValue)
{
	Super::UpdateSettingValue(bOverrideValue);

	if (bOverrideValue)
	{
		CurrentAAQuality = AvailableAAQualityOptions[CurrentSelectedValueIndex];
	}
	FText AAQualityText;

	switch (CurrentAAQuality)
	{
	case -1:
		AAQualityText = FText(LOCTEXT("Settings.AAQuality.Disabled", "关闭"));
		break;
	case 0:
		AAQualityText = FText(LOCTEXT("Settings.AAQuality.Low", "低"));
		break;
	case 1:
		AAQualityText = FText(LOCTEXT("Settings.AAQuality.Medium", "中"));
		break;
	case 2:
		AAQualityText = FText(LOCTEXT("Settings.AAQuality.High", "高"));
		break;
	case 3:
		AAQualityText = FText(LOCTEXT("Settings.AAQuality.Epic", "极高"));
		break;
	case 4:
		AAQualityText = FText(LOCTEXT("Settings.AAQuality.Cinematic", "电影级"));
		break;
	default:
		AAQualityText = FText::FromString("未定义");
		break;
	}
	Text_SettingValue->SetText(AAQualityText);
}

#undef LOCTEXT_NAMESPACE



void USettingRowWidget_AAQuality::NextValue()
{
	if (CurrentSelectedValueIndex >= AvailableOptions - 1)
	{
		CurrentSelectedValueIndex = 1;
	}
	else
	{
		CurrentSelectedValueIndex++;
	}
	UpdateSettingValue();

	int32 NextAAQuality = AvailableAAQualityOptions[CurrentSelectedValueIndex];
	SetCurrentAAQuality(NextAAQuality);
}

void USettingRowWidget_AAQuality::PreviousValue()
{
	if (CurrentSelectedValueIndex <= 1)
	{
		CurrentSelectedValueIndex = AvailableOptions - 1;
	}
	else
	{
		CurrentSelectedValueIndex--;
	}
	UpdateSettingValue();

	int32 NextAAQuality = AvailableAAQualityOptions[CurrentSelectedValueIndex];
	SetCurrentAAQuality(NextAAQuality);
}

void USettingRowWidget_AAQuality::SetCurrentAAQuality(int32 InAAQuality)
{
	CurrentAAQuality = InAAQuality;
	UpdateSettingValue();

	OnValueChanged.Broadcast(SettingInfo.SettingType, CurrentAppliedValueIndex != CurrentSelectedValueIndex);
}

