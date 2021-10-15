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
            pathtype = cms.string("PF"),
        ),
        cms.PSet(
            pathname = cms.string("HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71_v"),
            pathtype = cms.string("Calo")
        ),
        cms.PSet(
            pathname = cms.string("HLT_DoublePFJets40_CaloBTagDeepCSV_p71_v"),
            pathtype = cms.string("Calo")
        ),
        #cms.PSet(
        #    pathname = cms.string("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5_v"),
        #    pathtype = cms.string("Calo"),
        #),
        #cms.PSet(
        #    pathname = cms.string("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_v"),
        #    pathtype = cms.string("PF"),
        #),
        #cms.PSet(
        #    pathname = cms.string("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_v"),
        #    pathtype = cms.string("Calo"),
        #),
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

bTagHLTTrackMonitoring_EmuPF = trackToTrackComparisonHists.clone()
bTagHLTTrackMonitoring_EmuPF.dzWRTPvCut               = cms.double(0.1)
bTagHLTTrackMonitoring_EmuPF.monitoredTrack           = cms.InputTag("hltMergedTracks")
bTagHLTTrackMonitoring_EmuPF.referenceTrack           = cms.InputTag("referenceTracksForHLTBTag")
bTagHLTTrackMonitoring_EmuPF.monitoredBeamSpot        = cms.InputTag("hltOnlineBeamSpot")
bTagHLTTrackMonitoring_EmuPF.referenceBeamSpot        = cms.InputTag("offlineBeamSpot")
bTagHLTTrackMonitoring_EmuPF.topDirName               = cms.string("HLT/BTV/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5PF")
bTagHLTTrackMonitoring_EmuPF.referencePrimaryVertices = cms.InputTag("offlinePrimaryVertices")
bTagHLTTrackMonitoring_EmuPF.monitoredPrimaryVertices = cms.InputTag("hltVerticesPFSelector")
bTagHLTTrackMonitoring_EmuPF.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*")

bTagHLTTrackMonitoring_CaloDeepCSV = bTagHLTTrackMonitoring_EmuPF.clone()
bTagHLTTrackMonitoring_CaloDeepCSV.topDirName = cms.string("HLT/BTV/HLT_DoublePFJets40_CaloBTagDeepCSV_p71Calo")
bTagHLTTrackMonitoring_CaloDeepCSV.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_DoublePFJets40_CaloBTagDeepCSV_p71*")
bTagHLTTrackMonitoring_CaloDeepCSV.monitoredTrack = cms.InputTag("hltMergedTracksForBTag")
bTagHLTTrackMonitoring_CaloDeepCSV.monitoredPrimaryVertices = cms.InputTag("hltVerticesL3")

bTagHLTTrackMonitoring_Mu12CaloDeepCSV = bTagHLTTrackMonitoring_CaloDeepCSV.clone()
bTagHLTTrackMonitoring_Mu12CaloDeepCSV.topDirName = cms.string("HLT/BTV/HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71Calo")
bTagHLTTrackMonitoring_Mu12CaloDeepCSV.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71*")

#bTagHLTTrackMonitoring_EmuCalo = trackToTrackComparisonHists.clone()
#bTagHLTTrackMonitoring_EmuCalo.monitoredTrack           = cms.InputTag("hltMergedTracksForBTag")
#bTagHLTTrackMonitoring_EmuCalo.topDirName               = cms.string("HLT/BTV/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5Calo")
#bTagHLTTrackMonitoring_EmuCalo.monitoredPrimaryVertices = cms.InputTag("hltVerticesL3")
#bTagHLTTrackMonitoring_EmuCalo.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5*")


#bTagHLTTrackMonitoring_SixJetCalo = bTagHLTTrackMonitoring_EmuCalo.clone()
#bTagHLTTrackMonitoring_SixJetCalo.topDirName               = cms.string("HLT/BTV/HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94PF")
#bTagHLTTrackMonitoring_SixJetCalo.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_v*")


#bTagHLTTrackMonitoring_EmuPF = bTagHLTTrackMonitoring_EmuCalo.clone()
#bTagHLTTrackMonitoring_EmuPF.monitoredTrack           = cms.InputTag("hltMergedTracks")
#bTagHLTTrackMonitoring_EmuPF.monitoredPrimaryVertices = cms.InputTag("hltVerticesPFSelector")
#bTagHLTTrackMonitoring_EmuPF.topDirName               = cms.string("HLT/BTV/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5PF")
#bTagHLTTrackMonitoring_EmuPF.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*")


#bTagHLTTrackMonitoring_SixJetPF = bTagHLTTrackMonitoring_EmuPF.clone()
#bTagHLTTrackMonitoring_SixJetPF.monitoredTrack           = cms.InputTag("hltMergedTracks")
#bTagHLTTrackMonitoring_SixJetPF.monitoredPrimaryVertices = cms.InputTag("hltVerticesPFSelector")
#bTagHLTTrackMonitoring_SixJetPF.topDirName               = cms.string("HLT/BTV/HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94PF")
#bTagHLTTrackMonitoring_SixJetPF.genericTriggerEventPSet.hltPaths = cms.vstring("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_v*")




bTagHLTTrackMonitoringSequence = cms.Sequence(
    cms.ignore(referenceTracksForHLTBTag)
    #+ bTagHLTTrackMonitoring_CaloDeepCSV
    #+ bTagHLTTrackMonitoring_Mu12CaloDeepCSV
    #+ bTagHLTTrackMonitoring_EmuCalo
    #+ bTagHLTTrackMonitoring_SixJetCalo
    + bTagHLTTrackMonitoring_EmuPF
    + bTagHLTTrackMonitoring_CaloDeepCSV
    + bTagHLTTrackMonitoring_Mu12CaloDeepCSV
    #+ bTagHLTTrackMonitoring_SixJetPF
)



