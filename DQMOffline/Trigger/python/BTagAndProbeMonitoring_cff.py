import FWCore.ParameterSet.Config as cms

from DQMOffline.Trigger.BTagAndProbeMonitor_cfi import BTagAndProbeMonitoring 

from Configuration.Eras.Modifier_run2_HLTconditions_2018_cff import run2_HLTconditions_2018
from Configuration.Eras.Modifier_run2_HLTconditions_2017_cff import run2_HLTconditions_2017
from Configuration.Eras.Modifier_run2_HLTconditions_2016_cff import run2_HLTconditions_2016

###
### Ele+Jet
###

BTagAndProbeJet_jet = BTagAndProbeMonitoring.clone()
BTagAndProbeJet_jet.FolderName = cms.string('HLT/BTV/EleJet/JetMonitor')
BTagAndProbeJet_jet.nmuons = cms.uint32(1)
BTagAndProbeJet_jet.nelectrons = cms.uint32(1)
BTagAndProbeJet_jet.njets = cms.uint32(1)
BTagAndProbeJet_jet.nbjets = cms.uint32(1)
#BTagAndProbeJet_jet.eleSelection = cms.string('pt>50 & abs(eta)<2.1')
#BTagAndProbeJet_jet.jetSelection = cms.string('pt>30 & abs(eta)<2.4')
BTagAndProbeJet_jet.histoPSet.eleEtaBinning = cms.vdouble(-2.1,-1.5,-0.9,-0.6,-0.3,-0.1,0,0.1,0.3,0.6,0.9,1.5,2.1)
BTagAndProbeJet_jet.histoPSet.eleEtaBinning2D = cms.vdouble(-2.1,-1.5,-0.6,0,0.6,1.5,2.1)
BTagAndProbeJet_jet.histoPSet.elePtBinning = cms.vdouble(0,50,60,80,120,200,400)
BTagAndProbeJet_jet.histoPSet.elePtBinning2D = cms.vdouble(0,50,70,120,200,400)
BTagAndProbeJet_jet.histoPSet.jetPtBinning = cms.vdouble(0,30,35,37.5,40,50,60,80,120,200,400)
BTagAndProbeJet_jet.histoPSet.jetPtBinning2D = cms.vdouble(0,30,35,40,50,60,80,100,200,400)
BTagAndProbeJet_jet.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*')
BTagAndProbeJet_jet.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5*')

#BTagAndProbeJet_jet.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned_v*')
#BTagAndProbeJet_jet.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele35_WPTight_Gsf_v*',
#                                                                'HLT_Ele38_WPTight_Gsf_v*',
#                                                                'HLT_Ele40_WPTight_Gsf_v*',)

### ---

BTagAndProbeJet_ele = BTagAndProbeMonitoring.clone()
BTagAndProbeJet_ele.FolderName = cms.string('HLT/BTV/EleJet/ElectronMonitor')
BTagAndProbeJet_ele.nmuons = cms.uint32(1)
BTagAndProbeJet_ele.nelectrons = cms.uint32(1)
BTagAndProbeJet_ele.njets = cms.uint32(1)
BTagAndProbeJet_ele.nbjets = cms.uint32(1)
#BTagAndProbeJet_ele.eleSelection = cms.string('pt>25 & abs(eta)<2.1')
#BTagAndProbeJet_ele.jetSelection = cms.string('pt>50 & abs(eta)<2.4')
BTagAndProbeJet_ele.histoPSet.eleEtaBinning = cms.vdouble(-2.1,-1.5,-0.9,-0.6,-0.3,-0.1,0,0.1,0.3,0.6,0.9,1.5,2.1)
BTagAndProbeJet_ele.histoPSet.eleEtaBinning2D = cms.vdouble(-2.1,-1.5,-0.6,0,0.6,1.5,2.1)
BTagAndProbeJet_ele.histoPSet.elePtBinning = cms.vdouble(0,25,30,32.5,35,40,45,50,60,80,120,200,400)
BTagAndProbeJet_ele.histoPSet.elePtBinning2D = cms.vdouble(0,25,30,40,50,60,80,100,200,400)
BTagAndProbeJet_ele.histoPSet.jetPtBinning = cms.vdouble(0,50,60,80,120,200,400)
BTagAndProbeJet_ele.histoPSet.jetPtBinning2D = cms.vdouble(0,50,60,80,100,200,400)
BTagAndProbeJet_ele.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned_v*')
BTagAndProbeJet_ele.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_PFJet60_v*',
                                                                'HLT_PFJet80_v*',
                                                                'HLT_PFJet140_v*',
                                                                'HLT_PFJet200_v*',
                                                                'HLT_PFJet260_v*',
                                                                'HLT_PFJet320_v*',
                                                                'HLT_PFJet400_v*',
                                                                'HLT_PFJet450_v*',
                                                                'HLT_PFJet500_v*',
                                                                'HLT_PFJet550_v*',)
