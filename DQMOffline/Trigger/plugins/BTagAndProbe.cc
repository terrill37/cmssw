#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/DQMEDAnalyzer.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/Registry.h"
#include "FWCore/Utilities/interface/transform.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "CommonTools/Utils/interface/StringCutObjectSelector.h"
#include "CommonTools/TriggerUtils/interface/GenericTriggerEventFlag.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETCollection.h"
#include "DQMOffline/Trigger/plugins/TriggerDQMBase.h"

//Tagging variables
#include "DataFormats/BTauReco/interface/ShallowTagInfo.h"

#include <string>
//#include <TH1F.h>
#include <vector>
#include <memory>
#include <map>

class BTagAndProbe : public DQMEDAnalyzer, public TriggerDQMBase {
public:
  typedef dqm::reco::MonitorElement MonitorElement;
  typedef dqm::reco::DQMStore DQMStore;

  BTagAndProbe(const edm::ParameterSet&);
  ~BTagAndProbe() throw() override;
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

protected:
  void bookHistograms(DQMStore::IBooker&, edm::Run const&, edm::EventSetup const&) override;
  void analyze(edm::Event const& iEvent, edm::EventSetup const& iSetup) override;
  //void fillCutFlow(std::string cut) override;
  //void AddCut(std::string) override;

  struct JetRefCompare {
    inline bool operator()(const edm::RefToBase<reco::Jet>& j1, const edm::RefToBase<reco::Jet>& j2) const {
      return (j1.id() < j2.id()) || ((j1.id() == j2.id()) && (j1.key() < j2.key()));
    }
  };
  typedef std::map<edm::RefToBase<reco::Jet>, float, JetRefCompare> JetTagMap;

private:
  const std::string folderName_;

  const bool requireValidHLTPaths_;
  bool hltPathsAreValid_;

  edm::EDGetTokenT<reco::VertexCollection> vtxToken_;
  edm::EDGetTokenT<reco::MuonCollection> muoToken_;
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  edm::EDGetTokenT<edm::ValueMap<bool> > elecIDToken_;
  edm::EDGetTokenT<reco::PFJetCollection> jetToken_;
  std::vector<edm::EDGetTokenT<reco::JetTagCollection> > jetTagTokens_;
  edm::EDGetTokenT<reco::PFMETCollection> metToken_;

  //Tag info
  edm::EDGetTokenT<std::vector<reco::ShallowTagInfo> > shallowTagInfosToken_;

  struct PVcut {
    double dxy;
    double dz;
  };

  // for the tag and probe
  MonitorElement* h_nElectrons1 = nullptr;
  MonitorElement* h_nElectrons2 = nullptr;
  MonitorElement* h_nElectrons3 = nullptr;
  MonitorElement* h_nElectrons4 = nullptr;
  MonitorElement* h_nElectrons5 = nullptr;
  MonitorElement* h_nElectrons6 = nullptr;
  MonitorElement* h_nElectrons7 = nullptr;

  MonitorElement* h_nMuons1 = nullptr;
  MonitorElement* h_nMuons2 = nullptr;
  MonitorElement* h_nMuons3 = nullptr;
  MonitorElement* h_nMuons4 = nullptr;
  MonitorElement* h_nMuons5 = nullptr;
  MonitorElement* h_nMuons6 = nullptr;
  //MonitorElement* h_nMuons7 = nullptr;

  MonitorElement* h_nJets = nullptr;
  MonitorElement* h_btagVal = nullptr;
  MonitorElement* h_btagVal2 = nullptr;
  MonitorElement* h_btagVal_pp = nullptr;
  MonitorElement* h_btagVal_pf = nullptr;
  MonitorElement* h_btagVal_pa = nullptr;

  MonitorElement* h_nJets1 = nullptr;
  MonitorElement* h_nJets2 = nullptr;
  MonitorElement* h_nJets3 = nullptr;
  MonitorElement* h_nJets4 = nullptr;
  MonitorElement* h_nJets5 = nullptr;
  MonitorElement* h_nJets6 = nullptr;
  MonitorElement* h_nJets7 = nullptr;
  MonitorElement* h_nJets8 = nullptr;
  MonitorElement* h_nJets9 = nullptr;
  MonitorElement* h_nJets10 = nullptr;
  MonitorElement* h_nJets11 = nullptr;
  MonitorElement* h_nJets12 = nullptr;
  
  //muon pt
  MonitorElement* h_Muons1_pt = nullptr;
  MonitorElement* h_Muons2_pt = nullptr;
  MonitorElement* h_Muons3_pt = nullptr;
  MonitorElement* h_Muons4_pt = nullptr;
  MonitorElement* h_Muons5_pt = nullptr;
  MonitorElement* h_Muons6_pt = nullptr;
  
  //muon eta
  MonitorElement* h_Muons1_eta = nullptr;
  MonitorElement* h_Muons2_eta = nullptr;
  MonitorElement* h_Muons3_eta = nullptr;
  MonitorElement* h_Muons4_eta = nullptr;
  MonitorElement* h_Muons5_eta = nullptr;
  MonitorElement* h_Muons6_eta = nullptr;
  
  //electron pt
  MonitorElement* h_Electrons1_pt = nullptr;
  MonitorElement* h_Electrons2_pt = nullptr;
  MonitorElement* h_Electrons3_pt = nullptr;
  MonitorElement* h_Electrons4_pt = nullptr;

