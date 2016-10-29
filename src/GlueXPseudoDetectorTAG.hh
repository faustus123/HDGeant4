//
// GlueXPseudoDetectorTAG - class header
//
// author: richard.t.jones at uconn.edu
// version: october 29, 2016
//
// In the context of the Geant4 event-level multithreading model,
// this class is "shared", ie. has no thread-local state, but it
// is thread-safe in that its methods can be called concurrently
// from several different threads without conflicts.

#ifndef _GLUEXPSEUDODETECTORTAG_
#define _GLUEXPSEUDODETECTORTAG_

#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4AutoLock.hh"

#include <HDDM/hddm_s.hpp>

class GlueXPseudoDetectorTAG
{
 public:
   GlueXPseudoDetectorTAG(int run_number);
   ~GlueXPseudoDetectorTAG();

   int getRunNo();
   void setRunNo(int runno);
   int addTaggerHit(G4ThreeVector &vertex, double energy, double time, int bg);
   int addRFsync(double tsync);

 protected:
   GlueXPseudoDetectorTAG(GlueXPseudoDetectorTAG &src);
   GlueXPseudoDetectorTAG& operator=(GlueXPseudoDetectorTAG &src);

   int fRunNo;

 private:
   static double TRIGGER_TIME_SIGMA;
   static double TIME_REFERENCE_PLANE_Z;
   static double BEAM_BUCKET_PERIOD;
   static double BEAM_VELOCITY;

   static int HODO_MAX_HITS;
   static int MICRO_MAX_HITS;
   static double HODO_TWO_HIT_TIME_RESOL;
   static double MICRO_TWO_HIT_TIME_RESOL;
   static double HODO_HIT_DE;
   static double MICRO_HIT_DE;

   static const int MICRO_NCHANNELS = 102;
   static double MICRO_LIMITS_ERANGE[2];
   static int MICRO_CHANNEL_NUMBER[MICRO_NCHANNELS];
   static double MICRO_CHANNEL_EMIN[MICRO_NCHANNELS];
   static double MICRO_CHANNEL_EMAX[MICRO_NCHANNELS];

   static const int HODO_NCHANNELS = 274;
   static double HODO_LIMITS_ERANGE[2];
   static int HODO_CHANNEL_NUMBER[HODO_NCHANNELS];
   static double HODO_CHANNEL_EMIN[HODO_NCHANNELS];
   static double HODO_CHANNEL_EMAX[HODO_NCHANNELS];

   static double TAGGER_TMIN_NS;
   static double TAGGER_TMAX_NS;

   static int instanceCount;
   static G4Mutex fMutex;
};

inline int GlueXPseudoDetectorTAG::getRunNo()
{
   return fRunNo;
}

#endif
