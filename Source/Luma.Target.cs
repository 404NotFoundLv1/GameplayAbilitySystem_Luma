// Copyright (c) 2024, Nardoritos. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class LumaTarget : TargetRules
{
    public LumaTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V6;

        ExtraModuleNames.AddRange(new string[] { "Aura" });
    }
}
