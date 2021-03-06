// DO NOT EDIT THIS FILE - it is machine generated
#ifndef SPL_JNIFunctions_com_ibm_iot4i_events_IoTP_h
#define SPL_JNIFunctions_com_ibm_iot4i_events_IoTP_h

#include <SPL/Runtime/Function/SPLJavaFunction.h>
#include <SPL/Runtime/Type/SPLType.h>

namespace SPL {
namespace JNIFunctions {
namespace com {
namespace ibm {
namespace iot4i {
namespace events {
namespace IoTP {
class SPL_JNIFunctions {
public:

// Generated from com.ibm.iot4i.events.IoTP.GetJsonStringKeyImpl in impl/java/bin/com/ibm/iot4i/events/IoTP/GetJsonStringKeyImpl$StreamsModel.class at Wed Sep 20 11:57:41 EDT 2017
static SPL::ustring getJsonStringKey(SPL::ustring const & arg1, SPL::ustring const & arg2) {
    static __thread void *func;
    static __thread jclass classGlobalRef;
    static __thread jmethodID mid;
    if (func == NULL) {
        func = SPL::SPLJavaFunction::loadFunction("iot4i-shield-toolkit", "1.0.0", SPLJAVAFUNCTION_ADL_FILENAME, "impl/java/bin", "com.ibm.iot4i.events.IoTP.GetJsonStringKeyImpl", "getJsonStringKey", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", "com.ibm.iot4i.events.IoTP", "<string T> public T getJsonStringKey(T orgId, T topic)", &classGlobalRef, &mid);
    }
    JNIEnv* env = SPL::SPLJavaFunction::getJNIEnv(func);
    jstring obj1 = env->NewString((jchar *) arg1.getBuffer(), (jsize) arg1.length());
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCreateError(func);
    jstring obj2 = env->NewString((jchar *) arg2.getBuffer(), (jsize) arg2.length());
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCreateError(func);
    jstring resObj = (jstring) env->CallStaticObjectMethod(classGlobalRef, mid, obj1, obj2);
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCallError(func);
    env->DeleteLocalRef(obj1);
    env->DeleteLocalRef(obj2);
    if (resObj != NULL) {
        const jchar *chars = env->GetStringChars(resObj, NULL);
        if (chars == NULL)
            SPL::SPLJavaFunction::throwCreateError(func);
        SPL::ustring result((const UChar *) chars, (int32_t) env->GetStringLength(resObj));
        env->ReleaseStringChars(resObj, chars);
        env->DeleteLocalRef(resObj);
        return result;
    } else {
        return SPL::ustring::fromUTF8("");
    }
}

// Generated from com.ibm.iot4i.events.IoTP.GetJsonStringKeyImpl in impl/java/bin/com/ibm/iot4i/events/IoTP/GetJsonStringKeyImpl$StreamsModel.class at Wed Sep 20 11:57:41 EDT 2017
static SPL::rstring getJsonStringKey(SPL::rstring const & arg1, SPL::rstring const & arg2) {
    SPL::ustring result = getJsonStringKey(SPL::ustring::fromUTF8(arg1), SPL::ustring::fromUTF8(arg2));
    return SPL::ustring::toUTF8(result);
}

// Generated from com.ibm.iot4i.events.IoTP.GetJsonStringKeyImpl in impl/java/bin/com/ibm/iot4i/events/IoTP/GetJsonStringKeyImpl$StreamsModel.class at Wed Sep 20 11:57:41 EDT 2017
template <SPL::int32 msize>
static SPL::bstring<msize> getJsonStringKey(SPL::bstring<msize> const & arg1, SPL::bstring<msize> const & arg2) {
    SPL::rstring result = getJsonStringKey((SPL::rstring) arg1, (SPL::rstring) arg2);
    return (SPL::bstring<msize>) result;
}

};
}
}
}
}
}
}
}
#endif
