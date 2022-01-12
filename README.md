# 介绍

**dns-tool**

通过C中的gethostbyname()函数通过域名解析IP地址
# 原理
~~~
//gethostbyname() 函数
struct hostent *gethostbyname(const char *hostname);
//hostname 为主机名，也就是域名。使用该函数时，只要传递域名字符串，就会返回域名对应的 IP 地址。返回的地址信息会装入 hostent 结构体，该结构体的定义如下
struct hostent{
    char *h_name;  //official name
    char **h_aliases;  //alias list
    int  h_addrtype;  //host address type
    int  h_length;  //address lenght
    char **h_addr_list;  //address list
}
~~~
# 特技
- 直接使用c函数解析域名地址，速度快，可作为网络检测工具使用，检测DNS劫持
- aar包中so极致精简,arm64-v8a为**2.2kb**

# 效果

![image](https://user-images.githubusercontent.com/17868751/149097808-8f62beca-f951-4c21-970e-b90597254eeb.png)


