// eJzNVdFu2jAUlf8EoT0kG40TSOlqVZVaUKW2rKOCPewpchIXXJI4sk1L9vW7cSLaMEtjD9MmIq58uPE593B9nYjc43HuKS0ZzdXO29CnDSXkvg4TUahtziQKkA_0fIep7Hm4eXZUMX7O7V_1llIYY_1NmM9m8bz5cLfLje7_0fXjVaUev2feuo8uFvNZdPdwe7MtEs1hxygReQScERc65PUqF4W3vgSGIEQZ1x98BO8QIkEUL1bIYIEFG1qwkQULLdipBRtbsDML9tmCnds0WwuxVRLYSgkOa0E4ZymnWD1Fak0lSzFYyE_1UmrMsVdj4efIyxGxH8zJjCitex33CRFK1XpgFTqmmqBAF81GIkowq9UBzhg7EdQtw_0om1XTxRMkm1kMrr9M3XFu676ErDDvFWsxvJWMM347GkskKjQ0rHrPf9Qsg3zcGPipAV00shsg3XUy5ZAltXzjEC_067b_09TrZuLaG_1xMXyiOeQEZBxr_1jShRapyK1yITNIX_19_0P_1osuYlfHYpkiLkieHnRO0J7mbWsq6VTRn6oZnv3RbgAgxwPtxQQjIJAR0wlfd4QaAkWFyo24q1Gw6cN7hqTv7z3wyx88d9MyUacKoCeGgZ349BY9atarMooQqffG_0mEHj4JYXehz2LkE0ZDjtGzYZzyK_0nTquC6yOYyjO_1hoFbGzmnXscAxCMhscQgJWTNS0KljWFmGHZhPMmBH4bgza27gajw67yza0jSiH3F8Jv7xuUIwnX1IZV6O2E5EwpumJviP8TVPRHDX


#include "./SourceStream.h"
using namespace SPL::_Operator::source::source;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator::source::source
#define MY_BASE_OPERATOR SourceStream_Base
#define MY_OPERATOR SourceStream$OP





#include <dlfcn.h>

#include <SPL/Toolkit/JavaOp.h>
#include <SPL/Toolkit/RuntimeException.h>

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
{
  /* Get a handle to the Java virtual machine */
  SPL::JNI::JVMControl *jvmControl = SPL::JNI::JVMControl::getJVM();
   
  /* Attach to the JVM  for the duration of the initialization */
  JNIEnv * env = jvmControl->attach();

  /* How we invoke methods against an OperatorSetup instance */
  SPL::JNI::OpSetupInvoker* osi = jvmControl->getOpSetupInvoker();

  /* OperatorSetup instance specific to this operator */
  jobject setup = osi->newSetup(env, this); 

  /**
     Pass the parameters into my OperatorSetup instance.
  */
     osi->setParameter(env, setup, "className", SPL::rstring("com.ibm.streamsx.kafka.operators.KafkaConsumerOperator"));
   osi->setParameter(env, setup, "classLibrary", (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.kafka")) + SPL::rstring("/impl/java/bin")));
   osi->setParameter(env, setup, "classLibrary", (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.kafka")) + SPL::rstring("/opt/downloaded/*")));
   osi->setParameter(env, setup, "classLibrary", (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.kafka")) + SPL::rstring("/impl/lib/*")));
   osi->setParameter(env, setup, "topic", lit$0);
   osi->setParameter(env, setup, "propertiesFile", ::SPL::JNIFunctions::com::ibm::iot4i::common::SPL_JNIFunctions::getKafkaPropertiesFileName(SPL::Functions::Utility::getToolkitDirectory(lit$1), lit$2, lit$3, lit$4, (lit$5 + ::SPL::spl_cast<SPL::rstring, SPL::uint64 >::cast(::SPL::Functions::Utility::jobID())), (((lit$7 + ::SPL::spl_cast<SPL::rstring, SPL::uint64 >::cast(::SPL::Functions::Utility::jobID())) + lit$6) + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(::SPL::Functions::Utility::getChannel())), lit$8, lit$9, lit$10, lit$11, lit$12, lit$13));


  /**
    Pass input port information into the Java operator.
 
    Are logic clauses present.
   
    Pass the windowing information for each port as
    a list of values for the parameter '[window].N' where
    N is the index of the windowed input port.
  */
   hasTupleLogic = false;


  
  /* At this point all the initialization information has been
     passed to OperatorSetup. Create a JNIBridge instance object
     we use to communicate with the user's Operator implementation
     at runtime.
  */
  
  _bi = jvmControl->getBridgeInvoker();
  _bridge = _bi->newBridge(env, this, setup);
        
  /* Completed Java initialization, detach from the JVM */
  jvmControl->detach();

  setupStateHandler();

  void * handle = dlopen("libstreams-stdtk-javaop.so", RTLD_LAZY);
  if (!handle) {
    const FormattableMessage& m = SPL_APPLICATION_RUNTIME_EXCEPTION("libstreams-stdtk-javaop.so");
    THROW_STRING(SPLRuntimeJavaOperator, m);
  }
  _fp = (FP) dlsym(handle, "callProcessTupleWithNativeByteBuffer");
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::setupStateHandler()
{
    _stateHandler.reset(new SPL::JNI::JavaOpStateHandler(_bi, _bridge));
    getContext().registerStateHandler(*_stateHandler);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() 
{
    _bi->allPortsReady(_bridge);
    createThreads(1);
}
 
void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
   _bi->shutdown(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
   _bi->complete(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple & tuple, uint32_t port)
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
   _bi->processTuple(_bridge, tuple, port);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
   _bi->processPunctuation(_bridge, punct, port);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("source::source::SourceStream",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    initRTC(*this, lit$4, "lit$4");
    initRTC(*this, lit$5, "lit$5");
    initRTC(*this, lit$6, "lit$6");
    initRTC(*this, lit$7, "lit$7");
    initRTC(*this, lit$8, "lit$8");
    initRTC(*this, lit$9, "lit$9");
    initRTC(*this, lit$10, "lit$10");
    initRTC(*this, lit$11, "lit$11");
    initRTC(*this, lit$12, "lit$12");
    initRTC(*this, lit$13, "lit$13");
    param$className$0 = SPL::rstring("com.ibm.streamsx.kafka.operators.KafkaConsumerOperator");
    addParameterValue ("className", SPL::ConstValueHandle(param$className$0));
    param$classLibrary$0 = (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.kafka")) + SPL::rstring("/impl/java/bin"));
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$0));
    param$classLibrary$1 = (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.kafka")) + SPL::rstring("/opt/downloaded/*"));
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$1));
    param$classLibrary$2 = (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.kafka")) + SPL::rstring("/impl/lib/*"));
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$2));
    addParameterValue ("topic", SPL::ConstValueHandle(lit$0));
    param$propertiesFile$0 = ::SPL::JNIFunctions::com::ibm::iot4i::common::SPL_JNIFunctions::getKafkaPropertiesFileName(SPL::Functions::Utility::getToolkitDirectory(lit$1), lit$2, lit$3, lit$4, (lit$5 + ::SPL::spl_cast<SPL::rstring, SPL::uint64 >::cast(::SPL::Functions::Utility::jobID())), (((lit$7 + ::SPL::spl_cast<SPL::rstring, SPL::uint64 >::cast(::SPL::Functions::Utility::jobID())) + lit$6) + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(::SPL::Functions::Utility::getChannel())), lit$8, lit$9, lit$10, lit$11, lit$12, lit$13);
    addParameterValue ("propertiesFile", SPL::ConstValueHandle(param$propertiesFile$0));
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}




