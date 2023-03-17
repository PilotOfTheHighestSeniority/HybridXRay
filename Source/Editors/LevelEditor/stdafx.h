﻿#pragma once
#include "../XrECore/stdafx.h"
#include "../XrECore/Editor/device.h"
#include "../XrECore/Editor/UI_MainCommand.h"
#include "../XrECore/Editor/UI_ToolsCustom.h"
#include "../XrECore/Editor/ui_main.h"
#include "../XrECore/Editor/GeometryCollector.h"
#include "../XrECore/Editor/EditorPreferences.h"
#include "../XrECore/Editor/render.h"
#include "../XrECore/Editor/UIRenderForm.h"
#include "../XrECore/Editor/ELog.h"
#include "../XrECore/Editor/tlsprite.h"
#include "../XrECore/Editor/EditObject.h"
#include "../XrECore/Editor/EditMesh.h"
#include "../XrECore/Editor/D3DUtils.h"
#include "../XrEcore/Editor/PhysicsShellHolderEditorBase.h"
#include "../XrETools/ETools.h"
#include "../XrECore/Engine/Texture.h"
#include "../XrECore/Editor/Library.h"
#include "../XrECore/Editor/ImageManager.h"
#include "../XrECore/Editor/pick_defs.h"
#include "../XrECore/Editor/SoundManager.h"
#include "../XrECore/Editor/EDetailModel.h"
#include "../XrECore/Engine/Image.h"
#include "../XrECore/Engine/guid_generator.h"
#include "../XrECore/Editor/ExportSkeleton.h"
#include "../FreeMagic/MgcAppr3DPlaneFit.h"
#include "../FreeMagic/MgcEigen.h"
#include "../FreeMagic/MgcLinearSystem.h"
#include "../FreeMagic/MgcConvexHull2D.h"

#include "../XrCore/doug_lea_allocator.h"
#include "../XrCore/FixedMap.h"

#include "LightAnimLibrary.h"
#include "motion.h"
#include "envelope.h"
#include "communicate.h"
#include "xrHemisphere.h"
#include "LevelGameDef.h"
#include "SkeletonAnimated.h"
#include "ObjectAnimator.h"
#include "xr_efflensflare.h"
#include "du_box.h"
#include "Communicate.h"
#include "pure.h"
#include "xrLevel.h"
#include "XrEditorSceneInterface.h"
#include "std_classes.h"
#include "IGame_Persistent.h"
#include "XR_IOConsole.h"
#include "CustomHUD.h"
#include "CameraManager.h"
#include "IGame_Level.h"
#include "x_ray.h"
#include "..\..\XrCDB\xrCDB.h"
#include "..\..\XrCDB\ISpatial.h"
#include "..\..\XrRender\Public\ParticleCustom.h"
#include "..\..\XrRender\Private\DetailManager.h"
#include "..\..\XrRender\Private\ParticleEffect.h"
#include "..\..\XrRender\Private\ParticleEffectDef.h"
#include "..\..\XrRender\Private\ParticleGroup.h"
#include "EngineAPI.h"
#include "cl_intersect.h"

#include "../../xrServerEntities/xrMessages.h"

#ifndef _DEBUG
#define USE_ARENA_ALLOCATOR
#endif

#include "AI/game_graph_builder.h"
#include "AI/level_graph_editor.h"

#include "Engine/XRayEditor.h"
#include "Engine/XrGameManager.h"

#include "UI/UITopBarForm.h"
#include "UI/UIMainMenuForm.h"
#include "UI/UILeftBarForm.h"
#include "UI/UILPropertiesFrom.h"
#include "UI/UIMainForm.h"
#include "UI/Tools/UIToolCustom.h"
#include "UI/UIPropertiesModal.h"
#include "UI/Tools/UIShapeTool.h"

#include "Editor/Tools/ESceneClassList.h"

#include "Editor/Utils/Gimzo/Gizmo.h"

#include "Editor/UI_LevelMain.h"
#include "Editor/UI_LevelTools.h"

#include "Editor/Utils/portalutils.h"
#include "Editor/Utils/XrSEFactoryManager.h"
#include "Editor/Utils/iniStreamImpl.h"
#include "Editor/Utils/SoundManager_LE.h"
#include "Editor/Utils/LevelPreferences.h"
#include "Editor/Utils/Custom2DProjector.h"

