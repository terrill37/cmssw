import FWCore.ParameterSet.Config as cms

from DQMOffline.Trigger.BTagAndProbeMonitor_cfi import BTagAndProbeMonitoring

from Configuration.Eras.Modifier_run2_HLTconditions_2018_cff import run2_HLTconditions_2018
from Configuration.Eras.Modifier_run2_HLTconditions_2017_cff import run2_HLTconditions_2017
from Configuration.Eras.Modifier_run2_HLTconditions_2016_cff import run2_HLTconditions_2016

###
### Ele+Jet
###

BTagAndProbe_1e1m = BTagAndProbeMonitoring.clone()
BTagAndProbe_1e1m.FolderName = cms.string('HLT/BTV/TnP/oneEle_oneMu')
BTagAndProbe_1e1m.nmuons = cms.uint32(1)
BTagAndProbe_1e1m.nelectrons = cms.uint32(1)
BTagAndProbe_1e1m.njets = cms.uint32(2)
BTagAndProbe_1e1m.nbjets = cms.uint32(2)
BTagAndProbe_1e1m.eleSelection = cms.string('pt>10 & abs(eta)<2.5')
BTagAndProbe_1e1m.muoSelection = cms.string('pt>10 & abs(eta)<2.4')
BTagAndProbe_1e1m.bjetSelection = cms.string('pt>20 & abs(eta)<2.4')
BTagAndProbe_1e1m.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*')
BTagAndProbe_1e1m.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*')
BTagAndProbe_1e1m.debug = cms.bool(True)
#BTagAndProbeJet_jet.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned_v*')
#BTagAndProbeJet_jet.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele35_WPTight_Gsf_v*',
#                                                                'HLT_Ele38_WPTight_Gsf_v*',
#                                                                'HLT_Ele40_WPTight_Gsf_v*',)

### ---

BTagAndProbe_1e0m = BTagAndProbe_1e1m.clone()
BTagAndProbe_1e0m.FolderName = cms.string('HLT/BTV/TnP/OneEle_NoMu')
BTagAndProbe_1e0m.nmuons = cms.uint32(0)
BTagAndProbe_1e0m.nelectrons = cms.uint32(1)
BTagAndProbe_1e0m.debug = cms.bool(False)

### ---
BTagAndProbe_0e1m = BTagAndProbe_1e1m.clone()
BTagAndProbe_0e1m.FolderName = cms.string('HLT/BTV/TnP/NoEle_OneMu')
BTagAndProbe_0e1m.nmuons = cms.uint32(1)
BTagAndProbe_0e1m.nelectrons = cms.uint32(0)
BTagAndProbe_0e1m.debug = cms.bool(False)

BTagAndProbe_2e0m = BTagAndProbe_1e1m.clone()
BTagAndProbe_2e0m.FolderName = cms.string('HLT/BTV/TnP/TwoEle_NoMu')
BTagAndProbe_2e0m.nmuons = cms.uint32(0)
BTagAndProbe_2e0m.nelectrons = cms.uint32(2)
BTagAndProbe_2e0m.debug = cms.bool(False)

BTagAndProbe_0e2m = BTagAndProbe_1e1m.clone()
BTagAndProbe_0e2m.FolderName = cms.string('HLT/BTV/TnP/NoEle_TwoMu')
BTagAndProbe_0e2m.nmuons = cms.uint32(2)
BTagAndProbe_0e2m.nelectrons = cms.uint32(0)
BTagAndProbe_0e2m.debug = cms.bool(False)
###
### Ele+HT
###

#BTagAndProbeHT_ht = BTagAndProbeMonitoring.clone()
#BTagAndProbeHT_ht.FolderName = cms.string('HLT/BTV/EleHT/HTMonitor')
#BTagAndProbeHT_ht.nmuons = cms.uint32(1)
#BTagAndProbeHT_ht.nelectrons = cms.uint32(1)
#BTagAndProbeHT_ht.njets = cms.uint32(1)
#BTagAndProbeHT_ht.nbjets = cms.uint32(1)
#BTagAndProbeHT_ht.eleSelection = cms.string('pt>10 & abs(eta)<2.1')
#BTagAndProbeHT_ht.bjetSelection = cms.string('pt>30 & abs(eta)<2.4')
#BTagAndProbeHT_ht.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele28_eta2p1_WPTight_Gsf_HT150_v*')
#BTagAndProbeHT_ht.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele35_WPTight_Gsf_v*',
#                                                              'HLT_Ele38_WPTight_Gsf_v*',
#                                                              'HLT_Ele40_WPTight_Gsf_v*',)
#
#### ---
#
#BTagAndProbeHT_ele = BTagAndProbeMonitoring.clone()
#BTagAndProbeHT_ele.FolderName = cms.string('HLT/BTV/EleHT/ElectronMonitor')
#BTagAndProbeHT_ele.nmuons = cms.uint32(1)
#BTagAndProbeHT_ele.nelectrons = cms.uint32(1)
#BTagAndProbeHT_ele.njets = cms.uint32(1)
##BTagAndProbeHT_ele.eleSelection = cms.string('pt>25 & abs(eta)<2.1')
#BTagAndProbeHT_ele.bjetSelection = cms.string('pt>30 & abs(eta)<2.4')
#BTagAndProbeHT_ele.nbjets = cms.uint32(1)
#BTagAndProbeHT_ele.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele28_eta2p1_WPTight_Gsf_HT150_v*')
#BTagAndProbeHT_ele.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_PFHT250_v*',
#                                                               'HLT_PFHT370_v*',
#                                                               'HLT_PFHT430_v*',
#                                                               'HLT_PFHT510_v*',
#                                                               'HLT_PFHT590_v*',
#                                                               'HLT_PFHT680_v*',
#                                                               'HLT_PFHT780_v*',
#                                                               'HLT_PFHT890_v*',)
#
#### ---
#
#BTagAndProbeHT_all = BTagAndProbeMonitoring.clone()
#BTagAndProbeHT_all.FolderName = cms.string('HLT/BTV/EleHT/GlobalMonitor')
#BTagAndProbeHT_all.nmuons = cms.uint32(1)
#BTagAndProbeHT_all.nelectrons = cms.uint32(1)
#BTagAndProbeHT_all.njets = cms.uint32(1)
#BTagAndProbeHT_all.nbjets = cms.uint32(1)
##BTagAndProbeHT_all.eleSelection = cms.string('pt>25 & abs(eta)<2.1')
#BTagAndProbeHT_all.bjetSelection = cms.string('pt>30 & abs(eta)<2.4')
#BTagAndProbeHT_all.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele28_eta2p1_WPTight_Gsf_HT150_v*')
#BTagAndProbeHT_all.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_IsoMu24_v*')

###
### SingleMuon
###

###
### Top HLT-DQM Sequence
###

from DQMOffline.Trigger.HLTEGTnPMonitor_cfi import egmGsfElectronIDsForDQM

BTagAndProbeHLT = cms.Sequence(

      BTagAndProbe_1e1m
    + BTagAndProbe_1e0m
    + BTagAndProbe_0e1m
#    + BTagAndProbe_2e0m
#    + BTagAndProbe_0e2m
#    + BTagAndProbeHT_ele
#    + BTagAndProbeHT_ht
#    + BTagAndProbeHT_all


    , cms.Task(egmGsfElectronIDsForDQM) # Use of electron VID requires this module being executed first
)
