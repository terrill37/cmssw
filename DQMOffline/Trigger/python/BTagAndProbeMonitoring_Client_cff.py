import FWCore.ParameterSet.Config as cms

from DQMServices.Core.DQMEDHarvester import DQMEDHarvester

BTagAndProbe_TnP = DQMEDHarvester("DQMGenericClient", #FIXME
    subDirs        = cms.untracked.vstring("HLT/BTV/TnP/*"),
    verbose        = cms.untracked.uint32(0), # Set to 2 for all messages
    resolution     = cms.vstring(),
    efficiency     = cms.vstring(
        "jet_eta 'BTag and Probe jet eta efficiency; jet #eta; efficiency' jet_eta_numerator jet_eta_denominator",
        "jet_pt 'BTag and Probe jet pt efficiency; jet pt; efficiency' jet_pt_numerator jet_pt_denominator",
    ),
)

BTagAndProbe_eleHT = DQMEDHarvester("DQMGenericClient", #FIXME
    subDirs        = cms.untracked.vstring("HLT/BTV/EleHT/*"),
    verbose        = cms.untracked.uint32(0),
    resolution     = cms.vstring(),
    efficiency     = cms.vstring(
        "jet_eta 'BTag and Probe jet eta efficiency; jet #eta; efficiency' jet_eta_numerator jet_eta_denominator",
        "jet_pt 'BTag and Probe jet pt efficiency; jet pt; efficiency' jet_pt_numerator jet_pt_denominator",
    ),
)


BTagAndProbeClient = cms.Sequence( #FIXME
    BTagAndProbe_TnP
  + BTagAndProbe_eleHT
  #+ BTagAndProbe_singleMu
  #+ BTagAndProbe_diElec
  #+ BTagAndProbe_diMu
  #+ BTagAndProbe_ElecMu
  #+ BTagAndProbe_fullyhadronic_Reference
  #+ BTagAndProbe_fullyhadronic_DoubleBTag
  #+ BTagAndProbe_fullyhadronic_SingleBTag
  #+ BTagAndProbe_fullyhadronic_TripleBTag
)