#include "Editor/Entry/CustomObject.h"
#include "Editor/Entry/Glow/glow.h"
#include "Editor/Entry/Group/GroupObject.h"
#include "Editor/Entry/Light/ELight.h"
#include "Editor/Entry/Particles/EParticlesObject.h"
#include "Editor/Entry/Portal/portal.h"
#include "Editor/Entry/Sector/sector.h"
#include "Editor/Entry/Shape/EShape.h"
#include "Editor/Entry/Sound/ESound_Environment.h"
#include "Editor/Entry/Sound/ESound_Source.h"
#include "Editor/Entry/Spawn/SpawnPoint.h"
#include "Editor/Entry/StaticObject/SceneObject.h"
#include "Editor/Entry/WayPoint/WayPoint.h"

#include "Editor/Tools/Base/ESceneControlsCustom.h"
#include "Editor/Tools/Base/ESceneCustomMTools.h"
#include "Editor/Tools/Base/ESceneCustomOTools.h"
#include "Editor/Tools/Base/ESceneDummyTools.h"

#include "Editor/Tools/AIMap/ESceneAIMapTools_Export.h"
#include "Editor/Tools/AIMap/ESceneAIMapTools.h"
#include "Editor/Tools/AIMap/ESceneAIMapControls.h"
#include "Editor/Tools/Details/ESceneDOTools.h"
#include "Editor/Tools/FogVolume/ESceneFogVolumeTools.h"
#include "Editor/Tools/Group/ESceneGroupTools.h"
#include "Editor/Tools/Group/ESceneGroupControls.h"
#include "Editor/Tools/Light/ESceneLightTools.h"
#include "Editor/Tools/Particles/EScenePSTools.h"
#include "Editor/Tools/Particles/EScenePSControls.h"
#include "Editor/Tools/Sector/ESceneSectorTools.h"
#include "Editor/Tools/Sector/ESceneSectorControls.h"
#include "Editor/Tools/Portal/EScenePortalTools.h"
#include "Editor/Tools/Portal/EScenePortalControls.h"
#include "Editor/Tools/Shape/ESceneShapeTools.h"
#include "Editor/Tools/Shape/ESceneShapeControls.h"
#include "Editor/Tools/Sound/ESceneSoundSrcTools.h"
#include "Editor/Tools/Sound/ESceneSoundEnvTools.h"
#include "Editor/Tools/Spawn/ESceneSpawnTools.h"
#include "Editor/Tools/Spawn/ESceneSpawnControls.h"
#include "Editor/Tools/StaticObject/ESceneObjectTools.h"
#include "Editor/Tools/StaticObject/ESceneObjectControls.h"
#include "Editor/Tools/Wallmark/ESceneWallmarkTools.h"
#include "Editor/Tools/Wallmark/ESceneWallmarkControls.h"
#include "Editor/Tools/WayPoint/ESceneWayTools.h"
#include "Editor/Tools/WayPoint/ESceneWayControls.h"
#include "Editor/Tools/Glow/ESceneGlowTools.h"

#include "Editor/Scene/CFromBuilder.h"
#include "Editor/Scene/scene.h"
#include "Editor/Scene/SceneGraph.h"
#include "Editor/Scene/SceneSummaryInfo.h"
#include "Editor/Builder/Builder.h"

#include "Editor/Utils/XrSEFactoryManager.h"

#include "UI/UIMainForm.h"
#include "UI/UIMainMenuForm.h"
#include "UI/UIDOOneColor.h"
#include "UI/UIDOShuffle.h"
#include "UI/UILeftBarForm.h"
#include "UI/UILPropertiesFrom.h"
#include "UI/UIWorldPropertiesFrom.h"
#include "UI/ObjectList/UIObjectListItem.h"
#include "UI/ObjectList/UIObjectList.h"
#include "UI/UIPropertiesModal.h"
#include "UI/UITopBarForm.h"

#include "UI/Tools/UIAIMapTool.h"
#include "UI/Tools/UIDOTool.h"
#include "UI/Tools/UIFogVolTool.h"
#include "UI/Tools/UIGroupTool.h"
#include "UI/Tools/UILightTool.h"
#include "UI/Tools/UIObjectTool.h"
#include "UI/Tools/UIParticlesTool.h"
#include "UI/Tools/UIPortalTool.h"
#include "UI/Tools/UISectorTool.h"
#include "UI/Tools/UIShapeTool.h"
#include "UI/Tools/UISpawnTool.h"
#include "UI/Tools/UIToolCustom.h"
#include "UI/Tools/UIWayTool.h"