  //electron eta
  MonitorElement* h_Electrons1_eta = nullptr;
  MonitorElement* h_Electrons2_eta = nullptr;
  MonitorElement* h_Electrons3_eta = nullptr;
  MonitorElement* h_Electrons4_eta = nullptr;

  MonitorElement* cutFlow = nullptr;
  //TH1F* cutFlow;

  // new for tnp
  ObjME jetNSecondaryVertices_;
  ObjME jet_pt_;
  ObjME jet_eta_;
  ObjME trackSumJetEtRatio_;
  ObjME trackSip2dValAboveCharm_;
  ObjME trackSip2dSigAboveCharm_;
  ObjME trackSip3dValAboveCharm_;
  ObjME trackSip3dSigAboveCharm_;
  ObjME jetNTracksEtaRel_;
  ObjME jetNSelectedTracks_;
  ObjME vertexCategory_;
  ObjME trackSumJetDeltaR_;

  ObjME trackJetDistVal_;
  ObjME trackPtRel_;
  ObjME trackDeltaR_;
  ObjME trackPtRatio_;
  ObjME trackSip3dSig_;
  ObjME trackSip2dSig_;
  ObjME trackDecayLenVal_;
  ObjME trackEtaRek_;

  ObjME vertexMass_;
  ObjME vertexNTracks_;
  ObjME vertexEnergyRatio_;
  ObjME vertexJetDeltaR_;
  ObjME flightDistance2dVal_;
  ObjME flightDistance3dVal_;
  ObjME flightDistance2dSig_;
  ObjME flightDistance3dSig_;

  ObjME elePt_jetPt_;
  ObjME elePt_eventHT_;

  ObjME ele1Pt_ele2Pt_;
  ObjME ele1Eta_ele2Eta_;
  ObjME mu1Pt_mu2Pt_;
  ObjME mu1Eta_mu2Eta_;
  ObjME elePt_muPt_;
  ObjME eleEta_muEta_;
  ObjME invMass_mumu_;
  ObjME eventMHT_;
  ObjME invMass_mumu_variableBinning_;
  ObjME eventMHT_variableBinning_;
  //ObjME muPt_phoPt_;
  //ObjME muEta_phoEta_;

  ObjME DeltaR_jet_Mu_;

  ObjME eventHT_;
  ObjME eventHT_variableBinning_;

  std::vector<ObjME> muPhi_;
  std::vector<ObjME> muEta_;
  std::vector<ObjME> muPt_;

  std::vector<ObjME> elePhi_;
  std::vector<ObjME> eleEta_;
  std::vector<ObjME> elePt_;

  std::vector<ObjME> jetPhi_;
  std::vector<ObjME> jetEta_;
  std::vector<ObjME> jetPt_;

  // 2D distributions
  std::vector<ObjME> jetPtEta_;
  std::vector<ObjME> jetEtaPhi_;

  std::vector<ObjME> elePtEta_;
  std::vector<ObjME> eleEtaPhi_;

  std::vector<ObjME> muPtEta_;
  std::vector<ObjME> muEtaPhi_;

  std::unique_ptr<GenericTriggerEventFlag> num_genTriggerEventFlag_;
  std::unique_ptr<GenericTriggerEventFlag> den_genTriggerEventFlag_;

  //StringCutObjectSelector<reco::MET, true> metSelection_;
  StringCutObjectSelector<reco::PFJet, true> jetSelection_;
  StringCutObjectSelector<reco::GsfElectron, true> eleSelection_;
  StringCutObjectSelector<reco::Muon, true> muoSelection_;
  //StringCutObjectSelector<reco::Photon, true> phoSelection_;
  //StringCutObjectSelector<reco::PFJet, true> HTdefinition_;

  StringCutObjectSelector<reco::Vertex, true> vtxSelection_;

  StringCutObjectSelector<reco::Jet, true> bjetSelection_;

  unsigned int njets_;
  unsigned int nelectrons_;
  unsigned int nmuons_;
  //unsigned int nphotons_;
  double leptJetDeltaRmin_;
  //double bJetMuDeltaRmax_;
  double bJetDeltaEtaMax_;
  //double HTcut_;
  unsigned int nbjets_;
  double workingpoint_;
  std::string btagalgoName_;
  PVcut lepPVcuts_;
  bool applyLeptonPVcuts_;

  bool applyMETcut_ = false;

  //double invMassUppercut_;
  //double invMassLowercut_;
  //bool opsign_;
  //StringCutObjectSelector<reco::PFJet, true> MHTdefinition_;
  //double MHTcut_;

  //bool invMassCutInAllMuPairs_;

  //bool enablePhotonPlot_;
  //bool enableMETPlot_;
};

