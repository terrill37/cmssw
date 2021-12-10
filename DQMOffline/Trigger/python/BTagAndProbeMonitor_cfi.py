import FWCore.ParameterSet.Config as cms

from DQMOffline.Trigger.BTagAndProbeMonitoring_cfi import BTagAndProbeMonitoring #FIXME

BTagAndProbeMonitoring = BTagAndProbeMonitoring.clone() #FIXME

BTagAndProbeMonitoring.FolderName = 'HLT/BTV/default/'
BTagAndProbeMonitoring.requireValidHLTPaths = True

# histo PSets
BTagAndProbeMonitoring.histoPSet.lsPSet.nbins =  250
BTagAndProbeMonitoring.histoPSet.lsPSet.xmin  =    0
BTagAndProbeMonitoring.histoPSet.lsPSet.xmax  = 2500

BTagAndProbeMonitoring.histoPSet.metPSet.nbins =  30
BTagAndProbeMonitoring.histoPSet.metPSet.xmin  =   0
BTagAndProbeMonitoring.histoPSet.metPSet.xmax  = 300

BTagAndProbeMonitoring.histoPSet.ptPSet.nbins =  60
BTagAndProbeMonitoring.histoPSet.ptPSet.xmin  =   0
BTagAndProbeMonitoring.histoPSet.ptPSet.xmax  = 300

BTagAndProbeMonitoring.histoPSet.lsPSet.nbins = 2500

BTagAndProbeMonitoring.histoPSet.phiPSet.nbins = 32
BTagAndProbeMonitoring.histoPSet.phiPSet.xmin  = -3.2
BTagAndProbeMonitoring.histoPSet.phiPSet.xmax  =  3.2

BTagAndProbeMonitoring.histoPSet.etaPSet.nbins = 24
BTagAndProbeMonitoring.histoPSet.etaPSet.xmin  = -2.4
BTagAndProbeMonitoring.histoPSet.etaPSet.xmax  =  2.4

BTagAndProbeMonitoring.histoPSet.htPSet.nbins =  60
BTagAndProbeMonitoring.histoPSet.htPSet.xmin  =   0
BTagAndProbeMonitoring.histoPSet.htPSet.xmax  = 600

BTagAndProbeMonitoring.histoPSet.csvPSet.nbins = 50
BTagAndProbeMonitoring.histoPSet.csvPSet.xmin  =  0
BTagAndProbeMonitoring.histoPSet.csvPSet.xmax  =  1

BTagAndProbeMonitoring.histoPSet.DRPSet.nbins = 60
BTagAndProbeMonitoring.histoPSet.DRPSet.xmin  =  0
BTagAndProbeMonitoring.histoPSet.DRPSet.xmax  =  6

BTagAndProbeMonitoring.histoPSet.invMassPSet.nbins = 40
BTagAndProbeMonitoring.histoPSet.invMassPSet.xmin  =  0
BTagAndProbeMonitoring.histoPSet.invMassPSet.xmax  = 80

BTagAndProbeMonitoring.histoPSet.MHTPSet.nbins =  80
BTagAndProbeMonitoring.histoPSet.MHTPSet.xmin  =  60
BTagAndProbeMonitoring.histoPSet.MHTPSet.xmax  = 300

# MET and HT binning
BTagAndProbeMonitoring.histoPSet.metBinning = [0,20,40,60,80,100,125,150,175,200]
BTagAndProbeMonitoring.histoPSet.HTBinning  = [0,20,40,60,80,100,125,150,175,200,300,400,500,700]
# Eta binning
BTagAndProbeMonitoring.histoPSet.eleEtaBinning = [-2.4,-2.1,-1.5,-0.9,-0.3,0.,0.3,0.9,1.5,2.1,2.4]
BTagAndProbeMonitoring.histoPSet.jetEtaBinning = [-2.4,-2.1,-1.5,-0.9,-0.3,0.,0.3,0.9,1.5,2.1,2.4]
BTagAndProbeMonitoring.histoPSet.muEtaBinning  = [-2.4,-2.1,-1.5,-0.9,-0.3,0.,0.3,0.9,1.5,2.1,2.4]
# pt binning
BTagAndProbeMonitoring.histoPSet.elePtBinning = [0,5,10,20,30,40,50,70,100,200,400]
BTagAndProbeMonitoring.histoPSet.jetPtBinning = [0,5,10,20,30,40,50,70,100,200,400]
BTagAndProbeMonitoring.histoPSet.muPtBinning  = [0,5,10,20,30,40,50,70,100,200,400]
# Eta binning 2D
BTagAndProbeMonitoring.histoPSet.eleEtaBinning2D = [-2.5,-1.5,-0.6,0.,0.6,1.5,2.5]
BTagAndProbeMonitoring.histoPSet.jetEtaBinning2D = [-2.5,-1.5,-0.6,0.,0.6,1.5,2.5]
BTagAndProbeMonitoring.histoPSet.muEtaBinning2D  = [-2.5,-1.5,-0.6,0.,0.6,1.5,2.5]
#BTagAndProbeMonitoring.histoPSet.phoEtaBinning2D = [-2.5,-1.5,-0.6,0.,0.6,1.5,2.5]
# pt binning 2D
BTagAndProbeMonitoring.histoPSet.elePtBinning2D = [0,20,30,50,100,200,400]
BTagAndProbeMonitoring.histoPSet.jetPtBinning2D = [0,20,30,50,100,200,400]
BTagAndProbeMonitoring.histoPSet.muPtBinning2D  = [0,20,30,50,100,200,400]
#BTagAndProbeMonitoring.histoPSet.phoPtBinning2D = [0,20,30,50,100,200,400]
# HT and phi binning 2D
BTagAndProbeMonitoring.histoPSet.HTBinning2D  = [0,20,40,70,100,150,200,400,700]
BTagAndProbeMonitoring.histoPSet.phiBinning2D = [-3.1416,-1.8849,-0.6283,0.6283,1.8849,3.1416]

