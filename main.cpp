/************************************************************************/
/* wenzhou @ 2019.2.26
   1.实际使用时测试下多种邮件客户端接收情况，防止被当做垃圾拦截和显示乱码
   2.实际工程化使用的时候，为了保险可以申请多个SMTP发送的时候依次试直到成功，或者支持把账号密码加密升级下去，这样可以动态修改
   3.最好使用企业邮箱SMTP，常用的免费QQ邮箱很容易被识别为垃圾邮件，国外的可以考虑gmail和outlook的SMTP
*/
/************************************************************************/

#include <iostream>
#include "CSmtp.h"
#include "CodingHelper.h"

int main()
{
	bool bError = false;

	try
	{
		CSmtp mail;

		//设置SMTP服务器地址，使用加密传输
		mail.SetSMTPServer("smtp.qq.com", 465);
		mail.SetSecurityType(USE_SSL);

		//开通对应的SMTP服务的账号和密码，注意勾选SSL，注意这里登录密码和实际登录邮箱密码不一样
		//企业邮开通方式参考 https://jingyan.baidu.com/article/a378c960eabf1eb3282830f6.html
		//QQ开通方式参考 https://jingyan.baidu.com/article/2c8c281d9a927a0008252a9c.html
		//其他邮箱类似
		mail.SetLogin("1016867319@qq.com");
		mail.SetPassword("xxxxx");

		//发送者信息
		char * pszName = CCodingHelper::Unicode2Utf8(L"博联众科");
  		mail.SetSenderName(pszName);						//用户接受邮件时会显示的对应名字,设置一个对企业友好的名字
		delete[] pszName;

  		mail.SetSenderMail("1016867319@qq.com");			//发送者的邮箱，必须和对应的STMP服务器采用同一家后缀，如果要支持自己填写邮箱，需要判断选择不同的STMP
  		mail.SetReplyTo("1016867319@qq.com");				//用户在客户端点击回复时，回复的邮箱，一般和SetSenderMail的保持一致

		//保持默认,解决编码问题和反垃圾识别问题
		mail.SetCharSet("utf-8");
  		mail.SetXPriority(XPRIORITY_NORMAL);			
  		mail.SetXMailer("Microsoft Outlook Express 6.00.2900.2869");

		//填写收件者(可设置多个)
		mail.AddRecipient("wenzhou1219@foxmail.com");
		mail.AddRecipient("wenzhou1219@hotmail.com");

		//填写邮件标题
		char * pszTitle = CCodingHelper::Unicode2Utf8(L"The Message 中文标题");
		mail.SetSubject(pszTitle);
		delete[] pszTitle;

		//填写邮件内容(支持通过html来格式化显示内容)
		mail.m_bHTML = true;
		char * pszHtml = CCodingHelper::Unicode2Utf8(L"<table>\
		<tr>\
			<td>第一行第一列</td>\
			<td>第一行第二列</td>\
		</tr>\
		<tr>\
			<td>第二行第一列</td>\
			<td>第二行第二列</td>\
		</tr>\
		</table>");
  		mail.AddMsgLine(pszHtml);
		delete [] pszHtml;

		//添加附件
  		mail.AddAttachment("c:\\中文路径\\1.txt");
		mail.AddAttachment("c:\\2.txt");

		//发送
		mail.Send();
	}
	catch(ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}

	if(!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}
