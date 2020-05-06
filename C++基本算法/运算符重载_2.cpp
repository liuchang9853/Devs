//=��������غ���

#include <iostream>
#include <cstring>
using namespace std;

class CMyString {
	public :
		CMyString(char * pData = nullptr);
		//��Ĭ���β�ֵ�ĺ�����ע��ؼ���nullptr����C++11����������
		CMyString(const CMyString & str);
		~CMyString(void);
		CMyString & operator=(const CMyString &str);
		void show () {
			cout << m_pData;
		}
	private :
		char *m_pData;
};
CMyString::CMyString(char *pData) {
	if(pData == nullptr) {
		m_pData = new char[1];
		m_pData[0] = '\0';
		/*
		����û����һ��䣬�����������ܳ��� 
		*/ 
	} else {
		int length = strlen(pData); 
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
		/*
		��1�� 
		����Ҫ���ף������ݳ�Ա����ָ�����͵����ݣ���Ҫ��֤����ָ��������ָ���
		�ڴ�ռ��ǲ�����ģ���������������������Ƕ���ķ���ԡ� 
		������룺
		m_pData = pData;
		���������ڣ��������m_pDataָ��һ���¿��ٵ�length+1��char�ռ䣬��pData
		��ָ�ռ��е��ַ������Ƶ���char�ռ��С� ʵ���˶���ķ���ԡ���m_pData = pData;
		��ֻ�Ǽ򵥵İ�pData�д�ŵĵ�ַ��ֵ��m_pData�����󲻷�ա�
		��2����λ����Ե�֪��#include<cstring>�µĺ����������Ĳ���char������������
		char * ptr�� 
		*/ 
	}
}
CMyString::~CMyString()
{
    delete[] m_pData;
}
CMyString::CMyString(const CMyString &str) {
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}
CMyString & CMyString::operator = (const CMyString & str) {
	/*
	1.�ú������뷵��һ�����ò��У�ʵ���ϣ����е���������غ�����Ҫ����һ�����ò��С�
	��Ϊֻ�з������ò��������ȡ����ӵȲ�����

	����Ĳ���ҲӦ�������ã�Ϊ������ø��ƹ��캯������ν�˷ѡ�
	*/

	if(this == &str)
		return *this;
	/*
	2.֮������this == &str������this == str������Ϊthis��ָ��ǰ�����ָ�롣
	*this�Ƕ�����
	int &i = j;�У�i��j�ı�����i��j��ʾ��ͬ�ռ��е����ݡ��ʸþ��ʾ��return������
	�������أ�&����
	*/

	delete []m_pData;
	m_pData = nullptr;
	/*
	3.��֪��
	int *p=new int [���ʽ];
	delete [] p;
	����p��һ��ָ��̬����ռ��ָ�롣

	ʵ���ϣ�
	char * p = nullptr;
	delete [] p;
	return 0;
	Ҳ���ԣ���ֻҪ��p��һ��ָ�룬�Ϳ�����delete��������ָ��Ŀռ䡣
	delete����new�ؼ��ֹ���������ָ�빲�档

	��һ��ּ���ͷű�������ڴ棬����ֵǰδ�ͷ�ԭ���ڴ棬������ڴ�й©��
	��Ҳָ����2����Ҫ�ԣ���this == &str����û�в���2�����ڻ���this��ָ
	�ռ��ͬʱ��Ҳ������&str�ռ䡣
	*/

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData , str.m_pData);
	/*
	4.���ȣ�strlen()��strcpy()�Ⱥ�������#include<cstring>����char���������
	��Σ�֮����+1����ΪҪΪchar����string���һ���̶�Ԫ��"\0"���ٿռ䡣
	*/

	return *this;
}
int main() {
	char * p_1 = "I love you.";
	char * p_2 = "I hate you.";
	char * p_3 = "I forgive you.";
	CMyString str_1(p_1);
	CMyString str_2(p_2);
	CMyString str_3(p_3);
	str_1=str_2=str_3;
	str_1.show();
	return 0;
}