### ---
BTagAndProbeJet_all = BTagAndProbeMonitoring.clone()
BTagAndProbeJet_all.FolderName = cms.string('HLT/BTV/EleJet/GlobalMonitor')
BTagAndProbeJet_all.nmuons = cms.uint32(1)
BTagAndProbeJet_all.nelectrons = cms.uint32(1)
BTagAndProbeJet_all.njets = cms.uint32(1)
BTagAndProbeJet_all.nbjets = cms.uint32(1)
#BTagAndProbeJet_all.eleSelection = cms.string('pt>25 & abs(eta)<2.1')
#BTagAndProbeJet_all.jetSelection = cms.string('pt>30 & abs(eta)<2.4')
BTagAndProbeJet_all.histoPSet.eleEtaBinning = cms.vdouble(-2.1,-1.5,-0.9,-0.6,-0.3,-0.1,0,0.1,0.3,0.6,0.9,1.5,2.1)
BTagAndProbeJet_all.histoPSet.eleEtaBinning2D = cms.vdouble(-2.1,-1.5,-0.6,0,0.6,1.5,2.1)
BTagAndProbeJet_all.histoPSet.elePtBinning = cms.vdouble(0,25,30,32.5,35,40,45,50,60,80,120,200,400)
BTagAndProbeJet_all.histoPSet.elePtBinning2D = cms.vdouble(0,25,30,40,50,60,80,100,200,400)
BTagAndProbeJet_all.histoPSet.jetPtBinning = cms.vdouble(0,30,35,37.5,40,50,60,80,120,200,400)
BTagAndProbeJet_all.histoPSet.jetPtBinning2D = cms.vdouble(0,30,35,40,50,60,80,100,200,400)
BTagAndProbeJet_all.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned_v*')
# topEleJet_all.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_IsoMu24_v*')

###
### Ele+HT
###

BTagAndProbeHT_ht = BTagAndProbeMonitoring.clone()
BTagAndProbeHT_ht.FolderName = cms.string('HLT/BTV/EleHT/HTMonitor')
BTagAndProbeHT_ht.nmuons = cms.uint32(1)
BTagAndProbeHT_ht.nelectrons = cms.uint32(1)
BTagAndProbeHT_ht.njets = cms.uint32(1)
BTagAndProbeHT_ht.nbjets = cms.uint32(1)
#BTagAndProbeHT_ht.eleSelection = cms.string('pt>50 & abs(eta)<2.1')
#BTagAndProbeHT_ht.jetSelection = cms.string('pt>30 & abs(eta)<2.4')
#BTagAndProbeHT_ht.HTcut = cms.double(100)
BTagAndProbeHT_ht.histoPSet.eleEtaBinning = cms.vdouble(-2.1,-1.5,-0.9,-0.6,-0.3,-0.1,0,0.1,0.3,0.6,0.9,1.5,2.1)
BTagAndProbeHT_ht.histoPSet.eleEtaBinning2D = cms.vdouble(-2.1,-1.5,-0.6,0,0.6,1.5,2.1)
BTagAndProbeHT_ht.histoPSet.elePtBinning = cms.vdouble(0,50,60,80,120,200,400)
BTagAndProbeHT_ht.histoPSet.elePtBinning2D = cms.vdouble(0,50,70,120,200,400)
BTagAndProbeHT_ht.histoPSet.jetPtBinning = cms.vdouble(0,30,40,50,60,80,120,200,400)
BTagAndProbeHT_ht.histoPSet.jetPtBinning2D = cms.vdouble(0,30,40,60,80,100,200,400)
BTagAndProbeHT_ht.histoPSet.HTBinning  = cms.vdouble(0,100,120,140,150,160,175,200,300,400,500,700)
BTagAndProbeHT_ht.histoPSet.HTBinning2D  = cms.vdouble(0,100,125,150,175,200,400,700)
BTagAndProbeHT_ht.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele28_eta2p1_WPTight_Gsf_HT150_v*')
BTagAndProbeHT_ht.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele35_WPTight_Gsf_v*',
                                                              'HLT_Ele38_WPTight_Gsf_v*',
                                                              'HLT_Ele40_WPTight_Gsf_v*',)

### ---

