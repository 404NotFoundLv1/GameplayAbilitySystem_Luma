// Copyright (c) 2024, Nardoritos. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class LumaEditorTarget : TargetRules
{
    public LumaEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V6;

        ExtraModuleNames.AddRange(new string[] { "Aura" });
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
    }
}
