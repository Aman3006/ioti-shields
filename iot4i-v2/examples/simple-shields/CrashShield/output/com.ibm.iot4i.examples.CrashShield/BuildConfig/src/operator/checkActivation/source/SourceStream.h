// eJzNVV1v2yAUFf8kivbgbKkxiZt2qKrUJqrULutSJXvYk4VtGlN_1YAFp4_136YWyltYe07KHaFCtXHF9zz7kcIOK5y8LclUpQksu9m5LHlGD8pQ5zXshdTgVAwNO_1CRi6LmweVZUUXtO7F_1F1zSc_105laLsLVZu3tNul_0df1wVcmHH5mbDMHFerUM7u5vb3ZFpJieMYh4HuiaAePKZ_1Uo54WbXOoK6BRkTH3wgP4GY6FJsWILDIYs2MSCTS2Yb8FOLdjMgp1ZsHML9tnG2SrEpgTZpCCbFtQXA2BOY0agfAxkQgSNoe4rO5EJo1ksoWnyyfME0j3Jy4xKKFkdDwlzQWSyNgMYE0VAwQvqAR9EGZHynuQU9Bh3VTnDyOohl5dUEMWFdDtm_0tbCwxG4UnqGcKfojaC0qbdkoSCiAtN_0SceMDybC_0Ltiuh8VxluqNpxnKVMLJmikp66cYwgOR6PBp0E3E9a9gU_1kmcCQFTqjx_1HfkOKlgjF_1KTJOYr2_0H_18XXqZZGQttjBQvWdR3Dmq3dze1FLVVFKPyhmW_1uQ0BjA3w9gzBWNPEWPPUf7XDDaDPEZMbdFO1ZuPAVadO7ey_165PZfqPxwBw9TZg2wR8PHMe8n_0kutXxlmQURkerirZxx08MdK9TMH1xq2jrDab_0wEXni4e3CGZn2m3NrdFwFXWA6OaaAVjpPSFHQrK5yEHL_03kLO3luIOZWbgLw2oja2y4fa9UN_0376eufN4ycXhOvrjbQdyIPQlmdIKvG7FnEpJtvQV8X4B9hhvAe

#include <SPL/Toolkit/JavaOp.h>


#ifndef SPL_OPER_INSTANCE_CHECKACTIVATION_SOURCE_SOURCESTREAM_H_
#define SPL_OPER_INSTANCE_CHECKACTIVATION_SOURCE_SOURCESTREAM_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../../../type/BeJwrMSo2zk6tLDbPTS0uTkxPBQAysQYl.h"
#include <SPL_JNIFunctions_com_ibm_iot4i_common.h>


#define MY_OPERATOR SourceStream$OP
#define MY_BASE_OPERATOR SourceStream_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::checkActivation::source

namespace SPL {
namespace _Operator {
namespace checkActivation {
namespace source {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSo2zk6tLDbPTS0uTkxPBQAysQYl OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::rstring lit$3;
    SPL::rstring lit$4;
    SPL::rstring lit$5;
    SPL::rstring lit$6;
    SPL::rstring lit$7;
    SPL::rstring lit$8;
    SPL::rstring lit$9;
    SPL::rstring lit$10;
    SPL::rstring lit$11;
    SPL::rstring lit$12;
    SPL::rstring lit$13;
    SPL::rstring lit$14;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$className$0;
    SPL::rstring param$classLibrary$0;
    SPL::rstring param$classLibrary$1;
    SPL::rstring param$classLibrary$2;
    SPL::rstring param$propertiesFile$0;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);
private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR 
{
public:
  // constructor
  MY_OPERATOR();

  // destructor
  virtual ~MY_OPERATOR(); 

  // notify port readiness
  void allPortsReady(); 

  // notify termination
  void prepareToShutdown(); 

  // processing for source and threaded operators   
  void process(uint32_t idx);
    
  // tuple processing for mutating ports 
  void process(Tuple & tuple, uint32_t port);
    
  // tuple processing for non-mutating ports
  void process(Tuple const & tuple, uint32_t port);

  // punctuation processing
  void process(Punctuation const & punct, uint32_t port);
private:
  void setupStateHandler();

  // members
  
  /** How we invoke actions on the Java Operator implementation */
  SPL::JNI::JNIBridgeInvoker* _bi;
  
  /* The instance of the JNIBridge used to wrap the Java Operator implementation */
  jobject _bridge;

  typedef void (*FP)(SPL::JNI::JNIBridgeInvoker&, jobject, NativeByteBuffer &, uint32_t);
  FP _fp;
  
  bool hasTupleLogic;
  
  std::tr1::shared_ptr<SPL::StateHandler> _stateHandler;

public:
  virtual void javaopInternalAction(Punctuation const & punct, uint32_t port)
  {
     _bi->action(_bridge, punct, port);
  }
    
  // handle byte buffers being send as is
  virtual void processRaw(NativeByteBuffer & buffer, uint32_t port)
  {
     (*_fp)(*_bi, _bridge, buffer, port);
  }
  
  //Java operators handle byte buffers directly
  virtual bool sendRawBufferData() { return !hasTupleLogic; }

  // Requests the blocking of a consistent region permit
  virtual void blockConsistentRegionPermit() {
      _bi->blockConsistentRegionPermit(_bridge);
  }
}; 

} // namespace checkActivation
} // namespace source
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_CHECKACTIVATION_SOURCE_SOURCESTREAM_H_