BTagAndProbe::BTagAndProbe(const edm::ParameterSet& iConfig)
    : folderName_(iConfig.getParameter<std::string>("FolderName")),
      requireValidHLTPaths_(iConfig.getParameter<bool>("requireValidHLTPaths")),
      hltPathsAreValid_(false),
      vtxToken_(mayConsume<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices"))),
      muoToken_(mayConsume<reco::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
      eleToken_(mayConsume<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
      elecIDToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("elecID"))),
      jetToken_(mayConsume<reco::PFJetCollection>(iConfig.getParameter<edm::InputTag>("jets"))),
      jetTagTokens_(
          edm::vector_transform(iConfig.getParameter<std::vector<edm::InputTag> >("btagAlgos"),
                                [this](edm::InputTag const& tag) { return mayConsume<reco::JetTagCollection>(tag); })),
      metToken_(consumes<reco::PFMETCollection>(iConfig.getParameter<edm::InputTag>("met"))),
      shallowTagInfosToken_(
        consumes<std::vector<reco::ShallowTagInfo> >(edm::InputTag("hltDeepCombinedSecondaryVertexBJetTagsInfos"))),
      num_genTriggerEventFlag_(new GenericTriggerEventFlag(
          iConfig.getParameter<edm::ParameterSet>("numGenericTriggerEventPSet"), consumesCollector(), *this)),
      den_genTriggerEventFlag_(new GenericTriggerEventFlag(
          iConfig.getParameter<edm::ParameterSet>("denGenericTriggerEventPSet"), consumesCollector(), *this)),
      jetSelection_(iConfig.getParameter<std::string>("jetSelection")),
      eleSelection_(iConfig.getParameter<std::string>("eleSelection")),
      muoSelection_(iConfig.getParameter<std::string>("muoSelection")),
      vtxSelection_(iConfig.getParameter<std::string>("vertexSelection")),
      bjetSelection_(iConfig.getParameter<std::string>("bjetSelection")),
      njets_(iConfig.getParameter<unsigned int>("njets")),
      nelectrons_(iConfig.getParameter<unsigned int>("nelectrons")),
      nmuons_(iConfig.getParameter<unsigned int>("nmuons")),
      leptJetDeltaRmin_(iConfig.getParameter<double>("leptJetDeltaRmin")),
      bJetDeltaEtaMax_(iConfig.getParameter<double>("bJetDeltaEtaMax")),
      nbjets_(iConfig.getParameter<unsigned int>("nbjets")),
      workingpoint_(iConfig.getParameter<double>("workingpoint")),
      applyLeptonPVcuts_(iConfig.getParameter<bool>("applyLeptonPVcuts")){
     
      
  ObjME empty;

  muPhi_ = std::vector<ObjME>(nmuons_, empty);
  muEta_ = std::vector<ObjME>(nmuons_, empty);
  muPt_ = std::vector<ObjME>(nmuons_, empty);
  muPtEta_ = std::vector<ObjME>(nmuons_, empty);
  muEtaPhi_ = std::vector<ObjME>(nmuons_, empty);

  elePhi_ = std::vector<ObjME>(nelectrons_, empty);
  eleEta_ = std::vector<ObjME>(nelectrons_, empty);
  elePt_ = std::vector<ObjME>(nelectrons_, empty);
  elePtEta_ = std::vector<ObjME>(nelectrons_, empty);
  eleEtaPhi_ = std::vector<ObjME>(nelectrons_, empty);

  jetPhi_ = std::vector<ObjME>(njets_, empty);
  jetEta_ = std::vector<ObjME>(njets_, empty);
  jetPt_ = std::vector<ObjME>(njets_, empty);
  jetPtEta_ = std::vector<ObjME>(njets_, empty);
  jetEtaPhi_ = std::vector<ObjME>(njets_, empty);

  //Suvankar
  lepPVcuts_.dxy = (iConfig.getParameter<edm::ParameterSet>("leptonPVcuts")).getParameter<double>("dxy");
  lepPVcuts_.dz = (iConfig.getParameter<edm::ParameterSet>("leptonPVcuts")).getParameter<double>("dz");
}

BTagAndProbe::~BTagAndProbe() throw() {
  if (num_genTriggerEventFlag_)
    num_genTriggerEventFlag_.reset();
  if (den_genTriggerEventFlag_)
    den_genTriggerEventFlag_.reset();
}

void BTagAndProbe::bookHistograms(DQMStore::IBooker& ibooker, edm::Run const& iRun, edm::EventSetup const& iSetup) {
  // Initialize the GenericTriggerEventFlag
  if (num_genTriggerEventFlag_ && num_genTriggerEventFlag_->on())
    num_genTriggerEventFlag_->initRun(iRun, iSetup);
  if (den_genTriggerEventFlag_ && den_genTriggerEventFlag_->on())
    den_genTriggerEventFlag_->initRun(iRun, iSetup);

  // check if every HLT path specified in numerator and denominator has a valid match in the HLT Menu
  hltPathsAreValid_ = (num_genTriggerEventFlag_ && den_genTriggerEventFlag_ && num_genTriggerEventFlag_->on() &&
                       den_genTriggerEventFlag_->on() && num_genTriggerEventFlag_->allHLTPathsAreValid() &&
                       den_genTriggerEventFlag_->allHLTPathsAreValid());

  // if valid HLT paths are required,
  // create DQM outputs only if all paths are valid
  if (requireValidHLTPaths_ && (!hltPathsAreValid_)) {
    return;
  }

  std::string histname, histtitle;
  std::string title;
  std::string currentFolder = folderName_;
  ibooker.setCurrentFolder(currentFolder);
    
  histname = "nElectrons1";
  title = "number of electrons1";
  h_nElectrons1 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10);
  
  histname = "nElectrons2";
  title = "number of electrons2";
  h_nElectrons2 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10);
  
  histname = "nElectrons3";
  title = "number of electrons3";
  h_nElectrons3 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10);
  
  histname = "nElectrons4";
  title = "number of electrons4";
  h_nElectrons4 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 
  
  histname = "nElectrons5";
  title = "number of electrons5";
  h_nElectrons5 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10);
  
  histname = "nElectrons6";
  title = "number of electrons6";
  h_nElectrons6 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10);
  
  histname = "nElectrons7";
  title = "number of electrons7";
  h_nElectrons7 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 

  histname = "nMuons1";
  title = "number of muons1";
  h_nMuons1 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 
 
  histname = "nMuons2";
  title = "number of muons2";
  h_nMuons2 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 
  
  histname = "nMuons3";
  title = "number of muons3";
  h_nMuons3 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 
  
  histname = "nMuons4";
  title = "number of muons4";
  h_nMuons4 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 
  
  histname = "nMuons5";
  title = "number of muons5";
  h_nMuons5 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 
  
  histname = "nMuons6";
  title = "number of muons6";
  h_nMuons6 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10); 
  
  //muon pt
  histname = "Muons1_pt";
  title = "muons1 pt";
  h_Muons1_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 100); 
 
  histname = "Muons2_pt";
  title = "muons2 pt";
  h_Muons2_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 100); 
  
  histname = "Muons3_pt";
  title = "muons3 pt";
  h_Muons3_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 100); 
  
  histname = "Muons4_pt";
  title = "muons4 pt";
  h_Muons4_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 50); 
  
  histname = "Muons5_pt";
  title = "muons5 pt";
  h_Muons5_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 50); 
  
  histname = "Muons6_pt";
  title = "muons6 pt";
  h_Muons6_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 50); 
  
  //muon eta
  histname = "Muons1_eta";
  title = "muons1 eta";
  h_Muons1_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -5, 5); 
 
  histname = "Muons2_eta";
  title = "muons2 eta";
  h_Muons2_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -5, 5); 
  
  histname = "Muons3_eta";
  title = "muons3 eta";
  h_Muons3_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -5, 5); 
  
  histname = "Muons4_eta";
  title = "muons4 eta";
  h_Muons4_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -2.50, 2.50); 
  
  histname = "Muons5_eta";
  title = "muons5 eta";
  h_Muons5_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -2.50, 2.50); 
  
  histname = "Muons6_eta";
  title = "muons6 eta";
  h_Muons6_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -2.50, 2.50);
  
  //electron pt
  histname = "Electrons1_pt";
  title = "electrons1 pt";
  h_Electrons1_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 100); 
 
  histname = "Electrons2_pt";
  title = "Electrons2 pt";
  h_Electrons2_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 100); 
  
  histname = "Electrons3_pt";
  title = "Electrons3 pt";
  h_Electrons3_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 100); 
  
  histname = "Electrons4_pt";
  title = "Electrons4 pt";
  h_Electrons4_pt = ibooker.book1D(histname.c_str(), title.c_str(), 50, 0, 100); 
 

  //electron eta
  histname = "Electrons1_eta";
  title = "Electrons1 eta";
  h_Electrons1_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -2.50, 2.50); 
 
  histname = "Electrons2_eta";
  title = "Electrons2 eta";
  h_Electrons2_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -2.50, 2.50); 
  
  histname = "Electrons3_eta";
  title = "Electrons3 eta";
  h_Electrons3_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -2.50, 2.50);  

  histname = "Electrons4_eta";
  title = "Electrons4 eta";
  h_Electrons4_eta = ibooker.book1D(histname.c_str(), title.c_str(), 10, -2.50, 2.50);  


  //nJets
  histname = "nJets1";
  title = "number of jets1";
  h_nJets1 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
   
  histname = "nJets2";
  title = "number of jets2";
  h_nJets2 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
   
  histname = "nJets3";
  title = "number of jets3";
  h_nJets3 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
   
  histname = "nJets4";
  title = "number of jets4";
  h_nJets4 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
   
  histname = "nJets5";
  title = "number of jets5";
  h_nJets5 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);

  histname = "nJets6";
  title = "number of jets6";
  h_nJets6 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);

  histname = "nJets7";
  title = "number of jets7";
  h_nJets7 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
  
  histname = "nJets8";
  title = "number of jets8";
  h_nJets8 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
  
  histname = "nJets9";
  title = "number of jets9";
  h_nJets9 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
  
  histname = "nJets10";
  title = "number of jets10";
  h_nJets10 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
  
  histname = "nJets11";
  title = "number of jets11";
  h_nJets11 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);
  
  histname = "nJets12";
  title = "number of jets12";
  h_nJets12 = ibooker.book1D(histname.c_str(), title.c_str(), 20, 0, 20);

  histname = "btagVal";
  title = "btagVal";
  h_btagVal = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 1);
  
  histname = "btagVal2";
  title = "btagVal";
  h_btagVal2 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 1);
 
  histname = "btagVal_probe_pass";
  title = "btagVal";
  h_btagVal_pp = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 1);
 
  histname = "btagVal_probe_fail";
  title = "btagVal";
  h_btagVal_pf = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 1);
  
  histname = "btagVal_probe_all";
  title = "btagVal";
  h_btagVal_pa = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 1);

  histname = "cutFlow";
  title = "cutFlow";
  cutFlow = ibooker.book1D(histname.c_str(), title.c_str(), 20, 1, 21);
  cutFlow->setBinLabel(1, "all");

  histname = "jetNSecondaryVertices";
  title = "jetNSecondaryVertices";
  bookME(ibooker,
         jetNSecondaryVertices_,
         histname, title, 
         10, -0.5, 9.5);
  setMETitle(jetNSecondaryVertices_, "jetNSecondaryVertices", "Entries");

  histname = "jet_pt";
  title = "jet p_{T}";
  bookME(ibooker,
         jet_pt_,
         histname, title,
         50, -0.1, 200.);
  setMETitle(jet_pt_, "jet pt", "Entries");

  histname = "jet_eta";
  title = "jet #eta";
  bookME(ibooker,
         jet_eta_,
         histname, title,
         20, -2.5, 2.5);
  setMETitle(jet_eta_, "#eta", "Entries");

  histname = "nJets6";
  title = "number of jets6";
  h_nJets6 = ibooker.book1D(histname.c_str(), title.c_str(), 10, 0, 10);

}

