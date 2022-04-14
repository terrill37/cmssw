import FWCore.ParameterSet.Config as cms

from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer

triggerFlagPSet = cms.PSet(
    dcsInputTag = cms.InputTag('scalersRawToDigi'),
    dcsPartitions = cms.vint32( 24, 25, 26, 27, 28, 29 ),
    andOrDcs = cms.bool(False),
    errorReplyDcs = cms.bool(True),
    dbLabel = cms.string(''),
    andOrHlt = cms.bool(True),
    hltInputTag = cms.InputTag('TriggerResults', '', 'HLT'),
    hltPaths = cms.vstring(),
    hltDBKey = cms.string(''),
    errorReplyHlt = cms.bool(False),
    verbosityLevel = cms.uint32(1)
)

BTVTagAndProbeMonitor = DQMEDAnalyzer("TagAndProbeBtagTriggerMonitor",
    dirname = cms.string("HLT/BTV/tagAndProbe1/"),
    requireValidHLTPaths = cms.bool(True),
    processname = cms.string("HLT"),
    jetPtMin = cms.double(40),
    jetEtaMax = cms.double(2.2),
    tagBtagMin = cms.double(0.80),
    probeBtagMin = cms.double(0.45),
    triggerobjbtag = cms.string("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5"),
    triggerSummary = cms.InputTag("hltTriggerSummaryAOD","","HLT"),
    offlineBtag = cms.InputTag("pfCombinedInclusiveSecondaryVertexV2BJetTags"),
    histoPSet = cms.PSet(
        jetPt  = cms.vdouble(40,45,50,55,60,65,70,75,80,85,90,95,100),
        jetEta = cms.vdouble(-2.5,-2.0,-1.5,-1.0,-0.5,0.0,0.5,1.0,1.5,2.0,2.5),
        jetPhi = cms.vdouble(-3.5,-3.0,-2.5,-2.0,-1.5,-1.0,-0.5,0.0,0.5,1.0,1.5,2.0,2.5,3.0,3.5),
        jetBtag = cms.vdouble(0.80,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.00),
    ),
    genericTriggerEventPSet = triggerFlagPSet.clone(),
)

#bTagHLTTagAndProbeMonitoringSequence = cms.Sequence(
#    BTVTagAndProbeMonitor
#)

