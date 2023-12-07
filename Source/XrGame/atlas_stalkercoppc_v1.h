﻿///////////////////////////////////////////////////////////////////////////////
// GameSpy ATLAS Competition System Header File
//
// NOTE: This is an auto-generated file, do not edit this file directly.
///////////////////////////////////////////////////////////////////////////////

#ifndef _ATLAS_STALKERCOPPC_V1_H_
#define _ATLAS_STALKERCOPPC_V1_H_

#ifdef __cplusplus
extern "C"
{
#endif

    extern int   ATLAS_GET_KEY(char* keyName);
    extern char* ATLAS_GET_KEY_NAME(int keyId);
    extern int   ATLAS_GET_STAT(char* statName);
    extern char* ATLAS_GET_STAT_NAME(int statId);
    extern int   ATLAS_GET_STAT_PAGE_BY_ID(int statId);
    extern int   ATLAS_GET_STAT_PAGE_BY_NAME(char* statName);

#define ATLAS_RULE_SET_VERSION                          1

    // KEYS
    // Use these key ID's to report match data for your game.

#define KEY_BestScore_KillsInRow                        3    // [TYPE: int] [DESC: kills in row]
#define KEY_BestScore_KnifeKillsInRow                   4    // [TYPE: int] [DESC: knife kills in row]
#define KEY_BestScore_BackstabsKillsInRow               5    // [TYPE: int] [DESC: knife backstabs kills in row]
#define KEY_BestScore_HeadshotsKillsInRow               6    // [TYPE: int] [DESC: headshots kills in row]
#define KEY_BestScore_EyeKillsInRow                     7    // [TYPE: int] [DESC: eye kills in row]
#define KEY_BestScore_BleedKillsInRow                   8    // [TYPE: int] [DESC: bleed kills in row]
#define KEY_BestScore_ExplosiveKillsInRow               9    // [TYPE: int] [DESC: explosive kills in row]
#define KEY_AwardMasscare                               10   // [TYPE: int]
#define KEY_AwardMasscareLastRewardDate                 11   // [TYPE: int]
#define KEY_AwardParanoia                               12   // [TYPE: int]
#define KEY_AwardParanoiaLastRewardDate                 13   // [TYPE: int]
#define KEY_AwardOverwhelmingSuperiority                14   // [TYPE: int]
#define KEY_AwardOverwhelmingSuperiorityLastRewardDate  15   // [TYPE: int]
#define KEY_AwardBlitzkrieg                             16   // [TYPE: int]
#define KEY_AwardBlitzkriegLastRewardDate               17   // [TYPE: int]
#define KEY_AwardDryVictory                             18   // [TYPE: int]
#define KEY_AwardDryVictoryLastRewardDate               19   // [TYPE: int]
#define KEY_AwardMultichampion                          20   // [TYPE: int]
#define KEY_AwardMultichampionLastRewardDate            21   // [TYPE: int]
#define KEY_AwardMad                                    22   // [TYPE: int]
#define KEY_AwardMadLastRewardDate                      23   // [TYPE: int]
#define KEY_AwardAchillesHeel                           24   // [TYPE: int]
#define KEY_AwardAchillesHeelLastRewardDate             25   // [TYPE: int]
#define KEY_AwardFasterThanBullets                      26   // [TYPE: int]
#define KEY_AwardFasterThanBulletsLastRewardDate        27   // [TYPE: int]
#define KEY_AwardHarvestTime                            28   // [TYPE: int]
#define KEY_AwardHarvestTimeLastRewardDate              29   // [TYPE: int]
#define KEY_AwardSkewer                                 30   // [TYPE: int]
#define KEY_AwardSkewerLastRewardDate                   31   // [TYPE: int]
#define KEY_AwardDoubleShotDoubleKill                   32   // [TYPE: int]
#define KEY_AwardDoubleShotDoubleKillLastRewardDate     33   // [TYPE: int]
#define KEY_AwardClimber                                34   // [TYPE: int]
#define KEY_AwardClimberLastRewardDate                  35   // [TYPE: int]
#define KEY_AwardOpener                                 36   // [TYPE: int]
#define KEY_AwardOpenerLastRewardDate                   37   // [TYPE: int]
#define KEY_AwardToughy                                 38   // [TYPE: int]
#define KEY_AwardToughyLastRewardDate                   39   // [TYPE: int]
#define KEY_AwardInvincibleFury                         40   // [TYPE: int]
#define KEY_AwardInvincibleFuryLastRewardDate           41   // [TYPE: int]
#define KEY_AwardOculist                                42   // [TYPE: int]
#define KEY_AwardOculistLastRewardDate                  43   // [TYPE: int]
#define KEY_AwardLightingReflexes                       44   // [TYPE: int]
#define KEY_AwardLightingReflexesLastRewardDate         45   // [TYPE: int]
#define KEY_AwardSprinterStopper                        46   // [TYPE: int]
#define KEY_AwardSprinterStopperLastRewardDate          47   // [TYPE: int]
#define KEY_AwardMarksMan                               48   // [TYPE: int]
#define KEY_AwardMarksManLastRewardDate                 49   // [TYPE: int]
#define KEY_AwardPeaceAmbassador                        50   // [TYPE: int]
#define KEY_AwardPeaceAmbassadorLastRewardDate          51   // [TYPE: int]
#define KEY_AwardDeadlyAccuracy                         52   // [TYPE: int]
#define KEY_AwardDeadlyAccuracyLastRewardDate           53   // [TYPE: int]
#define KEY_AwardRemembrance                            54   // [TYPE: int]
#define KEY_AwardRemembranceLastRewardDate              55   // [TYPE: int]
#define KEY_AwardAvenger                                56   // [TYPE: int]
#define KEY_AwardAvengerLastRewardDate                  57   // [TYPE: int]
#define KEY_AwardCherub                                 58   // [TYPE: int]
#define KEY_AwardCherubLastRewardDate                   59   // [TYPE: int]
#define KEY_AwardDignity                                60   // [TYPE: int]
#define KEY_AwardDignityLastRewardDate                  61   // [TYPE: int]
#define KEY_AwardStalkerFlair                           62   // [TYPE: int]
#define KEY_AwardStalkerFlairLastRewardDate             63   // [TYPE: int]
#define KEY_AwardLucky                                  64   // [TYPE: int]
#define KEY_AwardLuckyLastRewardDate                    65   // [TYPE: int]
#define KEY_AwardBlackList                              66   // [TYPE: int]
#define KEY_AwardBlackListLastRewardDate                67   // [TYPE: int]
#define KEY_AwardSilentDeath                            68   // [TYPE: int]
#define KEY_AwardSilentDeathLastRewardDate              69   // [TYPE: int]
#define KEY_PlayerName                                  70   // [TYPE: string]

    ///////////////////////////////////////////////////////////////////////////////

    // STATS
    // Use these stat ID's to query aggregate statistics for your game.

#define STAT_AwardAchillesHeel                          1    // [TYPE: int]
#define STAT_AwardAchillesHeelLastRewardDate            2    // [TYPE: int]
#define STAT_AwardAvenger                               3    // [TYPE: int]
#define STAT_AwardAvengerLastRewardDate                 4    // [TYPE: int]
#define STAT_AwardBlackList                             5    // [TYPE: int]
#define STAT_AwardBlackListLastRewardDate               6    // [TYPE: int]
#define STAT_AwardBlitzkrieg                            7    // [TYPE: int]
#define STAT_AwardBlitzkriegLastRewardDate              8    // [TYPE: int]
#define STAT_AwardCherub                                9    // [TYPE: int]
#define STAT_AwardCherubLastRewardDate                  10   // [TYPE: int]
#define STAT_AwardClimber                               11   // [TYPE: int]
#define STAT_AwardClimberLastRewardDate                 12   // [TYPE: int]
#define STAT_AwardDeadlyAccuracy                        13   // [TYPE: int]
#define STAT_AwardDeadlyAccuracyLastRewardDate          14   // [TYPE: int]
#define STAT_AwardDignity                               15   // [TYPE: int]
#define STAT_AwardDignityLastRewardDate                 16   // [TYPE: int]
#define STAT_AwardDoubleShotDoubleKill                  17   // [TYPE: int]
#define STAT_AwardDoubleShotDoubleKillLastRewardDate    18   // [TYPE: int]
#define STAT_AwardDryVictory                            19   // [TYPE: int]
#define STAT_AwardDryVictoryLastRewardDate              20   // [TYPE: int]
#define STAT_AwardFasterThanBullets                     21   // [TYPE: int]
#define STAT_AwardFasterThanBulletsLastRewardDate       22   // [TYPE: int]
#define STAT_AwardHarvestTime                           23   // [TYPE: int]
#define STAT_AwardHarvestTimeLastRewardDate             24   // [TYPE: int]
#define STAT_AwardInvincibleFury                        25   // [TYPE: int]
#define STAT_AwardInvincibleFuryLastRewardDate          26   // [TYPE: int]
#define STAT_AwardLightingReflexes                      27   // [TYPE: int]
#define STAT_AwardLightingReflexesLastRewardDate        28   // [TYPE: int]
#define STAT_AwardLucky                                 29   // [TYPE: int]
#define STAT_AwardLuckyLastRewardDate                   30   // [TYPE: int]
#define STAT_AwardMad                                   31   // [TYPE: int]
#define STAT_AwardMadLastRewardDate                     32   // [TYPE: int]
#define STAT_AwardMarksman                              33   // [TYPE: int]
#define STAT_AwardMarksmanLastRewardDate                34   // [TYPE: int]
#define STAT_AwardMasscare                              35   // [TYPE: int]
#define STAT_AwardMasscareLastRewardDate                36   // [TYPE: int]
#define STAT_AwardMultichampion                         37   // [TYPE: int]
#define STAT_AwardMultichampionLastRewardDate           38   // [TYPE: int]
#define STAT_AwardOculist                               39   // [TYPE: int]
#define STAT_AwardOculistLastRewardDate                 40   // [TYPE: int]
#define STAT_AwardOpener                                41   // [TYPE: int]
#define STAT_AwardOpenerLastRewardDate                  42   // [TYPE: int]
#define STAT_AwardOwerwhelmingSuperiority               43   // [TYPE: int]
#define STAT_AwardOwerwhelmingSuperiorityLastRewardDate 44   // [TYPE: int]
#define STAT_AwardParanoia                              45   // [TYPE: int]
#define STAT_AwardParanoiaLastRewardDate                46   // [TYPE: int]
#define STAT_AwardPeaceAmbassador                       47   // [TYPE: int]
#define STAT_AwardPeaceAmbassadorLastRewardDate         48   // [TYPE: int]
#define STAT_AwardRemembrance                           49   // [TYPE: int]
#define STAT_AwardRemembranceLastRewardDate             50   // [TYPE: int]
#define STAT_AwardSilentDeath                           51   // [TYPE: int]
#define STAT_AwardSilentDeathLastRewardDate             52   // [TYPE: int]
#define STAT_AwardSkewer                                53   // [TYPE: int]
#define STAT_AwardSkewerLastRewardDate                  54   // [TYPE: int]
#define STAT_AwardSprinterStopper                       55   // [TYPE: int]
#define STAT_AwardSprinterStopperLastRewardDate         56   // [TYPE: int]
#define STAT_AwardStalkerFlair                          57   // [TYPE: int]
#define STAT_AwardStalkerFlairLastRewardDate            58   // [TYPE: int]
#define STAT_AwardToughy                                59   // [TYPE: int]
#define STAT_AwardToughyLastRewardDate                  60   // [TYPE: int]
#define STAT_BestScore_BackstabsKillsInRow              61   // [TYPE: int]
#define STAT_BestScore_BleedKillsInRow                  62   // [TYPE: int]
#define STAT_BestScore_ExplosiveKillsInRow              63   // [TYPE: int]
#define STAT_BestScore_EyeKillsInRow                    64   // [TYPE: int]
#define STAT_BestScore_HeadshotsKillsInRow              65   // [TYPE: int]
#define STAT_BestScore_KillsInRow                       66   // [TYPE: int]
#define STAT_BestScore_KnifeKillsInRow                  67   // [TYPE: int]
#define STAT_PlayerName                                 68   // [TYPE: string] [DESC: contains players name]

#ifdef __cplusplus
}
#endif

#endif   // _ATLAS_STALKERCOPPC_V1_H_
