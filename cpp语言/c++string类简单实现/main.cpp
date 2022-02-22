#include<iostream>
#include<string.h>
using namespace std;

class String
{

    private:
        char* m_dataCStr;//底层存储结构-new动态内存
    public:
        char* getData()
        {
            return m_dataCStr;
        }

        //合成默认构造函数：成员数据-0(全局);不确定值(局部对象)
        String() //仿造string类的自定义默认构造函数
        {
            m_dataCStr=new int[15]; //默认15个int容量。
            m_dataCstr[0]='\0';
        } 
        String(const char* str)///String string1="nihao";String string1("nihao");
        {
            if(!str)//必须判空，否则strlen(null)错误
            {
                 m_dataCStr=new int[1]; 
                 m_dataCstr[0]='\0';
            }
            else
            {

                 m_dataCStr=new int[strlen(str)+1];
                 strcpy(m_dataCstr,str);//strcpy 将src指向的到结束字符为止的这一段字符串复制给des;参数均不能为空;des的size应足够
            }
            cout<<"String::String(const & str)"<<endl;

        }
        String(const &String str)//String string1=string2;String string1(string2);
        {
            if(!str.m_dataCStr)//实际情况是str.m_dataCStr不可能为null，但是为了保险起见，应该判断--以防后续的strlen(NULL)错误。
              m_dataCStr=0;
            else
            {
                 m_dataCStr=new int[strlen(str)+1];
                 strcpy(m_dataCstr,str);           
            }
              
        
        }
        ~String()
        {
            if(!m_dataCStr)//保险起见
            {
                delete []m_dataCStr;//delete null 错误
                m_dataCStr=0;//防止野指针
            }
        }


        const String& operato=(const & String str)//[];=;->往往为成员函数;>>为非成员函数
        {
            if(this!=*str)
            {
                if(!str.m_dataCStr)//实际情况是str.m_dataCStr不可能为null，但是为了保险起见，应该判断--以防后续的strlen(NULL)错误。
                  delete []m_dataCStr;  
                  m_dataCStr=0;
                else
                {
                    if(strlen(m_dataCStr)!=strlen(str.m_dataCStr))
                    {
                        delete []m_dataCStr;
                        m_dataCStr=new int[strlen(str.m_dataCStr)+1];
                    }
                     strcpy(m_dataCstr,str.m_dataCStr);           
                 }
            }

            return *this;
        }



        int size()
        {
            return strlen(m_dataCStr);//strlen(),返回第一个结束字符之前的字节数
        }
        

};
String g_string;
int main()
{
   String string1;
   cout<<static_cast<void*>(g_string.getData())<<endl;
   cout<<static_cast<void*>(string1.getData())<<endl;
    return 0;

}

/*
String::String(const char* str)
{
    //str为NULL
    //Str不为NULL


}
        String(const &String str);
        ~String();
        const String& operator=(const & String);
*/