//void BTagAndProbe::fillCutFlow(std::string cut){
//}

//void BTagAndProbe::AddCut(std::string cut){
//}

void BTagAndProbe::analyze(edm::Event const& iEvent, edm::EventSetup const& iSetup) {
  //vector definitions
  std::vector<reco::GsfElectron> electrons;
  std::vector<reco::Muon> muons;
  
  //clear vectors
  electrons.clear();
  muons.clear();
 
  //jets map definition
  // map of Jet,btagValues (for all jets passing bJetSelection_)
  //  - btagValue of each jet is calculated as sum of values from InputTags in jetTagTokens_
  JetTagMap allJetBTagVals;
  
  JetTagMap bjets;
  
  allJetBTagVals.clear();
  bjets.clear();
  
  //cout<<"electrons size initial: "<<electrons.size()<<" muons size initial: "<<muons.size()<<endl;

  int cutFlowStatus = 1;
  cutFlow->Fill(cutFlowStatus);
  
  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "allValid");
  // if valid HLT paths are required,
  // analyze event only if all paths are valid
  //std::cout<<"requireValidPaths: "<<requireValidHLTPaths_<<" hltPathsAreValid: "<<hltPathsAreValid_<<endl;
  if (requireValidHLTPaths_ && (!hltPathsAreValid_)) return;
  
  // electron Handle valid
  edm::Handle<edm::View<reco::GsfElectron> > eleHandle;
  iEvent.getByToken(eleToken_, eleHandle);
  if (!eleHandle.isValid() && nelectrons_ > 0) {
    edm::LogWarning("BTagAndProbe") << "Electron handle not valid \n";
    return;
  }
  
  //electron ID Handle valid
  edm::Handle<edm::ValueMap<bool> > eleIDHandle;
  iEvent.getByToken(elecIDToken_, eleIDHandle);
  if (!eleIDHandle.isValid() && nelectrons_ > 0) {
    edm::LogWarning("BTagAndProbe") << "Electron ID handle not valid \n";
    return;
  }
  
  //muon handle valid
  edm::Handle<reco::MuonCollection> muoHandle;
  iEvent.getByToken(muoToken_, muoHandle);
  if (!muoHandle.isValid() && nmuons_ > 0) {
    edm::LogWarning("BTagAndProbe") << "Muon handle not valid \n";
    return;
  }
  
  for (const auto& jetTagToken : jetTagTokens_) {
    edm::Handle<reco::JetTagCollection> bjetHandle;
    iEvent.getByToken(jetTagToken, bjetHandle);
    if (!bjetHandle.isValid() && nbjets_ > 0) {
      edm::LogWarning("BTagAndProbe") << "B-Jet handle not valid, will skip event \n";
      return;
    }
  }
  
  //tag info
  edm::Handle<std::vector<reco::ShallowTagInfo> > shallowTagInfos;
  iEvent.getByToken(shallowTagInfosToken_, shallowTagInfos);
  if(!shallowTagInfos.isValid()){
    edm::LogWarning("BTagAndProbe") << "shallow tag handle not valid, will skip event \n";
    return;
  }
 
  cutFlow->Fill(cutFlowStatus);

  // Filter out events if Trigger Filtering is requested
  //if (den_genTriggerEventFlag_->on() && !den_genTriggerEventFlag_->accept(iEvent, iSetup)) return; 
  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "passTrigger");
  cutFlow->Fill(cutFlowStatus);

  edm::Handle<reco::VertexCollection> primaryVertices;
  iEvent.getByToken(vtxToken_, primaryVertices);
  //Primary Vertex selection
  const reco::Vertex* pv = nullptr;
  for (auto const& v : *primaryVertices) {
    if (!vtxSelection_(v)) continue;
    pv = &v;
    break;
  }
  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "LeptonPVcuts");
  
  if (applyLeptonPVcuts_ && (pv == nullptr)) {
    edm::LogWarning("BTagAndProbe") << "Invalid handle to reco::VertexCollection, event will be skipped";
    return;
  } 
  cutFlow->Fill(cutFlowStatus);

  unsigned int nElectrons = 0;
  if (nelectrons_ > 0) {
    if (eleHandle->size() < nelectrons_) return; // this is why n_electrons must be at least '1'

    cutFlowStatus++;
    cutFlow->setBinLabel(cutFlowStatus, "elecHandleSize");
    cutFlow->Fill(cutFlowStatus);
    
    h_nElectrons1->Fill(eleHandle->size());
    h_nElectrons2->Fill(eleIDHandle->size());
    //FIXME possibly add eleIDHandle == eleHandle sizes requirement
    //int nElectronHandle=eleHandle->size();
    for (size_t index = 0; index < eleHandle->size(); index++) {
      const auto e = eleHandle->at(index);
      const auto el = eleHandle->ptrAt(index);

      bool pass_id = (*eleIDHandle)[el];
      //pass_id = true;
      
      h_Electrons1_pt->Fill(e.pt());
      h_Electrons1_eta->Fill(e.eta());

      if (eleSelection_(e) && pass_id) {
        //electrons.push_back(e);
      
      
        h_Electrons2_pt->Fill(e.pt());
        h_Electrons2_eta->Fill(e.eta());
           
        if (applyLeptonPVcuts_ && ((std::fabs(e.gsfTrack()->dxy(pv->position())) >= lepPVcuts_.dxy) ||
                                   (std::fabs(e.gsfTrack()->dz(pv->position())) >= lepPVcuts_.dz))) {
          continue;
        }
        electrons.push_back(e);
      
        h_Electrons3_pt->Fill(e.pt());
        h_Electrons3_eta->Fill(e.eta());
      }
    }
    nElectrons = electrons.size();
    h_nElectrons3->Fill(nElectrons);
  }
  //have a debug
  //cout<<"nelectrons_: "<<nelectrons_<<" nElectrons: "<<nElectrons<<endl;
 
  h_nMuons1->Fill(muoHandle->size()); 
  
  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "passMuonSize");
  //cutFlow->Fill(cutFlowStatus);
  
  unsigned int nMuons = 0;
  if (nmuons_ > 0) { // need nmuons_ at least be '1'
    for (auto const& m : *muoHandle) {
      h_Muons1_pt->Fill(m.pt());
      h_Muons1_eta->Fill(m.eta());
      if (muoSelection_(m)) {
        //muons.push_back(m);
      
        
        h_Muons2_pt->Fill(m.pt());
        h_Muons2_eta->Fill(m.eta());

        if (applyLeptonPVcuts_ && ((std::fabs(m.muonBestTrack()->dxy(pv->position())) >= lepPVcuts_.dxy) ||
                                     (std::fabs(m.muonBestTrack()->dz(pv->position())) >= lepPVcuts_.dz))) {
            continue;
        }
        muons.push_back(m);
        
        h_Muons3_pt->Fill(m.pt());
        h_Muons3_eta->Fill(m.eta());
      }
    }
    h_nMuons2->Fill(muons.size());

    nMuons = muons.size();
    if (nMuons < nmuons_) return;
    h_nMuons3->Fill(nMuons);
    cutFlow->Fill(cutFlowStatus);
  }
  
  //std::cout<<"before allJetBTagVals loop"<<endl;
  //for(const auto& x : allJetBTagVals){
  //  std::cout<<"allJetBTagVals: "<< x.first->pt()<<" "<<x.first->eta()<<" "<<x.first->phi() <<": "<< x.second <<endl;
  //}
  //if (nbjets_ > 0) {
  //if (true){  
  // map of Jet,btagValues (for all jets passing bJetSelection_)
  //  - btagValue of each jet is calculated as sum of values from InputTags in jetTagTokens_
  //JetTagMap allJetBTagVals;
  //std::cout<<"nbjets_: "<<nbjets_<<endl;
  int nbjets1=0;
  int nbjets2=0;
  int nbjets3=0;
  
  for (const auto& jetTagToken : jetTagTokens_) {
    edm::Handle<reco::JetTagCollection> bjetHandle;
    iEvent.getByToken(jetTagToken, bjetHandle); 

    const reco::JetTagCollection& bTags = *(bjetHandle.product());
    //int nbjets1=0;
    for (const auto& i_jetTag : bTags) {
      const auto& jetRef = i_jetTag.first; // where jet that is tagged exists
      nbjets1++;
      if (not bjetSelection_(*dynamic_cast<const reco::Jet*>(jetRef.get()))) continue;
      nbjets2++;        
      const auto btagVal = i_jetTag.second; // bTagVal exists
      h_btagVal->Fill(btagVal);

      if (not std::isfinite(btagVal)) continue; // checks bTagVal exists
      nbjets3++;
      if (allJetBTagVals.find(jetRef) != allJetBTagVals.end()) {
        allJetBTagVals.at(jetRef) += btagVal; // add bjet tagVal to map
      } 
      else {
        allJetBTagVals.insert(JetTagMap::value_type(jetRef, btagVal));
      }
    }
  }
  h_nJets1->Fill(nbjets1);
  h_nJets2->Fill(nbjets2);
  h_nJets3->Fill(nbjets3);

  int nbjets4=0;
  int nbjets5=0;
  int nbjets6=0;
  //int nbjets7=0;
  for (const auto& jetBTagVal : allJetBTagVals) {
    /*if (jetBTagVal.second < workingpoint_) { //check if passing btag
      cout<<"working point: "<<workingpoint_<<endl;
      continue;
    }*/
    bool isJetOverlappedWithLepton = false;
    nbjets4++;
    if(nmuons_>0){
      for(auto const& m : muons){
        if(deltaR(*jetBTagVal.first, m) < leptJetDeltaRmin_){
          isJetOverlappedWithLepton = true;
          break;
        }
        h_Muons4_pt->Fill(m.pt());
        h_Muons4_eta->Fill(m.eta());
      }
    }
    if (isJetOverlappedWithLepton) continue;
    nbjets5++;

    isJetOverlappedWithLepton = false;
    if(nelectrons_>0){
      for(auto const& e : electrons){
        if(deltaR(*jetBTagVal.first, e)<leptJetDeltaRmin_){
          isJetOverlappedWithLepton = true;
          break;
        }
      }
    }
    if (isJetOverlappedWithLepton) continue;
    nbjets6++;

    bjets.insert(JetTagMap::value_type(jetBTagVal.first, jetBTagVal.second));
  }
  h_nJets4->Fill(nbjets4);
  h_nJets5->Fill(nbjets5);
  h_nJets6->Fill(nbjets6);

  h_nJets7->Fill(bjets.size());
  h_nElectrons4->Fill(nElectrons);
  h_nMuons3->Fill(nMuons);

  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "tooFewJets");
  if (bjets.size() < nbjets_) return; 
  cutFlow->Fill(cutFlowStatus);
  h_nJets8->Fill(bjets.size());
  
 
  ////if(bjets.size() < 1){ // need at least one bjet in event
  ////  return;
  ////}
  unsigned int nbJets = bjets.size();
  
  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "PassJetDeltaEta");
  if (nbjets_ > 1) {
    double deltaEta = std::abs(bjets.begin()->first->eta() - (++bjets.begin())->first->eta());
    if (deltaEta > bJetDeltaEtaMax_)
      return;
  }
  cutFlow->Fill(cutFlowStatus);
  h_nJets9->Fill(bjets.size()); 

  ////// Event selection
  h_nElectrons5->Fill(nElectrons); //FIXME 
  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "reqNumElectrons");
  if(nElectrons!=nelectrons_) return;
  cutFlow->Fill(cutFlowStatus);
  h_nJets10->Fill(bjets.size());
  h_nElectrons5->Fill(nElectrons);
  h_nMuons4->Fill(nMuons);

  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "reqNumMuons");
  if(nMuons!=nmuons_) return;
  cutFlow->Fill(cutFlowStatus);
  h_nJets11->Fill(bjets.size());
  h_nElectrons6->Fill(nElectrons);
  h_nMuons5->Fill(nMuons);

  cutFlowStatus++;
  cutFlow->setBinLabel(cutFlowStatus, "twoJets");
 
  if(nbJets<2) return;
  
  cutFlow->Fill(cutFlowStatus);
  h_nJets12->Fill(nbJets);
  
  //loop electron, muon distributions
  if(nmuons_>0){
    for(auto const& m : muons){
      h_Muons5_pt->Fill(m.pt());
      h_Muons5_eta->Fill(m.eta());
    } 
  }

  if(nelectrons_>0){
    for(auto const& e : electrons){
      h_Electrons4_pt->Fill(e.pt());
      h_Electrons4_eta->Fill(e.eta());
    }
  }

  h_nElectrons7->Fill(nElectrons); //Fill electron counter
  h_nMuons6->Fill(nMuons); //Fill muon counter

  bool isProbe;
  bool passProbe;
  for(auto& jet1: bjets){
    isProbe = false;
    for(auto& jet2: bjets){
      if(deltaR(*jet1.first,*jet2.first)<0.3) continue; // check if same jet
      if (jet2.second >= workingpoint_){// check if passing btag
        //std::cout<<"working point: "<<workingpoint_<<endl;
        isProbe = true;
        //h_btagVal2->Fill(jet2.second);
        break;
      }  
    }
    
    if(isProbe){
      h_btagVal_pa->Fill(jet1.second);
      passProbe=false;
      
      if(jet1.second>=workingpoint_){
        h_btagVal_pp->Fill(jet1.second);
        passProbe=true;
      }
      else h_btagVal_pf->Fill(jet1.second);

      jet_pt_.fill(passProbe, jet1.first->pt());
      jet_eta_.fill(passProbe, jet1.first->eta());
    
      for(const auto& shallowTagInfo : *shallowTagInfos){
        const auto& tagVars = shallowTagInfo.taggingVariables();
        
        auto jetEta = tagVars.getList(reco::btau::jetEta, false)[0];
        auto jetPhi = tagVars.getList(reco::btau::jetPhi, false)[0];
        auto jetPt  = tagVars.getList(reco::btau::jetPt, false)[0];
        
        //std::cout<<"jet pt: "<<jetPt<<endl;
        //if(deltaR(jet1.first->eta(), jet1.first->phi(), jetEta, jetPhi)>0.1) continue;
        std::cout<<"jetPt: "<<jetPt<<" "<<jet1.first->pt()<<endl;
        std::cout<<"jetEta: "<<jetEta<<" "<<jet1.first->eta()<<endl;
        std::cout<<"jetPhi: "<</*jetPhi<<*/" "<<jet1.first->phi()<<endl;
      }



    } 
    // fill plots for probe
    // jet_pt_.fill(probe_pass, jet1.first->pt()); 
    // jet_eta_.fill(probe_pass, jet1.first->eta());
  }
   
}

