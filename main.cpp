/************************************************************************/
/* wenzhou @ 2019.2.26
   1.ʵ��ʹ��ʱ�����¶����ʼ��ͻ��˽����������ֹ�������������غ���ʾ����
   2.ʵ�ʹ��̻�ʹ�õ�ʱ��Ϊ�˱��տ���������SMTP���͵�ʱ��������ֱ���ɹ�������֧�ְ��˺��������������ȥ���������Զ�̬�޸�
   3.���ʹ����ҵ����SMTP�����õ����QQ��������ױ�ʶ��Ϊ�����ʼ�������Ŀ��Կ���gmail��outlook��SMTP
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

		//����SMTP��������ַ��ʹ�ü��ܴ���
		mail.SetSMTPServer("smtp.qq.com", 465);
		mail.SetSecurityType(USE_SSL);

		//��ͨ��Ӧ��SMTP������˺ź����룬ע�⹴ѡSSL��ע�������¼�����ʵ�ʵ�¼�������벻һ��
		//��ҵ�ʿ�ͨ��ʽ�ο� https://jingyan.baidu.com/article/a378c960eabf1eb3282830f6.html
		//QQ��ͨ��ʽ�ο� https://jingyan.baidu.com/article/2c8c281d9a927a0008252a9c.html
		//������������
		mail.SetLogin("1016867319@qq.com");
		mail.SetPassword("xxxxx");

		//��������Ϣ
		char * pszName = CCodingHelper::Unicode2Utf8(L"�����ڿ�");
  		mail.SetSenderName(pszName);						//�û������ʼ�ʱ����ʾ�Ķ�Ӧ����,����һ������ҵ�Ѻõ�����
		delete[] pszName;

  		mail.SetSenderMail("1016867319@qq.com");			//�����ߵ����䣬����Ͷ�Ӧ��STMP����������ͬһ�Һ�׺�����Ҫ֧���Լ���д���䣬��Ҫ�ж�ѡ��ͬ��STMP
  		mail.SetReplyTo("1016867319@qq.com");				//�û��ڿͻ��˵���ظ�ʱ���ظ������䣬һ���SetSenderMail�ı���һ��

		//����Ĭ��,�����������ͷ�����ʶ������
		mail.SetCharSet("utf-8");
  		mail.SetXPriority(XPRIORITY_NORMAL);			
  		mail.SetXMailer("Microsoft Outlook Express 6.00.2900.2869");

		//��д�ռ���(�����ö��)
		mail.AddRecipient("wenzhou1219@foxmail.com");
		mail.AddRecipient("wenzhou1219@hotmail.com");

		//��д�ʼ�����
		char * pszTitle = CCodingHelper::Unicode2Utf8(L"The Message ���ı���");
		mail.SetSubject(pszTitle);
		delete[] pszTitle;

		//��д�ʼ�����(֧��ͨ��html����ʽ����ʾ����)
		mail.m_bHTML = true;
		char * pszHtml = CCodingHelper::Unicode2Utf8(L"<table>\
		<tr>\
			<td>��һ�е�һ��</td>\
			<td>��һ�еڶ���</td>\
		</tr>\
		<tr>\
			<td>�ڶ��е�һ��</td>\
			<td>�ڶ��еڶ���</td>\
		</tr>\
		</table>");
  		mail.AddMsgLine(pszHtml);
		delete [] pszHtml;

		//��Ӹ���
  		mail.AddAttachment("c:\\����·��\\1.txt");
		mail.AddAttachment("c:\\2.txt");

		//����
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