BTagAndProbeHT_ele = BTagAndProbeMonitoring.clone()
BTagAndProbeHT_ele.FolderName = cms.string('HLT/BTV/EleHT/ElectronMonitor')
BTagAndProbeHT_ele.nmuons = cms.uint32(1)
BTagAndProbeHT_ele.nelectrons = cms.uint32(1)
BTagAndProbeHT_ele.njets = cms.uint32(1)
#BTagAndProbeHT_ele.eleSelection = cms.string('pt>25 & abs(eta)<2.1')
#BTagAndProbeHT_ele.jetSelection = cms.string('pt>30 & abs(eta)<2.4')
BTagAndProbeHT_ele.nbjets = cms.uint32(1)
BTagAndProbeHT_ele.HTcut = cms.double(200)
BTagAndProbeHT_ele.histoPSet.eleEtaBinning = cms.vdouble(-2.1,-1.5,-0.9,-0.6,-0.3,-0.1,0,0.1,0.3,0.6,0.9,1.5,2.1)
BTagAndProbeHT_ele.histoPSet.eleEtaBinning2D = cms.vdouble(-2.1,-1.5,-0.6,0,0.6,1.5,2.1)
BTagAndProbeHT_ele.histoPSet.elePtBinning = cms.vdouble(0,25,30,32.5,35,40,45,50,60,80,120,200,400)
BTagAndProbeHT_ele.histoPSet.elePtBinning2D = cms.vdouble(0,25,30,40,50,60,80,100,200,400)
BTagAndProbeHT_ele.histoPSet.jetPtBinning = cms.vdouble(0,30,40,50,60,80,120,200,400)
BTagAndProbeHT_ele.histoPSet.jetPtBinning2D = cms.vdouble(0,30,40,60,80,100,200,400)
BTagAndProbeHT_ele.histoPSet.HTBinning  = cms.vdouble(0,200,250,300,350,400,500,700)
BTagAndProbeHT_ele.histoPSet.HTBinning2D  = cms.vdouble(0,200,250,300,400,500,700)
BTagAndProbeHT_ele.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele28_eta2p1_WPTight_Gsf_HT150_v*')
BTagAndProbeHT_ele.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_PFHT250_v*',
                                                               'HLT_PFHT370_v*',
                                                               'HLT_PFHT430_v*',
                                                               'HLT_PFHT510_v*',
                                                               'HLT_PFHT590_v*',
                                                               'HLT_PFHT680_v*',
                                                               'HLT_PFHT780_v*',
                                                               'HLT_PFHT890_v*',)

### ---

BTagAndProbeHT_all = BTagAndProbeMonitoring.clone()
BTagAndProbeHT_all.FolderName = cms.string('HLT/BTV/EleHT/GlobalMonitor')
BTagAndProbeHT_all.nmuons = cms.uint32(1)
BTagAndProbeHT_all.nelectrons = cms.uint32(1)
BTagAndProbeHT_all.njets = cms.uint32(1)
BTagAndProbeHT_all.nbjets = cms.uint32(1)
#BTagAndProbeHT_all.eleSelection = cms.string('pt>25 & abs(eta)<2.1')
#BTagAndProbeHT_all.jetSelection = cms.string('pt>30 & abs(eta)<2.4')
BTagAndProbeHT_all.HTcut = cms.double(100)
BTagAndProbeHT_all.histoPSet.eleEtaBinning = cms.vdouble(-2.1,-1.5,-0.9,-0.6,-0.3,-0.1,0,0.1,0.3,0.6,0.9,1.5,2.1)
BTagAndProbeHT_all.histoPSet.eleEtaBinning2D = cms.vdouble(-2.1,-1.5,-0.6,0,0.6,1.5,2.1)
BTagAndProbeHT_all.histoPSet.elePtBinning = cms.vdouble(0,25,30,32.5,35,40,45,50,60,80,120,200,400)
BTagAndProbeHT_all.histoPSet.elePtBinning2D = cms.vdouble(0,25,30,40,50,60,80,100,200,400)
BTagAndProbeHT_all.histoPSet.jetPtBinning = cms.vdouble(0,30,40,50,60,80,120,200,400)
BTagAndProbeHT_all.histoPSet.jetPtBinning2D = cms.vdouble(0,30,40,60,80,100,200,400)
BTagAndProbeHT_all.histoPSet.HTBinning  = cms.vdouble(0,100,120,140,150,160,175,200,300,400,500,700)
BTagAndProbeHT_all.histoPSet.HTBinning2D  = cms.vdouble(0,100,125,150.175,200,400,700)
BTagAndProbeHT_all.numGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_Ele28_eta2p1_WPTight_Gsf_HT150_v*')
BTagAndProbeHT_all.denGenericTriggerEventPSet.hltPaths = cms.vstring('HLT_IsoMu24_v*')

###
### SingleMuon
###

###
### Top HLT-DQM Sequence
###

from DQMOffline.Trigger.HLTEGTnPMonitor_cfi import egmGsfElectronIDsForDQM

BTagAndProbeHLT = cms.Sequence(

      BTagAndProbeJet_ele
    + BTagAndProbeJet_jet
    + BTagAndProbeJet_all
    + BTagAndProbeHT_ele
    + BTagAndProbeHT_ht
    + BTagAndProbeHT_all


    , cms.Task(egmGsfElectronIDsForDQM) # Use of electron VID requires this module being executed first
)


