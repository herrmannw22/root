// @(#)root/mathcore:$Name:  $:$Id: LinkDef.hv 1.0 2005/06/23 12:00:00 moneta Exp $
// Authors: Mark Fischler & Lorenzo Moneta   06/2005 

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ namespace ROOT::Math;


#pragma link C++ class ROOT::Math::Cartesian3D<double>+;
#pragma link C++ class ROOT::Math::Polar3D<double>+;
#pragma link C++ class ROOT::Math::CylindricalEta3D<double>+;

#pragma link C++ class ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double> >+;
#pragma link C++ class ROOT::Math::DisplacementVector3D<ROOT::Math::Polar3D<double> >+;
#pragma link C++ class ROOT::Math::DisplacementVector3D<ROOT::Math::CylindricalEta3D<double> >+;

#pragma link C++ class ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<double> >+;
#pragma link C++ class ROOT::Math::PositionVector3D<ROOT::Math::Polar3D<double> >+;
#pragma link C++ class ROOT::Math::PositionVector3D<ROOT::Math::CylindricalEta3D<double> >+;

#pragma link C++ class ROOT::Math::Cartesian4D<double>+;
#pragma link C++ class ROOT::Math::CylindricalEta4D<double>+;
#pragma link C++ class ROOT::Math::EEtaPhiMSystem<double>+;
#pragma link C++ class ROOT::Math::PtEtaPhiMSystem<double>+;

#pragma link C++ class ROOT::Math::BasicLorentzVector<ROOT::Math::Cartesian4D<double> >+;
#pragma link C++ class ROOT::Math::BasicLorentzVector<ROOT::Math::CylindricalEta4D<double> >+;
#pragma link C++ class ROOT::Math::BasicLorentzVector<ROOT::Math::EEtaPhiMSystem<double> >+;
#pragma link C++ class ROOT::Math::BasicLorentzVector<ROOT::Math::PtEtaPhiMSystem<double> >+;

#pragma link C++ typedef ROOT::Math::XYZVector;
#pragma link C++ typedef ROOT::Math::RhoEtaPhiVector;
#pragma link C++ typedef ROOT::Math::Polar3DVector;

#pragma link C++ typedef ROOT::Math::XYZPoint;
#pragma link C++ typedef ROOT::Math::RhoEtaPhiPoint;
#pragma link C++ typedef ROOT::Math::Polar3DPoint;

#pragma link C++ typedef ROOT::Math::LorentzVector;
#pragma link C++ typedef ROOT::Math::LorentzVectorPtEtaPhiE;
#pragma link C++ typedef ROOT::Math::LorentzVectorPtEtaPhiM;
#pragma link C++ typedef ROOT::Math::LorentzVectorEEtaPhiM;


// dictionary for points and vectors
#include "LinkDef2.h"
#include "LinkDef3.h"
#include "LinkDef4.h"





#include "TVectorD.h"
#pragma extra_include "TVectorD.h";
// #pragma link C++ function  ROOT::Math::BasicLorentzVector<ROOT::Math::Cartesian4D<double> >::ROOT::Math::BasicLorentzVector<ROOT::Math::Cartesian4D<double> >(const TVectorD &, size_t);
#pragma link C++ function  ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<double> >::AssignFrom(const TVectorD &, size_t);
#pragma link C++ function  ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double> >::AssignFrom(const TVectorD &, size_t);
#pragma link C++ function  ROOT::Math::BasicLorentzVector<ROOT::Math::Cartesian4D<double> >::AssignFrom(const TVectorD &, size_t);


// utility functions
//#pragma link C++ function  ROOT::Math::VectorUtil::DeltaPhi < ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D< double> > , ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double> > >( const  ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D< double> > &, const  ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D< double> > &)

#pragma link C++ namespace ROOT::Math::VectorUtil;




#pragma extra_include "vector";
#include <vector>

//#pragma link C++ class vector<ROOT::Math::BasicLorentzVector<ROOT::Math::Cartesian4D<double> > >+;
#pragma link C++ class vector<ROOT::Math::LorentzVector >+;


#endif
