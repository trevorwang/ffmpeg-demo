#include <jni.h>
#include <string>

extern "C"
{
#include <libavcodec/avcodec.h>
}

extern "C" JNIEXPORT jstring JNICALL
Java_mingsin_ffmpeg_nativelib_NativeLib_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C" JNIEXPORT jint JNICALL
Java_mingsin_ffmpeg_nativelib_NativeLib_add(JNIEnv *env, jobject thiz, jint x, jint y) {
    return x + y;
}
extern "C" JNIEXPORT jstring JNICALL
Java_mingsin_ffmpeg_nativelib_NativeLib_mediaInfo(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(avcodec_configuration());
}
extern "C"
JNIEXPORT jobject JNICALL
Java_mingsin_ffmpeg_nativelib_NativeLib_getDemo(JNIEnv *env, jobject thiz) {
    jclass javaClass = env->FindClass("mingsin/ffmpeg/nativelib/JniDemo");
    jmethodID constructor = env->GetMethodID(javaClass, "<init>", "(Ljava/lang/String;)V");
    jobject javaObject = env->NewObject(javaClass, constructor, env->NewStringUTF("hello demo"));
    return javaObject;
}