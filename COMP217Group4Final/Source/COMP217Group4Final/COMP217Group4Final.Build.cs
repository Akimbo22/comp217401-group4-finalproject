// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class COMP217Group4Final : ModuleRules
{
	public COMP217Group4Final(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"COMP217Group4Final",
			"COMP217Group4Final/Variant_Platforming",
			"COMP217Group4Final/Variant_Platforming/Animation",
			"COMP217Group4Final/Variant_Combat",
			"COMP217Group4Final/Variant_Combat/AI",
			"COMP217Group4Final/Variant_Combat/Animation",
			"COMP217Group4Final/Variant_Combat/Gameplay",
			"COMP217Group4Final/Variant_Combat/Interfaces",
			"COMP217Group4Final/Variant_Combat/UI",
			"COMP217Group4Final/Variant_SideScrolling",
			"COMP217Group4Final/Variant_SideScrolling/AI",
			"COMP217Group4Final/Variant_SideScrolling/Gameplay",
			"COMP217Group4Final/Variant_SideScrolling/Interfaces",
			"COMP217Group4Final/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