void BTagAndProbe::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.add<std::string>("FolderName", "HLT/BTV");

  desc.add<bool>("requireValidHLTPaths", true);

  desc.add<edm::InputTag>("vertices", edm::InputTag("offlinePrimaryVertices"));
  desc.add<edm::InputTag>("muons", edm::InputTag("muons"));
  desc.add<edm::InputTag>("electrons", edm::InputTag("gedGsfElectrons"));
  desc.add<edm::InputTag>("elecID", edm::InputTag("egmGsfElectronIDsForDQM:cutBasedElectronID-Fall17-94X-V1-tight"));
  //desc.add<edm::InputTag>("photons", edm::InputTag("photons"));
  desc.add<edm::InputTag>("jets", edm::InputTag("ak4PFJetsCHS"));
  desc.add<std::vector<edm::InputTag> >(
      "btagAlgos", {edm::InputTag("pfDeepCSVJetTags:probb"), edm::InputTag("pfDeepCSVJetTags:probbb")});
  desc.add<edm::InputTag>("met", edm::InputTag("pfMet"));

  desc.add<std::string>("jetSelection", "pt > 30");
  desc.add<std::string>("eleSelection", "pt > 0 && abs(eta) < 2.5");
  desc.add<std::string>("muoSelection", "pt > 6 && abs(eta) < 2.4");
  desc.add<std::string>("vertexSelection", "!isFake");
  desc.add<std::string>("bjetSelection", "pt > 30");
  desc.add<unsigned int>("njets", 0);
  desc.add<unsigned int>("nelectrons", 0);
  desc.add<unsigned int>("nmuons", 0);
  desc.add<double>("leptJetDeltaRmin", 0);
  desc.add<double>("bJetMuDeltaRmax", 9999.);
  desc.add<double>("bJetDeltaEtaMax", 9999.);

  desc.add<unsigned int>("nbjets", 0);
  desc.add<double>("workingpoint", 0.4941);  // DeepCSV Medium wp
  desc.add<bool>("applyLeptonPVcuts", false);
 
  edm::ParameterSetDescription genericTriggerEventPSet;
  genericTriggerEventPSet.add<bool>("andOr");
  genericTriggerEventPSet.add<edm::InputTag>("dcsInputTag", edm::InputTag("scalersRawToDigi"));
  genericTriggerEventPSet.add<std::vector<int> >("dcsPartitions", {});
  genericTriggerEventPSet.add<bool>("andOrDcs", false);
  genericTriggerEventPSet.add<bool>("errorReplyDcs", true);
  genericTriggerEventPSet.add<std::string>("dbLabel", "");
  genericTriggerEventPSet.add<bool>("andOrHlt", true);
  genericTriggerEventPSet.add<edm::InputTag>("hltInputTag", edm::InputTag("TriggerResults::HLT"));
  genericTriggerEventPSet.add<std::vector<std::string> >("hltPaths", {});
  genericTriggerEventPSet.add<std::string>("hltDBKey", "");
  genericTriggerEventPSet.add<bool>("errorReplyHlt", false);
  genericTriggerEventPSet.add<unsigned int>("verbosityLevel", 1);

  desc.add<edm::ParameterSetDescription>("numGenericTriggerEventPSet", genericTriggerEventPSet);
  desc.add<edm::ParameterSetDescription>("denGenericTriggerEventPSet", genericTriggerEventPSet);

  //edm::ParameterSetDescription histoPSet;
  edm::ParameterSetDescription metPSet;
  edm::ParameterSetDescription phiPSet;
  edm::ParameterSetDescription etaPSet;
  edm::ParameterSetDescription ptPSet;
  edm::ParameterSetDescription htPSet;
  edm::ParameterSetDescription DRPSet;
  edm::ParameterSetDescription csvPSet;
  edm::ParameterSetDescription invMassPSet;
  edm::ParameterSetDescription MHTPSet;
  fillHistoPSetDescription(metPSet);
  fillHistoPSetDescription(phiPSet);
  fillHistoPSetDescription(ptPSet);
  fillHistoPSetDescription(etaPSet);
  fillHistoPSetDescription(htPSet);
  fillHistoPSetDescription(DRPSet);
  fillHistoPSetDescription(csvPSet);
  fillHistoPSetDescription(MHTPSet);
  fillHistoPSetDescription(invMassPSet);

  std::vector<double> bins = {0.,   20.,  40.,  60.,  80.,  90.,  100., 110., 120., 130., 140., 150., 160.,
                              170., 180., 190., 200., 220., 240., 260., 280., 300., 350., 400., 450., 1000.};
  std::vector<double> eta_bins = {-3., -2.5, -2., -1.5, -1., -.5, 0., .5, 1., 1.5, 2., 2.5, 3.};
  std::vector<double> bins_2D = {0., 40., 80., 100., 120., 140., 160., 180., 200., 240., 280., 350., 450., 1000.};
  std::vector<double> eta_bins_2D = {-3., -2., -1., 0., 1., 2., 3.};
  std::vector<double> phi_bins_2D = {
      -3.1415, -2.5132, -1.8849, -1.2566, -0.6283, 0, 0.6283, 1.2566, 1.8849, 2.5132, 3.1415};
  edm::ParameterSetDescription lPVcutPSet;
  lPVcutPSet.add<double>("dxy", 9999.);
  lPVcutPSet.add<double>("dz", 9999.);
  desc.add<edm::ParameterSetDescription>("leptonPVcuts", lPVcutPSet);

  descriptions.add("BTagAndProbeMonitoring", desc);
}

// Define this as a plug-in
DEFINE_FWK_MODULE(BTagAndProbe);
