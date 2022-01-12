package com.tip.net.dns;

public class DNSUtil {
    static {
        System.loadLibrary("dns-util");
    }

    public native static String getHostByName(String host);
}
