# sendmail-in-cpp

Based on project [SMTP](https://www.codeproject.com/Articles/98355/SMTP-Client-with-SSL-TLS)，sendmail in c++, support multi utf8 language

基于[SMTP项目](https://www.codeproject.com/Articles/98355/SMTP-Client-with-SSL-TLS)，演示了完整的基于SMTP发送邮件的过程：
* 支持SSL/TLS
* 支持腾讯、163、google、outlook等邮箱
* 支持简单垃圾拦截
* 支持多国语言
* 支持HTML发送
* 支持X86/X64
* 默认SMTP只支持2010前版本，修改后支持VS 2015/2017，当前工程为2015；升级OPenSSL版本为1.0.2h