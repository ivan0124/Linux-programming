#RSA pair key encrypt/decrypt Sample code
This sample demo:
* how to use RSA public key encrypt and private key decrypt plaintext
* how to use RSA private key encrypt and public key decrypt plaintext

# How to setup build code environment
1. install openssl for [generate RSA public key and private key](https://github.com/ivan0124/Linux-programming/wiki/How-to-generate-RSA-public-and-private-keys%28PEM-format%29-with-openssl-%3F)
<pre>
$ sudo apt-get install openssl
</pre>

2. install openssl library and header file for compiliation. you will sea header files installed in `/usr/include/openssl`
<pre>
$ sudo apt-get libssl-dev
</pre>

#Code Description
1. [generating RSA public key and private key](https://github.com/ivan0124/Linux-programming/wiki/How-to-generate-RSA-public-and-private-keys%28PEM-format%29-with-openssl-%3F) `publicKey` and `privateKey`, then put in source code: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
main(){
...
   char publicKey[]="-----BEGIN PUBLIC KEY-----\n"\
    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAy8Dbv8prpJ/0kKhlGeJY\n"\
    "ozo2t60EG8L0561g13R29LvMR5hyvGZlGJpmn65+A4xHXInJYiPuKzrKUnApeLZ+\n"\
    "vw1HocOAZtWK0z3r26uA8kQYOKX9Qt/DbCdvsF9wF8gRK0ptx9M6R13NvBxvVQAp\n"\
    "fc9jB9nTzphOgM4JiEYvlV8FLhg9yZovMYd6Wwf3aoXK891VQxTr/kQYoq1Yp+68\n"\
    "i6T4nNq7NWC+UNVjQHxNQMQMzU6lWCX8zyg3yH88OAQkUXIXKfQ+NkvYQ1cxaMoV\n"\
    "PpY72+eVthKzpMeyHkBn7ciumk5qgLTEJAfWZpe4f4eFZj/Rc8Y8Jj2IS5kVPjUy\n"\
    "wQIDAQAB\n"\
    "-----END PUBLIC KEY-----\n";
  
    char privateKey[]="-----BEGIN RSA PRIVATE KEY-----\n"\
    "MIIEowIBAAKCAQEAy8Dbv8prpJ/0kKhlGeJYozo2t60EG8L0561g13R29LvMR5hy\n"\
    "vGZlGJpmn65+A4xHXInJYiPuKzrKUnApeLZ+vw1HocOAZtWK0z3r26uA8kQYOKX9\n"\
    "Qt/DbCdvsF9wF8gRK0ptx9M6R13NvBxvVQApfc9jB9nTzphOgM4JiEYvlV8FLhg9\n"\
    "yZovMYd6Wwf3aoXK891VQxTr/kQYoq1Yp+68i6T4nNq7NWC+UNVjQHxNQMQMzU6l\n"\
    "WCX8zyg3yH88OAQkUXIXKfQ+NkvYQ1cxaMoVPpY72+eVthKzpMeyHkBn7ciumk5q\n"\
    "gLTEJAfWZpe4f4eFZj/Rc8Y8Jj2IS5kVPjUywQIDAQABAoIBADhg1u1Mv1hAAlX8\n"\
    "omz1Gn2f4AAW2aos2cM5UDCNw1SYmj+9SRIkaxjRsE/C4o9sw1oxrg1/z6kajV0e\n"\
    "N/t008FdlVKHXAIYWF93JMoVvIpMmT8jft6AN/y3NMpivgt2inmmEJZYNioFJKZG\n"\
    "X+/vKYvsVISZm2fw8NfnKvAQK55yu+GRWBZGOeS9K+LbYvOwcrjKhHz66m4bedKd\n"\
    "gVAix6NE5iwmjNXktSQlJMCjbtdNXg/xo1/G4kG2p/MO1HLcKfe1N5FgBiXj3Qjl\n"\
    "vgvjJZkh1as2KTgaPOBqZaP03738VnYg23ISyvfT/teArVGtxrmFP7939EvJFKpF\n"\
    "1wTxuDkCgYEA7t0DR37zt+dEJy+5vm7zSmN97VenwQJFWMiulkHGa0yU3lLasxxu\n"\
    "m0oUtndIjenIvSx6t3Y+agK2F3EPbb0AZ5wZ1p1IXs4vktgeQwSSBdqcM8LZFDvZ\n"\
    "uPboQnJoRdIkd62XnP5ekIEIBAfOp8v2wFpSfE7nNH2u4CpAXNSF9HsCgYEA2l8D\n"\
    "JrDE5m9Kkn+J4l+AdGfeBL1igPF3DnuPoV67BpgiaAgI4h25UJzXiDKKoa706S0D\n"\
    "4XB74zOLX11MaGPMIdhlG+SgeQfNoC5lE4ZWXNyESJH1SVgRGT9nBC2vtL6bxCVV\n"\
    "WBkTeC5D6c/QXcai6yw6OYyNNdp0uznKURe1xvMCgYBVYYcEjWqMuAvyferFGV+5\n"\
    "nWqr5gM+yJMFM2bEqupD/HHSLoeiMm2O8KIKvwSeRYzNohKTdZ7FwgZYxr8fGMoG\n"\
    "PxQ1VK9DxCvZL4tRpVaU5Rmknud9hg9DQG6xIbgIDR+f79sb8QjYWmcFGc1SyWOA\n"\
    "SkjlykZ2yt4xnqi3BfiD9QKBgGqLgRYXmXp1QoVIBRaWUi55nzHg1XbkWZqPXvz1\n"\
    "I3uMLv1jLjJlHk3euKqTPmC05HoApKwSHeA0/gOBmg404xyAYJTDcCidTg6hlF96\n"\
    "ZBja3xApZuxqM62F6dV4FQqzFX0WWhWp5n301N33r0qR6FumMKJzmVJ1TA8tmzEF\n"\
    "yINRAoGBAJqioYs8rK6eXzA8ywYLjqTLu/yQSLBn/4ta36K8DyCoLNlNxSuox+A5\n"\
    "w6z2vEfRVQDq4Hm4vBzjdi3QfYLNkTiTqLcvgWZ+eX44ogXtdTDO7c+GeMKWz4XX\n"\
    "uJSUVL5+CVjKLjZEJ6Qc2WZLl94xSwL71E41H4YciVnSCQxVc4Jw\n"\
    "-----END RSA PRIVATE KEY-----\n";
</pre>

2. prepare `plainText` for encrypt and decrypt. because RSA key length is `2048 bits`, so plainText array size is `2048/8`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
main(){
...
char plainText[2048/8] = "Hello this is ivan"; //key length : 2048
</pre>

3. include openssl header files: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
...
</pre>

4. link openssl library: [Makefile](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/Makefile)
<pre>
...
LDLIBS	:=-lcrypto
...
</pre>

5. step5,6 explain how public key encrypt and private key decrypt. using `public_encrypt()` to encrypt plainText and encrypted text to `encrypted`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
int public_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted)
{
        RSA * rsa = createRSA(key,1);
        int result = RSA_public_encrypt(data_len,data,encrypted,rsa,padding);
        return result;
}
...
int encrypted_length= public_encrypt(plainText,strlen(plainText),publicKey,encrypted);
...
</pre>

6. using `private_decrypt()` to decrypt encrypted text and put plaintext to `decrypted`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
int private_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted)
{
        RSA * rsa = createRSA(key,0);
        int  result = RSA_private_decrypt(data_len,enc_data,decrypted,rsa,padding);
        return result;
}
...
int decrypted_length = private_decrypt(encrypted,encrypted_length,privateKey, decrypted);
...
</pre>

7. step7,8 explain how private key encrypt and public key decrypt. using `private_encrypt()` to encrypt plainText and encrypted text to `encrypted`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
int private_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted)
{
        RSA * rsa = createRSA(key,0);
        int result = RSA_private_encrypt(data_len,data,encrypted,rsa,padding);
        return result;
}
...
encrypted_length= private_encrypt(plainText,strlen(plainText),privateKey,encrypted);
...
</pre>

8. using `public_decrypt()` to decrypt encrypted text and put plaintext to `decrypted`: [app_a.c](https://github.com/ivan0124/Linux-programming/blob/master/user_RSA_encrypt_decrypt/app_src/app_a/app_a.c)
<pre>
...
int public_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted)
{
    RSA * rsa = createRSA(key,1);
    int  result = RSA_public_decrypt(data_len,enc_data,decrypted,rsa,padding);
    return result;
}
...
decrypted_length = public_decrypt(encrypted,encrypted_length,publicKey, decrypted);
...
</pre>

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
app_a - application
lib_common.so - shared library
</pre>

3. run `mk.sh test` to test.
<pre>$ mk.sh test </pre>
![result link](http://139.162.35.49/image/Linux-Programming/RSA_20160422_1.png)

4. remove all build result
<pre>$ mk.sh clean</pre> 


