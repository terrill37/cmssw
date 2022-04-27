import FWCore.ParameterSet.Config as cms

from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer

BTVHLTOfflineSource = DQMEDAnalyzer("BTVHLTOfflineSource",

    dirname                 = cms.untracked.string("HLT/BTV"),
    processname             = cms.string("HLT"),
    verbose                 = cms.untracked.bool(False),

    triggerSummaryLabel     = cms.InputTag("hltTriggerSummaryAOD", "", "HLT"),
    triggerResultsLabel     = cms.InputTag("TriggerResults", "", "HLT"),
    onlineDiscrLabelPF      = cms.InputTag("hltDeepCombinedSecondaryVertexBJetTagsPF", "probb"),
    onlineDiscrLabelCalo    = cms.InputTag("hltDeepCombinedSecondaryVertexBJetTagsCalo", "probb"),
    offlineDiscrLabelb      = cms.InputTag("pfDeepCSVJetTags", "probb"),
    offlineDiscrLabelbb     = cms.InputTag("pfDeepCSVJetTags", "probbb"),
    hltFastPVLabel          = cms.InputTag("hltFastPrimaryVertex"),
    hltPFPVLabel            = cms.InputTag("hltVerticesPFSelector"),
    hltCaloPVLabel          = cms.InputTag("hltVerticesL3"),
    offlinePVLabel          = cms.InputTag("offlinePrimaryVertices"),
    offlineIPLabel          = cms.InputTag("pfImpactParameterTagInfos"),
    turnon_threshold_loose  = cms.double(0.2),
    turnon_threshold_medium = cms.double(0.5),
    turnon_threshold_tight  = cms.double(0.8),
    minDecayLength          = cms.double(-9999.0),
    maxDecayLength          = cms.double(5.0),
    minJetDistance          = cms.double(0.0),
    maxJetDistance          = cms.double(0.07),
    dRTrackMatch            = cms.double(0.01),


    pathPairs = cms.VPSet(

        cms.PSet(
            pathname = cms.string("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5_v"),
            pathtype = cms.string("PF")
        ),
        cms.PSet(
            pathname = cms.string("HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71_v"),
            pathtype = cms.string("Calo")
        ),
        cms.PSet(
            pathname = cms.string("HLT_DoublePFJets40_CaloBTagDeepCSV_p71_v"),
            pathtype = cms.string("Calo")
        ),
   ),
)

#
#  Relative Online-Offline Track Monitoring
#
from DQM.TrackingMonitorSource.trackToTrackComparisonHists_cfi import trackToTrackComparisonHists

referenceTracksForHLTBTag = cms.EDFilter('TrackSelector',
    src = cms.InputTag('generalTracks'),
    cut = cms.string("quality('highPurity')")
)

bTagHLTTrackMonitoring_EmuPF = trackToTrackComparisonHists.clone(
    dzWRTPvCut               = 0.1,
    monitoredTrack           = "hltMergedTracks",
    referenceTrack           = "referenceTracksForHLTBTag",
    monitoredBeamSpot        = "hltOnlineBeamSpot",
    referenceBeamSpot        = "offlineBeamSpot",
    topDirName               = "HLT/BTV/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5PF",
    referencePrimaryVertices = "offlinePrimaryVertices",
    monitoredPrimaryVertices = "hltVerticesPFSelector",
    genericTriggerEventPSet = dict(hltPaths = ["HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*"])
)

bTagHLTTrackMonitoring_CaloDeepCSV = bTagHLTTrackMonitoring_EmuPF.clone( 
    monitoredTrack = "hltMergedTracksForBTag",
    monitoredPrimaryVertices = "hltVerticesL3",
    topDirName = "HLT/BTV/HLT_DoublePFJets40_CaloBTagDeepCSV_p71Calo",
    genericTriggerEventPSet = dict(hltPaths = ["HLT_DoublePFJets40_CaloBTagDeepCSV_p71*"])
)

bTagHLTTrackMonitoring_Mu12CaloDeepCSV = bTagHLTTrackMonitoring_CaloDeepCSV.clone(
    topDirName = "HLT/BTV/HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71Calo",
    genericTriggerEventPSet = dict(hltPaths = ["HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71*"])
)

#bTagAndProbeMonitoring_EmuPF = trackToTrackComparisonHists.clone()
#bTagAndProbeMonitoring_EmuPF.dzWRTPvCut               = cms.double(0.1)
#bTagAndProbeMonitoring_EmuPF.monitoredTrack           = cms.InputTag("hltMergedTracks")
#bTagAndProbeMonitoring_EmuPF.referenceTrack           = cms.InputTag("referenceTracksForHLTBTag")
#bTagAndProbeMonitoring_EmuPF.monitoredBeamSpot        = cms.InputTag("hltOnlineBeamSpot")
#bTagAndProbeMonitoring_EmuPF.referenceBeamSpot        = cms.InputTag("offlineBeamSpot")
#bTagAndProbeMonitoring_EmuPF.topDirName               = cms.string("HLT/BTV/TagAndProbe/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5PF")
#bTagAndProbeMonitoring_EmuPF.referencePrimaryVertices = cms.InputTag("offlinePrimaryVertices")
#bTagAndProbeMonitoring_EmuPF.monitoredPrimaryVertices = cms.InputTag("hltVerticesPFSelector")
#bTagAndProbeMonitoring_EmuPF.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*")

#from DQMOffline.Trigger.BTVTagAndProbeTriggerMonitor_cfi import *

bTagHLTTrackMonitoringSequence = cms.Sequence(
    cms.ignore(referenceTracksForHLTBTag)
    #+ bTagHLTTrackMonitoring_EmuPF
    + bTagHLTTrackMonitoring_CaloDeepCSV
    + bTagHLTTrackMonitoring_Mu12CaloDeepCSV
    #+ bTagAndProbeMonitoring_EmuPF
    #+ bTagHLTTrackMonitoring_SixJetPF
)

#bTagHLTTrackTagAndProbeSequence = cms.Sequence(
#    cms.ignore(referenceTracksForHLTBTag)
#    + bTagAndProbeMonitoring_EmuPF
#)

