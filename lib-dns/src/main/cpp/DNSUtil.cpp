//
// Created by Tip on 2020/5/19.
//

#include "DNSUtil.h"
#include <arpa/inet.h>
#include <netdb.h>

//#include <android/log.h>
#include <string.h>


//#define  LOG_TAG    "nativeprint"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
//#define LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__

extern "C" {
/*
 * Class:     com_tip_net_dns_DNSUtil
 * Method:    getHostByName
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_tip_net_dns_DNSUtil_getHostByName
        (JNIEnv *env, jclass jno, jstring jstr) {

    hostent *host = gethostbyname(env->GetStringUTFChars(jstr,0));
    if(!host){
        return nullptr;
    }
    char h_name[1024] = "h_name=";
    strcat(h_name,host->h_name);
    strcat(h_name,"&c_name=");
    for(int i=0; host->h_aliases[i]; i++){
        strcat(h_name,host->h_aliases[i]);
        strcat(h_name,"|");
    }
    //地址类型
    strcat(h_name,"&h_addrtype=");
    strcat(h_name,(host->h_addrtype==AF_INET) ? "AF_INET": "AF_INET6");
    //IP地址
    strcat(h_name,"&h_addr_ip=");
    for(int i=0; host->h_addr_list[i]; i++){
        strcat(h_name,inet_ntoa( *(struct in_addr*)host->h_addr_list[i]));
        strcat(h_name,"|");
    }
//    LOGD("%s",h_name);
    return env->NewStringUTF(h_name);
}

}

