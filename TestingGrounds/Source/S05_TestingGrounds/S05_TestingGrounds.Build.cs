// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class S05_TestingGrounds : ModuleRules
{
	public S05_TestingGrounds(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        //add "AIModule", "GameplayTasks"

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "GameplayTasks", "HeadMountedDisplay" });
	}
}
