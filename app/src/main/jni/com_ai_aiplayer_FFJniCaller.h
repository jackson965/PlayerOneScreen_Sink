/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ai_aiplayer_FFJniCaller */

#ifndef _Included_com_ai_aiplayer_FFJniCaller
#define _Included_com_ai_aiplayer_FFJniCaller
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ai_aiplayer_FFJniCaller
 * Method:    decode
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ai_aiplayer_FFJniCaller_decode
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_ai_aiplayer_FFJniCaller
 * Method:    render
 * Signature: (Ljava/lang/String;Landroid/view/Surface;)V
 */
JNIEXPORT void JNICALL Java_com_ai_aiplayer_FFJniCaller_render
  (JNIEnv *, jobject, jstring, jobject);

/*
 * Class:     com_ai_aiplayer_FFJniCaller
 * Method:    audioDecode
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ai_aiplayer_FFJniCaller_audioDecode
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_ai_aiplayer_FFJniCaller
 * Method:    audioPlayer
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ai_aiplayer_FFJniCaller_audioPlayer
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_ai_aiplayer_FFJniCaller
 * Method:    play
 * Signature: (Ljava/lang/String;Landroid/view/Surface;)V
 */
JNIEXPORT void JNICALL Java_com_ai_aiplayer_FFJniCaller_play
  (JNIEnv *, jobject, jstring, jobject);

/*
 * Class:     com_ai_aiplayer_FFJniCaller
 * Method:    ffmpegCmdUtil
 * Signature: (I[Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ai_aiplayer_FFJniCaller_ffmpegCmdUtil
  (JNIEnv *, jobject, jint, jobjectArray);

/*
 * Class:     com_ai_aiplayer_FFJniCaller
 * Method:    addWatermark
 * Signature: (I[Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ai_aiplayer_FFJniCaller_addWatermark
  (JNIEnv *, jobject, jint, jobjectArray);

#ifdef __cplusplus
}
#endif
#endif