BTagAndProbeMonitoring.enablePhotonPlot = False
BTagAndProbeMonitoring.enableMETPlot = False

BTagAndProbeMonitoring.applyLeptonPVcuts = False
BTagAndProbeMonitoring.leptonPVcuts.dxy = 9999.
BTagAndProbeMonitoring.leptonPVcuts.dz  = 9999.

BTagAndProbeMonitoring.met       = "pfMetEI" # pfMet
BTagAndProbeMonitoring.jets      = "ak4PFJetsCHS" # ak4PFJets, ak4PFJetsCHS, pfJetsEI
BTagAndProbeMonitoring.electrons = "gedGsfElectrons" # while pfIsolatedElectronsEI are reco::PFCandidate !
BTagAndProbeMonitoring.elecID    = "egmGsfElectronIDsForDQM:cutBasedElectronID-Fall17-94X-V1-tight" #Electron ID
BTagAndProbeMonitoring.muons     = "muons" # while pfIsolatedMuonsEI are reco::PFCandidate !
#BTagAndProbeMonitoring.photons   = "photons" # reco::Photon
BTagAndProbeMonitoring.vertices  = "offlinePrimaryVertices"

BTagAndProbeMonitoring.btagAlgos = ['pfDeepCSVJetTags:probb', 'pfDeepCSVJetTags:probbb']
BTagAndProbeMonitoring.workingpoint = 0.8484 # Medium wp

BTagAndProbeMonitoring.HTdefinition = 'pt>30 & abs(eta)<2.5'
BTagAndProbeMonitoring.leptJetDeltaRmin = 0.4
BTagAndProbeMonitoring.bJetMuDeltaRmax  = 9999.
BTagAndProbeMonitoring.bJetDeltaEtaMax  = 9999.

BTagAndProbeMonitoring.numGenericTriggerEventPSet.andOr         = False
BTagAndProbeMonitoring.numGenericTriggerEventPSet.andOrHlt      = True # True:=OR; False:=AND
BTagAndProbeMonitoring.numGenericTriggerEventPSet.hltInputTag   = "TriggerResults::HLT"
BTagAndProbeMonitoring.numGenericTriggerEventPSet.errorReplyHlt = False
BTagAndProbeMonitoring.numGenericTriggerEventPSet.verbosityLevel = 0

BTagAndProbeMonitoring.denGenericTriggerEventPSet.andOr         = False
BTagAndProbeMonitoring.denGenericTriggerEventPSet.andOrHlt      = True # True:=OR; False:=AND
BTagAndProbeMonitoring.denGenericTriggerEventPSet.hltInputTag   = "TriggerResults::HLT"
BTagAndProbeMonitoring.denGenericTriggerEventPSet.errorReplyHlt = False
BTagAndProbeMonitoring.denGenericTriggerEventPSet.dcsInputTag   = "scalersRawToDigi"
BTagAndProbeMonitoring.denGenericTriggerEventPSet.dcsPartitions = [24, 25, 26, 27, 28, 29] # 24-27: strip, 28-29: pixel, we should add all other detectors !
BTagAndProbeMonitoring.denGenericTriggerEventPSet.andOrDcs      = False
BTagAndProbeMonitoring.denGenericTriggerEventPSet.errorReplyDcs = True
BTagAndProbeMonitoring.denGenericTriggerEventPSet.verbosityLevel = 0

BTagAndProbeMonitoring.MHTdefinition = 'pt>30 & abs(eta)<2.5'
BTagAndProbeMonitoring.MHTcut = -1
BTagAndProbeMonitoring.invMassUppercut = -1.0
BTagAndProbeMonitoring.invMassLowercut = -1.0
BTagAndProbeMonitoring.oppositeSignMuons = False
BTagAndProbeMonitoring.invMassCutInAllMuPairs = False
