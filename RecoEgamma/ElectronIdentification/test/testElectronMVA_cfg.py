import FWCore.ParameterSet.Config as cms
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
from Configuration.AlCa.GlobalTag import GlobalTag
from RecoEgamma.EgammaElectronProducers.lowPtGsfElectronID_cfi import lowPtGsfElectronID
from RecoEgamma.EgammaElectronProducers.lowPtGsfElectrons_cfi import lowPtRegressionModifier

process = cms.Process("ElectronMVANtuplizer")

process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")

process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_mc', '')

# File with the ID variables to include in the Ntuplizer
mvaVariablesFile = "RecoEgamma/ElectronIdentification/data/ElectronIDVariables.txt"

outputFile = "electron_ntuple.root"

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
         #'/store/mc/Run3Summer19MiniAOD/DYJets_incl_MLL-50_TuneCP5_14TeV-madgraphMLM-pythia8/MINIAODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v1/270000/670DBBD9-A15B-BF4F-930B-AB4A1EADB2A0.root'
         #'/store/mc/RunIIFall17MiniAOD/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/RECOSIMstep_94X_mc2017_realistic_v10-v1/00000/0293A280-B5F3-E711-8303-3417EBE33927.root'
         'file:/uscms/home/wterrill/nobackup/retraining/CMSSW_14_1_7/src/RecoEgamma/ElectronIdentification/test/JPsiToEE_pth0to10_MiniAOD.root'
    )
)

useAOD = False

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
# turn on VID producer, indicate data format  to be
# DataFormat.AOD or DataFormat.MiniAOD, as appropriate
if useAOD == True :
    dataFormat = DataFormat.AOD
    input_tags = dict(
        src = cms.InputTag("gedGsfElectrons"),
        vertices = cms.InputTag("offlinePrimaryVertices"),
        pileup = cms.InputTag("addPileupInfo"),
        genParticles = cms.InputTag("genParticles"),
        ebReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
        eeReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEE"),
    )
else :
    dataFormat = DataFormat.MiniAOD
    input_tags = dict()

switchOnVIDElectronIdProducer(process, dataFormat)

# define which IDs we want to produce
my_id_modules = [
        'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_GeneralPurpose_V1_cff',
        'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_HZZ_V1_cff',
        'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_noIso_V1_cff',
        'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_iso_V1_cff',
        'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_noIso_V2_cff',
        'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_iso_V2_cff',
        #'RecoEgamma.ElectronIdentification.Identification.LowPtElectrons.LowPtElectrons_ID_2021May17.root',
        #'RecoEgamma.EgammaElectronProducers.lowPtGsfElectrons_cfi',
                 ]

#add them to the VID producer
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)

process.ntuplizer = cms.EDAnalyzer('ElectronMVANtuplizer',
        #
        eleMVAs             = cms.vstring(
                                           #"lowPtGsfElectronID:2019Aug07",
                                           #"lowPtGsfElectronIDExtra:2020Sept15",
                                           #"lowPtGsfElectronID:2020Nov28",
                                           #"lowPtGsfElectronIDExtra:2021May17"
                                           #"egmGsfElectronIDs:mvaEleID-Fall17-iso-V1-wpLoose",
                                          ),
        eleMVALabels        = cms.vstring(
                                           #"Aug201907",
                                           #"Sept202015",
                                           #"Nov202018",
                                           #"May202117",
                                           #"Fall17isoV1wpLoose",
                                          ),
        eleMVAValMaps        = cms.vstring(
                                           #"electronMVAValueMapProducer:ElectronMVAEstimatorRun2Fall17NoIsoV2RawValues",
                                           ),
        eleMVAValMapLabels   = cms.vstring(
                                           #"Fall17NoIsoV2Vals",
                                           ),
        eleMVACats           = cms.vstring(
                                           #"electronMVAValueMapProducer:ElectronMVAEstimatorRun2Fall17NoIsoV2Categories",
                                           ),
        eleMVACatLabels      = cms.vstring(
                                           #"EleMVACats",
                                           ),
        #
        variableDefinition   = cms.string(mvaVariablesFile),
        ptThreshold = cms.double(0.0),
        #
        doEnergyMatrix = cms.bool(False), # disabled by default due to large size
        energyMatrixSize = cms.int32(2), # corresponding to 5x5
        src = cms.InputTag("slimmedLowPtElectrons"),
        isMC = cms.bool(True),
        #
        **input_tags
        )
"""
The energy matrix is for ecal driven electrons the n x n of raw
rec-hit energies around the seed crystal.

The size of the energy matrix is controlled with the parameter
"energyMatrixSize", which controlls the extension of crystals in each
direction away from the seed, in other words n = 2 * energyMatrixSize + 1.

The energy matrix gets saved as a vector but you can easily unroll it
to a two dimensional numpy array later, for example like that:

>>> import uproot
>>> import numpy as np
>>> import matplotlib.pyplot as plt

>>> tree = uproot.open("electron_ntuple.root")["ntuplizer/tree"]
>>> n = 5

>>> for a in tree.array("ele_energyMatrix"):
>>>     a = a.reshape((n,n))
>>>     plt.imshow(np.log10(a))
>>>     plt.colorbar()
>>>     plt.show()
"""

process.TFileService = cms.Service("TFileService", fileName = cms.string(outputFile))

process.p = cms.Path(process.egmGsfElectronIDSequence * process.ntuplizer)
