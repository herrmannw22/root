## \file
## \ingroup tutorial_roofit
## \notebook -nodraw
##
## Organization and simultaneous fits: basic use of the 'object factory' associated with a workspace to rapidly build p.d.f.s functions and their parameter components
##
## \macro_code
##
## \date February 2018
## \author Clemens Lange, Wouter Verkerke (C++ version)

import ROOT


compact = ROOT.kFALSE
w = ROOT.RooWorkspace("w")

# Creating and adding basic pdfs
# ----------------------------------------------------------------

# Remake example p.d.f. of tutorial rs502_wspacewrite.C:
#
# Basic p.d.f. construction: ClassName.ObjectName(constructor arguments)
# Variable construction    : VarName[x,xlo,xhi], VarName[xlo,xhi], VarName[x]
# P.d.f. addition          : SUM.ObjectName(coef1*pdf1,...coefM*pdfM,pdfN)
#

if not compact:
    # Use object factory to build p.d.f. of tutorial rs502_wspacewrite
    w.factory("Gaussian::sig1(x[-10,10],mean[5,0,10],0.5)")
    w.factory("Gaussian::sig2(x,mean,1)")
    w.factory("Chebychev::bkg(x,{a0[0.5,0.,1],a1[-0.2,0.,1.]})")
    w.factory("SUM::sig(sig1frac[0.8,0.,1.]*sig1,sig2)")
    w.factory("SUM::model(bkgfrac[0.5,0.,1.]*bkg,sig)")

else:

    # Use object factory to build p.d.f. of tutorial rs502_wspacewrite but
    #  - Contracted to a single line recursive expression,
    #  - Omitting explicit names for components that are not referred to explicitly later

    w.factory(
        "SUM::model(bkgfrac[0.5,0.,1.]*Chebychev::bkg(x[-10,10],{a0[0.5,0.,1],a1[-0.2,0.,1.]}), "
        "SUM(sig1frac[0.8,0.,1.]*Gaussian(x,mean[5,0,10],0.5), Gaussian(x,mean,1)))")

# Advanced pdf constructor arguments
# ----------------------------------------------------------------
#
# P.d.f. constructor arguments may by any type of ROOT.RooAbsArg, also
#
# Double_t -. converted to ROOT.RooConst(...)
# {a,b,c} -. converted to ROOT.RooArgSet() or ROOT.RooArgList() depending on required ctor arg
# dataset name -. convered to ROOT.RooAbsData reference for any dataset residing in the workspace
# enum -. Any enum label that belongs to an enum defined in the (base)
# class

# Make a dummy dataset p.d.f. 'model' and import it in the workspace
data = w.pdf("model").generate(ROOT.RooArgSet(w.var("x")), 1000)
getattr(w, 'import')(data, ROOT.RooFit.Rename("data"))

# Construct a KEYS p.d.f. passing a dataset name and an enum type defining the
# mirroring strategy
# w.factory("KeysPdf::k(x,data,NoMirror,0.2)")
# Workaround for pyROOT
x = w.var("x")
k = ROOT.RooKeysPdf("k", "k", x, data, ROOT.RooKeysPdf.NoMirror, 0.2)
getattr(w, 'import')(k, ROOT.RooFit.Rename("k"))

# Print workspace contents
w.Print()

# Make workspace visible on command line
ROOT.gDirectory.Add(w)
