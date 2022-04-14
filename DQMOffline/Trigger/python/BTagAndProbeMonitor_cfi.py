import FWCore.ParameterSet.Config as cms

from DQMOffline.Trigger.BTagAndProbeMonitoring_cfi import BTagAndProbeMonitoring #FIXME

BTagAndProbeMonitoring = BTagAndProbeMonitoring.clone() #FIXME

BTagAndProbeMonitoring.FolderName = 'HLT/BTV/default/'
BTagAndProbeMonitoring.requireValidHLTPaths = True

BTagAndProbeMonitoring.applyLeptonPVcuts = False
BTagAndProbeMonitoring.leptonPVcuts.dxy = 9999.
BTagAndProbeMonitoring.leptonPVcuts.dz  = 9999.

#BTagAndProbeMonitoring.met       = "pfMetEI" # pfMet
BTagAndProbeMonitoring.jets      = "ak4PFJetsCHS" # ak4PFJets, ak4PFJetsCHS, pfJetsEI
BTagAndProbeMonitoring.electrons = "gedGsfElectrons" # while pfIsolatedElectronsEI are reco::PFCandidate !
BTagAndProbeMonitoring.elecID    = "egmGsfElectronIDsForDQM:cutBasedElectronID-Fall17-94X-V1-tight" #Electron ID
BTagAndProbeMonitoring.muons     = "muons" # while pfIsolatedMuonsEI are reco::PFCandidate !
#BTagAndProbeMonitoring.photons   = "photons" # reco::Photon
BTagAndProbeMonitoring.vertices  = "offlinePrimaryVertices"

BTagAndProbeMonitoring.btagAlgos = ['pfDeepCSVJetTags:probb', 'pfDeepCSVJetTags:probbb']
BTagAndProbeMonitoring.workingpoint = 0.8484 # Medium wp

#BTagAndProbeMonitoring.HTdefinition = 'pt>30 & abs(eta)<2.5'
BTagAndProbeMonitoring.leptJetDeltaRmin = 0.4
#BTagAndProbeMonitoring.bJetMuDeltaRmax  = 9999.
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

#BTagAndProbeMonitoring.debug = False
